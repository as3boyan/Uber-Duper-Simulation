/**
 * Created by ... on 05.01.2016.
 */
var R0 = 6378137;
var mu = 3.9860047e14;

function h_x_y(x, y) {
    return Math.sqrt(Math.pow(x, 2) + Math.pow(y, 2)) - R0;
}

function calculate_T_period(R) {
    return 2 * Math.PI * Math.sqrt(Math.pow(R, 3) / mu);
}

function right_part(t, StateVector) {
    var R = Math.sqrt(Math.pow(StateVector[0], 2) + Math.pow(StateVector[1], 2));
    var R3 = Math.pow(R, 3);

    var result = [0, 0, 0, 0];
    result[0] = StateVector[2];
    result[1] = StateVector[3];
    result[2] = -mu / R3 * StateVector[0];
    result[3] = -mu / R3 * StateVector[1];
    return result;
}

function runge_kutta_t_state_vector(t, params, t_step, f) {
    var k1 = [];
    var k2 = [];
    var k3 = [];
    var k4 = [];

    var h = t_step;

    k1 = f(t, params);

    var new_params = [];

    for (var i = 0; i < params.length; i++) {
        var p = params[i];
        new_params[i] = p + h / 2 * k1[i];
    }

    k2 = f(t + h / 2, new_params);

    for (var i = 0; i < params.length; i++) {
        var p = params[i];
        new_params[i] = p + h / 2 * k2[i];
    }

    k3 = f(t + h / 2, new_params);

    for (var i = 0; i < params.length; i++) {
        var p = params[i];
        new_params[i] = p + h * k3[i];
    }

    k4 = f(t + h, new_params);

    for (var i = 0; i < params.length; i++) {
        var p = params[i];
        params[i] = p + h / 6 * (k1[i] + 2 * k2[i] + 2 * k3[i] + k4[i]);
    }

    return params;
}

function regular_calculation(Vx, Vy, t, t_end, t_step, x, y) {
    var params = [x, y, Vx, Vy];

    while (t <= t_end) {
        if (t >= t_end - t_step) {
            console.log(t);
            console.log(params);
        }
        t += t_step;
        params = runge_kutta_t_state_vector(t, params, t_step, right_part);
    }
}

function benchmark_test(Vx, Vy, t, t_end, t_step, x, y) {
    var params = [x, y, Vx, Vy];

    while (t <= t_end) {
        t += t_step;
        params = runge_kutta_t_state_vector(t, params, t_step, right_part);
    }
}

function test(Vx, Vy, t, t_end, t_step, x, y, R) {
    var T_period = calculate_T_period(R);
    var params = [x, y, Vx, Vy];
    var parameters = [x, y, Vx, Vy];

    var texts = ["x", "y", "Vx", "Vy"];

    while (t <= t_end) {
        t += t_step;
        params = runge_kutta_t_state_vector(t, params, t_step, right_part);

        if (t >= T_period && t <= T_period + t_step) {
            console.log("Виток № ", t / T_period);
            console.log("T = ", t);

            for (var i = 0; i < 4; i++) {
                var x1 = params[i];
                var x2 = parameters[i];

                if (x1 - x2 > 1e-10) {
                    console.log("Разница в значениях:", texts[i], x1, x2, x1 - x2);
                }
            }
        }

        var hXY = h_x_y(params[0], params[1]);

        if (Math.abs(hXY - 1000000) > 1e-5) {
            console.log("Высота изменилась ", t, hXY);
            break;
        }
    }
}

function main(type, step) {
    var t_end = 10000;
    var t_step = step;
    var h0 = 1000000;
    var R = R0 + h0;
    var t = 0;
    var x = 0;
    var y = R;
    var Vx = Math.sqrt(mu / R);
    var Vy = 0;

    switch (type) {
        case "regular":
            regular_calculation(Vx, Vy, t, t_end, t_step, x, y);
            break;
        case "benchmark":
            benchmark_test(Vx, Vy, t, t_end, t_step, x, y);
            break;
        case "test":
            test(Vx, Vy, t, t_end, t_step, x, y, R);
            break;
    }

    var Vy = 0;
}

function run_calculation_and_measure_time(run_type, step) {
    var startDate = Date.now();
    main(run_type, step);
    var endDate = Date.now();
    var delta = (endDate - startDate) / 1000;
    console.log(run_type, "t_step =", step, "\n", delta);
}

["benchmark", "regular", "test"].forEach(
    function (run_type) {
        if (run_type != "test") {
            [1, 0.1, 0.01].forEach(
                function (step) {
                    run_calculation_and_measure_time(run_type, step);
                }
            );
        }
        else {
            var step = 0.1;
            run_calculation_and_measure_time(run_type, step);
        }
    }
);