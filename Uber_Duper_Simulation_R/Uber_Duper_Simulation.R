require(compiler)
enableJIT(3)

R0 = 6378137
mu = 3.9860047e14

h_x_y <- function (x, y) {
	sqrt(x^2 + y^2) - R0
}

calculate_T_period <- function (R) {
	2 * pi * sqrt(R^3 / mu)
}

right_part <- function (t, StateVector) {
	R <- sqrt(StateVector[1]^2 + StateVector[2]^2)
	R3 = R^3
	
	result <- array(, 4)
	result[1] <- StateVector[3]
	result[2] <- StateVector[4]
	result[3] <- -mu / R3 * StateVector[1]
	result[4] <- -mu / R3 * StateVector[2]
	result
}

runge_kutta_t_state_vector <- function(t, params, t_step, f) {
	k1 <- array(, 4)
	k2 <- array(, 4)
	k3 <- array(, 4)
	k4 <- array(, 4)

	h <- t_step

	k1 = f(t, params)

	new_params <- array(, 4)

	for (i in 1:4) {
		p <- params[i]
		new_params[i] = p + h / 2 * k1[i]
	}

	k2 = f(t + h / 2, new_params)

	for (i in 1:4) {
		p <- params[i]
		new_params[i] = p + h / 2 * k2[i]
	}

	k3 = f(t + h / 2, new_params)

	for (i in 1:4) {
		p <- params[i]
		new_params[i] = p + h * k3[i]
	}

	k4 = f(t + h, new_params)

	result = array(, 4)

	for (i in 1:4) {
		p <- params[i]
		result [i] <- p + h / 6 * (k1[i] + 2 * k2[i] + 2 * k3[i] + k4[i])
	}

	result
}

regular_calculation <- function (t, t_end, t_step, params) {
	file1 <- file("output.tr", "wt")
	cat("t, x, y, Vx, Vy\n", file=file1)
	
	while (t <= t_end) {
		cat(sprintf("%.3f %.0f %.0f %.3f %.3f\n", t, params[1], params[2], params[3], params[4]), file=file1)

		t = t + t_step

		params = runge_kutta_t_state_vector(t, params, t_step, right_part)
	}

	close(file1)
}

benchmark_test <- function (t, t_end, t_step, params) {
	while (t <= t_end) {
		t = t + t_step
		params = runge_kutta_t_state_vector(t, params, t_step, right_part)
	}
}

test <- function (t, t_end, t_step, params, R) {
	T_period = calculate_T_period(R)

	parameters = array(0, 4)
	
	for (i in 1:4) {
		parameters[i] = params[i]
	}

	texts = c("x", "y", "Vx", "Vy")

	while (t <= t_end) {
		t = t + t_step
		params = runge_kutta_t_state_vector(t, params, t_step, right_part)

		if (t >= T_period && t <= T_period + t_step) {
			print(paste("Виток № ", round(t / T_period)))
			print(paste("T = ", t))

			for (i in 1:4) {
				x1 <- round(parameters[i])
				x2 <- round(params[i])
				if (x1 != x2) {
					print(paste("Разница в значениях:", texts[i], x1, x2))
				}
			}

			rounded_height = round(h_x_y(params[1], params[2]), 5)
			if (rounded_height - 1e+06 > 1e-5) {
				print(rounded_height)
				stop("Высота не соответствует начальной")
			}
		}   
	}
}

main <- function (run_type, step) {
	t_end = 10000
	t_step = step
	h0 = 1000000
	R = R0 + h0
	t = 0
	x = 0
	y = R
	Vx = sqrt(mu / R)
	Vy = 0

	params <- c(x, y, Vx, Vy)

	if (run_type == "regular") {
		regular_calculation(t, t_end, t_step, params)
	}
	else if (run_type == "benchmark") {
		benchmark_test(t, t_end, t_step, params) 
	}
	else if (run_type == "test") {
		test(t, t_end, t_step, params, R)
	}
}

run_calculation_and_measure_time <- function (run_type, step, file2) {
	t = system.time(main(run_type, step))[3]

	data <- paste(run_type, "t_step =", step, "\n", t, "\n")
	cat(data, file = file2)
	print(data)
}

setwd("D:\\Denis\\Uber_Duper_Simulation\\Uber_Duper_Simulation_R")

file1 <- file("results.txt", "wt")

for (run_type in c("benchmark", "regular", "test")) {
	if (run_type != "test") {
		for (step in c(1, 0.1, 0.01)) {
			run_calculation_and_measure_time(run_type, step, file1)
		}
	}
	else {
		step <- 0.1
		run_calculation_and_measure_time(run_type, step, file1)
	}
}
	
close(file1)
