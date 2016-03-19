module Main where

import System.IO
import System.Time
import Text.Printf

mu :: Double
mu = 3.9860047e14

r0 :: Double
r0 = 6378137.0

h_x_y x y = sqrt(x^2 + y^2) - r0

calculate_T_period r = 2 * pi * sqrt(r^3) / mu

right_part :: Double -> [Double] -> [Double]
right_part t [x, y, vx, vy] = let r = sqrt(x^2 + y^2)
                                  r3 = r^3
                              in [vx, vy, -mu / r3 * x, -mu / r3 * y]

rk4 t parameters t_step f = 
    let h = t_step
        numbers = [0..3]
    in
        let k1 = f t parameters
            new_parameters1 = [parameters!!i + h / 2 * k1!!i | i <- numbers]        
            k2 = f (t + h / 2) new_parameters1
	    new_parameters2 = [parameters!!i + h / 2 * k2!!i | i <- numbers]
            k3 = f (t + h / 2) new_parameters2
	    new_parameters3 = [parameters!!i + h * k3!!i | i <- numbers]
            k4 = f (t + h) new_parameters3
        in [parameters!!i + h / 6 * (k1!!i + 2 * k2!!i + 2 * k3!!i + k4!!i) | i <- [0..3]]

runge_kutta_regular :: Double -> Double -> Double -> [Double] -> (Double -> [Double] -> [Double]) -> Handle -> IO()
runge_kutta_regular t t_step t_end parameters f h = do
    --putStrLn $ show $ parameters
    hPrintf h "%.3f %.0f %.0f %.3f %.3f\n" t (parameters!!0) (parameters!!1) (parameters!!2) (parameters!!3)
    if (t < t_end)
    then
        let next_time = t + t_step
            updated_parameters = rk4 next_time parameters t_step f
        in runge_kutta_regular next_time t_step t_end updated_parameters f h
    else return()

runge_kutta_benchmark :: Double -> Double -> Double -> [Double] -> (Double -> [Double] -> [Double]) -> IO()
runge_kutta_benchmark t t_step t_end parameters f = do
    if (t < t_end)
    then
        let next_time = t + t_step
            updated_parameters = rk4 next_time parameters t_step f
        in runge_kutta_benchmark next_time t_step t_end updated_parameters f
    else do
        putStrLn $ show $ ([t] ++ parameters)
        return()

main3_regular t_start t_step t_end h = 
    let h0 = 1000000.0
        r = r0 + h0
    in runge_kutta_regular t_start t_step t_end [0, r, sqrt(mu / r), 0] right_part h

main3_benchmark t_start t_step t_end = 
    let h0 = 1000000.0
        r = r0 + h0
    in runge_kutta_benchmark t_start t_step t_end [0, r, sqrt(mu / r), 0] right_part

main2 t_start t_step t_end h2 print = do
    startTime <- getClockTimeMS
    if (print) then do
        h <- openFile "output.tr" WriteMode
        main3_regular t_start t_step t_end h
        hClose h
    else do
        main3_benchmark t_start t_step t_end
    endTime <- getClockTimeMS
    hPrintf h2 "%d\n" (let k = endTime - startTime in k)
    return ()

getClockTimeMS = do
    (TOD s p) <- getClockTime
    return $ (s * 1000000 + p `div` 10^6)

main :: IO()
main = do
    h <- openFile "results.txt" WriteMode
    main2 0 1 10000 h False
    main2 0 0.1 10000 h False
    main2 0 0.01 10000 h False
    main2 0 1 10000 h True
    main2 0 0.1 10000 h True
    main2 0 0.01 10000 h True
    hClose h
    return()