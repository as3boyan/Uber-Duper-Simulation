(function () { "use strict";
var HxOverrides = function() { };
HxOverrides.__name__ = true;
HxOverrides.cca = function(s,index) {
	var x = s.charCodeAt(index);
	if(x != x) return undefined;
	return x;
};
HxOverrides.substr = function(s,pos,len) {
	if(pos != null && pos != 0 && len != null && len < 0) return "";
	if(len == null) len = s.length;
	if(pos < 0) {
		pos = s.length + pos;
		if(pos < 0) pos = 0;
	} else if(len < 0) len = s.length + len - pos;
	return s.substr(pos,len);
};
var Main = function() {
	this.mu = 3.9860047e14;
	this.R0 = 6378137;
};
Main.__name__ = true;
Main.main = function() {
	var main = new Main();
	var file1 = null;
	var _g = 0;
	var _g1 = ["benchmark","regular","test"];
	while(_g < _g1.length) {
		var run_type = _g1[_g];
		++_g;
		if(run_type != "test") {
			var _g2 = 0;
			var _g3 = [1,0.1,0.01];
			while(_g2 < _g3.length) {
				var step = _g3[_g2];
				++_g2;
				main.run_calculation_and_measure_time(run_type,step,file1);
			}
		} else {
			var step1 = 0.1;
			main.run_calculation_and_measure_time(run_type,step1,file1);
		}
	}
};
Main.prototype = {
	h_x_y: function(x,y) {
		return Math.sqrt(Math.pow(x,2) + Math.pow(y,2)) - this.R0;
	}
	,calculate_T_period: function(R) {
		return 2 * Math.PI * Math.sqrt(Math.pow(R,3) / this.mu);
	}
	,right_part: function(t,StateVector) {
		var R = Math.sqrt(Math.pow(StateVector[0],2) + Math.pow(StateVector[1],2));
		var R3 = Math.pow(R,3);
		var result = [0.0,0.0,0.0,0.0];
		result[0] = StateVector[2];
		result[1] = StateVector[3];
		result[2] = -this.mu / R3 * StateVector[0];
		result[3] = -this.mu / R3 * StateVector[1];
		return result;
	}
	,runge_kutta_t_state_vector: function(t,params,t_step,f) {
		var k1;
		var k2;
		var k3;
		var k4 = [];
		var h = t_step;
		k1 = f(t,params);
		var new_params = [0.0,0,0,0];
		var _g1 = 0;
		var _g = params.length;
		while(_g1 < _g) {
			var i = _g1++;
			var p = params[i];
			new_params[i] = p + h / 2 * k1[i];
		}
		k2 = f(t + h / 2,new_params);
		var _g11 = 0;
		var _g2 = params.length;
		while(_g11 < _g2) {
			var i1 = _g11++;
			var p1 = params[i1];
			new_params[i1] = p1 + h / 2 * k2[i1];
		}
		k3 = f(t + h / 2,new_params);
		var _g12 = 0;
		var _g3 = params.length;
		while(_g12 < _g3) {
			var i2 = _g12++;
			var p2 = params[i2];
			new_params[i2] = p2 + h * k3[i2];
		}
		k4 = f(t + h,new_params);
		var _g13 = 0;
		var _g4 = params.length;
		while(_g13 < _g4) {
			var i3 = _g13++;
			var p3 = params[i3];
			params[i3] = p3 + h / 6 * (k1[i3] + 2 * k2[i3] + 2 * k3[i3] + k4[i3]);
		}
		return params;
	}
	,regular_calculation: function(Vx,Vy,t,t_end,t_step,x,y) {
	}
	,benchmark_test: function(Vx,Vy,t,t_end,t_step,x,y) {
		var params = [x,y,Vx,Vy];
		while(t <= t_end) {
			t += t_step;
			params = this.runge_kutta_t_state_vector(t,params,t_step,$bind(this,this.right_part));
		}
	}
	,test: function(Vx,Vy,t,t_end,t_step,x,y,R) {
		var T_period = this.calculate_T_period(R);
		var params = [x,y,Vx,Vy];
		var parameters = params.slice();
		var texts = ["x","y","Vx","Vy"];
		while(t <= t_end) {
			t += t_step;
			params = this.runge_kutta_t_state_vector(t,params,t_step,$bind(this,this.right_part));
			if(t >= T_period && t <= T_period + t_step) {
				haxe.Log.trace("Виток № ",{ fileName : "Main.hx", lineNumber : 196, className : "Main", methodName : "test", customParams : [Math.floor(t / T_period)]});
				haxe.Log.trace("T = ",{ fileName : "Main.hx", lineNumber : 197, className : "Main", methodName : "test", customParams : [t]});
				var _g = 0;
				while(_g < 4) {
					var i = _g++;
					var x1 = parameters[i];
					var x2 = params[i];
					if(x1 - x2 > 1e-5) haxe.Log.trace(texts[i],{ fileName : "Main.hx", lineNumber : 206, className : "Main", methodName : "test", customParams : [": ",x1,x2,x1 - x2]});
				}
			}
			var h = this.h_x_y(params[0],params[1]);
			if(h - 1000000 > 1e-5) haxe.Log.trace("Высота изменилась ",{ fileName : "Main.hx", lineNumber : 215, className : "Main", methodName : "test", customParams : [h]});
		}
	}
	,main2: function(type,step) {
		var t_end = 10000.0;
		var t_step = step;
		var h0 = 1000000.0;
		var R = this.R0 + h0;
		var t = 0.0;
		var x = 0.0;
		var y = R;
		var Vx = Math.sqrt(this.mu / R);
		var Vy = 0.0;
		switch(type) {
		case "regular":
			this.regular_calculation(Vx,Vy,t,t_end,t_step,x,y);
			break;
		case "benchmark":
			this.benchmark_test(Vx,Vy,t,t_end,t_step,x,y);
			break;
		case "test":
			this.test(Vx,Vy,t,t_end,t_step,x,y,R);
			break;
		default:
		}
	}
	,run_calculation_and_measure_time: function(run_type,step,file1) {
		var startDate = haxe.Timer.stamp();
		this.main2(run_type,step);
		var endDate = haxe.Timer.stamp();
		var delta = endDate - startDate;
		var str;
		str = run_type + " t_step = " + (step == null?"null":"" + step) + "\n" + (delta == null?"null":"" + delta) + "\n";
		haxe.Log.trace(str,{ fileName : "Main.hx", lineNumber : 270, className : "Main", methodName : "run_calculation_and_measure_time"});
	}
	,__class__: Main
};
var IMap = function() { };
IMap.__name__ = true;
Math.__name__ = true;
var Reflect = function() { };
Reflect.__name__ = true;
Reflect.field = function(o,field) {
	try {
		return o[field];
	} catch( e ) {
		return null;
	}
};
var Std = function() { };
Std.__name__ = true;
Std.string = function(s) {
	return js.Boot.__string_rec(s,"");
};
Std["int"] = function(x) {
	return x | 0;
};
var StringBuf = function() {
	this.b = "";
};
StringBuf.__name__ = true;
StringBuf.prototype = {
	__class__: StringBuf
};
var de = {};
de.polygonal = {};
de.polygonal.Printf = function() { };
de.polygonal.Printf.__name__ = true;
de.polygonal.Printf.init = function() {
	de.polygonal.Printf.dataTypeMap = de.polygonal.Printf.makeDataTypeMap();
	de.polygonal.Printf.formatIntFuncHash = new haxe.ds.IntMap();
	de.polygonal.Printf.formatIntFuncHash.set(1,de.polygonal.Printf.formatSignedDecimal);
	de.polygonal.Printf.formatIntFuncHash.set(2,de.polygonal.Printf.formatUnsignedDecimal);
	de.polygonal.Printf.formatIntFuncHash.set(0,de.polygonal.Printf.formatCharacter);
	de.polygonal.Printf.formatIntFuncHash.set(4,de.polygonal.Printf.formatHexadecimal);
	de.polygonal.Printf.formatIntFuncHash.set(3,de.polygonal.Printf.formatOctal);
	de.polygonal.Printf.formatIntFuncHash.set(5,de.polygonal.Printf.formatBinary);
	de.polygonal.Printf.formatFloatFuncHash = new haxe.ds.IntMap();
	de.polygonal.Printf.formatFloatFuncHash.set(0,de.polygonal.Printf.formatNormalFloat);
	de.polygonal.Printf.formatFloatFuncHash.set(1,de.polygonal.Printf.formatScientific);
	de.polygonal.Printf.formatFloatFuncHash.set(2,de.polygonal.Printf.formatNaturalFloat);
	de.polygonal.Printf.formatStringFuncHash = new haxe.ds.IntMap();
	de.polygonal.Printf.formatStringFuncHash.set(2,de.polygonal.Printf.formatString);
};
de.polygonal.Printf.makeDataTypeMap = function() {
	var hash = new haxe.ds.IntMap();
	hash.set(105,de.polygonal._Printf.FormatDataType.FmtInteger(de.polygonal._Printf.IntegerType.ISignedDecimal));
	hash.set(100,de.polygonal._Printf.FormatDataType.FmtInteger(de.polygonal._Printf.IntegerType.ISignedDecimal));
	hash.set(117,de.polygonal._Printf.FormatDataType.FmtInteger(de.polygonal._Printf.IntegerType.IUnsignedDecimal));
	hash.set(99,de.polygonal._Printf.FormatDataType.FmtInteger(de.polygonal._Printf.IntegerType.ICharacter));
	hash.set(120,de.polygonal._Printf.FormatDataType.FmtInteger(de.polygonal._Printf.IntegerType.IHex));
	hash.set(88,de.polygonal._Printf.FormatDataType.FmtInteger(de.polygonal._Printf.IntegerType.IHex));
	hash.set(111,de.polygonal._Printf.FormatDataType.FmtInteger(de.polygonal._Printf.IntegerType.IOctal));
	hash.set(98,de.polygonal._Printf.FormatDataType.FmtInteger(de.polygonal._Printf.IntegerType.IBin));
	hash.set(102,de.polygonal._Printf.FormatDataType.FmtFloat(de.polygonal._Printf.FloatType.FNormal));
	hash.set(101,de.polygonal._Printf.FormatDataType.FmtFloat(de.polygonal._Printf.FloatType.FScientific));
	hash.set(69,de.polygonal._Printf.FormatDataType.FmtFloat(de.polygonal._Printf.FloatType.FScientific));
	hash.set(103,de.polygonal._Printf.FormatDataType.FmtFloat(de.polygonal._Printf.FloatType.FNatural));
	hash.set(71,de.polygonal._Printf.FormatDataType.FmtFloat(de.polygonal._Printf.FloatType.FNatural));
	hash.set(115,de.polygonal._Printf.FormatDataType.FmtString);
	hash.set(112,de.polygonal._Printf.FormatDataType.FmtPointer);
	hash.set(110,de.polygonal._Printf.FormatDataType.FmtNothing);
	return hash;
};
de.polygonal.Printf.format = function(fmt,args) {
	if(!de.polygonal.Printf._initialized) {
		de.polygonal.Printf._initialized = true;
		de.polygonal.Printf.init();
	}
	var _g1 = 0;
	var _g = args.length;
	while(_g1 < _g) {
		var i = _g1++;
		if(args[i] == null) args[i] = "null";
	}
	var output = "";
	var argIndex = 0;
	var tokens = de.polygonal.Printf.tokenize(fmt);
	var _g2 = 0;
	while(_g2 < tokens.length) {
		var token = tokens[_g2];
		++_g2;
		switch(token[1]) {
		case 3:
			throw "invalid format specifier";
			break;
		case 0:
			var str = token[2];
			output += str;
			break;
		case 2:
			var name = token[2];
			if(!Object.prototype.hasOwnProperty.call(args[0],name)) throw "no field named " + name;
			output += Std.string(Reflect.field(args[0],name));
			break;
		case 1:
			var tagArgs = token[3];
			var type = token[2];
			if(tagArgs.width != null) tagArgs.width = tagArgs.width; else tagArgs.width = js.Boot.__cast(args[argIndex++] , Int);
			if(tagArgs.precision != null) tagArgs.precision = tagArgs.precision; else tagArgs.precision = js.Boot.__cast(args[argIndex++] , Int);
			var value = args[argIndex++];
			var formatFunction;
			switch(type[1]) {
			case 1:
				var floatType = type[2];
				formatFunction = de.polygonal.Printf.formatFloatFuncHash.get(floatType[1]);
				break;
			case 0:
				var integerType = type[2];
				formatFunction = de.polygonal.Printf.formatIntFuncHash.get(integerType[1]);
				break;
			case 2:
				formatFunction = de.polygonal.Printf.formatStringFuncHash.get(2);
				break;
			case 3:
				throw "specifier 'p' is not supported";
				break;
			case 4:
				throw "specifier 'n' is not supported";
				break;
			}
			output += formatFunction(value,tagArgs);
			break;
		}
	}
	return output;
};
de.polygonal.Printf.tokenize = function(fmt) {
	var length = fmt.length;
	var lastStr = new StringBuf();
	var i = 0;
	var c = 0;
	var tokens = new Array();
	while(i < length) {
		var c1 = de.polygonal.Printf.codeAt(fmt,i++);
		if(c1 == 37) {
			c1 = de.polygonal.Printf.codeAt(fmt,i++);
			if(c1 == 37) lastStr.b += String.fromCharCode(c1); else {
				if(lastStr.b.length > 0) {
					tokens.push(de.polygonal._Printf.FormatToken.BareString(lastStr.b));
					lastStr = new StringBuf();
				}
				var token;
				if(c1 == 40) {
					var endPos = fmt.indexOf(")",i);
					if(endPos == -1) token = de.polygonal._Printf.FormatToken.Unknown("named param",i); else {
						var paramName = HxOverrides.substr(fmt,i,endPos - i);
						i = endPos + 1;
						token = de.polygonal._Printf.FormatToken.Property(paramName);
					}
				} else {
					var params = { flags : 0, pos : -1, width : -1, precision : -1};
					while(c1 == 45 || c1 == 43 || c1 == 35 || c1 == 48 || c1 == 32) {
						if(c1 == 45) params.flags |= 1 << de.polygonal._Printf.FormatFlags.Minus[1]; else if(c1 == 43) params.flags |= 1 << de.polygonal._Printf.FormatFlags.Plus[1]; else if(c1 == 35) params.flags |= 1 << de.polygonal._Printf.FormatFlags.Sharp[1]; else if(c1 == 48) params.flags |= 1 << de.polygonal._Printf.FormatFlags.Zero[1]; else if(c1 == 32) params.flags |= 1 << de.polygonal._Printf.FormatFlags.Space[1];
						c1 = de.polygonal.Printf.codeAt(fmt,i++);
					}
					if((params.flags & 1 << de.polygonal._Printf.FormatFlags.Minus[1]) != 0 && (params.flags & 1 << de.polygonal._Printf.FormatFlags.Zero[1]) != 0) params.flags &= 268435455 - (1 << de.polygonal._Printf.FormatFlags.Zero[1]);
					if((params.flags & 1 << de.polygonal._Printf.FormatFlags.Space[1]) != 0 && (params.flags & 1 << de.polygonal._Printf.FormatFlags.Plus[1]) != 0) params.flags &= 268435455 - (1 << de.polygonal._Printf.FormatFlags.Space[1]);
					if(c1 == 42) {
						params.width = null;
						c1 = de.polygonal.Printf.codeAt(fmt,i++);
					} else if(c1 >= 48 && c1 <= 57) {
						params.width = 0;
						while(c1 >= 48 && c1 <= 57) {
							params.width = c1 - 48 + params.width * 10;
							c1 = de.polygonal.Printf.codeAt(fmt,i++);
						}
						if(c1 == 36) {
							params.pos = params.width - 1;
							params.width = -1;
							c1 = de.polygonal.Printf.codeAt(fmt,i++);
							if(c1 == 42) {
								params.width = null;
								c1 = de.polygonal.Printf.codeAt(fmt,i++);
							} else if(c1 >= 48 && c1 <= 57) {
								params.width = 0;
								while(c1 >= 48 && c1 <= 57) {
									params.width = c1 - 48 + params.width * 10;
									c1 = de.polygonal.Printf.codeAt(fmt,i++);
								}
							}
						}
					}
					if(c1 == 46) {
						c1 = de.polygonal.Printf.codeAt(fmt,i++);
						if(c1 == 42) {
							params.precision = null;
							c1 = de.polygonal.Printf.codeAt(fmt,i++);
						} else if(c1 >= 48 && c1 <= 57) {
							params.precision = 0;
							while(c1 >= 48 && c1 <= 57) {
								params.precision = c1 - 48 + params.precision * 10;
								c1 = de.polygonal.Printf.codeAt(fmt,i++);
							}
						} else params.precision = 0;
					}
					while(c1 == 104 || c1 == 108 || c1 == 76) {
						switch(c1) {
						case 104:
							params.flags |= 1 << de.polygonal._Printf.FormatFlags.LengthH[1];
							break;
						case 108:
							params.flags |= 1 << de.polygonal._Printf.FormatFlags.Lengthl[1];
							break;
						case 76:
							params.flags |= 1 << de.polygonal._Printf.FormatFlags.LengthL[1];
							break;
						}
						c1 = de.polygonal.Printf.codeAt(fmt,i++);
					}
					if(c1 == 69 || c1 == 71 || c1 == 88) params.flags |= 1 << de.polygonal._Printf.FormatFlags.UpperCase[1];
					var type = de.polygonal.Printf.dataTypeMap.get(c1);
					if(type == null) token = de.polygonal._Printf.FormatToken.Unknown(String.fromCharCode(c1),i); else token = de.polygonal._Printf.FormatToken.Tag(type,params);
				}
				tokens.push(token);
			}
		} else lastStr.b += String.fromCharCode(c1);
	}
	if(lastStr.b.length > 0) tokens.push(de.polygonal._Printf.FormatToken.BareString(lastStr.b));
	return tokens;
};
de.polygonal.Printf.formatBinary = function(value,args) {
	var output = "";
	var flags = args.flags;
	var precision = args.precision;
	var width = args.width;
	if(precision == -1) precision = 1;
	if(value != 0) {
		if((flags & 1 << de.polygonal._Printf.FormatFlags.LengthH[1]) != 0) value &= 65535;
		var i = value;
		do {
			output = ((i & 1) > 0?"1":"0") + output;
			i >>>= 1;
		} while(i > 0);
		if(precision > 1) {
			if(precision > output.length) output = de.polygonal.Printf.lpad(output,"0",precision);
			if((flags & 1 << de.polygonal._Printf.FormatFlags.Sharp[1]) != 0) output = "b" + output;
		}
	}
	if((flags & 1 << de.polygonal._Printf.FormatFlags.Minus[1]) != 0) {
		if(width > output.length) return de.polygonal.Printf.rpad(output," ",width); else return output;
	} else if(width > output.length) return de.polygonal.Printf.lpad(output,(flags & 1 << de.polygonal._Printf.FormatFlags.Zero[1]) != 0?"0":" ",width); else return output;
};
de.polygonal.Printf.formatOctal = function(value,args) {
	var output = "";
	var flags = args.flags;
	var precision = args.precision;
	var width = args.width;
	if(precision == -1) precision = 1;
	if(value != 0) {
		if((flags & 1 << de.polygonal._Printf.FormatFlags.LengthH[1]) != 0) value &= 65535;
		output = de.polygonal.Printf.toOct(value);
		if((flags & 1 << de.polygonal._Printf.FormatFlags.Sharp[1]) != 0) output = "0" + output;
		if(precision > 1 && output.length < precision) output = de.polygonal.Printf.lpad(output,"0",precision);
	}
	if((flags & 1 << de.polygonal._Printf.FormatFlags.Minus[1]) != 0) {
		if(width > output.length) return de.polygonal.Printf.rpad(output," ",width); else return output;
	} else if(width > output.length) return de.polygonal.Printf.lpad(output,(flags & 1 << de.polygonal._Printf.FormatFlags.Zero[1]) != 0?"0":" ",width); else return output;
};
de.polygonal.Printf.formatHexadecimal = function(value,args) {
	var output = "";
	var flags = args.flags;
	var precision = args.precision;
	var width = args.width;
	if(precision == -1) precision = 1;
	if(value != 0) {
		if((flags & 1 << de.polygonal._Printf.FormatFlags.LengthH[1]) != 0) value &= 65535;
		output = de.polygonal.Printf.toHex(value);
		if(precision > 1 && output.length < precision) output = de.polygonal.Printf.lpad(output,"0",precision);
		if((flags & 1 << de.polygonal._Printf.FormatFlags.Sharp[1]) != 0 && value != 0) output = "0x" + output;
		if((flags & 1 << de.polygonal._Printf.FormatFlags.UpperCase[1]) != 0) output = output.toUpperCase(); else output = output.toLowerCase();
	}
	if((flags & 1 << de.polygonal._Printf.FormatFlags.Minus[1]) != 0) {
		if(width > output.length) return de.polygonal.Printf.rpad(output," ",width); else return output;
	} else if(width > output.length) return de.polygonal.Printf.lpad(output,(flags & 1 << de.polygonal._Printf.FormatFlags.Zero[1]) != 0?"0":" ",width); else return output;
};
de.polygonal.Printf.formatUnsignedDecimal = function(value,args) {
	var output;
	var precision = args.precision;
	if(value >= 0) output = de.polygonal.Printf.formatSignedDecimal(value,args); else {
		var x = new haxe.Int64(0,value);
		output = x.toString();
		if(precision > 1 && output.length < precision) output = de.polygonal.Printf.lpad(output,"0",precision);
		output = de.polygonal.Printf.padNumber(output,value,args.flags,args.width);
	}
	return output;
};
de.polygonal.Printf.formatNaturalFloat = function(value,args) {
	args.precision = 0;
	var formatedFloat = de.polygonal.Printf.formatNormalFloat(value,args);
	var formatedScientific = de.polygonal.Printf.formatScientific(value,args);
	if((args.flags & 1 << de.polygonal._Printf.FormatFlags.Sharp[1]) != 0) {
		if(formatedFloat.indexOf(".") != -1) {
			var pos = formatedFloat.length - 1;
			while(formatedFloat.charCodeAt(pos) == 48) pos--;
			formatedFloat = HxOverrides.substr(formatedFloat,0,pos);
		}
	}
	if(formatedFloat.length <= formatedScientific.length) return formatedFloat; else return formatedScientific;
};
de.polygonal.Printf.formatScientific = function(value,args) {
	var output = "";
	var flags = args.flags;
	var precision = args.precision;
	if(precision == -1) precision = 6;
	var sign;
	var exponent;
	if(value == 0) {
		sign = 0;
		exponent = 0;
		output += "0";
		if(precision > 0) {
			output += ".";
			var _g = 0;
			while(_g < precision) {
				var i = _g++;
				output += "0";
			}
		}
	} else {
		if(value > 0.) sign = 1; else if(value < 0.) sign = -1; else sign = 0;
		value = Math.abs(value);
		exponent = Math.floor(Math.log(value) / 2.302585092994046);
		value = value / Math.pow(10,exponent);
		var p = Math.pow(0.1,precision);
		value = Math.round(value / p) * p;
	}
	if(sign < 0) output += "-"; else if((flags & 1 << de.polygonal._Printf.FormatFlags.Plus[1]) != 0) output += "+"; else output += "";
	if(value != 0) output += de.polygonal.Printf.rpad((function($this) {
		var $r;
		var _this = de.polygonal.Printf.str(value);
		$r = HxOverrides.substr(_this,0,precision + 2);
		return $r;
	}(this)),"0",precision + 2);
	if((flags & 1 << de.polygonal._Printf.FormatFlags.UpperCase[1]) != 0) output += "E"; else output += "e";
	if(exponent >= 0) output += "+"; else output += "-";
	if(exponent < 10) output += "00"; else if(exponent < 100) output += "0";
	output += de.polygonal.Printf.str(de.polygonal.Printf.iabs(exponent));
	return output;
};
de.polygonal.Printf.formatSignedDecimal = function(value,args) {
	var output;
	var flags = args.flags;
	var precision = args.precision;
	var width = args.width;
	if(precision == 0 && value == 0) output = ""; else {
		if((flags & 1 << de.polygonal._Printf.FormatFlags.LengthH[1]) != 0) value &= 65535;
		output = de.polygonal.Printf.str(de.polygonal.Printf.iabs(value));
		if(precision > 1 && output.length < precision) output = de.polygonal.Printf.lpad(output,"0",precision);
		if((flags & 1 << de.polygonal._Printf.FormatFlags.Zero[1]) != 0) output = de.polygonal.Printf.lpad(output,"0",value < 0?width - 1:width);
		if(value < 0) output = "-" + output;
	}
	if(value >= 0) {
		if((flags & 1 << de.polygonal._Printf.FormatFlags.Plus[1]) != 0) output = "+" + output; else if((flags & 1 << de.polygonal._Printf.FormatFlags.Space[1]) != 0) output = " " + output;
	}
	if((flags & 1 << de.polygonal._Printf.FormatFlags.Minus[1]) != 0) output = de.polygonal.Printf.rpad(output," ",args.width); else output = de.polygonal.Printf.lpad(output," ",args.width);
	return output;
};
de.polygonal.Printf.formatString = function(x,args) {
	var output = x;
	var precision = args.precision;
	var width = args.width;
	if(precision > 0) output = HxOverrides.substr(x,0,precision);
	var k = output.length;
	if(width > 0 && k < width) {
		if((args.flags & 1 << de.polygonal._Printf.FormatFlags.Minus[1]) != 0) output = de.polygonal.Printf.rpad(output," ",width); else output = de.polygonal.Printf.lpad(output," ",width);
	}
	return output;
};
de.polygonal.Printf.formatNormalFloat = function(value,args) {
	var output;
	var flags = args.flags;
	var precision = args.precision;
	var width = args.width;
	if(precision == -1) precision = 6;
	if(precision == 0) {
		output = de.polygonal.Printf.str(de.polygonal.Printf.iabs(Math.round(value)));
		if((flags & 1 << de.polygonal._Printf.FormatFlags.Sharp[1]) != 0) output += ".";
	} else {
		value = de.polygonal.Printf.roundTo(value,Math.pow(.1,precision));
		var decimalPlaces = precision;
		if(Math.isNaN(value)) output = "NaN"; else {
			var t = Std["int"](Math.pow(10,decimalPlaces));
			output = de.polygonal.Printf.str((value * t | 0) / t);
			var i = output.indexOf(".");
			if(i != -1) {
				var _g = HxOverrides.substr(output,i + 1,null).length;
				while(_g < decimalPlaces) {
					var i1 = _g++;
					output += "0";
				}
			} else {
				output += ".";
				var _g1 = 0;
				while(_g1 < decimalPlaces) {
					var i2 = _g1++;
					output += "0";
				}
			}
		}
	}
	if((flags & 1 << de.polygonal._Printf.FormatFlags.Plus[1]) != 0 && value >= 0) output = "+" + output; else if((flags & 1 << de.polygonal._Printf.FormatFlags.Space[1]) != 0 && value >= 0) output = " " + output;
	if((flags & 1 << de.polygonal._Printf.FormatFlags.Zero[1]) != 0) output = de.polygonal.Printf.lpad(output,"0",value < 0?width - 1:width);
	if((flags & 1 << de.polygonal._Printf.FormatFlags.Minus[1]) != 0) output = de.polygonal.Printf.rpad(output," ",width); else output = de.polygonal.Printf.lpad(output," ",width);
	return output;
};
de.polygonal.Printf.formatCharacter = function(x,args) {
	var output = String.fromCharCode(x);
	if(args.width > 1) {
		if((args.flags & 1 << de.polygonal._Printf.FormatFlags.Minus[1]) != 0) output = de.polygonal.Printf.rpad(output," ",args.width); else output = de.polygonal.Printf.lpad(output," ",args.width);
	}
	return output;
};
de.polygonal.Printf.padNumber = function(x,n,flags,width) {
	var k = x.length;
	if(width > 0 && k < width) {
		if((flags & 1 << de.polygonal._Printf.FormatFlags.Minus[1]) != 0) x = de.polygonal.Printf.rpad(x," ",width); else if(n >= 0) x = de.polygonal.Printf.lpad(x,(flags & 1 << de.polygonal._Printf.FormatFlags.Zero[1]) != 0?"0":" ",width); else if((flags & 1 << de.polygonal._Printf.FormatFlags.Zero[1]) != 0) x = "-" + de.polygonal.Printf.lpad(HxOverrides.substr(x,1,null),"0",width); else x = de.polygonal.Printf.lpad(x," ",width);
	}
	return x;
};
de.polygonal.Printf.lpad = function(s,c,l) {
	if(c.length <= 0) throw "c.length <= 0";
	while(s.length < l) s = c + s;
	return s;
};
de.polygonal.Printf.rpad = function(s,c,l) {
	if(c.length <= 0) throw "c.length <= 0";
	while(s.length < l) s = s + c;
	return s;
};
de.polygonal.Printf.toHex = function(x) {
	var s = "";
	var hexChars = "0123456789ABCDEF";
	do {
		s = hexChars.charAt(x & 15) + s;
		x >>>= 4;
	} while(x > 0);
	return s;
};
de.polygonal.Printf.toOct = function(x) {
	var s = "";
	var t = x;
	do {
		s = (t & 7) + s;
		t >>>= 3;
	} while(t > 0);
	return s;
};
de.polygonal.Printf.iabs = function(x) {
	return Std["int"](Math.abs(x));
};
de.polygonal.Printf.str = function(x) {
	return Std.string(x);
};
de.polygonal.Printf.codeAt = function(x,i) {
	return x.charCodeAt(i);
};
de.polygonal.Printf.isDigit = function(x) {
	return x >= 48 && x <= 57;
};
de.polygonal.Printf.roundTo = function(x,y) {
	return Math.round(x / y) * y;
};
de.polygonal._Printf = {};
de.polygonal._Printf.FormatFlags = { __ename__ : true, __constructs__ : ["Minus","Plus","Space","Sharp","Zero","LengthH","LengthL","Lengthl","UpperCase"] };
de.polygonal._Printf.FormatFlags.Minus = ["Minus",0];
de.polygonal._Printf.FormatFlags.Minus.__enum__ = de.polygonal._Printf.FormatFlags;
de.polygonal._Printf.FormatFlags.Plus = ["Plus",1];
de.polygonal._Printf.FormatFlags.Plus.__enum__ = de.polygonal._Printf.FormatFlags;
de.polygonal._Printf.FormatFlags.Space = ["Space",2];
de.polygonal._Printf.FormatFlags.Space.__enum__ = de.polygonal._Printf.FormatFlags;
de.polygonal._Printf.FormatFlags.Sharp = ["Sharp",3];
de.polygonal._Printf.FormatFlags.Sharp.__enum__ = de.polygonal._Printf.FormatFlags;
de.polygonal._Printf.FormatFlags.Zero = ["Zero",4];
de.polygonal._Printf.FormatFlags.Zero.__enum__ = de.polygonal._Printf.FormatFlags;
de.polygonal._Printf.FormatFlags.LengthH = ["LengthH",5];
de.polygonal._Printf.FormatFlags.LengthH.__enum__ = de.polygonal._Printf.FormatFlags;
de.polygonal._Printf.FormatFlags.LengthL = ["LengthL",6];
de.polygonal._Printf.FormatFlags.LengthL.__enum__ = de.polygonal._Printf.FormatFlags;
de.polygonal._Printf.FormatFlags.Lengthl = ["Lengthl",7];
de.polygonal._Printf.FormatFlags.Lengthl.__enum__ = de.polygonal._Printf.FormatFlags;
de.polygonal._Printf.FormatFlags.UpperCase = ["UpperCase",8];
de.polygonal._Printf.FormatFlags.UpperCase.__enum__ = de.polygonal._Printf.FormatFlags;
de.polygonal._Printf.FormatToken = { __ename__ : true, __constructs__ : ["BareString","Tag","Property","Unknown"] };
de.polygonal._Printf.FormatToken.BareString = function(str) { var $x = ["BareString",0,str]; $x.__enum__ = de.polygonal._Printf.FormatToken; return $x; };
de.polygonal._Printf.FormatToken.Tag = function(type,args) { var $x = ["Tag",1,type,args]; $x.__enum__ = de.polygonal._Printf.FormatToken; return $x; };
de.polygonal._Printf.FormatToken.Property = function(name) { var $x = ["Property",2,name]; $x.__enum__ = de.polygonal._Printf.FormatToken; return $x; };
de.polygonal._Printf.FormatToken.Unknown = function(str,pos) { var $x = ["Unknown",3,str,pos]; $x.__enum__ = de.polygonal._Printf.FormatToken; return $x; };
de.polygonal._Printf.FormatDataType = { __ename__ : true, __constructs__ : ["FmtInteger","FmtFloat","FmtString","FmtPointer","FmtNothing"] };
de.polygonal._Printf.FormatDataType.FmtInteger = function(integerType) { var $x = ["FmtInteger",0,integerType]; $x.__enum__ = de.polygonal._Printf.FormatDataType; return $x; };
de.polygonal._Printf.FormatDataType.FmtFloat = function(floatType) { var $x = ["FmtFloat",1,floatType]; $x.__enum__ = de.polygonal._Printf.FormatDataType; return $x; };
de.polygonal._Printf.FormatDataType.FmtString = ["FmtString",2];
de.polygonal._Printf.FormatDataType.FmtString.__enum__ = de.polygonal._Printf.FormatDataType;
de.polygonal._Printf.FormatDataType.FmtPointer = ["FmtPointer",3];
de.polygonal._Printf.FormatDataType.FmtPointer.__enum__ = de.polygonal._Printf.FormatDataType;
de.polygonal._Printf.FormatDataType.FmtNothing = ["FmtNothing",4];
de.polygonal._Printf.FormatDataType.FmtNothing.__enum__ = de.polygonal._Printf.FormatDataType;
de.polygonal._Printf.IntegerType = { __ename__ : true, __constructs__ : ["ICharacter","ISignedDecimal","IUnsignedDecimal","IOctal","IHex","IBin"] };
de.polygonal._Printf.IntegerType.ICharacter = ["ICharacter",0];
de.polygonal._Printf.IntegerType.ICharacter.__enum__ = de.polygonal._Printf.IntegerType;
de.polygonal._Printf.IntegerType.ISignedDecimal = ["ISignedDecimal",1];
de.polygonal._Printf.IntegerType.ISignedDecimal.__enum__ = de.polygonal._Printf.IntegerType;
de.polygonal._Printf.IntegerType.IUnsignedDecimal = ["IUnsignedDecimal",2];
de.polygonal._Printf.IntegerType.IUnsignedDecimal.__enum__ = de.polygonal._Printf.IntegerType;
de.polygonal._Printf.IntegerType.IOctal = ["IOctal",3];
de.polygonal._Printf.IntegerType.IOctal.__enum__ = de.polygonal._Printf.IntegerType;
de.polygonal._Printf.IntegerType.IHex = ["IHex",4];
de.polygonal._Printf.IntegerType.IHex.__enum__ = de.polygonal._Printf.IntegerType;
de.polygonal._Printf.IntegerType.IBin = ["IBin",5];
de.polygonal._Printf.IntegerType.IBin.__enum__ = de.polygonal._Printf.IntegerType;
de.polygonal._Printf.FloatType = { __ename__ : true, __constructs__ : ["FNormal","FScientific","FNatural"] };
de.polygonal._Printf.FloatType.FNormal = ["FNormal",0];
de.polygonal._Printf.FloatType.FNormal.__enum__ = de.polygonal._Printf.FloatType;
de.polygonal._Printf.FloatType.FScientific = ["FScientific",1];
de.polygonal._Printf.FloatType.FScientific.__enum__ = de.polygonal._Printf.FloatType;
de.polygonal._Printf.FloatType.FNatural = ["FNatural",2];
de.polygonal._Printf.FloatType.FNatural.__enum__ = de.polygonal._Printf.FloatType;
var haxe = {};
haxe.Int64 = function(high,low) {
	this.high = high | 0;
	this.low = low | 0;
};
haxe.Int64.__name__ = true;
haxe.Int64.sub = function(a,b) {
	var high = a.high - b.high | 0;
	var low = a.low - b.low | 0;
	if(haxe.Int64.uicompare(a.low,b.low) < 0) high--;
	return new haxe.Int64(high,low);
};
haxe.Int64.divMod = function(modulus,divisor) {
	var quotient = new haxe.Int64(0,0);
	var mask_high = 0;
	var mask_low = 1;
	divisor = new haxe.Int64(divisor.high,divisor.low);
	while(divisor.high >= 0) {
		var cmp = haxe.Int64.ucompare(divisor,modulus);
		divisor.high = divisor.high << 1 | 0 | divisor.low >>> 31 | 0;
		divisor.low = divisor.low << 1 | 0;
		mask_high = mask_high << 1 | 0 | mask_low >>> 31 | 0;
		mask_low = mask_low << 1 | 0;
		if(cmp >= 0) break;
	}
	while((mask_low | mask_high | 0) != 0) {
		if(haxe.Int64.ucompare(modulus,divisor) >= 0) {
			quotient.high = quotient.high | mask_high | 0;
			quotient.low = quotient.low | mask_low | 0;
			modulus = haxe.Int64.sub(modulus,divisor);
		}
		mask_low = mask_low >>> 1 | (mask_high << 31 | 0) | 0;
		mask_high = mask_high >>> 1;
		divisor.low = divisor.low >>> 1 | (divisor.high << 31 | 0) | 0;
		divisor.high = divisor.high >>> 1;
	}
	return { quotient : quotient, modulus : modulus};
};
haxe.Int64.neg = function(a) {
	var high = ~a.high | 0;
	var low = -a.low | 0;
	if(low == 0) high++;
	return new haxe.Int64(high,low);
};
haxe.Int64.uicompare = function(a,b) {
	if(a < 0) {
		if(b < 0) return ~b - ~a | 0; else return 1;
	} else if(b < 0) return -1; else return a - b | 0;
};
haxe.Int64.ucompare = function(a,b) {
	var v = haxe.Int64.uicompare(a.high,b.high);
	if(v != 0) return v; else return haxe.Int64.uicompare(a.low,b.low);
};
haxe.Int64.prototype = {
	toString: function() {
		if((this.high | this.low) == 0) return "0";
		var str = "";
		var neg = false;
		var i = this;
		if(i.high < 0) {
			neg = true;
			i = haxe.Int64.neg(i);
		}
		var ten = new haxe.Int64(0,10);
		while(!((i.high | i.low) == 0)) {
			var r = haxe.Int64.divMod(i,ten);
			str = r.modulus.low + str;
			i = r.quotient;
		}
		if(neg) str = "-" + str;
		return str;
	}
	,__class__: haxe.Int64
};
haxe.Log = function() { };
haxe.Log.__name__ = true;
haxe.Log.trace = function(v,infos) {
	js.Boot.__trace(v,infos);
};
haxe.Timer = function() { };
haxe.Timer.__name__ = true;
haxe.Timer.stamp = function() {
	return new Date().getTime() / 1000;
};
haxe.ds = {};
haxe.ds.IntMap = function() {
	this.h = { };
};
haxe.ds.IntMap.__name__ = true;
haxe.ds.IntMap.__interfaces__ = [IMap];
haxe.ds.IntMap.prototype = {
	set: function(key,value) {
		this.h[key] = value;
	}
	,get: function(key) {
		return this.h[key];
	}
	,__class__: haxe.ds.IntMap
};
var js = {};
js.Boot = function() { };
js.Boot.__name__ = true;
js.Boot.__unhtml = function(s) {
	return s.split("&").join("&amp;").split("<").join("&lt;").split(">").join("&gt;");
};
js.Boot.__trace = function(v,i) {
	var msg;
	if(i != null) msg = i.fileName + ":" + i.lineNumber + ": "; else msg = "";
	msg += js.Boot.__string_rec(v,"");
	if(i != null && i.customParams != null) {
		var _g = 0;
		var _g1 = i.customParams;
		while(_g < _g1.length) {
			var v1 = _g1[_g];
			++_g;
			msg += "," + js.Boot.__string_rec(v1,"");
		}
	}
	var d;
	if(typeof(document) != "undefined" && (d = document.getElementById("haxe:trace")) != null) d.innerHTML += js.Boot.__unhtml(msg) + "<br/>"; else if(typeof console != "undefined" && console.log != null) console.log(msg);
};
js.Boot.getClass = function(o) {
	if((o instanceof Array) && o.__enum__ == null) return Array; else return o.__class__;
};
js.Boot.__string_rec = function(o,s) {
	if(o == null) return "null";
	if(s.length >= 5) return "<...>";
	var t = typeof(o);
	if(t == "function" && (o.__name__ || o.__ename__)) t = "object";
	switch(t) {
	case "object":
		if(o instanceof Array) {
			if(o.__enum__) {
				if(o.length == 2) return o[0];
				var str = o[0] + "(";
				s += "\t";
				var _g1 = 2;
				var _g = o.length;
				while(_g1 < _g) {
					var i = _g1++;
					if(i != 2) str += "," + js.Boot.__string_rec(o[i],s); else str += js.Boot.__string_rec(o[i],s);
				}
				return str + ")";
			}
			var l = o.length;
			var i1;
			var str1 = "[";
			s += "\t";
			var _g2 = 0;
			while(_g2 < l) {
				var i2 = _g2++;
				str1 += (i2 > 0?",":"") + js.Boot.__string_rec(o[i2],s);
			}
			str1 += "]";
			return str1;
		}
		var tostr;
		try {
			tostr = o.toString;
		} catch( e ) {
			return "???";
		}
		if(tostr != null && tostr != Object.toString) {
			var s2 = o.toString();
			if(s2 != "[object Object]") return s2;
		}
		var k = null;
		var str2 = "{\n";
		s += "\t";
		var hasp = o.hasOwnProperty != null;
		for( var k in o ) {
		if(hasp && !o.hasOwnProperty(k)) {
			continue;
		}
		if(k == "prototype" || k == "__class__" || k == "__super__" || k == "__interfaces__" || k == "__properties__") {
			continue;
		}
		if(str2.length != 2) str2 += ", \n";
		str2 += s + k + " : " + js.Boot.__string_rec(o[k],s);
		}
		s = s.substring(1);
		str2 += "\n" + s + "}";
		return str2;
	case "function":
		return "<function>";
	case "string":
		return o;
	default:
		return String(o);
	}
};
js.Boot.__interfLoop = function(cc,cl) {
	if(cc == null) return false;
	if(cc == cl) return true;
	var intf = cc.__interfaces__;
	if(intf != null) {
		var _g1 = 0;
		var _g = intf.length;
		while(_g1 < _g) {
			var i = _g1++;
			var i1 = intf[i];
			if(i1 == cl || js.Boot.__interfLoop(i1,cl)) return true;
		}
	}
	return js.Boot.__interfLoop(cc.__super__,cl);
};
js.Boot.__instanceof = function(o,cl) {
	if(cl == null) return false;
	switch(cl) {
	case Int:
		return (o|0) === o;
	case Float:
		return typeof(o) == "number";
	case Bool:
		return typeof(o) == "boolean";
	case String:
		return typeof(o) == "string";
	case Array:
		return (o instanceof Array) && o.__enum__ == null;
	case Dynamic:
		return true;
	default:
		if(o != null) {
			if(typeof(cl) == "function") {
				if(o instanceof cl) return true;
				if(js.Boot.__interfLoop(js.Boot.getClass(o),cl)) return true;
			}
		} else return false;
		if(cl == Class && o.__name__ != null) return true;
		if(cl == Enum && o.__ename__ != null) return true;
		return o.__enum__ == cl;
	}
};
js.Boot.__cast = function(o,t) {
	if(js.Boot.__instanceof(o,t)) return o; else throw "Cannot cast " + Std.string(o) + " to " + Std.string(t);
};
var $_, $fid = 0;
function $bind(o,m) { if( m == null ) return null; if( m.__id__ == null ) m.__id__ = $fid++; var f; if( o.hx__closures__ == null ) o.hx__closures__ = {}; else f = o.hx__closures__[m.__id__]; if( f == null ) { f = function(){ return f.method.apply(f.scope, arguments); }; f.scope = o; f.method = m; o.hx__closures__[m.__id__] = f; } return f; }
Math.NaN = Number.NaN;
Math.NEGATIVE_INFINITY = Number.NEGATIVE_INFINITY;
Math.POSITIVE_INFINITY = Number.POSITIVE_INFINITY;
Math.isFinite = function(i) {
	return isFinite(i);
};
Math.isNaN = function(i1) {
	return isNaN(i1);
};
String.prototype.__class__ = String;
String.__name__ = true;
Array.__name__ = true;
Date.prototype.__class__ = Date;
Date.__name__ = ["Date"];
var Int = { __name__ : ["Int"]};
var Dynamic = { __name__ : ["Dynamic"]};
var Float = Number;
Float.__name__ = ["Float"];
var Bool = Boolean;
Bool.__ename__ = ["Bool"];
var Class = { __name__ : ["Class"]};
var Enum = { };
de.polygonal.Printf._initialized = false;
Main.main();
})();
