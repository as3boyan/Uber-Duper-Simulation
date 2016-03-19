#ifndef INCLUDED_Main
#define INCLUDED_Main

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(Main)


class HXCPP_CLASS_ATTRIBUTES  Main_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Main_obj OBJ_;
		Main_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Main_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Main_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("Main"); }

		int R0;
		Float mu;
		virtual Float h_x_y( Float x,Float y);
		Dynamic h_x_y_dyn();

		virtual Float calculate_T_period( Float R);
		Dynamic calculate_T_period_dyn();

		virtual Array< Float > right_part( Float t,Array< Float > StateVector);
		Dynamic right_part_dyn();

		virtual Array< Float > runge_kutta_t_state_vector( Float t,Array< Float > params,Float t_step,Dynamic f);
		Dynamic runge_kutta_t_state_vector_dyn();

		virtual Void regular_calculation( Float Vx,Float Vy,Float t,Float t_end,Float t_step,Float x,Float y);
		Dynamic regular_calculation_dyn();

		virtual Void benchmark_test( Float Vx,Float Vy,Float t,Float t_end,Float t_step,Float x,Float y);
		Dynamic benchmark_test_dyn();

		virtual Void test( Float Vx,Float Vy,Float t,Float t_end,Float t_step,Float x,Float y,Float R);
		Dynamic test_dyn();

		virtual Void main2( ::String type,Float step);
		Dynamic main2_dyn();

		virtual Void run_calculation_and_measure_time( ::String run_type,Float step,Dynamic file1);
		Dynamic run_calculation_and_measure_time_dyn();

		static Void main( );
		static Dynamic main_dyn();

};


#endif /* INCLUDED_Main */ 
