package;

import haxe.Timer;
import Math.sqrt;
import Math.pow;
import Math.PI;

#if !js
import openfl.display.Sprite;
import openfl.Lib;
import openfl.text.TextField;
#end

#if js
import js.Browser;
import js.html.DivElement;
import js.html.ParagraphElement;
#end

#if desktop
import sys.io.File;
import sys.io.FileOutput;
#end

import de.polygonal.Printf.format;

/**
 * ...
 * @author 
 */

class Main #if flash extends Sprite #end
{
	var R0 = 6378137;
	var mu = 3.9860047e14;
	
	function h_x_y(x, y):Float
	{
		return sqrt(pow(x, 2) + pow(y, 2)) - R0;
	}
	
	function calculate_T_period(R)
	{
		return 2 * PI * sqrt(pow(R, 3) / mu);
	}
	
	function right_part(t, StateVector)
	{
		var R = sqrt(pow(StateVector[0], 2) + pow(StateVector[1], 2));
		var R3 = pow(R, 3);
		
		var result = [0.0, 0.0, 0.0, 0.0];
		result[0] = StateVector[2];
		result[1] = StateVector[3];
		result[2] = -mu / R3 * StateVector[0];
		result[3] = -mu / R3 * StateVector[1];
		return result;
	}
	
	function runge_kutta_t_state_vector(t, params:Array<Float>, t_step:Float, f:Float->Array<Float>->Array<Float>)
	{
		var k1, k2, k3, k4 = [];
		
		var h = t_step;
		
		k1 = f(t, params);
		
		var new_params = [0.0, 0, 0, 0];
		
		for (i in 0...params.length) 
		{
			var p = params[i];
			new_params[i] = p + h / 2 * k1[i];
		}
		
		k2 = f(t + h / 2, new_params);
		
		for (i in 0...params.length) 
		{
			var p = params[i];
			new_params[i] = p + h / 2 * k2[i];
		}
		
		k3 = f(t + h / 2, new_params);
		
		for (i in 0...params.length) 
		{
			var p = params[i];
			new_params[i] = p + h * k3[i];
		}
		
		k4 = f(t + h, new_params);
		
		for (i in 0...params.length) 
		{
			var p = params[i];
			params[i] = p + h / 6 * (k1[i] + 2 * k2[i] + 2 * k3[i] + k4[i]);
		}
		
		return params;
	}
	
	#if desktop
	function regular_calculation(Vx, Vy, t:Float, t_end, t_step:Float, x, y)
	{
		var file1 = File.write("output.tr", false);
		file1.writeString("t, x, y, Vx, Vy\n");
		
		var params = [x, y, Vx, Vy];
		
		while (t <= t_end) 
		{
			file1.writeString(format("%.3f %d %d %.3f %.3f\n", [t].concat(params)));
			
			t += t_step;
			
			params = runge_kutta_t_state_vector(t, params, t_step, right_part);
		}
		
		file1.close();
	}
	
	#elseif js
	
	function regular_calculation(Vx, Vy, t:Float, t_end, t_step:Float, x, y)
	{
		//var div:DivElement = cast(Browser.document.getElementById("openfl-content"), DivElement);
		//div.style.display = "none";
		//
		////var p:ParagraphElement = Browser.document.createParagraphElement();
		//var text = "t, x, y, Vx, Vy\n";
		////Browser.document.body.appendChild(p);
		//
		//var params = [x, y, Vx, Vy];
		//
		//while (t <= t_end) 
		//{			
			//text += format("%.3f %d %d %.3f %.3f\n", [t].concat(params));
			//
			//t += t_step;
			//
			//params = runge_kutta_t_state_vector(t, params, t_step, right_part);
		//}
		//
		////p.textContent = text;
		//trace(text);
		
		//Browser.document.body.appendChild(p);
	}
	#end
	
	function benchmark_test(Vx, Vy, t:Float, t_end, t_step:Float, x, y)
	{		
		//var s = Date.now();
		
		var params = [x, y, Vx, Vy];
		
		while (t <= t_end) 
		{					
			t += t_step;
			params = runge_kutta_t_state_vector(t, params, t_step, right_part);
			
			//if (t > 9999)
			//{
				//trace(params);
			//}
			
		}
		
		//var e = Date.now();
		
		//trace((e.getTime() - s.getTime()) / 1000);
		
		//#if !desktop
		//trace(params);
		//#end
	}
	
	function test(Vx, Vy, t:Float, t_end, t_step:Float, x, y, R)
	{		
		var T_period = calculate_T_period(R);
		
		var params = [x, y, Vx, Vy];
		
		var parameters = params.copy();
		
		var texts = ["x", "y", "Vx", "Vy"];
		
		while (t <= t_end) 
		{
			t += t_step;
			params = runge_kutta_t_state_vector(t, params, t_step, right_part);
			
			if (t >= T_period && t <= T_period + t_step) 
			{
				trace("Виток № ", Math.floor(t / T_period));
				trace("T = ", t);
				
				for (i in 0...4) 
				{
					var x1 = parameters[i];
					var x2 = params[i];
					
					if (x1 - x2 > 1e-5) 
					{
						trace(texts[i], ": ", x1, x2, x1 - x2);
					}
				}
			}
			
			var h = h_x_y(params[0], params[1]);
			
			if (h - 1000000 > 1e-5) 
			{
				trace("Высота изменилась ", h);
			}
		}
	}
	
	function main2(type, step)
	{
		var t_end = 10000.0;
		var t_step:Float = step;
		var h0 = 1000000.0;
		var R = R0 + h0;
		var t = 0.0;
		var x = 0.0;
		var y = R;
		var Vx = sqrt(mu / R);
		var Vy = 0.0;
		
		switch (type) 
		{
			case "regular":
				#if !flash
				regular_calculation(Vx, Vy, t, t_end, t_step, x, y);
				#end
			case "benchmark":
				benchmark_test(Vx, Vy, t, t_end, t_step, x, y);
			case "test":
				test(Vx, Vy, t, t_end, t_step, x, y, R);
			default:
				
		}
	}
	
	function run_calculation_and_measure_time(run_type, step, file1)
	{
		var startDate = Timer.stamp();
		main2(run_type, step);
		var endDate = Timer.stamp();
		
		var delta:Float = endDate - startDate;
		
		var str = run_type + " t_step = " + Std.string(step) + "\n" + Std.string(delta) + "\n";
		
		
		#if desktop
		file1.writeString(str);
		#end
		
		//var tf = new TextField();
		//tf.text = str;
		//tf.width = 480;
		//tf.textColor = 0xFFFFFFFF;
		//tf.x = Std.random(480);
		//tf.y = Std.random(480);
		//Lib.current.addChild(tf);
		
		trace(str);
	}
	
	static function main() 
	{
		var main = new Main();
		
		var file1 = null;
		
		#if desktop
		file1 = File.write("results.txt", false);
		#end
		
		for (run_type in ["benchmark", "regular", "test"]) 
		{
			if (run_type != "test") 
			{
				for (step in [1, 0.1, 0.01]) 
				{
					main.run_calculation_and_measure_time(run_type, step, file1);
				}
			}
			else
			{
				var step = 0.1;
				main.run_calculation_and_measure_time(run_type, step, file1);
			}
		}
		
		#if desktop
		file1.close();
		Sys.exit(0);
		#end
	}
	
}