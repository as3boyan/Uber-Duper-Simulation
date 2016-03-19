#include <hxcpp.h>

#ifndef INCLUDED_de_polygonal__Printf_FormatDataType
#include <de/polygonal/_Printf/FormatDataType.h>
#endif
#ifndef INCLUDED_de_polygonal__Printf_FormatToken
#include <de/polygonal/_Printf/FormatToken.h>
#endif
namespace de{
namespace polygonal{
namespace _Printf{

::de::polygonal::_Printf::FormatToken  FormatToken_obj::BareString(::String str)
	{ return hx::CreateEnum< FormatToken_obj >(HX_CSTRING("BareString"),0,hx::DynamicArray(0,1).Add(str)); }

::de::polygonal::_Printf::FormatToken  FormatToken_obj::Property(::String name)
	{ return hx::CreateEnum< FormatToken_obj >(HX_CSTRING("Property"),2,hx::DynamicArray(0,1).Add(name)); }

::de::polygonal::_Printf::FormatToken  FormatToken_obj::Tag(::de::polygonal::_Printf::FormatDataType type,Dynamic args)
	{ return hx::CreateEnum< FormatToken_obj >(HX_CSTRING("Tag"),1,hx::DynamicArray(0,2).Add(type).Add(args)); }

::de::polygonal::_Printf::FormatToken  FormatToken_obj::Unknown(::String str,int pos)
	{ return hx::CreateEnum< FormatToken_obj >(HX_CSTRING("Unknown"),3,hx::DynamicArray(0,2).Add(str).Add(pos)); }

HX_DEFINE_CREATE_ENUM(FormatToken_obj)

int FormatToken_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("BareString")) return 0;
	if (inName==HX_CSTRING("Property")) return 2;
	if (inName==HX_CSTRING("Tag")) return 1;
	if (inName==HX_CSTRING("Unknown")) return 3;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC1(FormatToken_obj,BareString,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(FormatToken_obj,Property,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC2(FormatToken_obj,Tag,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC2(FormatToken_obj,Unknown,return)

int FormatToken_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("BareString")) return 1;
	if (inName==HX_CSTRING("Property")) return 1;
	if (inName==HX_CSTRING("Tag")) return 2;
	if (inName==HX_CSTRING("Unknown")) return 2;
	return super::__FindArgCount(inName);
}

Dynamic FormatToken_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("BareString")) return BareString_dyn();
	if (inName==HX_CSTRING("Property")) return Property_dyn();
	if (inName==HX_CSTRING("Tag")) return Tag_dyn();
	if (inName==HX_CSTRING("Unknown")) return Unknown_dyn();
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("BareString"),
	HX_CSTRING("Tag"),
	HX_CSTRING("Property"),
	HX_CSTRING("Unknown"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FormatToken_obj::__mClass,"__mClass");
};
#endif

static ::String sMemberFields[] = { ::String(null()) };
Class FormatToken_obj::__mClass;

Dynamic __Create_FormatToken_obj() { return new FormatToken_obj; }

void FormatToken_obj::__register()
{

hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("de.polygonal._Printf.FormatToken"), hx::TCanCast< FormatToken_obj >,sStaticFields,sMemberFields,
	&__Create_FormatToken_obj, &__Create,
	&super::__SGetClass(), &CreateFormatToken_obj, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatic
#endif
#ifdef HXCPP_SCRIPTABLE
    , 0
#endif
);
}

void FormatToken_obj::__boot()
{
}


} // end namespace de
} // end namespace polygonal
} // end namespace _Printf
