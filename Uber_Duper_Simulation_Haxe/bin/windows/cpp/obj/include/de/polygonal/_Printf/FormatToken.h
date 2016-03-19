#ifndef INCLUDED_de_polygonal__Printf_FormatToken
#define INCLUDED_de_polygonal__Printf_FormatToken

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(de,polygonal,_Printf,FormatDataType)
HX_DECLARE_CLASS3(de,polygonal,_Printf,FormatToken)
namespace de{
namespace polygonal{
namespace _Printf{


class FormatToken_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef FormatToken_obj OBJ_;

	public:
		FormatToken_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("de.polygonal._Printf.FormatToken"); }
		::String __ToString() const { return HX_CSTRING("FormatToken.") + tag; }

		static ::de::polygonal::_Printf::FormatToken BareString(::String str);
		static Dynamic BareString_dyn();
		static ::de::polygonal::_Printf::FormatToken Property(::String name);
		static Dynamic Property_dyn();
		static ::de::polygonal::_Printf::FormatToken Tag(::de::polygonal::_Printf::FormatDataType type,Dynamic args);
		static Dynamic Tag_dyn();
		static ::de::polygonal::_Printf::FormatToken Unknown(::String str,int pos);
		static Dynamic Unknown_dyn();
};

} // end namespace de
} // end namespace polygonal
} // end namespace _Printf

#endif /* INCLUDED_de_polygonal__Printf_FormatToken */ 
