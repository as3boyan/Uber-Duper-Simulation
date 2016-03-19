using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Diagnostics;

namespace Uber_Duper_Simulation_CSharp
{
    public delegate double[] right_part_function(double t, double[] StateVector);

    class Program
    {
        double R0 = 6378137;
        double mu = 3.9860047e14;

        //Расчет текущей высоты
        double h_x_y(double x, double y)
        {
            return Math.Sqrt(Math.Pow(x, 2) + Math.Pow(y, 2)) - R0;
        }

        //Расчет периода обращения
        double T(double R)
        {
            return 2 * Math.PI * Math.Sqrt(Math.Pow(R, 3) / mu);
        }

        //Правые части
        double[] right_part(double t, double[] StateVector)
        {
            double R = Math.Sqrt(StateVector[0] * StateVector[0] + StateVector[1] * StateVector[1]);
            double R3 = Math.Pow(R, 3);

            double[] result = { 0, 0, 0, 0 };
            result[0] = StateVector[2];
            result[1] = StateVector[3];
            result[2] = -mu / R3 * StateVector[0];
            result[3] = -mu / R3 * StateVector[1];
            return result;
        }

        //Интегрированния методом Рунге-Кутта (4-го порядка)
        double[] runge_kutta_t_state_vector(double t, double[] parameters, double t_step, right_part_function f)
        {
            double[] k1, k2, k3, k4;

            double h = t_step;

            k1 = f(t, parameters);

            double[] new_params = { 0, 0, 0, 0 };

            for (int i = 0; i < parameters.Length; i++)
            {
                double p = parameters[i];
                new_params[i] = (p + h / 2 * k1[i]);
            }

            k2 = f(t + h / 2, new_params);

            for (int i = 0; i < parameters.Length; i++)
            {
                double p = parameters[i];
                new_params[i] = (p + h / 2 * k2[i]);
            }

            k3 = f(t + h / 2, new_params);

            for (int i = 0; i < parameters.Length; i++)
            {
                double p = parameters[i];
                new_params[i] = p + h * k3[i];
            }

            k4 = f(t + h, new_params);

            for (int i = 0; i < parameters.Length; i++)
            {
                double p = parameters[i];
                parameters[i] = p + h / 6 * (k1[i] + 2 * k2[i] + 2 * k3[i] + k4[i]);
            }

            return parameters;
        }

        //Обычный расчет (с выводом вектора состояния в файл output.tr)
        void regular_calculation(double Vx, double Vy, double t, double t_end, double t_step, double x, double y)
        {
            StreamWriter sw = File.CreateText("output.tr");
            sw.WriteLine("t, x, y, Vx, Vy");

            while (t <= t_end)
            {
                sw.WriteLine("{0:F3} {1:F0} {2:F0} {3:F3} {4:F3}", t, x, y, Vx, Vy);
                t += t_step;

                double[] parameters = runge_kutta_t_state_vector(t, new double[4] { x, y, Vx, Vy }, t_step, right_part);
                x = parameters[0];
                y = parameters[1];
                Vx = parameters[2];
                Vy = parameters[3];
            }

            sw.Close();
        }

        //Тест производительности (без вывода вектора состояния в файл output.tr)
        void benchmark_test(double Vx, double Vy, double t, double t_end, double t_step, double x, double y)
        {
            while (t <= t_end)
            {
                t += t_step;

                double[] parameters = runge_kutta_t_state_vector(t, new double[4] { x, y, Vx, Vy }, t_step, right_part);
                x = parameters[0];
                y = parameters[1];
                Vx = parameters[2];
                Vy = parameters[3];
            }
        }

        //        Тест на корректность результатов
        //(с проверкой высоты и проверкой соответствия вектора состояния с момента начала движения
        //на момент завершения первого витка)
        void test(double Vx, double Vy, double t, double t_end, double t_step, double x, double y, double R)
        {
            double T_period = T(R);

            double[] parameters_at_start = { x, y, Vx, Vy };

            double k;

            while (t <= t_end)
            {
                t += t_step;

                double[] parameters = runge_kutta_t_state_vector(t, new double[4] { x, y, Vx, Vy }, t_step, right_part);
                x = parameters[0];
                y = parameters[1];
                Vx = parameters[2];
                Vy = parameters[3];

                k = Math.Round(T_period, 1);

                if (Math.Round(t, 1) % k == 0)
                {
                    Console.WriteLine("Виток № {0}", Math.Round(t / T_period).ToString());
                    Console.WriteLine("T = {0}", t);

                    String[] texts = { "x", "y", "Vx", "Vy" };
                    double[] current_parameters = { x, y, Vx, Vy };

                    for (int i = 0; i < 4; i++)
                    {
                        double x1, x2;
                        x1 = Math.Round(parameters[i]);
                        x2 = Math.Round(current_parameters[i]);

                        if (x1 != x2)
                        {
                            Console.WriteLine("Разница в значениях: {0} {1} {2}", texts[i], x1, x2);
                        }
                    }
                }

                Debug.Assert(Math.Round(h_x_y(x, y), 5) == 1000000);
            }
        }

        //Начальные условия и выбор режима расчета (обычный, тест производительности, тест на корректность полученных данных)
        void main(string type, double step)
        {
            double t_end, t_step, h0, R;
            double t, x, y, Vx, Vy;

            t_end = 10000;
            t_step = step;
            h0 = 1000000;
            R = R0 + h0;

            t = 0;
            x = 0;
            y = R;
            Vx = Math.Sqrt(mu / R);
            Vy = 0;

            switch (type)
            {
                case "regular":
                    regular_calculation(Vx, Vy, t, t_end, t_step, x, y);
                    break;
                case "benchmark":
                    benchmark_test(Vx, Vy, t, t_end, t_step, x, y);
                    break;
                case "test":
                    test(Vx, Vy, t, t_end, t_step, x, y, R);
                    break;
                default:
                    break;
            }
        }

        void run_calculation_and_measure_time(string run_type, double step, StreamWriter sw)
        {
            Stopwatch stopwatch = Stopwatch.StartNew();
            main(run_type, step);
            stopwatch.Stop();

            sw.WriteLine(run_type + " t_step = {0}\n{1}", step, stopwatch.Elapsed.TotalSeconds);  // Замер затраченного времени
        }


        static void Main(string[] args)
        {
            StreamWriter sw = File.CreateText("results.txt");

            Program p = new Program();

            foreach (var run_type in new string[] { "benchmark", "regular", "test" })
            {
                if (run_type != "test")
                {
                    foreach (var step in new double[] { 1, 0.1, 0.01 })
                    {
                        p.run_calculation_and_measure_time(run_type, step, sw);
                    }
                }
                else
                {
                    double step = 0.1;
                    p.run_calculation_and_measure_time(run_type, step, sw);
                }
            }

            sw.Close();
        }
    }
}
