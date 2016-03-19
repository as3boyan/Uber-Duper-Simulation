#ifndef INCLUDED_de_polygonal__Printf_FloatType
#define INCLUDED_de_polygonal__Printf_FloatType

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(de,polygonal,_Printf,FloatType)
namespace de{
namespace polygonal{
namespace _Printf{


class FloatType_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef FloatType_obj OBJ_;

	public:
		FloatType_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("de.polygonal._Printf.FloatType"); }
		::String __ToString() const { return HX_CSTRING("FloatType.") + tag; }

		static ::de::polygonal::_Printf::FloatType FNatural;
		static inline ::de::polygonal::_Printf::FloatType FNatural_dyn() { return FNatural; }
		static ::de::polygonal::_Printf::FloatType FNormal;
		static inline ::de::polygonal::_Printf::FloatType FNormal_dyn() { return FNormal; }
		static ::de::polygonal::_Printf::FloatType FScientific;
		static inline ::de::polygonal::_Printf::FloatType FScientific_dyn() { return FScientific; }
};

} // end namespace de
} // end namespace polygonal
} // end namespace _Printf

#endif /* INCLUDED_de_polygonal__Printf_FloatType */ 
