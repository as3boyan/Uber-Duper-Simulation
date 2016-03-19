from math import sqrt, pow, pi
from pylab import *
import scipy
from scipy.integrate.odepack import odeint

R0 = 6378137
mu = 3.9860047e14

"""Расчет текущей высоты"""


def h_x_y(x, y):
    return sqrt(pow(x, 2) + pow(y, 2)) - R0


"""Расчет периода обращения"""


def T(R):
    return 2 * pi * sqrt(pow(R, 3) / mu)


"""Правые части"""


def right_part(t, StateVector):
    R = sqrt(StateVector[0] * StateVector[0] + StateVector[1] * StateVector[1])
    R3 = pow(R, 3)

    result = [0, 0, 0, 0]
    result[0] = StateVector[2]
    result[1] = StateVector[3]
    result[2] = -mu / R3 * StateVector[0]
    result[3] = -mu / R3 * StateVector[1]
    return result


"""Интегрированния методом Рунге-Кутта (4-го порядка)"""


def runge_kutta_t_state_vector(t, params, t_step, f):
    k1, k2, k3, k4 = [], [], [], []

    h = t_step

    k1 = f(t, params)

    new_params = []

    for i in range(0, len(params)):
        p = params[i]
        new_params.append(p + h / 2 * k1[i])

    k2 = f(t + h / 2, new_params)

    new_params = []

    for i in range(0, len(params)):
        p = params[i]
        new_params.append(p + h / 2 * k2[i])

    k3 = f(t + h / 2, new_params)

    new_params = []

    for i in range(0, len(params)):
        p = params[i]
        new_params.append(p + h * k3[i])

    k4 = f(t + h, new_params)

    for i in range(0, len(params)):
        p = params[i]
        params[i] = p + h / 6 * (k1[i] + 2 * k2[i] + 2 * k3[i] + k4[i])

    return params


"""Обычный расчет (с выводом вектора состояния в файл output.tr)"""


def regular_calculation(Vx, Vy, t, t_end, t_step, x, y):
    file = open("output.tr", mode="w")
    print('t, x, y, Vx, Vy', file=file)

    while t <= t_end:
        print("%(t).3f %(x)d %(y)d %(Vx).3f %(Vy).3f" % {"t": t, "x": x, "y": y, "Vx": Vx, "Vy": Vy},
              file=file)

        t += t_step

        x, y, Vx, Vy = runge_kutta_t_state_vector(t, [x, y, Vx, Vy], t_step, right_part)
    file.close()


"""Тест производительности (без вывода вектора состояния в файл output.tr)"""


def benchmark_test(Vx, Vy, t, t_end, t_step, x, y):
    while t <= t_end:
        t += t_step
        x, y, Vx, Vy = runge_kutta_t_state_vector(t, [x, y, Vx, Vy], t_step, right_part)


"""Тест на корректность результатов
(с проверкой высоты и проверкой соответствия вектора состояния с момента начала движения
на момент завершения первого витка)"""


def test(Vx, Vy, t, t_end, t_step, x, y, R):
    T_period = T(R)

    parameters = [x, y, Vx, Vy]

    x_data = []
    y_data = []

    while t <= t_end:
        x_data.append(x)
        y_data.append(y)

        t += t_step
        x, y, Vx, Vy = runge_kutta_t_state_vector(t, [x, y, Vx, Vy], t_step, right_part)

        k = round(T_period, 1)
        # print(round(t, 1) % k)
        if round(t, 1) % k == 0:
            print("Виток № ", round(t / T_period))
            print("T = ", t)

            for text, x0, x_period in zip(["x", "y", "Vx", "Vy"], parameters, [x, y, Vx, Vy]):
                x1, x2 = round(x0), round(x_period)
                if x1 != x2:
                    print("Разница в значениях:", text, x1, x2)

        assert (round(h_x_y(x, y), 5) == 1000000)

    plot(x_data, y_data)
    show()


"""Начальные условия и выбор режима расчета (обычный, тест производительности, тест на корректность полученных данных)"""


def main(type, step):
    t_end = 10000  # Конец времени движения
    t_step = float(step)  # Шаг интегрирования
    h0 = 1000000
    R = R0 + h0
    t, x, y, Vx, Vy = 0, 0, R, sqrt(mu / R), 0

    if type == "regular":
        regular_calculation(Vx, Vy, t, t_end, t_step, x, y)
    elif type == "benchmark":
        benchmark_test(Vx, Vy, t, t_end, t_step, x, y)
    elif type == "test":
        test(Vx, Vy, t, t_end, t_step, x, y, R)


def run_calculation_and_measure_time(run_type, step, file):
    timeit_timeit = timeit.timeit("main('" + run_type + "','" + str(step) + "')", setup="from __main__ import main",
                                  number=1)
    print(run_type, "t_step =", step, "\n",
          timeit_timeit,
          file=file)  # Замер затраченного времени (вывод в файл)
    print(run_type, "t_step =", step, "\n",
          timeit_timeit,
          )  # Замер затраченного времени (вывод на экран)


if __name__ == '__main__':
    import timeit

    file = open("results.txt", "w")

    for run_type in ["benchmark", "regular", "test"]:
        if run_type != "test":
            for step in [1, 0.1, 0.01]:
                run_calculation_and_measure_time(run_type, step, file)
        else:
            step = 0.1
            run_calculation_and_measure_time(run_type, step, file)

    file.close()

# odeint()