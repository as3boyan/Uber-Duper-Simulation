#include <hxcpp.h>

#ifndef INCLUDED_de_polygonal__Printf_FormatFlags
#include <de/polygonal/_Printf/FormatFlags.h>
#endif
namespace de{
namespace polygonal{
namespace _Printf{

::de::polygonal::_Printf::FormatFlags FormatFlags_obj::LengthH;

::de::polygonal::_Printf::FormatFlags FormatFlags_obj::LengthL;

::de::polygonal::_Printf::FormatFlags FormatFlags_obj::Lengthl;

::de::polygonal::_Printf::FormatFlags FormatFlags_obj::Minus;

::de::polygonal::_Printf::FormatFlags FormatFlags_obj::Plus;

::de::polygonal::_Printf::FormatFlags FormatFlags_obj::Sharp;

::de::polygonal::_Printf::FormatFlags FormatFlags_obj::Space;

::de::polygonal::_Printf::FormatFlags FormatFlags_obj::UpperCase;

::de::polygonal::_Printf::FormatFlags FormatFlags_obj::Zero;

HX_DEFINE_CREATE_ENUM(FormatFlags_obj)

int FormatFlags_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("LengthH")) return 5;
	if (inName==HX_CSTRING("LengthL")) return 6;
	if (inName==HX_CSTRING("Lengthl")) return 7;
	if (inName==HX_CSTRING("Minus")) return 0;
	if (inName==HX_CSTRING("Plus")) return 1;
	if (inName==HX_CSTRING("Sharp")) return 3;
	if (inName==HX_CSTRING("Space")) return 2;
	if (inName==HX_CSTRING("UpperCase")) return 8;
	if (inName==HX_CSTRING("Zero")) return 4;
	return super::__FindIndex(inName);
}

int FormatFlags_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("LengthH")) return 0;
	if (inName==HX_CSTRING("LengthL")) return 0;
	if (inName==HX_CSTRING("Lengthl")) return 0;
	if (inName==HX_CSTRING("Minus")) return 0;
	if (inName==HX_CSTRING("Plus")) return 0;
	if (inName==HX_CSTRING("Sharp")) return 0;
	if (inName==HX_CSTRING("Space")) return 0;
	if (inName==HX_CSTRING("UpperCase")) return 0;
	if (inName==HX_CSTRING("Zero")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic FormatFlags_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("LengthH")) return LengthH;
	if (inName==HX_CSTRING("LengthL")) return LengthL;
	if (inName==HX_CSTRING("Lengthl")) return Lengthl;
	if (inName==HX_CSTRING("Minus")) return Minus;
	if (inName==HX_CSTRING("Plus")) return Plus;
	if (inName==HX_CSTRING("Sharp")) return Sharp;
	if (inName==HX_CSTRING("Space")) return Space;
	if (inName==HX_CSTRING("UpperCase")) return UpperCase;
	if (inName==HX_CSTRING("Zero")) return Zero;
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("Minus"),
	HX_CSTRING("Plus"),
	HX_CSTRING("Space"),
	HX_CSTRING("Sharp"),
	HX_CSTRING("Zero"),
	HX_CSTRING("LengthH"),
	HX_CSTRING("LengthL"),
	HX_CSTRING("Lengthl"),
	HX_CSTRING("UpperCase"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FormatFlags_obj::LengthH,"LengthH");
	HX_MARK_MEMBER_NAME(FormatFlags_obj::LengthL,"LengthL");
	HX_MARK_MEMBER_NAME(FormatFlags_obj::Lengthl,"Lengthl");
	HX_MARK_MEMBER_NAME(FormatFlags_obj::Minus,"Minus");
	HX_MARK_MEMBER_NAME(FormatFlags_obj::Plus,"Plus");
	HX_MARK_MEMBER_NAME(FormatFlags_obj::Sharp,"Sharp");
	HX_MARK_MEMBER_NAME(FormatFlags_obj::Space,"Space");
	HX_MARK_MEMBER_NAME(FormatFlags_obj::UpperCase,"UpperCase");
	HX_MARK_MEMBER_NAME(FormatFlags_obj::Zero,"Zero");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FormatFlags_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(FormatFlags_obj::LengthH,"LengthH");
	HX_VISIT_MEMBER_NAME(FormatFlags_obj::LengthL,"LengthL");
	HX_VISIT_MEMBER_NAME(FormatFlags_obj::Lengthl,"Lengthl");
	HX_VISIT_MEMBER_NAME(FormatFlags_obj::Minus,"Minus");
	HX_VISIT_MEMBER_NAME(FormatFlags_obj::Plus,"Plus");
	HX_VISIT_MEMBER_NAME(FormatFlags_obj::Sharp,"Sharp");
	HX_VISIT_MEMBER_NAME(FormatFlags_obj::Space,"Space");
	HX_VISIT_MEMBER_NAME(FormatFlags_obj::UpperCase,"UpperCase");
	HX_VISIT_MEMBER_NAME(FormatFlags_obj::Zero,"Zero");
};
#endif

static ::String sMemberFields[] = { ::String(null()) };
Class FormatFlags_obj::__mClass;

Dynamic __Create_FormatFlags_obj() { return new FormatFlags_obj; }

void FormatFlags_obj::__register()
{

hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("de.polygonal._Printf.FormatFlags"), hx::TCanCast< FormatFlags_obj >,sStaticFields,sMemberFields,
	&__Create_FormatFlags_obj, &__Create,
	&super::__SGetClass(), &CreateFormatFlags_obj, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatic
#endif
#ifdef HXCPP_SCRIPTABLE
    , 0
#endif
);
}

void FormatFlags_obj::__boot()
{
hx::Static(LengthH) = hx::CreateEnum< FormatFlags_obj >(HX_CSTRING("LengthH"),5);
hx::Static(LengthL) = hx::CreateEnum< FormatFlags_obj >(HX_CSTRING("LengthL"),6);
hx::Static(Lengthl) = hx::CreateEnum< FormatFlags_obj >(HX_CSTRING("Lengthl"),7);
hx::Static(Minus) = hx::CreateEnum< FormatFlags_obj >(HX_CSTRING("Minus"),0);
hx::Static(Plus) = hx::CreateEnum< FormatFlags_obj >(HX_CSTRING("Plus"),1);
hx::Static(Sharp) = hx::CreateEnum< FormatFlags_obj >(HX_CSTRING("Sharp"),3);
hx::Static(Space) = hx::CreateEnum< FormatFlags_obj >(HX_CSTRING("Space"),2);
hx::Static(UpperCase) = hx::CreateEnum< FormatFlags_obj >(HX_CSTRING("UpperCase"),8);
hx::Static(Zero) = hx::CreateEnum< FormatFlags_obj >(HX_CSTRING("Zero"),4);
}


} // end namespace de
} // end namespace polygonal
} // end namespace _Printf
