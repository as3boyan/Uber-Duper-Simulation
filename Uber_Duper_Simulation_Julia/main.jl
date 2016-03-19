#04.12.2015 10:55

R0 = 6378137.0
mu = 3.9860047e14

function h_x_y(x, y)
  return sqrt(x^2 + y^2) - R0
end

function T(R)
    return 2 * pi * sqrt(R^3 / mu)
end

function right_part(t, StateVector)
    R = sqrt(StateVector[1] * StateVector[1] + StateVector[2] * StateVector[2])
    R3 = R^3

    result = [0.0, 0.0, 0.0, 0.0]
    result[1] = StateVector[3]
    result[2] = StateVector[4]
    result[3] = -mu / R3 * StateVector[1]
    result[4] = -mu / R3 * StateVector[2]
    return result
end

function runge_kutta_t_state_vector(t, params, t_step, f)
    k1, k2, k3, k4 = [], [], [], []

    h = t_step

    k1 = f(t, params)

    new_params = [0.0, 0.0, 0.0, 0.0]

    for i = 1:length(params)
        p = params[i]
        new_params[i] = p + h / 2 * k1[i]
    end

    k2 = f(t + h / 2, new_params)

    for i = 1:length(params)
        p = params[i]
        new_params[i] = p + h / 2 * k2[i]
    end

    k3 = f(t + h / 2, new_params)

    for i = 1:length(params)
        p = params[i]
        new_params[i] = p + h * k3[i]
    end

    k4 = f(t + h, new_params)

    for i = 1:length(params)
        p = params[i]
        params[i] = p + h / 6 * (k1[i] + 2 * k2[i] + 2 * k3[i] + k4[i])
    end

    return params
end

function regular_calculation(Vx, Vy, t, t_end, t_step, x, y)
    file = open("D:\\Denis\\Uber_Duper_Simulation\\Uber_Duper_Simulation_Julia\\output.tr", "w")
    @printf(file, "t, x, y, Vx, Vy\n")

    while t <= t_end
        @printf(file, "%.3f %d %d %.3f %.3f\n", t, x, y, Vx, Vy)

        t += t_step

        x, y, Vx, Vy = runge_kutta_t_state_vector(t, [x, y, Vx, Vy], t_step, right_part)
    end

    close(file)
end

function benchmark_test(Vx, Vy, t, t_end, t_step, x, y)
    while t <= t_end
        t += t_step
        x, y, Vx, Vy = runge_kutta_t_state_vector(t, [x, y, Vx, Vy], t_step, right_part)
    end
end

function test(Vx, Vy, t, t_end, t_step, x, y, R)
    T_period = T(R)

    parameters = [x, y, Vx, Vy]

    while t <= t_end
        t += t_step

        texts = ["x", "y", "Vx", "Vy"]
        x, y, Vx, Vy = runge_kutta_t_state_vector(t, [x, y, Vx, Vy], t_step, right_part)

        k = round(T_period, 1)
#         print(round(t, 1) % k)
        if round(t, 1) % k == 0
            println("Виток № ", round(t / T_period))
            println("T = ", t)

            current_parameters = [x, y, Vx, Vy]
            for i = 1:4
                x1, x2 = round(parameters[i]), round(current_parameters[i])
                if x1 != x2
                    println("Разница в значениях:", texts[i], " ", x1, x2)
                end
            end
        end
        assert (round(h_x_y(x, y), 5) == 1000000)
    end
end

function main(type2, step)
    t_end = 10000.0  # Конец времени движения
    t_step = step  # Шаг интегрирования
    h0 = 1000000.0
    R = R0 + h0
    t, x, y, Vx, Vy = 0.0, 0.0, R, sqrt(mu / R), 0.0

    if type2 == "regular"
        regular_calculation(Vx, Vy, t, t_end, t_step, x, y)
    elseif type2 == "benchmark"
        benchmark_test(Vx, Vy, t, t_end, t_step, x, y)
    elseif type2 == "test"
        test(Vx, Vy, t, t_end, t_step, x, y, R)
    end
end

function run_calculation_and_measure_time(run_type, step, file)
  println(file, run_type, " t_step = ", step)
  time = @timed(main(run_type, step))[2]
  println(file, time)
  println(time)
  #@time(main(run_type, step))
end

file = open("D:\\Denis\\Uber_Duper_Simulation\\Uber_Duper_Simulation_Julia\\results.txt", "w")

for run_type in ["benchmark", "regular", "test"]
  if run_type != "test"
    for step in [1, 0.1, 0.01]
        run_calculation_and_measure_time(run_type, step, file)
    end
    else
      step = 0.1
      run_calculation_and_measure_time(run_type, step, file)
    end
end

close(file)
