#include <hxcpp.h>

#ifndef INCLUDED_haxe_Int64
#include <haxe/Int64.h>
#endif
namespace haxe{

Void Int64_obj::__construct(int high,int low)
{
HX_STACK_FRAME("haxe.Int64","new",0xf44bbaf7,"haxe.Int64.new","D:\\Denis\\PortableSoft\\HaxeToolkit\\haxe\\std/haxe/Int64.hx",29,0x8ed75308)
HX_STACK_THIS(this)
HX_STACK_ARG(high,"high")
HX_STACK_ARG(low,"low")
{
	HX_STACK_LINE(30)
	this->high = high;
	HX_STACK_LINE(31)
	this->low = low;
}
;
	return null();
}

//Int64_obj::~Int64_obj() { }

Dynamic Int64_obj::__CreateEmpty() { return  new Int64_obj; }
hx::ObjectPtr< Int64_obj > Int64_obj::__new(int high,int low)
{  hx::ObjectPtr< Int64_obj > result = new Int64_obj();
	result->__construct(high,low);
	return result;}

Dynamic Int64_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Int64_obj > result = new Int64_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

::String Int64_obj::toString( ){
	HX_STACK_FRAME("haxe.Int64","toString",0x676a22b5,"haxe.Int64.toString","D:\\Denis\\PortableSoft\\HaxeToolkit\\haxe\\std/haxe/Int64.hx",80,0x8ed75308)
	HX_STACK_THIS(this)
	HX_STACK_LINE(81)
	if (((((int(this->high) | int(this->low))) == (int)0))){
		HX_STACK_LINE(82)
		return HX_CSTRING("0");
	}
	HX_STACK_LINE(83)
	::String str = HX_CSTRING("");		HX_STACK_VAR(str,"str");
	HX_STACK_LINE(84)
	bool neg = false;		HX_STACK_VAR(neg,"neg");
	HX_STACK_LINE(85)
	::haxe::Int64 i = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(86)
	if (((i->high < (int)0))){
		HX_STACK_LINE(87)
		neg = true;
		HX_STACK_LINE(88)
		::haxe::Int64 _g;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(88)
		{
			HX_STACK_LINE(88)
			int high = ~(int)(i->high);		HX_STACK_VAR(high,"high");
			HX_STACK_LINE(88)
			int low = -(i->low);		HX_STACK_VAR(low,"low");
			HX_STACK_LINE(88)
			if (((low == (int)0))){
				HX_STACK_LINE(88)
				(high)++;
			}
			HX_STACK_LINE(88)
			_g = ::haxe::Int64_obj::__new(high,low);
		}
		HX_STACK_LINE(88)
		i = _g;
	}
	HX_STACK_LINE(90)
	::haxe::Int64 ten = ::haxe::Int64_obj::__new((int)0,(int)10);		HX_STACK_VAR(ten,"ten");
	HX_STACK_LINE(91)
	while((true)){
		HX_STACK_LINE(91)
		if ((!((!(((((int(i->high) | int(i->low))) == (int)0))))))){
			HX_STACK_LINE(91)
			break;
		}
		HX_STACK_LINE(92)
		Dynamic r = ::haxe::Int64_obj::divMod(i,ten);		HX_STACK_VAR(r,"r");
		HX_STACK_LINE(93)
		str = (r->__Field(HX_CSTRING("modulus"),true)->__Field(HX_CSTRING("low"),true) + str);
		HX_STACK_LINE(94)
		i = r->__Field(HX_CSTRING("quotient"),true);
	}
	HX_STACK_LINE(96)
	if ((neg)){
		HX_STACK_LINE(96)
		str = (HX_CSTRING("-") + str);
	}
	HX_STACK_LINE(97)
	return str;
}


HX_DEFINE_DYNAMIC_FUNC0(Int64_obj,toString,return )

::haxe::Int64 Int64_obj::sub( ::haxe::Int64 a,::haxe::Int64 b){
	HX_STACK_FRAME("haxe.Int64","sub",0xf44f9417,"haxe.Int64.sub","D:\\Denis\\PortableSoft\\HaxeToolkit\\haxe\\std/haxe/Int64.hx",133,0x8ed75308)
	HX_STACK_ARG(a,"a")
	HX_STACK_ARG(b,"b")
	HX_STACK_LINE(134)
	int high = (a->high - b->high);		HX_STACK_VAR(high,"high");
	HX_STACK_LINE(135)
	int low = (a->low - b->low);		HX_STACK_VAR(low,"low");
	HX_STACK_LINE(136)
	int _g = ::haxe::Int64_obj::uicompare(a->low,b->low);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(136)
	if (((_g < (int)0))){
		HX_STACK_LINE(137)
		(high)--;
	}
	HX_STACK_LINE(138)
	return ::haxe::Int64_obj::__new(high,low);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Int64_obj,sub,return )

Dynamic Int64_obj::divMod( ::haxe::Int64 modulus,::haxe::Int64 divisor){
	HX_STACK_FRAME("haxe.Int64","divMod",0x6f2287ba,"haxe.Int64.divMod","D:\\Denis\\PortableSoft\\HaxeToolkit\\haxe\\std/haxe/Int64.hx",158,0x8ed75308)
	HX_STACK_ARG(modulus,"modulus")
	HX_STACK_ARG(divisor,"divisor")
	HX_STACK_LINE(159)
	::haxe::Int64 quotient = ::haxe::Int64_obj::__new((int)0,(int)0);		HX_STACK_VAR(quotient,"quotient");
	HX_STACK_LINE(160)
	int mask_high = (int)0;		HX_STACK_VAR(mask_high,"mask_high");
	HX_STACK_LINE(160)
	int mask_low = (int)1;		HX_STACK_VAR(mask_low,"mask_low");
	HX_STACK_LINE(161)
	::haxe::Int64 _g = ::haxe::Int64_obj::__new(divisor->high,divisor->low);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(161)
	divisor = _g;
	HX_STACK_LINE(162)
	while((true)){
		HX_STACK_LINE(162)
		if ((!(((divisor->high >= (int)0))))){
			HX_STACK_LINE(162)
			break;
		}
		HX_STACK_LINE(163)
		int cmp;		HX_STACK_VAR(cmp,"cmp");
		HX_STACK_LINE(163)
		{
			HX_STACK_LINE(163)
			int v = ::haxe::Int64_obj::uicompare(divisor->high,modulus->high);		HX_STACK_VAR(v,"v");
			HX_STACK_LINE(163)
			if (((v != (int)0))){
				HX_STACK_LINE(163)
				cmp = v;
			}
			else{
				HX_STACK_LINE(163)
				cmp = ::haxe::Int64_obj::uicompare(divisor->low,modulus->low);
			}
		}
		HX_STACK_LINE(164)
		divisor->high = (int((int(divisor->high) << int((int)1))) | int(hx::UShr(divisor->low,(int)31)));
		HX_STACK_LINE(165)
		divisor->low = (int(divisor->low) << int((int)1));
		HX_STACK_LINE(166)
		mask_high = (int((int(mask_high) << int((int)1))) | int(hx::UShr(mask_low,(int)31)));
		HX_STACK_LINE(167)
		mask_low = (int(mask_low) << int((int)1));
		HX_STACK_LINE(168)
		if (((cmp >= (int)0))){
			HX_STACK_LINE(168)
			break;
		}
	}
	HX_STACK_LINE(170)
	while((true)){
		HX_STACK_LINE(170)
		if ((!(((((int(mask_low) | int(mask_high))) != (int)0))))){
			HX_STACK_LINE(170)
			break;
		}
		HX_STACK_LINE(171)
		int _g1;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(171)
		{
			HX_STACK_LINE(171)
			int v = ::haxe::Int64_obj::uicompare(modulus->high,divisor->high);		HX_STACK_VAR(v,"v");
			HX_STACK_LINE(171)
			if (((v != (int)0))){
				HX_STACK_LINE(171)
				_g1 = v;
			}
			else{
				HX_STACK_LINE(171)
				_g1 = ::haxe::Int64_obj::uicompare(modulus->low,divisor->low);
			}
		}
		HX_STACK_LINE(171)
		if (((_g1 >= (int)0))){
			HX_STACK_LINE(172)
			quotient->high = (int(quotient->high) | int(mask_high));
			HX_STACK_LINE(173)
			quotient->low = (int(quotient->low) | int(mask_low));
			HX_STACK_LINE(174)
			::haxe::Int64 _g2 = ::haxe::Int64_obj::sub(modulus,divisor);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(174)
			modulus = _g2;
		}
		HX_STACK_LINE(176)
		mask_low = (int(hx::UShr(mask_low,(int)1)) | int((int(mask_high) << int((int)31))));
		HX_STACK_LINE(177)
		mask_high = hx::UShr(mask_high,(int)1);
		HX_STACK_LINE(179)
		divisor->low = (int(hx::UShr(divisor->low,(int)1)) | int((int(divisor->high) << int((int)31))));
		HX_STACK_LINE(180)
		divisor->high = hx::UShr(divisor->high,(int)1);
	}
	struct _Function_1_1{
		inline static Dynamic Block( ::haxe::Int64 &quotient,::haxe::Int64 &modulus){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","D:\\Denis\\PortableSoft\\HaxeToolkit\\haxe\\std/haxe/Int64.hx",182,0x8ed75308)
			{
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("quotient") , quotient,false);
				__result->Add(HX_CSTRING("modulus") , modulus,false);
				return __result;
			}
			return null();
		}
	};
	HX_STACK_LINE(182)
	return _Function_1_1::Block(quotient,modulus);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Int64_obj,divMod,return )

int Int64_obj::uicompare( int a,int b){
	HX_STACK_FRAME("haxe.Int64","uicompare",0x4e5b5aa8,"haxe.Int64.uicompare","D:\\Denis\\PortableSoft\\HaxeToolkit\\haxe\\std/haxe/Int64.hx",252,0x8ed75308)
	HX_STACK_ARG(a,"a")
	HX_STACK_ARG(b,"b")
	HX_STACK_LINE(252)
	if (((a < (int)0))){
		HX_STACK_LINE(252)
		if (((b < (int)0))){
			HX_STACK_LINE(252)
			return (~(int)(b) - ~(int)(a));
		}
		else{
			HX_STACK_LINE(252)
			return (int)1;
		}
	}
	else{
		HX_STACK_LINE(252)
		if (((b < (int)0))){
			HX_STACK_LINE(252)
			return (int)-1;
		}
		else{
			HX_STACK_LINE(252)
			return (a - b);
		}
	}
	HX_STACK_LINE(252)
	return (int)0;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Int64_obj,uicompare,return )


Int64_obj::Int64_obj()
{
}

Dynamic Int64_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"sub") ) { return sub_dyn(); }
		if (HX_FIELD_EQ(inName,"low") ) { return low; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"high") ) { return high; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"divMod") ) { return divMod_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"uicompare") ) { return uicompare_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Int64_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"low") ) { low=inValue.Cast< int >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"high") ) { high=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Int64_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("high"));
	outFields->push(HX_CSTRING("low"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("sub"),
	HX_CSTRING("divMod"),
	HX_CSTRING("uicompare"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(Int64_obj,high),HX_CSTRING("high")},
	{hx::fsInt,(int)offsetof(Int64_obj,low),HX_CSTRING("low")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("high"),
	HX_CSTRING("low"),
	HX_CSTRING("toString"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Int64_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Int64_obj::__mClass,"__mClass");
};

#endif

Class Int64_obj::__mClass;

void Int64_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxe.Int64"), hx::TCanCast< Int64_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatics
#endif
#ifdef HXCPP_SCRIPTABLE
    , sMemberStorageInfo
#endif
);
}

void Int64_obj::__boot()
{
}

} // end namespace haxe
