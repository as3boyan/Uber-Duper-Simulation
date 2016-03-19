#include <hxcpp.h>

#ifndef INCLUDED_de_polygonal__Printf_IntegerType
#include <de/polygonal/_Printf/IntegerType.h>
#endif
namespace de{
namespace polygonal{
namespace _Printf{

::de::polygonal::_Printf::IntegerType IntegerType_obj::IBin;

::de::polygonal::_Printf::IntegerType IntegerType_obj::ICharacter;

::de::polygonal::_Printf::IntegerType IntegerType_obj::IHex;

::de::polygonal::_Printf::IntegerType IntegerType_obj::IOctal;

::de::polygonal::_Printf::IntegerType IntegerType_obj::ISignedDecimal;

::de::polygonal::_Printf::IntegerType IntegerType_obj::IUnsignedDecimal;

HX_DEFINE_CREATE_ENUM(IntegerType_obj)

int IntegerType_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("IBin")) return 5;
	if (inName==HX_CSTRING("ICharacter")) return 0;
	if (inName==HX_CSTRING("IHex")) return 4;
	if (inName==HX_CSTRING("IOctal")) return 3;
	if (inName==HX_CSTRING("ISignedDecimal")) return 1;
	if (inName==HX_CSTRING("IUnsignedDecimal")) return 2;
	return super::__FindIndex(inName);
}

int IntegerType_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("IBin")) return 0;
	if (inName==HX_CSTRING("ICharacter")) return 0;
	if (inName==HX_CSTRING("IHex")) return 0;
	if (inName==HX_CSTRING("IOctal")) return 0;
	if (inName==HX_CSTRING("ISignedDecimal")) return 0;
	if (inName==HX_CSTRING("IUnsignedDecimal")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic IntegerType_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("IBin")) return IBin;
	if (inName==HX_CSTRING("ICharacter")) return ICharacter;
	if (inName==HX_CSTRING("IHex")) return IHex;
	if (inName==HX_CSTRING("IOctal")) return IOctal;
	if (inName==HX_CSTRING("ISignedDecimal")) return ISignedDecimal;
	if (inName==HX_CSTRING("IUnsignedDecimal")) return IUnsignedDecimal;
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("ICharacter"),
	HX_CSTRING("ISignedDecimal"),
	HX_CSTRING("IUnsignedDecimal"),
	HX_CSTRING("IOctal"),
	HX_CSTRING("IHex"),
	HX_CSTRING("IBin"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(IntegerType_obj::IBin,"IBin");
	HX_MARK_MEMBER_NAME(IntegerType_obj::ICharacter,"ICharacter");
	HX_MARK_MEMBER_NAME(IntegerType_obj::IHex,"IHex");
	HX_MARK_MEMBER_NAME(IntegerType_obj::IOctal,"IOctal");
	HX_MARK_MEMBER_NAME(IntegerType_obj::ISignedDecimal,"ISignedDecimal");
	HX_MARK_MEMBER_NAME(IntegerType_obj::IUnsignedDecimal,"IUnsignedDecimal");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(IntegerType_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(IntegerType_obj::IBin,"IBin");
	HX_VISIT_MEMBER_NAME(IntegerType_obj::ICharacter,"ICharacter");
	HX_VISIT_MEMBER_NAME(IntegerType_obj::IHex,"IHex");
	HX_VISIT_MEMBER_NAME(IntegerType_obj::IOctal,"IOctal");
	HX_VISIT_MEMBER_NAME(IntegerType_obj::ISignedDecimal,"ISignedDecimal");
	HX_VISIT_MEMBER_NAME(IntegerType_obj::IUnsignedDecimal,"IUnsignedDecimal");
};
#endif

static ::String sMemberFields[] = { ::String(null()) };
Class IntegerType_obj::__mClass;

Dynamic __Create_IntegerType_obj() { return new IntegerType_obj; }

void IntegerType_obj::__register()
{

hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("de.polygonal._Printf.IntegerType"), hx::TCanCast< IntegerType_obj >,sStaticFields,sMemberFields,
	&__Create_IntegerType_obj, &__Create,
	&super::__SGetClass(), &CreateIntegerType_obj, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatic
#endif
#ifdef HXCPP_SCRIPTABLE
    , 0
#endif
);
}

void IntegerType_obj::__boot()
{
hx::Static(IBin) = hx::CreateEnum< IntegerType_obj >(HX_CSTRING("IBin"),5);
hx::Static(ICharacter) = hx::CreateEnum< IntegerType_obj >(HX_CSTRING("ICharacter"),0);
hx::Static(IHex) = hx::CreateEnum< IntegerType_obj >(HX_CSTRING("IHex"),4);
hx::Static(IOctal) = hx::CreateEnum< IntegerType_obj >(HX_CSTRING("IOctal"),3);
hx::Static(ISignedDecimal) = hx::CreateEnum< IntegerType_obj >(HX_CSTRING("ISignedDecimal"),1);
hx::Static(IUnsignedDecimal) = hx::CreateEnum< IntegerType_obj >(HX_CSTRING("IUnsignedDecimal"),2);
}


} // end namespace de
} // end namespace polygonal
} // end namespace _Printf
