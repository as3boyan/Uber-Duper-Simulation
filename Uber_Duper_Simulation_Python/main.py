# 02.12.2015 15:49 - 16:31

from math import sqrt, pow, pi

def main():
    R0 = 6378137#6381110
    g0 = 9.80665
    mu = 3.9860047e14


    def h_x_y(x, y):
        return sqrt(pow(x, 2) + pow(y, 2)) - R0


    def g(h):
        return g0 * R0 / (R0 + h)


    def runge_kutta_t(x_n, y_n, h, f):
        k1 = f(x_n, y_n)
        k2 = f(x_n + h / 2, y_n + h / 2 * k1)
        k3 = f(x_n + h / 2, y_n + h / 2 * k2)
        k4 = f(x_n + h, y_n + h * k3)

        result = y_n + h / 6 * (k1 + 2 * k2 + 2 * k3 + k4)
        return result


    # h0 = 1000000
    h0 = 500000

    x0 = 0
    y0 = R0 + h0

    Vx0 = sqrt(mu / y0)
    Vy0 = 0

    t_start = 0
    t_end = 10000
    t_step = 1

    t = t_start
    x = x0
    y = R = y0
    Vx = Vx0
    Vy = Vy0

    g_h0 = g(h0)


    def dx_dt(t, x):
        return Vx


    def dy_dt(t, y):
        return Vy


    def dVx_dt(t, Vx):
        return -g_h0 * x / R


    def dVy_dt(t, Vy):
        return -g_h0 * y / R


    def right_part(t, StateVector):
        R = sqrt(StateVector[0] * StateVector[0] + StateVector[1] * StateVector[1])
        R3 = R * R * R

        result = [0, 0, 0, 0]
        result[0] = StateVector[2]
        result[1] = StateVector[3]
        # result[2] = -g_h0 * StateVector[0] / R
        # result[3] = -g_h0 * StateVector[1] / R

        result[2] = -mu / R3 * StateVector[0]
        result[3] = -mu / R3 * StateVector[1]
        return result


    print('t, x, y, Vx, Vy')

    t, x, y, Vx, Vy = 103.812, -4863577.315, -4863577.315, 5382.927, -5382.927

    # print(h_x_y(x, y))

    def T():
        return 2 * pi * sqrt(pow(R, 3) / mu)

    print(T())

    # x_array = []
    # y_array = []

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


    while t <= t_end:
        # x = runge_kutta_t(t, x, t_step, dx_dt)
        # y = runge_kutta_t(t, y, t_step, dy_dt)
        # Vx = runge_kutta_t(t, Vx, t_step, dVx_dt)
        # Vy = runge_kutta_t(t, Vy, t_step, dVy_dt)

        # x_array.append(x)
        # y_array.append(y)

        print("%(t).3f %(x)d %(y)d %(Vx).3f %(Vy).3f %(h).3f" % {"t": t, "x": x, "y": y, "Vx": Vx, "Vy": Vy, "h": h_x_y(x, y)})

        t += t_step

        x, y, Vx, Vy = runge_kutta_t_state_vector(t, [x, y, Vx, Vy], t_step, right_part)

    # (x_array, y_array)

    # f1 = Vy #dy/dt
    # f2 = g * y/R #dVy/dt

if __name__ == '__main__':
    import timeit
    print(timeit.timeit("main()", setup="from __main__ import main", number=1))
