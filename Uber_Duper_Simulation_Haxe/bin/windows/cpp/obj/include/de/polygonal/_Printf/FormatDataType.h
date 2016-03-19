#ifndef INCLUDED_de_polygonal__Printf_FormatDataType
#define INCLUDED_de_polygonal__Printf_FormatDataType

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(de,polygonal,_Printf,FloatType)
HX_DECLARE_CLASS3(de,polygonal,_Printf,FormatDataType)
HX_DECLARE_CLASS3(de,polygonal,_Printf,IntegerType)
namespace de{
namespace polygonal{
namespace _Printf{


class FormatDataType_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef FormatDataType_obj OBJ_;

	public:
		FormatDataType_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("de.polygonal._Printf.FormatDataType"); }
		::String __ToString() const { return HX_CSTRING("FormatDataType.") + tag; }

		static ::de::polygonal::_Printf::FormatDataType FmtFloat(::de::polygonal::_Printf::FloatType floatType);
		static Dynamic FmtFloat_dyn();
		static ::de::polygonal::_Printf::FormatDataType FmtInteger(::de::polygonal::_Printf::IntegerType integerType);
		static Dynamic FmtInteger_dyn();
		static ::de::polygonal::_Printf::FormatDataType FmtNothing;
		static inline ::de::polygonal::_Printf::FormatDataType FmtNothing_dyn() { return FmtNothing; }
		static ::de::polygonal::_Printf::FormatDataType FmtPointer;
		static inline ::de::polygonal::_Printf::FormatDataType FmtPointer_dyn() { return FmtPointer; }
		static ::de::polygonal::_Printf::FormatDataType FmtString;
		static inline ::de::polygonal::_Printf::FormatDataType FmtString_dyn() { return FmtString; }
};

} // end namespace de
} // end namespace polygonal
} // end namespace _Printf

#endif /* INCLUDED_de_polygonal__Printf_FormatDataType */ 
