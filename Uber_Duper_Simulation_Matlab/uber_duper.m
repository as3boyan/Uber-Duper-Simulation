function z = uber_duper()
%cd 'D:\Denis\Uber_Duper_Simulation\Uber_Duper_Simulation_Matlab'

steps = [1, 0.1, 0.01];

results = zeros(6, 1);
for x = 1:3
    results(x) = run_calculation_and_measure_time(0, 10000, steps(x), false);
    results(x + 3) = run_calculation_and_measure_time(0, 10000, steps(x), true);
end

save results.txt results -ascii

z = results;
end

function main2 = main(p_t_start, p_t_end, p_t_step, p_printOutput)
t_end = p_t_end;  % Конец времени движения
t_step = p_t_step;  % Шаг интегрирования
h0 = 1000000;
R0 = 6378137.0;
mu = 3.9860047e14;
R = R0 + h0;

t = p_t_start;
x = 0;
y = R;
Vx = sqrt(mu / R);
Vy = 0;

times = t:t_step:t_end;
%n = length(times);

% Интегрированния методом Рунге-Кутта (4-го порядка)
options = odeset('RelTol',1e-10,'AbsTol',[1e-10 1e-10 1e-10 1e-10]);
T = zeros(length(times), 1);
[T,Y] = ode45(@integrate, times, [x y Vx Vy], options);

if p_printOutput
c = [T, Y];
save output.tr c -ascii
end

%plot (Y(1:n,1),Y(1:n,2));
%figure(gcf)
main2 = true;
end

function z2 = run_calculation_and_measure_time(p_t_start, p_t_end, p_t_step, p_printOutput)
tic;
main(p_t_start, p_t_end, p_t_step, p_printOutput);
z2 = toc;
end

% Правые части
function dy = integrate(~,y)
mu = 3.9860047e14;

R = sqrt(y(1) * y(1) + y(2) * y(2));
R3 = R^3;

dy = zeros(4,1);    % a column vector

dy(1) = y(3);
dy(2) = y(4);
dy(3) = -mu / R3 * y(1);
dy(4) = -mu / R3 * y(2);
end

% Расчет текущей высоты
function a = h_x_y(x,y)
R0 = 6378137.0;
a = sqrt(x^2 + y^2) - R0;
end

% Расчет периода обращения
function a = T(R)
mu = 3.9860047e14;
a = 2 * pi * sqrt(R^3 / mu);
end
