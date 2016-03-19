package com.company;

import java.io.FileWriter;
import java.io.IOException;

import static java.lang.Math.*;

public class Main {

    public Main() {
        this.circularOrbitRightPart = new CircularOrbitRightPart();
    }

    interface RightPartClass {
        double[] right_part(double t, double[] StateVector);
    }

    class CircularOrbitRightPart implements RightPartClass {

        @Override
        public double[] right_part(double t, double[] StateVector) {
            double R = sqrt(StateVector[0] * StateVector[0] + StateVector[1] * StateVector[1]);
            double R3 = pow(R, 3);

            double[] result = new double[]{0, 0, 0, 0};
            result[0] = StateVector[2];
            result[1] = StateVector[3];
            result[2] = -mu / R3 * StateVector[0];
            result[3] = -mu / R3 * StateVector[1];
            return result;

        }
    }

    final double R0 = 6378137;
    final double mu = 3.9860047e14;

    CircularOrbitRightPart circularOrbitRightPart;

    double h_x_y(double x, double y) {
        return sqrt(pow(x, 2) + pow(y, 2)) - R0;
    }

    double T(double R) {
        return 2 * PI * sqrt(pow(R, 3) / mu);
    }

    double[] runge_kutta_t_state_vector(double t, double[] params, double t_step, RightPartClass rightPartClass)
    {
        double[] k1, k2, k3, k4;

        double h = t_step;

        k1 = rightPartClass.right_part(t, params);

        double[] new_params = {0, 0, 0, 0};

        double p;

        for (int i = 0; i < params.length; i++) {
            p = params[i];
            new_params[i] = p + h / 2 * k1[i];
        }

        k2 = rightPartClass.right_part(t + h / 2, new_params);

        for (int i = 0; i < params.length; i++) {
            p = params[i];
            new_params[i] = p + h / 2 * k2[i];
        }

        k3 = rightPartClass.right_part(t + h / 2, new_params);

        for (int i = 0; i < params.length; i++) {
            p = params[i];
            new_params[i] = p + h * k3[i];
        }

        k4 = rightPartClass.right_part(t + h, new_params);

        for (int i = 0; i < params.length; i++) {
            p = params[i];
            params[i] = p + h / 6 * (k1[i] + 2 * k2[i] + 2 * k3[i] + k4[i]);
        }

        return params;
    }

    void regular_calculation(double Vx, double Vy, double t, double t_end, double t_step, double x, double y) throws IOException {
        FileWriter fr = new FileWriter("output.tr");
        fr.write("t, x, y, Vx, Vy\n");

        double[] params = {0, 0, 0, 0};

        params[0] = x;
        params[1] = y;
        params[2] = Vx;
        params[3] = Vy;

        while (t <= t_end) {
            fr.write(String.format("%.3f %.0f %.0f %.3f %.3f\n", t, x, y, Vx, Vy));
            t += t_step;

            params = runge_kutta_t_state_vector(t, params ,t_step, circularOrbitRightPart);

            x = params[0];
            y = params[1];
            Vx = params[2];
            Vy = params[3];
        }
        fr.close();
    }

    void benchmark_test(double Vx, double Vy, double t, double t_end, double t_step, double x, double y)
    {
        double[] params = {0, 0, 0, 0};

        params[0] = x;
        params[1] = y;
        params[2] = Vx;
        params[3] = Vy;

        while (t <= t_end)
        {
            t += t_step;

            params = runge_kutta_t_state_vector(t, params, t_step, circularOrbitRightPart);
        }
    }

    void test(double Vx, double Vy, double t, double t_end, double t_step, double x, double y, double R) {
        double T_period = T(R);

        double[] parameters ={x, y, Vx, Vy};

        double[] params = {0, 0, 0, 0};

        params[0] = x;
        params[1] = y;
        params[2] = Vx;
        params[3] = Vy;

        String[] texts = {"x", "y", "Vx", "Vy"};

        while (t <= t_end) {
            t += t_step;

            params = runge_kutta_t_state_vector(t, params, t_step, circularOrbitRightPart);

            if (t >= T_period && (t <= T_period + t_step)) {
                System.out.println(String.format("Виток № %d", Math.round(t / T_period)));
                System.out.println(String.format("T = %f", t));

                for (int i = 0; i < 4; i++) {
                    if (parameters[i] - params[i] > 0) {
                        System.out.println(String.format("Разница в значениях [%s]: %f %f %f", texts[i], parameters[i], params[i], parameters[i] - params[i]));
                    }
                }
            }

            assert (h_x_y(params[0], params[1]) - 1000000 < 1e-16);
        }

    }

    void main2(String type2, double step) throws IOException {

        double t_end = 10000;// Конец времени движения
        double t_step = step;   // Шаг интегрирования
        int h0 = 1000000;
        double R = R0 + h0;
        double t = 0;
        double x = 0;
        double y = R;
        double Vx = sqrt(mu / R);
        double Vy = 0;

        if (type2 == "regular") {
            regular_calculation(Vx, Vy, t, t_end, t_step, x, y);
        } else if (type2 == "benchmark") {
            benchmark_test(Vx, Vy, t, t_end, t_step, x, y);
        } else if (type2 == "test") {
            test(Vx, Vy, t, t_end, t_step, x, y, R);
        }
    }

    void run_calculation_and_measure_time(String run_type, double step, FileWriter fr) throws IOException {
        long startTime = System.nanoTime();
        main2(run_type, step);
        long endTime = System.nanoTime();
        String format = String.format("%s t_step = %f\n%f\n", run_type , step, (endTime-startTime)/1e9);
        System.out.print(format);
        fr.write(format);  // Замер затраченного времени
    }

    public static void main(String[] args) throws IOException {
        Main main = new Main();

        FileWriter file = new FileWriter("results.txt");

        String[] run_types = {"benchmark", "regular", "test"};

        for (int i = 0; i < run_types.length; i++) {

            String run_type = run_types[i];
            if (run_type != "test")
            {
                Double[] steps = {1.0, 0.1, 0.01};
                for (int j = 0; j < steps.length; j++) {
                    main.run_calculation_and_measure_time(run_type, steps[j], file);
                }
            }
            else {
                double step = 0.1;
                main.run_calculation_and_measure_time(run_type, step, file);
            }
        }

        file.close();
    }
}
