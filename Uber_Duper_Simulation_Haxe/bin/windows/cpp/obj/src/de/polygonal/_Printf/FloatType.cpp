#include <hxcpp.h>

#ifndef INCLUDED_de_polygonal__Printf_FloatType
#include <de/polygonal/_Printf/FloatType.h>
#endif
namespace de{
namespace polygonal{
namespace _Printf{

::de::polygonal::_Printf::FloatType FloatType_obj::FNatural;

::de::polygonal::_Printf::FloatType FloatType_obj::FNormal;

::de::polygonal::_Printf::FloatType FloatType_obj::FScientific;

HX_DEFINE_CREATE_ENUM(FloatType_obj)

int FloatType_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("FNatural")) return 2;
	if (inName==HX_CSTRING("FNormal")) return 0;
	if (inName==HX_CSTRING("FScientific")) return 1;
	return super::__FindIndex(inName);
}

int FloatType_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("FNatural")) return 0;
	if (inName==HX_CSTRING("FNormal")) return 0;
	if (inName==HX_CSTRING("FScientific")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic FloatType_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("FNatural")) return FNatural;
	if (inName==HX_CSTRING("FNormal")) return FNormal;
	if (inName==HX_CSTRING("FScientific")) return FScientific;
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("FNormal"),
	HX_CSTRING("FScientific"),
	HX_CSTRING("FNatural"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FloatType_obj::FNatural,"FNatural");
	HX_MARK_MEMBER_NAME(FloatType_obj::FNormal,"FNormal");
	HX_MARK_MEMBER_NAME(FloatType_obj::FScientific,"FScientific");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FloatType_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(FloatType_obj::FNatural,"FNatural");
	HX_VISIT_MEMBER_NAME(FloatType_obj::FNormal,"FNormal");
	HX_VISIT_MEMBER_NAME(FloatType_obj::FScientific,"FScientific");
};
#endif

static ::String sMemberFields[] = { ::String(null()) };
Class FloatType_obj::__mClass;

Dynamic __Create_FloatType_obj() { return new FloatType_obj; }

void FloatType_obj::__register()
{

hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("de.polygonal._Printf.FloatType"), hx::TCanCast< FloatType_obj >,sStaticFields,sMemberFields,
	&__Create_FloatType_obj, &__Create,
	&super::__SGetClass(), &CreateFloatType_obj, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatic
#endif
#ifdef HXCPP_SCRIPTABLE
    , 0
#endif
);
}

void FloatType_obj::__boot()
{
hx::Static(FNatural) = hx::CreateEnum< FloatType_obj >(HX_CSTRING("FNatural"),2);
hx::Static(FNormal) = hx::CreateEnum< FloatType_obj >(HX_CSTRING("FNormal"),0);
hx::Static(FScientific) = hx::CreateEnum< FloatType_obj >(HX_CSTRING("FScientific"),1);
}


} // end namespace de
} // end namespace polygonal
} // end namespace _Printf
