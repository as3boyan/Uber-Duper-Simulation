Imports System.IO
Imports System.Diagnostics.Stopwatch

Module Module1

    Const R0 As Double = 6378137
    Const mu As Double = 398600470000000.0

    Delegate Function right_part_function(t As Double, StateVector As Double()) As Double()

    'Расчет текущей высоты
    Function h_x_y(x As Double, y As Double) As Double
        Return Math.Sqrt(Math.Pow(x, 2) + Math.Pow(y, 2)) - R0
    End Function

    'Расчет периода обращения
    Function T_period_calculation(R As Double)
        Return 2 * Math.PI * Math.Sqrt(Math.Pow(R, 3) / mu)
    End Function

    'Правые части
    Function right_part(t As Double, StateVector As Double()) As Double()
        Dim R As Double = Math.Sqrt(StateVector(0) * StateVector(0) + StateVector(1) * StateVector(1))
        Dim R3 As Double = Math.Pow(R, 3)

        Dim result As Double() = {0, 0, 0, 0}
        result(0) = StateVector(2)
        result(1) = StateVector(3)
        result(2) = -mu / R3 * StateVector(0)
        result(3) = -mu / R3 * StateVector(1)
        Return result
    End Function

    'Интегрированния методом Рунге-Кутта (4-го порядка)
    Function runge_kutta_t_state_vector(t As Double, parameters As Double(), t_step As Double, f As right_part_function) As Double()

        Dim k1, k2, k3, k4 As Double()

        Dim h As Double = t_step

        k1 = f(t, parameters)

        Dim new_params As Double() = {0, 0, 0, 0}

        For i = 0 To parameters.Length - 1
            Dim p As Double = parameters(i)
            new_params(i) = p + h / 2 * k1(i)
        Next

        k2 = f(t + h / 2, new_params)

        For i = 0 To parameters.Length - 1
            Dim p As Double = parameters(i)
            new_params(i) = p + h / 2 * k2(i)
        Next

        k3 = f(t + h / 2, new_params)

        For i = 0 To parameters.Length - 1
            Dim p As Double = parameters(i)
            new_params(i) = p + h * k3(i)
        Next

        k4 = f(t + h, new_params)

        For i = 0 To parameters.Length - 1
            Dim p As Double = parameters(i)
            parameters(i) = p + h / 6 * (k1(i) + 2 * k2(i) + 2 * k3(i) + k4(i))
        Next

        Return parameters
    End Function

    'Обычный расчет (с выводом вектора состояния в файл output.tr)
    Sub regular_calculation(Vx As Double, Vy As Double, t As Double, t_end As Double, t_step As Double, x As Double, y As Double)
        Dim sw As StreamWriter = File.CreateText("output.tr")
        sw.WriteLine("t, x, y, Vx, Vy")

        While t <= t_end

            sw.WriteLine("{0:F3} {1:F0} {2:F0} {3:F3} {4:F3}", t, x, y, Vx, Vy)
            t += t_step

            Dim parameters As Double() = runge_kutta_t_state_vector(t, New Double() {x, y, Vx, Vy}, t_step, AddressOf right_part)
            x = parameters(0)
            y = parameters(1)
            Vx = parameters(2)
            Vy = parameters(3)

        End While

        sw.Close()
    End Sub


    'Тест производительности (без вывода вектора состояния в файл output.tr)
    Sub benchmark_test(Vx As Double, Vy As Double, t As Double, t_end As Double, t_step As Double, x As Double, y As Double)
        While t <= t_end
            t += t_step

            Dim parameters As Double() = runge_kutta_t_state_vector(t, New Double() {x, y, Vx, Vy}, t_step, AddressOf right_part)
            x = parameters(0)
            y = parameters(1)
            Vx = parameters(2)
            Vy = parameters(3)
        End While
    End Sub

    'Тест на корректность результатов
    '(с проверкой высоты и проверкой соответствия вектора состояния с момента начала движения
    'на момент завершения первого витка)
    Sub test(Vx As Double, Vy As Double, t As Double, t_end As Double, t_step As Double, x As Double, y As Double, R As Double)
        Dim T_period As Double = T_period_calculation(R)

        Dim parameters_at_start As Double() = {x, y, Vx, Vy}

        Dim k As Double

        While t <= t_end
            t += t_step

            Dim parameters As Double() = runge_kutta_t_state_vector(t, New Double() {x, y, Vx, Vy}, t_step, AddressOf right_part)
            x = parameters(0)
            y = parameters(1)
            Vx = parameters(2)
            Vy = parameters(3)

            k = Math.Round(T_period, 1)

            If Math.Round(t, 1) Mod k = 0 Then

                Console.WriteLine("Виток № {0}", Math.Round(t / T_period).ToString())
                Console.WriteLine("T = {0}", t)

                Dim texts As String() = {"x", "y", "Vx", "Vy"}
                Dim current_parameters As Double() = {x, y, Vx, Vy}

                For i = 0 To 3
                    Dim x1, x2 As Double
                    x1 = Math.Round(parameters(i))
                    x2 = Math.Round(current_parameters(i))

                    If Not x1 = x2 Then
                        Console.WriteLine("Разница в значениях: {0} {1} {2}", texts(i), x1, x2)
                    End If

                Next

            End If

            Debug.Assert(Math.Round(h_x_y(x, y), 5) = 1000000)
        End While
    End Sub


    'Начальные условия и выбор режима расчета (обычный, тест производительности, тест на корректность полученных данных)
    Sub main2(type As String, step2 As Double)
        Dim t_end, t_step, h0, R As Double
        Dim t, x, y, Vx, Vy As Double

        t_end = 10000
        t_step = step2
        h0 = 1000000
        R = R0 + h0

        t = 0
        x = 0
        y = R
        Vx = Math.Sqrt(mu / R)
        Vy = 0

        If type = "regular" Then
            regular_calculation(Vx, Vy, t, t_end, t_step, x, y)
        ElseIf type = "benchmark" Then
            benchmark_test(Vx, Vy, t, t_end, t_step, x, y)
        ElseIf type = "test" Then
            test(Vx, Vy, t, t_end, t_step, x, y, R)
        End If
    End Sub

    Sub run_calculation_and_measure_time(run_type As String, step2 As Double, sw As StreamWriter)
        Dim sw2 As Stopwatch = Stopwatch.StartNew()
        main2(run_type, step2)
        sw2.Stop()

        sw.WriteLine(run_type + " t_step = {0}" + vbCrLf + "{1}", step2, sw2.Elapsed.TotalSeconds)  ' Замер затраченного времени
    End Sub

    Sub Main()
        Dim sw As StreamWriter = File.CreateText("results.txt")

        For Each run_type As String In {"benchmark", "regular", "test"}
            If Not run_type = "test" Then
                For Each step2 As Double In {1, 0.1, 0.01}
                    run_calculation_and_measure_time(run_type, step2, sw)
                Next
            Else
                Dim step2 As Double = 0.1
                run_calculation_and_measure_time(run_type, step2, sw)
            End If
        Next

        sw.Close()
    End Sub

End Module
