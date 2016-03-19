// Uber_Duper_Simulation_Cpp.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <assert.h>

#define _USE_MATH_DEFINES true
#include <math.h>

#include <time.h>

const double R0 = 6378137;
const double mu = 3.9860047e14;

double h_x_y(double x, double y)
{
	return sqrt(pow(x, 2) + pow(y, 2)) - R0;
}

double calculate_T_period(double R)
{
	return 2 * M_PI * sqrt(pow(R, 3) / mu);
}

void right_part(double t, double StateVector[], double result[])
{
	double R = sqrt(pow(StateVector[0], 2) + pow(StateVector[1], 2));
	double R3 = pow(R, 3);
	
	result[0] = StateVector[2];
	result[1] = StateVector[3];
	result[2] = -mu / R3 * StateVector[0];
	result[3] = -mu / R3 * StateVector[1];
}

void runge_kutta_t_state_vector(double t, double params[], double t_step, void(*f)(double t, double StateVector[], double result[]))
{
	double k1[4] = {};
	double k2[4] = {};
	double k3[4] = {};
	double k4[4] = {};

	double h = t_step;

	f(t, params, k1);

	double new_params[4] = {};

	for (int i = 0; i < 4; i++)
	{
		double p = params[i];
		new_params[i] = p + h / 2 * k1[i];
	}

	f(t + h / 2, new_params, k2);

	for (int i = 0; i < 4; i++)
	{
		double p = params[i];
		new_params[i] = p + h / 2 * k2[i];
	}

	f(t + h / 2, new_params, k3);

	for (int i = 0; i < 4; i++)
	{
		double p = params[i];
		new_params[i] = p + h * k3[i];
	}

	f(t + h, new_params, k4);

	for (int i = 0; i < 4; i++)
	{
		double p = params[i];
		params[i] = p + h / 6 * (k1[i] + 2 * k2[i] + 2 * k3[i] + k4[i]);
	}
}

void regular_calculation(double t, double t_end, double t_step, double params[])
{
	FILE *file1;
	file1 = fopen("output.tr", "w+");
	fprintf(file1, "t, x, y, Vx, Vy\n");

	while (t <= t_end)
	{
		fprintf(file1, "%.3f %.0f %.0f %.3f %.3f\n", t, params[0], params[1], params[2] ,params[3]);

		t += t_step;

		runge_kutta_t_state_vector(t, params, t_step, right_part);
	}

	fclose(file1);
}

void benchmark_test(double t, double t_end, double t_step, double params[])
{
	while (t <= t_end)
	{
		t += t_step;
		runge_kutta_t_state_vector(t, params, t_step, right_part);
	}
}

void test(double t, double t_end, double t_step, double params[], double R)
{
	double T_period = calculate_T_period(R);

	double parameters[4] = {};

	for (int i = 0; i < 4; i++)
	{
		parameters[i] = params[i];
	}

	//string texts[4] = {};

	while (t <= t_end)
	{
		t += t_step;
		runge_kutta_t_state_vector(t, params, t_step, right_part);

		if (t >= T_period && t <= T_period + t_step)
		{
			printf("Виток № %d", t / T_period);
			printf("T = %f", t);

			for (int i = 0; i < 4; i++)
			{
				//double x1 = Math::Round(parameters[0], 2);
				//double x2 = Math::Round(params[0], 2);
			}
		}

		//assert
	}
}

void main2(char *run_type, double p_t_step)
{
	const double t_end = 10000;
	const double t_step = p_t_step;
	const double h0 = 1000000;
	const double R = R0 + h0;

	double t = 0;
	double x = 0;
	double y = R;
	double Vx = sqrt(mu / R);
	double Vy = 0;

	double params[4] = {x, y, Vx, Vy};

	if (run_type == "regular")
	{
		regular_calculation(t, t_end, t_step, params);
	}
	else if (run_type == "benchmark")
	{
		benchmark_test(t, t_end, t_step, params);
	}
	else if (run_type == "test")
	{
		test(t, t_end, t_step, params, R);
	}
}

void run_calculation_and_measure_time(char* run_type, double t_step, FILE *file1)
{
	clock_t startTime = clock();
	main2(run_type, t_step);
	clock_t endTime = clock();
	
	clock_t delta = endTime - startTime;

	double seconds = delta / 1000.0;

	fprintf(file1, "%s t_step = %f\n%f\n", run_type, t_step, seconds);
	printf("%s t_step = %f\n%f\n", run_type, t_step, seconds);
}

int _tmain(int argc, _TCHAR* argv[])
{
	FILE *file1 = fopen("results.txt", "w+");

	char** run_types = new char*[4];
	run_types[0] = "benchmark";
	run_types[1] = "regular";
	run_types[2] = "test";

	char* run_type;

	double steps[3] = {1, 0.1, 0.01};

	for (int i = 0; i < 3; i++)
	{
		run_type = run_types[i];

		if (run_type != "test")
		{
			for (int j = 0; j < 3; j++)
			{
				double t_step = steps[j];
				run_calculation_and_measure_time(run_type, t_step, file1);
			}
		}
		else
		{
			double t_step = 0.1;
			run_calculation_and_measure_time(run_type, t_step, file1);
		}
	}

	fclose(file1);

	return 0;
}

