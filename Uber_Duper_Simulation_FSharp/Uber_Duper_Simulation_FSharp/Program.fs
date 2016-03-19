// Дополнительные сведения о F# см. на http://fsharp.net

open System
open System.IO
open System.Diagnostics

let R0 = 6378137.0
let mu = 3.9860047e14

let h_x_y x y = sqrt(Math.Pow(x,2.0) + Math.Pow(y,2.0)) - R0

let T R = 2.0 * Math.PI * sqrt(Math.Pow(R, 3.0) / mu)

let R_x_y x y = sqrt(Math.Pow(x, 2.0) + Math.Pow(y, 2.0))

let R3 (x, y) = Math.Pow(R_x_y x y, 3.0)

let right_part (t:double, stateVector:List<double>):List<double> = 
    let R3value = R3 (stateVector.Item(0), stateVector.Item(1)) in
    [
    stateVector.Item(2);
    stateVector.Item(3);
    -mu / R3value * stateVector.Item(0);
    -mu / R3value * stateVector.Item(1)
    ]

let runge_kutta_t_state_vector (t:double, parameters:List<double>, t_step:double, f:double * List<double> -> List<double>):List<double> =
    let h:double = t_step
    let k1:List<double> = f(t, parameters)
    let new_parameters = List.map (fun i -> parameters.Item(i) + h / 2.0 * k1.Item(i)) [0..3] in
    let k2:List<double> = f(t + h / 2.0, new_parameters)
    let new_parameters = List.map (fun i -> parameters.Item(i) + h / 2.0 * k2.Item(i)) [0..3] in
    let k3:List<double> = f(t + h / 2.0, new_parameters)
    let new_parameters = List.map (fun i -> parameters.Item(i) + h * k3.Item(i)) [0..3] in
    let k4:List<double> = f(t + h, new_parameters)

    let result = List.map (fun i -> parameters.Item(i) + h / 6.0 * (k1.Item(i) + 2.0 * k2.Item(i) + 2.0 * k3.Item(i) + k4.Item(i))) [0..3]
    result

   
let regular_calculation (t_start:double, t_end:double, t_step:double, x0:double, y0:double, vx0:double, vy0:double) =
    let file = File.CreateText("output.tr")
    file.WriteLine("t, x, y, Vx, Vy")
    
    (t_start, [x0; y0; vx0; vy0]) |> Seq.unfold (fun (t, stateVector) ->
        if (t <= t_end) then Some((t, stateVector), (t+t_step, runge_kutta_t_state_vector(t, stateVector, t_step, right_part)))
        else None
        ) |> Seq.iter(fun (t, stateVector) -> 
            file.WriteLine(String.Format("{0:F3} {1:F0} {2:F0} {3:F3} {4:F3}", t, stateVector.Item(0), stateVector.Item(1), stateVector.Item(2), stateVector.Item(3)))
        )

    file.Close()

let benchmark_test (t_start:double, t_end:double, t_step:double, x0:double, y0:double, vx0:double, vy0:double) =
    (t_start, [x0; y0; vx0; vy0]) |> Seq.unfold (fun (t, stateVector) ->
        if (t <= t_end) then Some((t, stateVector), (t+t_step, runge_kutta_t_state_vector(t, stateVector, t_step, right_part)))
        else None
        ) |> Seq.filter(fun (t, stateVector) ->
            t + t_step = t_end
        ) |> Seq.iter(fun (t, stateVector) ->
            Console.WriteLine(t.ToString(), stateVector.Item(0).ToString(), stateVector.Item(1).ToString(), stateVector.Item(2).ToString(), stateVector.Item(3).ToString())
        )
    

let test (t_start:double, t_end:double, t_step:double, x0:double, y0:double, vx0:double, vy0:double) =
    let result = (t_start, [x0; y0; vx0; vy0]) |> Seq.unfold (fun (t, stateVector) ->
        if (t <= t_end) then Some((t, stateVector), (t+t_step, runge_kutta_t_state_vector(t, stateVector, t_step, right_part)))
        else None
        )

    ignore result

let main (run_type, t_step) =
    let h0 = 1000000.0
    let R = R0 + h0
    
    let parameters = (0.0, 10000.0, t_step, 0.0, R, sqrt(mu / R), 0.0)

    if run_type = "regular" then 
        regular_calculation(parameters)
    elif run_type = "benchmark" then 
        benchmark_test(parameters)
    elif run_type = "test" then
        test(parameters)

let run_calculation_and_measure_time (run_type, t_step, file:StreamWriter) =
    let sw = Stopwatch.StartNew()
    main(run_type, t_step)
    sw.Stop()
    
    file.WriteLine(sprintf "%s t_step = %f\n%f" run_type t_step sw.Elapsed.TotalSeconds)

let file = File.CreateText("results.txt")
let run_types = ["benchmark"; "regular"; "test"]
let steps:List<double> = [1.0; 0.1; 0.01]

let results = 
    [0..run_types.Length - 2]
    |> Seq.iter(fun (i) -> 
        [0..steps.Length - 1]
        |> Seq.iter(fun (j) ->
            run_calculation_and_measure_time(run_types.Item(i), steps.Item(j), file)
        )
    )

run_calculation_and_measure_time("test", 0.01, file)

file.Close()



