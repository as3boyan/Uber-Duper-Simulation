#include <hxcpp.h>

#ifndef INCLUDED_de_polygonal__Printf_FloatType
#include <de/polygonal/_Printf/FloatType.h>
#endif
#ifndef INCLUDED_de_polygonal__Printf_FormatDataType
#include <de/polygonal/_Printf/FormatDataType.h>
#endif
#ifndef INCLUDED_de_polygonal__Printf_IntegerType
#include <de/polygonal/_Printf/IntegerType.h>
#endif
namespace de{
namespace polygonal{
namespace _Printf{

::de::polygonal::_Printf::FormatDataType  FormatDataType_obj::FmtFloat(::de::polygonal::_Printf::FloatType floatType)
	{ return hx::CreateEnum< FormatDataType_obj >(HX_CSTRING("FmtFloat"),1,hx::DynamicArray(0,1).Add(floatType)); }

::de::polygonal::_Printf::FormatDataType  FormatDataType_obj::FmtInteger(::de::polygonal::_Printf::IntegerType integerType)
	{ return hx::CreateEnum< FormatDataType_obj >(HX_CSTRING("FmtInteger"),0,hx::DynamicArray(0,1).Add(integerType)); }

::de::polygonal::_Printf::FormatDataType FormatDataType_obj::FmtNothing;

::de::polygonal::_Printf::FormatDataType FormatDataType_obj::FmtPointer;

::de::polygonal::_Printf::FormatDataType FormatDataType_obj::FmtString;

HX_DEFINE_CREATE_ENUM(FormatDataType_obj)

int FormatDataType_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("FmtFloat")) return 1;
	if (inName==HX_CSTRING("FmtInteger")) return 0;
	if (inName==HX_CSTRING("FmtNothing")) return 4;
	if (inName==HX_CSTRING("FmtPointer")) return 3;
	if (inName==HX_CSTRING("FmtString")) return 2;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC1(FormatDataType_obj,FmtFloat,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(FormatDataType_obj,FmtInteger,return)

int FormatDataType_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("FmtFloat")) return 1;
	if (inName==HX_CSTRING("FmtInteger")) return 1;
	if (inName==HX_CSTRING("FmtNothing")) return 0;
	if (inName==HX_CSTRING("FmtPointer")) return 0;
	if (inName==HX_CSTRING("FmtString")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic FormatDataType_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("FmtFloat")) return FmtFloat_dyn();
	if (inName==HX_CSTRING("FmtInteger")) return FmtInteger_dyn();
	if (inName==HX_CSTRING("FmtNothing")) return FmtNothing;
	if (inName==HX_CSTRING("FmtPointer")) return FmtPointer;
	if (inName==HX_CSTRING("FmtString")) return FmtString;
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("FmtInteger"),
	HX_CSTRING("FmtFloat"),
	HX_CSTRING("FmtString"),
	HX_CSTRING("FmtPointer"),
	HX_CSTRING("FmtNothing"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FormatDataType_obj::FmtNothing,"FmtNothing");
	HX_MARK_MEMBER_NAME(FormatDataType_obj::FmtPointer,"FmtPointer");
	HX_MARK_MEMBER_NAME(FormatDataType_obj::FmtString,"FmtString");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FormatDataType_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(FormatDataType_obj::FmtNothing,"FmtNothing");
	HX_VISIT_MEMBER_NAME(FormatDataType_obj::FmtPointer,"FmtPointer");
	HX_VISIT_MEMBER_NAME(FormatDataType_obj::FmtString,"FmtString");
};
#endif

static ::String sMemberFields[] = { ::String(null()) };
Class FormatDataType_obj::__mClass;

Dynamic __Create_FormatDataType_obj() { return new FormatDataType_obj; }

void FormatDataType_obj::__register()
{

hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("de.polygonal._Printf.FormatDataType"), hx::TCanCast< FormatDataType_obj >,sStaticFields,sMemberFields,
	&__Create_FormatDataType_obj, &__Create,
	&super::__SGetClass(), &CreateFormatDataType_obj, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatic
#endif
#ifdef HXCPP_SCRIPTABLE
    , 0
#endif
);
}

void FormatDataType_obj::__boot()
{
hx::Static(FmtNothing) = hx::CreateEnum< FormatDataType_obj >(HX_CSTRING("FmtNothing"),4);
hx::Static(FmtPointer) = hx::CreateEnum< FormatDataType_obj >(HX_CSTRING("FmtPointer"),3);
hx::Static(FmtString) = hx::CreateEnum< FormatDataType_obj >(HX_CSTRING("FmtString"),2);
}


} // end namespace de
} // end namespace polygonal
} // end namespace _Printf
