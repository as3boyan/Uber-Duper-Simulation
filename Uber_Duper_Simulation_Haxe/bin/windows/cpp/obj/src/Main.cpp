#include <hxcpp.h>

#ifndef INCLUDED_Main
#include <Main.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_Sys
#include <Sys.h>
#endif
#ifndef INCLUDED_de_polygonal_Printf
#include <de/polygonal/Printf.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_haxe_Timer
#include <haxe/Timer.h>
#endif
#ifndef INCLUDED_haxe_io_Output
#include <haxe/io/Output.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_openfl__v2_Lib
#include <openfl/_v2/Lib.h>
#endif
#ifndef INCLUDED_openfl__v2_display_DisplayObject
#include <openfl/_v2/display/DisplayObject.h>
#endif
#ifndef INCLUDED_openfl__v2_display_DisplayObjectContainer
#include <openfl/_v2/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_openfl__v2_display_IBitmapDrawable
#include <openfl/_v2/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_openfl__v2_display_InteractiveObject
#include <openfl/_v2/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_openfl__v2_display_MovieClip
#include <openfl/_v2/display/MovieClip.h>
#endif
#ifndef INCLUDED_openfl__v2_display_Sprite
#include <openfl/_v2/display/Sprite.h>
#endif
#ifndef INCLUDED_openfl__v2_events_EventDispatcher
#include <openfl/_v2/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_openfl__v2_events_IEventDispatcher
#include <openfl/_v2/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_openfl__v2_text_TextField
#include <openfl/_v2/text/TextField.h>
#endif
#ifndef INCLUDED_sys_io_File
#include <sys/io/File.h>
#endif
#ifndef INCLUDED_sys_io_FileOutput
#include <sys/io/FileOutput.h>
#endif

Void Main_obj::__construct()
{
HX_STACK_FRAME("Main","new",0x6616a5cb,"Main.new","Main.hx",29,0x087e5c05)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(32)
	this->mu = 3.9860047e14;
	HX_STACK_LINE(31)
	this->R0 = (int)6378137;
}
;
	return null();
}

//Main_obj::~Main_obj() { }

Dynamic Main_obj::__CreateEmpty() { return  new Main_obj; }
hx::ObjectPtr< Main_obj > Main_obj::__new()
{  hx::ObjectPtr< Main_obj > result = new Main_obj();
	result->__construct();
	return result;}

Dynamic Main_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Main_obj > result = new Main_obj();
	result->__construct();
	return result;}

Float Main_obj::h_x_y( Float x,Float y){
	HX_STACK_FRAME("Main","h_x_y",0x9d064146,"Main.h_x_y","Main.hx",35,0x087e5c05)
	HX_STACK_THIS(this)
	HX_STACK_ARG(x,"x")
	HX_STACK_ARG(y,"y")
	HX_STACK_LINE(36)
	Float _g = ::Math_obj::pow(x,(int)2);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(36)
	Float _g1 = ::Math_obj::pow(y,(int)2);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(36)
	Float _g2 = (_g + _g1);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(36)
	Float _g3 = ::Math_obj::sqrt(_g2);		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(36)
	return (_g3 - this->R0);
}


HX_DEFINE_DYNAMIC_FUNC2(Main_obj,h_x_y,return )

Float Main_obj::calculate_T_period( Float R){
	HX_STACK_FRAME("Main","calculate_T_period",0x605264fa,"Main.calculate_T_period","Main.hx",40,0x087e5c05)
	HX_STACK_THIS(this)
	HX_STACK_ARG(R,"R")
	HX_STACK_LINE(41)
	Float _g = ::Math_obj::pow(R,(int)3);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(41)
	Float _g1 = (Float(_g) / Float(this->mu));		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(41)
	Float _g2 = ::Math_obj::sqrt(_g1);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(41)
	return (((int)2 * ::Math_obj::PI) * _g2);
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,calculate_T_period,return )

Array< Float > Main_obj::right_part( Float t,Array< Float > StateVector){
	HX_STACK_FRAME("Main","right_part",0x0481f46b,"Main.right_part","Main.hx",45,0x087e5c05)
	HX_STACK_THIS(this)
	HX_STACK_ARG(t,"t")
	HX_STACK_ARG(StateVector,"StateVector")
	HX_STACK_LINE(46)
	Float _g = ::Math_obj::pow(StateVector->__get((int)0),(int)2);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(46)
	Float _g1 = ::Math_obj::pow(StateVector->__get((int)1),(int)2);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(46)
	Float _g2 = (_g + _g1);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(46)
	Float R = ::Math_obj::sqrt(_g2);		HX_STACK_VAR(R,"R");
	HX_STACK_LINE(47)
	Float R3 = ::Math_obj::pow(R,(int)3);		HX_STACK_VAR(R3,"R3");
	HX_STACK_LINE(49)
	Array< Float > result = Array_obj< Float >::__new().Add(0.0).Add(0.0).Add(0.0).Add(0.0);		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(50)
	result[(int)0] = StateVector->__get((int)2);
	HX_STACK_LINE(51)
	result[(int)1] = StateVector->__get((int)3);
	HX_STACK_LINE(52)
	result[(int)2] = ((Float(-(this->mu)) / Float(R3)) * StateVector->__get((int)0));
	HX_STACK_LINE(53)
	result[(int)3] = ((Float(-(this->mu)) / Float(R3)) * StateVector->__get((int)1));
	HX_STACK_LINE(54)
	return result;
}


HX_DEFINE_DYNAMIC_FUNC2(Main_obj,right_part,return )

Array< Float > Main_obj::runge_kutta_t_state_vector( Float t,Array< Float > params,Float t_step,Dynamic f){
	HX_STACK_FRAME("Main","runge_kutta_t_state_vector",0xf3568e6f,"Main.runge_kutta_t_state_vector","Main.hx",58,0x087e5c05)
	HX_STACK_THIS(this)
	HX_STACK_ARG(t,"t")
	HX_STACK_ARG(params,"params")
	HX_STACK_ARG(t_step,"t_step")
	HX_STACK_ARG(f,"f")
	HX_STACK_LINE(59)
	Array< Float > k1;		HX_STACK_VAR(k1,"k1");
	HX_STACK_LINE(59)
	Array< Float > k2;		HX_STACK_VAR(k2,"k2");
	HX_STACK_LINE(59)
	Array< Float > k3;		HX_STACK_VAR(k3,"k3");
	HX_STACK_LINE(59)
	Array< Float > k4 = Array_obj< Float >::__new();		HX_STACK_VAR(k4,"k4");
	HX_STACK_LINE(61)
	Float h = t_step;		HX_STACK_VAR(h,"h");
	HX_STACK_LINE(63)
	Array< Float > _g = f(t,params).Cast< Array< Float > >();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(63)
	k1 = _g;
	HX_STACK_LINE(65)
	Array< Float > new_params = Array_obj< Float >::__new().Add(0.0).Add((int)0).Add((int)0).Add((int)0);		HX_STACK_VAR(new_params,"new_params");
	HX_STACK_LINE(67)
	{
		HX_STACK_LINE(67)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(67)
		int _g2 = params->length;		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(67)
		while((true)){
			HX_STACK_LINE(67)
			if ((!(((_g1 < _g2))))){
				HX_STACK_LINE(67)
				break;
			}
			HX_STACK_LINE(67)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(69)
			Float p = params->__get(i);		HX_STACK_VAR(p,"p");
			HX_STACK_LINE(70)
			new_params[i] = (p + ((Float(h) / Float((int)2)) * k1->__get(i)));
		}
	}
	HX_STACK_LINE(73)
	Array< Float > _g1 = f((t + (Float(h) / Float((int)2))),new_params).Cast< Array< Float > >();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(73)
	k2 = _g1;
	HX_STACK_LINE(75)
	{
		HX_STACK_LINE(75)
		int _g11 = (int)0;		HX_STACK_VAR(_g11,"_g11");
		HX_STACK_LINE(75)
		int _g2 = params->length;		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(75)
		while((true)){
			HX_STACK_LINE(75)
			if ((!(((_g11 < _g2))))){
				HX_STACK_LINE(75)
				break;
			}
			HX_STACK_LINE(75)
			int i = (_g11)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(77)
			Float p = params->__get(i);		HX_STACK_VAR(p,"p");
			HX_STACK_LINE(78)
			new_params[i] = (p + ((Float(h) / Float((int)2)) * k2->__get(i)));
		}
	}
	HX_STACK_LINE(81)
	Array< Float > _g2 = f((t + (Float(h) / Float((int)2))),new_params).Cast< Array< Float > >();		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(81)
	k3 = _g2;
	HX_STACK_LINE(83)
	{
		HX_STACK_LINE(83)
		int _g11 = (int)0;		HX_STACK_VAR(_g11,"_g11");
		HX_STACK_LINE(83)
		int _g3 = params->length;		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(83)
		while((true)){
			HX_STACK_LINE(83)
			if ((!(((_g11 < _g3))))){
				HX_STACK_LINE(83)
				break;
			}
			HX_STACK_LINE(83)
			int i = (_g11)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(85)
			Float p = params->__get(i);		HX_STACK_VAR(p,"p");
			HX_STACK_LINE(86)
			new_params[i] = (p + (h * k3->__get(i)));
		}
	}
	HX_STACK_LINE(89)
	Array< Float > _g3 = f((t + h),new_params).Cast< Array< Float > >();		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(89)
	k4 = _g3;
	HX_STACK_LINE(91)
	{
		HX_STACK_LINE(91)
		int _g11 = (int)0;		HX_STACK_VAR(_g11,"_g11");
		HX_STACK_LINE(91)
		int _g4 = params->length;		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(91)
		while((true)){
			HX_STACK_LINE(91)
			if ((!(((_g11 < _g4))))){
				HX_STACK_LINE(91)
				break;
			}
			HX_STACK_LINE(91)
			int i = (_g11)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(93)
			Float p = params->__get(i);		HX_STACK_VAR(p,"p");
			HX_STACK_LINE(94)
			params[i] = (p + ((Float(h) / Float((int)6)) * ((((k1->__get(i) + ((int)2 * k2->__get(i))) + ((int)2 * k3->__get(i))) + k4->__get(i)))));
		}
	}
	HX_STACK_LINE(97)
	return params;
}


HX_DEFINE_DYNAMIC_FUNC4(Main_obj,runge_kutta_t_state_vector,return )

Void Main_obj::regular_calculation( Float Vx,Float Vy,Float t,Float t_end,Float t_step,Float x,Float y){
{
		HX_STACK_FRAME("Main","regular_calculation",0x96a25ad1,"Main.regular_calculation","Main.hx",102,0x087e5c05)
		HX_STACK_THIS(this)
		HX_STACK_ARG(Vx,"Vx")
		HX_STACK_ARG(Vy,"Vy")
		HX_STACK_ARG(t,"t")
		HX_STACK_ARG(t_end,"t_end")
		HX_STACK_ARG(t_step,"t_step")
		HX_STACK_ARG(x,"x")
		HX_STACK_ARG(y,"y")
		HX_STACK_LINE(103)
		::sys::io::FileOutput file1 = ::sys::io::File_obj::write(HX_CSTRING("output.tr"),false);		HX_STACK_VAR(file1,"file1");
		HX_STACK_LINE(104)
		file1->writeString(HX_CSTRING("t, x, y, Vx, Vy\n"));
		HX_STACK_LINE(106)
		Array< Float > params = Array_obj< Float >::__new().Add(x).Add(y).Add(Vx).Add(Vy);		HX_STACK_VAR(params,"params");
		HX_STACK_LINE(108)
		while((true)){
			HX_STACK_LINE(108)
			if ((!(((t <= t_end))))){
				HX_STACK_LINE(108)
				break;
			}
			HX_STACK_LINE(110)
			Array< Float > _g = Array_obj< Float >::__new().Add(t)->concat(params);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(110)
			::String _g1 = ::de::polygonal::Printf_obj::format(HX_CSTRING("%.3f %d %d %.3f %.3f\n"),_g);		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(110)
			file1->writeString(_g1);
			HX_STACK_LINE(112)
			hx::AddEq(t,t_step);
			HX_STACK_LINE(114)
			Array< Float > _g2 = this->runge_kutta_t_state_vector(t,params,t_step,this->right_part_dyn());		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(114)
			params = _g2;
		}
		HX_STACK_LINE(117)
		file1->close();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC7(Main_obj,regular_calculation,(void))

Void Main_obj::benchmark_test( Float Vx,Float Vy,Float t,Float t_end,Float t_step,Float x,Float y){
{
		HX_STACK_FRAME("Main","benchmark_test",0x983726c9,"Main.benchmark_test","Main.hx",150,0x087e5c05)
		HX_STACK_THIS(this)
		HX_STACK_ARG(Vx,"Vx")
		HX_STACK_ARG(Vy,"Vy")
		HX_STACK_ARG(t,"t")
		HX_STACK_ARG(t_end,"t_end")
		HX_STACK_ARG(t_step,"t_step")
		HX_STACK_ARG(x,"x")
		HX_STACK_ARG(y,"y")
		HX_STACK_LINE(151)
		Array< Float > params = Array_obj< Float >::__new().Add(x).Add(y).Add(Vx).Add(Vy);		HX_STACK_VAR(params,"params");
		HX_STACK_LINE(153)
		while((true)){
			HX_STACK_LINE(153)
			if ((!(((t <= t_end))))){
				HX_STACK_LINE(153)
				break;
			}
			HX_STACK_LINE(155)
			hx::AddEq(t,t_step);
			HX_STACK_LINE(156)
			Array< Float > _g = this->runge_kutta_t_state_vector(t,params,t_step,this->right_part_dyn());		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(156)
			params = _g;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC7(Main_obj,benchmark_test,(void))

Void Main_obj::test( Float Vx,Float Vy,Float t,Float t_end,Float t_step,Float x,Float y,Float R){
{
		HX_STACK_FRAME("Main","test",0xf1b1b087,"Main.test","Main.hx",165,0x087e5c05)
		HX_STACK_THIS(this)
		HX_STACK_ARG(Vx,"Vx")
		HX_STACK_ARG(Vy,"Vy")
		HX_STACK_ARG(t,"t")
		HX_STACK_ARG(t_end,"t_end")
		HX_STACK_ARG(t_step,"t_step")
		HX_STACK_ARG(x,"x")
		HX_STACK_ARG(y,"y")
		HX_STACK_ARG(R,"R")
		HX_STACK_LINE(166)
		Float T_period = this->calculate_T_period(R);		HX_STACK_VAR(T_period,"T_period");
		HX_STACK_LINE(168)
		Array< Float > params = Array_obj< Float >::__new().Add(x).Add(y).Add(Vx).Add(Vy);		HX_STACK_VAR(params,"params");
		HX_STACK_LINE(170)
		Array< Float > parameters = params->copy();		HX_STACK_VAR(parameters,"parameters");
		HX_STACK_LINE(172)
		Array< ::String > texts = Array_obj< ::String >::__new().Add(HX_CSTRING("x")).Add(HX_CSTRING("y")).Add(HX_CSTRING("Vx")).Add(HX_CSTRING("Vy"));		HX_STACK_VAR(texts,"texts");
		HX_STACK_LINE(174)
		while((true)){
			HX_STACK_LINE(174)
			if ((!(((t <= t_end))))){
				HX_STACK_LINE(174)
				break;
			}
			HX_STACK_LINE(176)
			hx::AddEq(t,t_step);
			HX_STACK_LINE(177)
			Array< Float > _g = this->runge_kutta_t_state_vector(t,params,t_step,this->right_part_dyn());		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(177)
			params = _g;
			HX_STACK_LINE(179)
			if (((bool((t >= T_period)) && bool((t <= (T_period + t_step)))))){
				HX_STACK_LINE(181)
				int _g1 = ::Math_obj::floor((Float(t) / Float(T_period)));		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(181)
				Dynamic _g2 = Dynamic( Array_obj<Dynamic>::__new().Add(_g1));		HX_STACK_VAR(_g2,"_g2");
				struct _Function_3_1{
					inline static Dynamic Block( Dynamic &_g2){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Main.hx",181,0x087e5c05)
						{
							hx::Anon __result = hx::Anon_obj::Create();
							__result->Add(HX_CSTRING("fileName") , HX_CSTRING("Main.hx"),false);
							__result->Add(HX_CSTRING("lineNumber") , (int)181,false);
							__result->Add(HX_CSTRING("className") , HX_CSTRING("Main"),false);
							__result->Add(HX_CSTRING("methodName") , HX_CSTRING("test"),false);
							__result->Add(HX_CSTRING("customParams") , _g2,false);
							return __result;
						}
						return null();
					}
				};
				HX_STACK_LINE(181)
				Dynamic _g3 = _Function_3_1::Block(_g2);		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(181)
				::haxe::Log_obj::trace(HX_CSTRING("\xd0""\x92""\xd0""\xb8""\xd1""\x82""\xd0""\xbe""\xd0""\xba"" \xe2""\x84""\x96"" "),_g3);
				struct _Function_3_2{
					inline static Dynamic Block( Float &t){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Main.hx",182,0x087e5c05)
						{
							hx::Anon __result = hx::Anon_obj::Create();
							__result->Add(HX_CSTRING("fileName") , HX_CSTRING("Main.hx"),false);
							__result->Add(HX_CSTRING("lineNumber") , (int)182,false);
							__result->Add(HX_CSTRING("className") , HX_CSTRING("Main"),false);
							__result->Add(HX_CSTRING("methodName") , HX_CSTRING("test"),false);
							__result->Add(HX_CSTRING("customParams") , Dynamic( Array_obj<Dynamic>::__new().Add(t)),false);
							return __result;
						}
						return null();
					}
				};
				HX_STACK_LINE(182)
				::haxe::Log_obj::trace(HX_CSTRING("T = "),_Function_3_2::Block(t));
				HX_STACK_LINE(184)
				{
					HX_STACK_LINE(184)
					int _g4 = (int)0;		HX_STACK_VAR(_g4,"_g4");
					HX_STACK_LINE(184)
					while((true)){
						HX_STACK_LINE(184)
						if ((!(((_g4 < (int)4))))){
							HX_STACK_LINE(184)
							break;
						}
						HX_STACK_LINE(184)
						int i = (_g4)++;		HX_STACK_VAR(i,"i");
						HX_STACK_LINE(186)
						Float x1 = parameters->__get(i);		HX_STACK_VAR(x1,"x1");
						HX_STACK_LINE(187)
						Float x2 = params->__get(i);		HX_STACK_VAR(x2,"x2");
						HX_STACK_LINE(189)
						if ((((x1 - x2) > 1e-5))){
							struct _Function_6_1{
								inline static Dynamic Block( Float &x1,Float &x2){
									HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Main.hx",191,0x087e5c05)
									{
										hx::Anon __result = hx::Anon_obj::Create();
										__result->Add(HX_CSTRING("fileName") , HX_CSTRING("Main.hx"),false);
										__result->Add(HX_CSTRING("lineNumber") , (int)191,false);
										__result->Add(HX_CSTRING("className") , HX_CSTRING("Main"),false);
										__result->Add(HX_CSTRING("methodName") , HX_CSTRING("test"),false);
										__result->Add(HX_CSTRING("customParams") , Dynamic( Array_obj<Dynamic>::__new().Add(HX_CSTRING(": ")).Add(x1).Add(x2).Add((x1 - x2))),false);
										return __result;
									}
									return null();
								}
							};
							HX_STACK_LINE(191)
							::haxe::Log_obj::trace(texts->__get(i),_Function_6_1::Block(x1,x2));
						}
					}
				}
			}
			HX_STACK_LINE(196)
			Float h = this->h_x_y(params->__get((int)0),params->__get((int)1));		HX_STACK_VAR(h,"h");
			HX_STACK_LINE(198)
			if ((((h - (int)1000000) > 1e-5))){
				struct _Function_3_1{
					inline static Dynamic Block( Float &h){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Main.hx",200,0x087e5c05)
						{
							hx::Anon __result = hx::Anon_obj::Create();
							__result->Add(HX_CSTRING("fileName") , HX_CSTRING("Main.hx"),false);
							__result->Add(HX_CSTRING("lineNumber") , (int)200,false);
							__result->Add(HX_CSTRING("className") , HX_CSTRING("Main"),false);
							__result->Add(HX_CSTRING("methodName") , HX_CSTRING("test"),false);
							__result->Add(HX_CSTRING("customParams") , Dynamic( Array_obj<Dynamic>::__new().Add(h)),false);
							return __result;
						}
						return null();
					}
				};
				HX_STACK_LINE(200)
				::haxe::Log_obj::trace(HX_CSTRING("\xd0""\x92""\xd1""\x8b""\xd1""\x81""\xd0""\xbe""\xd1""\x82""\xd0""\xb0"" \xd0""\xb8""\xd0""\xb7""\xd0""\xbc""\xd0""\xb5""\xd0""\xbd""\xd0""\xb8""\xd0""\xbb""\xd0""\xb0""\xd1""\x81""\xd1""\x8c"" "),_Function_3_1::Block(h));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC8(Main_obj,test,(void))

Void Main_obj::main2( ::String type,Float step){
{
		HX_STACK_FRAME("Main","main2",0x7f4e4004,"Main.main2","Main.hx",206,0x087e5c05)
		HX_STACK_THIS(this)
		HX_STACK_ARG(type,"type")
		HX_STACK_ARG(step,"step")
		HX_STACK_LINE(207)
		Float t_end = 10000.0;		HX_STACK_VAR(t_end,"t_end");
		HX_STACK_LINE(208)
		Float t_step = step;		HX_STACK_VAR(t_step,"t_step");
		HX_STACK_LINE(209)
		Float h0 = 1000000.0;		HX_STACK_VAR(h0,"h0");
		HX_STACK_LINE(210)
		Float R = (this->R0 + h0);		HX_STACK_VAR(R,"R");
		HX_STACK_LINE(211)
		Float t = 0.0;		HX_STACK_VAR(t,"t");
		HX_STACK_LINE(212)
		Float x = 0.0;		HX_STACK_VAR(x,"x");
		HX_STACK_LINE(213)
		Float y = R;		HX_STACK_VAR(y,"y");
		HX_STACK_LINE(214)
		Float Vx = ::Math_obj::sqrt((Float(this->mu) / Float(R)));		HX_STACK_VAR(Vx,"Vx");
		HX_STACK_LINE(215)
		Float Vy = 0.0;		HX_STACK_VAR(Vy,"Vy");
		HX_STACK_LINE(217)
		::String _switch_1 = (type);
		if (  ( _switch_1==HX_CSTRING("regular"))){
			HX_STACK_LINE(221)
			this->regular_calculation(Vx,Vy,t,t_end,t_step,x,y);
		}
		else if (  ( _switch_1==HX_CSTRING("benchmark"))){
			HX_STACK_LINE(224)
			this->benchmark_test(Vx,Vy,t,t_end,t_step,x,y);
		}
		else if (  ( _switch_1==HX_CSTRING("test"))){
			HX_STACK_LINE(226)
			this->test(Vx,Vy,t,t_end,t_step,x,y,R);
		}
		else  {
		}
;
;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Main_obj,main2,(void))

Void Main_obj::run_calculation_and_measure_time( ::String run_type,Float step,Dynamic file1){
{
		HX_STACK_FRAME("Main","run_calculation_and_measure_time",0x84af2315,"Main.run_calculation_and_measure_time","Main.hx",233,0x087e5c05)
		HX_STACK_THIS(this)
		HX_STACK_ARG(run_type,"run_type")
		HX_STACK_ARG(step,"step")
		HX_STACK_ARG(file1,"file1")
		HX_STACK_LINE(234)
		Float startDate = ::haxe::Timer_obj::stamp();		HX_STACK_VAR(startDate,"startDate");
		HX_STACK_LINE(235)
		this->main2(run_type,step);
		HX_STACK_LINE(236)
		Float endDate = ::haxe::Timer_obj::stamp();		HX_STACK_VAR(endDate,"endDate");
		HX_STACK_LINE(238)
		Float delta = (endDate - startDate);		HX_STACK_VAR(delta,"delta");
		HX_STACK_LINE(240)
		::String _g = ::Std_obj::string(step);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(240)
		::String _g1 = ((run_type + HX_CSTRING(" t_step = ")) + _g);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(240)
		::String _g2 = (_g1 + HX_CSTRING("\n"));		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(240)
		::String _g3 = ::Std_obj::string(delta);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(240)
		::String _g4 = (_g2 + _g3);		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(240)
		::String str = (_g4 + HX_CSTRING("\n"));		HX_STACK_VAR(str,"str");
		HX_STACK_LINE(244)
		file1->__Field(HX_CSTRING("writeString"),true)(str);
		HX_STACK_LINE(247)
		::openfl::_v2::text::TextField tf = ::openfl::_v2::text::TextField_obj::__new();		HX_STACK_VAR(tf,"tf");
		HX_STACK_LINE(248)
		tf->set_text(str);
		HX_STACK_LINE(249)
		tf->set_width((int)480);
		HX_STACK_LINE(250)
		tf->set_textColor((int)-1);
		HX_STACK_LINE(251)
		int _g5 = ::Std_obj::random((int)480);		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(251)
		tf->set_x(_g5);
		HX_STACK_LINE(252)
		int _g6 = ::Std_obj::random((int)480);		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(252)
		tf->set_y(_g6);
		HX_STACK_LINE(253)
		::openfl::_v2::Lib_obj::get_current()->addChild(tf);
		HX_STACK_LINE(255)
		::haxe::Log_obj::trace(str,hx::SourceInfo(HX_CSTRING("Main.hx"),255,HX_CSTRING("Main"),HX_CSTRING("run_calculation_and_measure_time")));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Main_obj,run_calculation_and_measure_time,(void))

Void Main_obj::main( ){
{
		HX_STACK_FRAME("Main","main",0xed0e206e,"Main.main","Main.hx",259,0x087e5c05)
		HX_STACK_LINE(260)
		::Main main = ::Main_obj::__new();		HX_STACK_VAR(main,"main");
		HX_STACK_LINE(262)
		::sys::io::FileOutput file1 = null();		HX_STACK_VAR(file1,"file1");
		HX_STACK_LINE(265)
		::sys::io::FileOutput _g = ::sys::io::File_obj::write(HX_CSTRING("results.txt"),false);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(265)
		file1 = _g;
		HX_STACK_LINE(268)
		{
			HX_STACK_LINE(268)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(268)
			Array< ::String > _g11 = Array_obj< ::String >::__new().Add(HX_CSTRING("benchmark")).Add(HX_CSTRING("regular")).Add(HX_CSTRING("test"));		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(268)
			while((true)){
				HX_STACK_LINE(268)
				if ((!(((_g1 < _g11->length))))){
					HX_STACK_LINE(268)
					break;
				}
				HX_STACK_LINE(268)
				::String run_type = _g11->__get(_g1);		HX_STACK_VAR(run_type,"run_type");
				HX_STACK_LINE(268)
				++(_g1);
				HX_STACK_LINE(270)
				if (((run_type != HX_CSTRING("test")))){
					HX_STACK_LINE(272)
					int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(272)
					Array< Float > _g3 = Array_obj< Float >::__new().Add((int)1).Add(0.1).Add(0.01);		HX_STACK_VAR(_g3,"_g3");
					HX_STACK_LINE(272)
					while((true)){
						HX_STACK_LINE(272)
						if ((!(((_g2 < _g3->length))))){
							HX_STACK_LINE(272)
							break;
						}
						HX_STACK_LINE(272)
						Float step = _g3->__get(_g2);		HX_STACK_VAR(step,"step");
						HX_STACK_LINE(272)
						++(_g2);
						HX_STACK_LINE(274)
						main->run_calculation_and_measure_time(run_type,step,file1);
					}
				}
				else{
					HX_STACK_LINE(279)
					Float step = 0.1;		HX_STACK_VAR(step,"step");
					HX_STACK_LINE(280)
					main->run_calculation_and_measure_time(run_type,step,file1);
				}
			}
		}
		HX_STACK_LINE(285)
		file1->close();
		HX_STACK_LINE(286)
		::Sys_obj::exit((int)0);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Main_obj,main,(void))


Main_obj::Main_obj()
{
}

Dynamic Main_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"R0") ) { return R0; }
		if (HX_FIELD_EQ(inName,"mu") ) { return mu; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"main") ) { return main_dyn(); }
		if (HX_FIELD_EQ(inName,"test") ) { return test_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"h_x_y") ) { return h_x_y_dyn(); }
		if (HX_FIELD_EQ(inName,"main2") ) { return main2_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"right_part") ) { return right_part_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"benchmark_test") ) { return benchmark_test_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"calculate_T_period") ) { return calculate_T_period_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"regular_calculation") ) { return regular_calculation_dyn(); }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"runge_kutta_t_state_vector") ) { return runge_kutta_t_state_vector_dyn(); }
		break;
	case 32:
		if (HX_FIELD_EQ(inName,"run_calculation_and_measure_time") ) { return run_calculation_and_measure_time_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Main_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"R0") ) { R0=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mu") ) { mu=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Main_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("R0"));
	outFields->push(HX_CSTRING("mu"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("main"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(Main_obj,R0),HX_CSTRING("R0")},
	{hx::fsFloat,(int)offsetof(Main_obj,mu),HX_CSTRING("mu")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("R0"),
	HX_CSTRING("mu"),
	HX_CSTRING("h_x_y"),
	HX_CSTRING("calculate_T_period"),
	HX_CSTRING("right_part"),
	HX_CSTRING("runge_kutta_t_state_vector"),
	HX_CSTRING("regular_calculation"),
	HX_CSTRING("benchmark_test"),
	HX_CSTRING("test"),
	HX_CSTRING("main2"),
	HX_CSTRING("run_calculation_and_measure_time"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Main_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Main_obj::__mClass,"__mClass");
};

#endif

Class Main_obj::__mClass;

void Main_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("Main"), hx::TCanCast< Main_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatics
#endif
#ifdef HXCPP_SCRIPTABLE
    , sMemberStorageInfo
#endif
);
}

void Main_obj::__boot()
{
}

