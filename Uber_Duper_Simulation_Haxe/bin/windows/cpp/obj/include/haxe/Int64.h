#ifndef INCLUDED_haxe_Int64
#define INCLUDED_haxe_Int64

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(haxe,Int64)
namespace haxe{


class HXCPP_CLASS_ATTRIBUTES  Int64_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Int64_obj OBJ_;
		Int64_obj();
		Void __construct(int high,int low);

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Int64_obj > __new(int high,int low);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Int64_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("Int64"); }

		int high;
		int low;
		virtual ::String toString( );
		Dynamic toString_dyn();

		static ::haxe::Int64 sub( ::haxe::Int64 a,::haxe::Int64 b);
		static Dynamic sub_dyn();

		static Dynamic divMod( ::haxe::Int64 modulus,::haxe::Int64 divisor);
		static Dynamic divMod_dyn();

		static int uicompare( int a,int b);
		static Dynamic uicompare_dyn();

};

} // end namespace haxe

#endif /* INCLUDED_haxe_Int64 */ 
