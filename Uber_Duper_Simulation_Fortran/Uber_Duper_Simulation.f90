module UberDuperSimulation
  implicit none
  INTEGER, PARAMETER :: DP = kind(1.0d0)
  REAL (DP), PARAMETER :: R0 = 6378137
  REAL (DP), PARAMETER :: mu = 3.9860047e14
  REAL (DP) :: Pi = 4D0*DATAN(1D0)
  
  abstract interface
    function rp (t, StateVector)
      INTEGER, PARAMETER :: DP = kind(1.0d0)
      REAL (DP), DIMENSION(0:3) :: StateVector, rp
      REAL (DP) :: t
    end function rp
  end interface
  
contains

function h_x_y(x, y)
  implicit none
  REAL (DP) :: x,y
  REAL (DP) :: h_x_y
  h_x_y = sqrt(x**2 + y**2) - R0
end function h_x_y

function calculate_T_period(R)
  REAL (DP) :: R
  REAL (DP) :: calculate_T_period
  calculate_T_period = 2 * Pi * sqrt(R**3 / mu)
end function calculate_T_period
  
function right_part(t, StateVector)
  REAL (DP), DIMENSION(0:3) :: StateVector, right_part
  REAL (DP) :: t, R, R3
  
  R = sqrt(StateVector(0)**2 + StateVector(1)**2)
  R3 = R**3
  
  right_part(0) = StateVector(2)
  right_part(1) = StateVector(3)
  right_part(2) = -mu / R3 * StateVector(0)
  right_part(3) = -mu / R3 * StateVector(1)
end function right_part
  
subroutine runge_kutta_t_state_vector(t, params, t_step, f)
  REAL (DP) :: t, t_step, h
  REAL (DP), DIMENSION(0:3) :: params, k1, k2, k3, k4, new_params
  INTEGER :: i
  REAL (DP) :: p
  procedure (rp), pointer :: f
  
  h = t_step
  
  k1 = f(t, params)
  
  do i=0,3
    p = params(i)
    new_params(i) = p + h / 2 * k1(i)
  end do
  
  k2 = f(t + h / 2, new_params)
  
  do i=0,3
    p = params(i)
    new_params(i) = p + h / 2 * k2(i)
  end do
  
  k3 = f(t + h / 2, new_params)
  
  do i=0,3
    p = params(i)
    new_params(i) = p + h * k3(i)
  end do
  
  k4 = f(t + h, new_params)
  
  do i=0,3
    p = params(i)
    params(i) = p + h / 6 * (k1(i) + 2 * k2(i) + 2 * k3(i) + k4(i))
  end do
  
end subroutine runge_kutta_t_state_vector

subroutine regular_calculation(t, t_end, t_step, x, y, Vx, Vy)
  REAL (DP) :: t,t_end,t_step,x,y,Vx,Vy
  REAL (DP), DIMENSION(0:3) :: params
  procedure (rp), pointer :: f
  
  params(0) = x
  params(1) = y
  params(2) = Vx
  params(3) = Vy
  
  f => right_part
  
  open(1, file='output.tr')
    do
      if (t > t_end) then
        exit
      end if
      
      write(1, '(F14.3, F14.0, F14.0, F14.3, F14.3)') t, params
      t = t + t_step
      call runge_kutta_t_state_vector(t, params, t_step, f)
    end do
  close(1)
end subroutine regular_calculation

subroutine benchmark_test(t, t_end, t_step, x, y, Vx, Vy)
  REAL (DP) :: t,t_end,t_step,x,y,Vx,Vy
  REAL (DP), DIMENSION(0:3) :: params
  procedure (rp), pointer :: f
  
  params(0) = x
  params(1) = y
  params(2) = Vx
  params(3) = Vy
  
  f => right_part
  
  do
    if (t > t_end) then
      exit
    end if
    
    t = t + t_step
    call runge_kutta_t_state_vector(t, params, t_step, f)
  end do
  
end subroutine benchmark_test

subroutine test(t, t_end, t_step, x, y, Vx, Vy, R)
  REAL (DP) :: t,t_end,t_step,x,y,Vx,Vy,R,T_period,x1,x2,h
  REAL (DP), DIMENSION(0:3) :: params, parameters
  procedure (rp), pointer :: f
  CHARACTER (LEN=2), DIMENSION(0:3) :: texts
  INTEGER :: i
  
  params(0) = x
  params(1) = y
  params(2) = Vx
  params(3) = Vy
  
  parameters = params
  
  texts(0) = "x"
  texts(1) = "y"
  texts(2) = "Vx"
  texts(3) = "Vy"
  
  f => right_part
  
  T_period = calculate_T_period(R)
  
  do
    if (t > t_end) then
      exit
    end if
    
    t = t + t_step
    call runge_kutta_t_state_vector(t, params, t_step, f)
    
    if (t .GE. T_period .and. t .LE. (t + t_step)) then
      print *, "Виток № ", t/T_period
      print *, "T = ", t
      
      do i = 0,3
        x1 = params(i)
        x2 = parameters(i)
        if (abs(x1 - x2) > 1e-5) then
          print *, "Разница в значениях:", texts(i), x1, x2, x1-x2
        end if
      end do
    end if
    
    h = h_x_y(params(0), params(1))
    
    if (h - 1000000 > 1e-5) then
      print *, "Высота изменилась", h
      stop
    end if
  end do
end subroutine test
  
subroutine main(run_type, step)
  REAL (DP) :: t_end, t_step, h0, R, t,x,y,Vx,Vy,step
  CHARACTER (LEN=*) :: run_type
  t_end = 10000
  t_step = step
  h0 = 1000000
  R = R0 + h0
  t = 0
  x = 0
  y = R
  Vx = sqrt(mu / R)
  Vy = 0
  
  if (run_type == "regular") then
    call regular_calculation(t, t_end, t_step, x, y, Vx, Vy)
  else if (run_type == "benchmark") then
    call benchmark_test(t, t_end, t_step, x, y, Vx, Vy)
  else if (run_type == "test") then
    call test(t, t_end, t_step, x, y, Vx, Vy, R)
  end if
  
end subroutine main

subroutine run_calculation_and_measure_time(run_type, step, n)
CHARACTER (LEN=*) :: run_type
REAL (DP) :: step
INTEGER :: n
integer (Kind=8) :: start_count, end_count, count_rate, count_max, delta
print *, run_type
call system_clock(start_count, count_rate, count_max)
call main(run_type, step)
call system_clock(end_count, count_rate, count_max)
delta = end_count - start_count
write (n,*) run_type, step
write (n,*) delta
print *, run_type, step, delta
end subroutine run_calculation_and_measure_time
 
subroutine main2()
CHARACTER (LEN=10), DIMENSION(0:2) :: run_types
REAL (DP), DIMENSION(0:2) :: steps
INTEGER :: i,j
REAL (DP) :: step
CHARACTER (LEN=10) :: run_type
run_types(0) = "benchmark"
run_types(1) = "regular"
run_types(2) = "test"
steps(0) = 1
steps(1) = 0.1
steps(2) = 0.01
open(2, file='results.txt')
do i = 0,2
    run_type = run_types(i)
    if (run_type /= "test") then
      do j = 0,2  
        step = steps(j)
        call run_calculation_and_measure_time(run_type, step, 2)
      end do
    else
      step = 0.1
      call run_calculation_and_measure_time(run_type, step, 2)
    end if
end do
close(2)
end subroutine main2
  
end module UberDuperSimulation

program Uber_Duper_Simulation
  USE UberDuperSimulation
  implicit none
  call main2()
end program Uber_Duper_Simulation
