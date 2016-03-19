#ifndef INCLUDED_de_polygonal__Printf_FormatFlags
#define INCLUDED_de_polygonal__Printf_FormatFlags

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(de,polygonal,_Printf,FormatFlags)
namespace de{
namespace polygonal{
namespace _Printf{


class FormatFlags_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef FormatFlags_obj OBJ_;

	public:
		FormatFlags_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("de.polygonal._Printf.FormatFlags"); }
		::String __ToString() const { return HX_CSTRING("FormatFlags.") + tag; }

		static ::de::polygonal::_Printf::FormatFlags LengthH;
		static inline ::de::polygonal::_Printf::FormatFlags LengthH_dyn() { return LengthH; }
		static ::de::polygonal::_Printf::FormatFlags LengthL;
		static inline ::de::polygonal::_Printf::FormatFlags LengthL_dyn() { return LengthL; }
		static ::de::polygonal::_Printf::FormatFlags Lengthl;
		static inline ::de::polygonal::_Printf::FormatFlags Lengthl_dyn() { return Lengthl; }
		static ::de::polygonal::_Printf::FormatFlags Minus;
		static inline ::de::polygonal::_Printf::FormatFlags Minus_dyn() { return Minus; }
		static ::de::polygonal::_Printf::FormatFlags Plus;
		static inline ::de::polygonal::_Printf::FormatFlags Plus_dyn() { return Plus; }
		static ::de::polygonal::_Printf::FormatFlags Sharp;
		static inline ::de::polygonal::_Printf::FormatFlags Sharp_dyn() { return Sharp; }
		static ::de::polygonal::_Printf::FormatFlags Space;
		static inline ::de::polygonal::_Printf::FormatFlags Space_dyn() { return Space; }
		static ::de::polygonal::_Printf::FormatFlags UpperCase;
		static inline ::de::polygonal::_Printf::FormatFlags UpperCase_dyn() { return UpperCase; }
		static ::de::polygonal::_Printf::FormatFlags Zero;
		static inline ::de::polygonal::_Printf::FormatFlags Zero_dyn() { return Zero; }
};

} // end namespace de
} // end namespace polygonal
} // end namespace _Printf

#endif /* INCLUDED_de_polygonal__Printf_FormatFlags */ 
