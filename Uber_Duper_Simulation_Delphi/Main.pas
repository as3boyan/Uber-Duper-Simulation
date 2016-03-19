unit Main;

interface

procedure run_calculations();

type
   Vect4 = array[0..3] of Extended;
   RightPartProcedure = procedure (const t:Extended; const StateVector:vect4; var result:vect4);

implementation
uses
   Math, SysUtils, DateUtils;
const
   R0:Extended = 6378137;
   mu:Extended = 3.9860047e14;

function h_x_y(const x, y:Extended):Extended;
begin
   h_x_y := Sqrt(power(x, 2) + power(y, 2)) - R0;
end;

function calculate_T(const R:Extended):Extended;
begin
   calculate_T := 2 * pi * sqrt(power(R, 3) / mu);
end;

procedure right_part(const t:Extended; const StateVector:Vect4; var result:Vect4);
var
   R, R3:Extended;
begin
   R := sqrt(power(StateVector[0], 2) + power(StateVector[1], 2));
   R3 := power(R, 3);

   result[0] := StateVector[2];
   result[1] := StateVector[3];
   result[2] := -mu / R3 * StateVector[0];
   result[3] := -mu / R3 * StateVector[1];
end;

procedure runge_kutta_t_state_vector(var t:Extended; var params:Vect4; const t_step:Extended; const right_part_proc:RightPartProcedure);
var
   k1, k2, k3, k4:Vect4;
   h: Extended;
   new_params:Vect4;
   i: Integer;
   p: Extended;
begin
   h := t_step;

   right_part_proc(t, params, k1);

   for i := 0 to 3 do
   begin
      p := params[i];
      new_params[i] := p + h / 2 * k1[i];
   end;

   right_part_proc(t + h / 2, new_params, k2);

   for i := 0 to 3 do
   begin
      p := params[i];
      new_params[i] := p + h / 2 * k2[i];
   end;

   right_part_proc(t + h / 2, new_params, k3);

   for i := 0 to 3 do
   begin
      p := params[i];
      new_params[i] := p + h * k3[i];
   end;

   right_part_proc(t + h, new_params, k4);

   for i := 0 to 3 do
   begin
      p := params[i];
      params[i] := p + h / 6 * (k1[i] + 2 * k2[i] + 2 * k3[i] + k4[i]);
   end;
end;

procedure regular_calculation(var t: Extended; const t_end: Extended; const t_step: Extended; var params: Vect4);
var
   file1:TextFile;
begin
   AssignFile(file1, 'output.tr');
   ReWrite(file1);

   Writeln(file1, 't, x, y, Vx, Vy');

   while (t <= t_end) do
   begin
      Writeln(file1, format('%.3f %.0f %.0f %.3f %.3f', [t, params[0], params[1], params[2], params[3]]));

      t := t + t_step;

      runge_kutta_t_state_vector(t, params, t_step, right_part);
   end;

   CloseFile(file1);
end;

procedure benchmark_test(var t: Extended; const t_end: Extended; const t_step: Extended; var params: Vect4);
begin
   while (t <= t_end) do
   begin
        t := t + t_step;
        runge_kutta_t_state_vector(t, params, t_step, right_part);
   end;
end;

procedure test(var t: Extended; const t_end: Extended; const t_step: Extended; var params: Vect4; const R: Extended);
var
   T_period: Extended;
//   k: Extended;
   parameters: Vect4;
   texts: array[0..3] of string;
   i: Integer;
   x1, x2: Extended;
begin
   for i := 0 to 3 do
   begin
        parameters[i] := params[i];
   end;

   T_period := calculate_T(R);

   while (t <= t_end) do
   begin
        t := t + t_step;
        runge_kutta_t_state_vector(t, params, t_step, right_part);

        //k := SimpleRoundTo(T_period, -1);

        //Int((SimpleRoundTo(t, -1) * 10)
        //(k * 10)

        if ((t > T_period) and (t <= T_period + t_step)) then
        begin
             Writeln('Виток № ', SimpleRoundTo(t / T_period));
             Writeln('T = ', t);

             for i := 0 to 3 do
             begin
                x1 := SimpleRoundTo(parameters[i]);
                x2 := SimpleRoundTo(params[i]);

                if not (x1 = x2) then
                begin
                        Writeln('Разница в значениях:', texts[i], x1, x2);
                end;
             end;
        end;

        if (h_x_y(params[0], params[1]) - 1000000 > 1e-5) then
        begin
           Writeln('Высота изменилась');
        end;
   end;
end;
procedure main2(const type2: string; step: Extended);
var
   t_end: Extended;
   t_step: Extended;
   h0: Extended;
   R: Extended;
   t: Extended;
   params: Vect4;
begin
   t := 0;
   t_end := 10000;
   t_step := step;
   h0 := 1000000;
   R := R0 + h0;

   params[0] := 0;
   params[1] := R;
   params[2] := sqrt(mu / R);
   params[3] := 0;

   if (type2 = 'regular') then
   begin
      regular_calculation(t, t_end, t_step, params);
   end
   else if (type2 = 'benchmark') then
   begin
      benchmark_test(t, t_end, t_step, params);
   end
   else if (type2 = 'test') then
   begin
      test(t, t_end, t_step, params, R);
   end
end;

procedure run_calculation_and_measure_time(const run_type: string; step: Extended; var file1:TextFile);
var
   startTime, endTime:TDateTime;
   seconds: Extended;
   m: Integer;
   str: string;
begin
   startTime := Now;
   main2(run_type, step);
   endTime := Now;
   m := MilliSecondsBetween(endTime, startTime);
   seconds := m / 1000.0;

   str := Format('%s t_step = %f ' + #13 + '%.5f', [run_type, step, seconds]);
   Writeln(file1, str); // Замер затраченного времени (вывод в файл)
   Writeln(str); // Замер затраченного времени (вывод на экран)
end;

procedure run_calculations();
var
   file1: TextFile;
   step: Extended;
   steps: array[0..2] of Extended;
   run_types: array[0..2] of string;
   run_type: string;
   i, j: Integer;
begin
   steps[0] := 1.0;
   steps[1] := 0.1;
   steps[2] := 0.01;

   run_types[0] := 'benchmark';
   run_types[1] := 'regular';
   run_types[2] := 'test';

   AssignFile(file1, 'results.txt');
   ReWrite(file1);

   for i := 0 to 2 do
   begin
      run_type := run_types[i];
      if not (run_type = 'test') then
      begin
        for j := 0 to 2 do
        begin
          step := steps[j];
          run_calculation_and_measure_time(run_type, step, file1);
        end
      end
      else
      begin
        step := 0.1;
        run_calculation_and_measure_time(run_type, step, file1);
      end
   end;

   CloseFile(file1);

end;

end.
