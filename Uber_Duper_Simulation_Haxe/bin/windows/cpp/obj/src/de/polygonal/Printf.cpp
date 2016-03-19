#include <hxcpp.h>

#ifndef INCLUDED_IMap
#include <IMap.h>
#endif
#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_StringBuf
#include <StringBuf.h>
#endif
#ifndef INCLUDED_de_polygonal_Printf
#include <de/polygonal/Printf.h>
#endif
#ifndef INCLUDED_de_polygonal__Printf_FloatType
#include <de/polygonal/_Printf/FloatType.h>
#endif
#ifndef INCLUDED_de_polygonal__Printf_FormatDataType
#include <de/polygonal/_Printf/FormatDataType.h>
#endif
#ifndef INCLUDED_de_polygonal__Printf_FormatFlags
#include <de/polygonal/_Printf/FormatFlags.h>
#endif
#ifndef INCLUDED_de_polygonal__Printf_FormatToken
#include <de/polygonal/_Printf/FormatToken.h>
#endif
#ifndef INCLUDED_de_polygonal__Printf_IntegerType
#include <de/polygonal/_Printf/IntegerType.h>
#endif
#ifndef INCLUDED_haxe_Int64
#include <haxe/Int64.h>
#endif
#ifndef INCLUDED_haxe_ds_IntMap
#include <haxe/ds/IntMap.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace de{
namespace polygonal{

Void Printf_obj::__construct()
{
	return null();
}

//Printf_obj::~Printf_obj() { }

Dynamic Printf_obj::__CreateEmpty() { return  new Printf_obj; }
hx::ObjectPtr< Printf_obj > Printf_obj::__new()
{  hx::ObjectPtr< Printf_obj > result = new Printf_obj();
	result->__construct();
	return result;}

Dynamic Printf_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Printf_obj > result = new Printf_obj();
	result->__construct();
	return result;}

::haxe::ds::IntMap Printf_obj::dataTypeMap;

::haxe::ds::IntMap Printf_obj::formatIntFuncHash;

::haxe::ds::IntMap Printf_obj::formatFloatFuncHash;

::haxe::ds::IntMap Printf_obj::formatStringFuncHash;

bool Printf_obj::_initialized;

Void Printf_obj::init( ){
{
		HX_STACK_FRAME("de.polygonal.Printf","init",0x8a4a852f,"de.polygonal.Printf.init","de/polygonal/Printf.hx",62,0x0b01abed)
		HX_STACK_LINE(63)
		::haxe::ds::IntMap _g = ::de::polygonal::Printf_obj::makeDataTypeMap();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(63)
		::de::polygonal::Printf_obj::dataTypeMap = _g;
		HX_STACK_LINE(65)
		::haxe::ds::IntMap _g1 = ::haxe::ds::IntMap_obj::__new();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(65)
		::de::polygonal::Printf_obj::formatIntFuncHash = _g1;
		HX_STACK_LINE(66)
		::de::polygonal::Printf_obj::formatIntFuncHash->set((int)1,::de::polygonal::Printf_obj::formatSignedDecimal_dyn());
		HX_STACK_LINE(67)
		::de::polygonal::Printf_obj::formatIntFuncHash->set((int)2,::de::polygonal::Printf_obj::formatUnsignedDecimal_dyn());
		HX_STACK_LINE(68)
		::de::polygonal::Printf_obj::formatIntFuncHash->set((int)0,::de::polygonal::Printf_obj::formatCharacter_dyn());
		HX_STACK_LINE(69)
		::de::polygonal::Printf_obj::formatIntFuncHash->set((int)4,::de::polygonal::Printf_obj::formatHexadecimal_dyn());
		HX_STACK_LINE(70)
		::de::polygonal::Printf_obj::formatIntFuncHash->set((int)3,::de::polygonal::Printf_obj::formatOctal_dyn());
		HX_STACK_LINE(71)
		::de::polygonal::Printf_obj::formatIntFuncHash->set((int)5,::de::polygonal::Printf_obj::formatBinary_dyn());
		HX_STACK_LINE(73)
		::haxe::ds::IntMap _g2 = ::haxe::ds::IntMap_obj::__new();		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(73)
		::de::polygonal::Printf_obj::formatFloatFuncHash = _g2;
		HX_STACK_LINE(74)
		::de::polygonal::Printf_obj::formatFloatFuncHash->set((int)0,::de::polygonal::Printf_obj::formatNormalFloat_dyn());
		HX_STACK_LINE(75)
		::de::polygonal::Printf_obj::formatFloatFuncHash->set((int)1,::de::polygonal::Printf_obj::formatScientific_dyn());
		HX_STACK_LINE(76)
		::de::polygonal::Printf_obj::formatFloatFuncHash->set((int)2,::de::polygonal::Printf_obj::formatNaturalFloat_dyn());
		HX_STACK_LINE(78)
		::haxe::ds::IntMap _g3 = ::haxe::ds::IntMap_obj::__new();		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(78)
		::de::polygonal::Printf_obj::formatStringFuncHash = _g3;
		HX_STACK_LINE(79)
		::de::polygonal::Printf_obj::formatStringFuncHash->set((int)2,::de::polygonal::Printf_obj::formatString_dyn());
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Printf_obj,init,(void))

::haxe::ds::IntMap Printf_obj::makeDataTypeMap( ){
	HX_STACK_FRAME("de.polygonal.Printf","makeDataTypeMap",0x2d5e2feb,"de.polygonal.Printf.makeDataTypeMap","de/polygonal/Printf.hx",108,0x0b01abed)
	HX_STACK_LINE(109)
	::haxe::ds::IntMap hash = ::haxe::ds::IntMap_obj::__new();		HX_STACK_VAR(hash,"hash");
	HX_STACK_LINE(110)
	::de::polygonal::_Printf::FormatDataType _g = ::de::polygonal::_Printf::FormatDataType_obj::FmtInteger(::de::polygonal::_Printf::IntegerType_obj::ISignedDecimal);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(110)
	hash->set((int)105,_g);
	HX_STACK_LINE(111)
	::de::polygonal::_Printf::FormatDataType _g1 = ::de::polygonal::_Printf::FormatDataType_obj::FmtInteger(::de::polygonal::_Printf::IntegerType_obj::ISignedDecimal);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(111)
	hash->set((int)100,_g1);
	HX_STACK_LINE(112)
	::de::polygonal::_Printf::FormatDataType _g2 = ::de::polygonal::_Printf::FormatDataType_obj::FmtInteger(::de::polygonal::_Printf::IntegerType_obj::IUnsignedDecimal);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(112)
	hash->set((int)117,_g2);
	HX_STACK_LINE(113)
	::de::polygonal::_Printf::FormatDataType _g3 = ::de::polygonal::_Printf::FormatDataType_obj::FmtInteger(::de::polygonal::_Printf::IntegerType_obj::ICharacter);		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(113)
	hash->set((int)99,_g3);
	HX_STACK_LINE(114)
	::de::polygonal::_Printf::FormatDataType _g4 = ::de::polygonal::_Printf::FormatDataType_obj::FmtInteger(::de::polygonal::_Printf::IntegerType_obj::IHex);		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(114)
	hash->set((int)120,_g4);
	HX_STACK_LINE(115)
	::de::polygonal::_Printf::FormatDataType _g5 = ::de::polygonal::_Printf::FormatDataType_obj::FmtInteger(::de::polygonal::_Printf::IntegerType_obj::IHex);		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(115)
	hash->set((int)88,_g5);
	HX_STACK_LINE(116)
	::de::polygonal::_Printf::FormatDataType _g6 = ::de::polygonal::_Printf::FormatDataType_obj::FmtInteger(::de::polygonal::_Printf::IntegerType_obj::IOctal);		HX_STACK_VAR(_g6,"_g6");
	HX_STACK_LINE(116)
	hash->set((int)111,_g6);
	HX_STACK_LINE(117)
	::de::polygonal::_Printf::FormatDataType _g7 = ::de::polygonal::_Printf::FormatDataType_obj::FmtInteger(::de::polygonal::_Printf::IntegerType_obj::IBin);		HX_STACK_VAR(_g7,"_g7");
	HX_STACK_LINE(117)
	hash->set((int)98,_g7);
	HX_STACK_LINE(119)
	::de::polygonal::_Printf::FormatDataType _g8 = ::de::polygonal::_Printf::FormatDataType_obj::FmtFloat(::de::polygonal::_Printf::FloatType_obj::FNormal);		HX_STACK_VAR(_g8,"_g8");
	HX_STACK_LINE(119)
	hash->set((int)102,_g8);
	HX_STACK_LINE(120)
	::de::polygonal::_Printf::FormatDataType _g9 = ::de::polygonal::_Printf::FormatDataType_obj::FmtFloat(::de::polygonal::_Printf::FloatType_obj::FScientific);		HX_STACK_VAR(_g9,"_g9");
	HX_STACK_LINE(120)
	hash->set((int)101,_g9);
	HX_STACK_LINE(121)
	::de::polygonal::_Printf::FormatDataType _g10 = ::de::polygonal::_Printf::FormatDataType_obj::FmtFloat(::de::polygonal::_Printf::FloatType_obj::FScientific);		HX_STACK_VAR(_g10,"_g10");
	HX_STACK_LINE(121)
	hash->set((int)69,_g10);
	HX_STACK_LINE(122)
	::de::polygonal::_Printf::FormatDataType _g11 = ::de::polygonal::_Printf::FormatDataType_obj::FmtFloat(::de::polygonal::_Printf::FloatType_obj::FNatural);		HX_STACK_VAR(_g11,"_g11");
	HX_STACK_LINE(122)
	hash->set((int)103,_g11);
	HX_STACK_LINE(123)
	::de::polygonal::_Printf::FormatDataType _g12 = ::de::polygonal::_Printf::FormatDataType_obj::FmtFloat(::de::polygonal::_Printf::FloatType_obj::FNatural);		HX_STACK_VAR(_g12,"_g12");
	HX_STACK_LINE(123)
	hash->set((int)71,_g12);
	HX_STACK_LINE(125)
	hash->set((int)115,::de::polygonal::_Printf::FormatDataType_obj::FmtString);
	HX_STACK_LINE(127)
	hash->set((int)112,::de::polygonal::_Printf::FormatDataType_obj::FmtPointer);
	HX_STACK_LINE(128)
	hash->set((int)110,::de::polygonal::_Printf::FormatDataType_obj::FmtNothing);
	HX_STACK_LINE(130)
	return hash;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Printf_obj,makeDataTypeMap,return )

::String Printf_obj::format( ::String fmt,Dynamic args){
	HX_STACK_FRAME("de.polygonal.Printf","format",0xfc1bdf16,"de.polygonal.Printf.format","de/polygonal/Printf.hx",549,0x0b01abed)
	HX_STACK_ARG(fmt,"fmt")
	HX_STACK_ARG(args,"args")
	HX_STACK_LINE(550)
	if ((!(::de::polygonal::Printf_obj::_initialized))){
		HX_STACK_LINE(552)
		::de::polygonal::Printf_obj::_initialized = true;
		HX_STACK_LINE(553)
		::de::polygonal::Printf_obj::init();
	}
	HX_STACK_LINE(556)
	{
		HX_STACK_LINE(556)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(556)
		int _g = args->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(556)
		while((true)){
			HX_STACK_LINE(556)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(556)
				break;
			}
			HX_STACK_LINE(556)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(557)
			if (((args->__GetItem(i) == null()))){
				HX_STACK_LINE(558)
				hx::IndexRef((args).mPtr,i) = HX_CSTRING("null");
			}
		}
	}
	HX_STACK_LINE(560)
	::String output = HX_CSTRING("");		HX_STACK_VAR(output,"output");
	HX_STACK_LINE(561)
	int argIndex = (int)0;		HX_STACK_VAR(argIndex,"argIndex");
	HX_STACK_LINE(562)
	Array< ::Dynamic > tokens = ::de::polygonal::Printf_obj::tokenize(fmt);		HX_STACK_VAR(tokens,"tokens");
	HX_STACK_LINE(563)
	{
		HX_STACK_LINE(563)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(563)
		while((true)){
			HX_STACK_LINE(563)
			if ((!(((_g < tokens->length))))){
				HX_STACK_LINE(563)
				break;
			}
			HX_STACK_LINE(563)
			::de::polygonal::_Printf::FormatToken token = tokens->__get(_g).StaticCast< ::de::polygonal::_Printf::FormatToken >();		HX_STACK_VAR(token,"token");
			HX_STACK_LINE(563)
			++(_g);
			HX_STACK_LINE(565)
			switch( (int)(token->__Index())){
				case (int)3: {
					HX_STACK_LINE(568)
					HX_STACK_DO_THROW(HX_CSTRING("invalid format specifier"));
				}
				;break;
				case (int)0: {
					HX_STACK_LINE(565)
					::String str = (::de::polygonal::_Printf::FormatToken(token))->__Param(0);		HX_STACK_VAR(str,"str");
					HX_STACK_LINE(571)
					hx::AddEq(output,str);
				}
				;break;
				case (int)2: {
					HX_STACK_LINE(565)
					::String name = (::de::polygonal::_Printf::FormatToken(token))->__Param(0);		HX_STACK_VAR(name,"name");
					HX_STACK_LINE(573)
					{
						HX_STACK_LINE(574)
						if ((!(::Reflect_obj::hasField(args->__GetItem((int)0),name)))){
							HX_STACK_LINE(575)
							HX_STACK_DO_THROW((HX_CSTRING("no field named ") + name));
						}
						HX_STACK_LINE(576)
						Dynamic _g1 = ::Reflect_obj::field(args->__GetItem((int)0),name);		HX_STACK_VAR(_g1,"_g1");
						HX_STACK_LINE(576)
						::String _g11 = ::Std_obj::string(_g1);		HX_STACK_VAR(_g11,"_g11");
						HX_STACK_LINE(576)
						hx::AddEq(output,_g11);
					}
				}
				;break;
				case (int)1: {
					HX_STACK_LINE(565)
					Dynamic tagArgs = (::de::polygonal::_Printf::FormatToken(token))->__Param(1);		HX_STACK_VAR(tagArgs,"tagArgs");
					HX_STACK_LINE(565)
					::de::polygonal::_Printf::FormatDataType type = (::de::polygonal::_Printf::FormatToken(token))->__Param(0);		HX_STACK_VAR(type,"type");
					HX_STACK_LINE(578)
					{
						HX_STACK_LINE(579)
						Dynamic _g3;		HX_STACK_VAR(_g3,"_g3");
						HX_STACK_LINE(579)
						if (((tagArgs->__Field(HX_CSTRING("width"),true) != null()))){
							HX_STACK_LINE(579)
							_g3 = tagArgs->__Field(HX_CSTRING("width"),true);
						}
						else{
							HX_STACK_LINE(579)
							int _g2 = (argIndex)++;		HX_STACK_VAR(_g2,"_g2");
							HX_STACK_LINE(579)
							_g3 = hx::TCast< Int >::cast(args->__GetItem(_g2));
						}
						HX_STACK_LINE(579)
						tagArgs->__FieldRef(HX_CSTRING("width")) = _g3;
						HX_STACK_LINE(580)
						Dynamic _g5;		HX_STACK_VAR(_g5,"_g5");
						HX_STACK_LINE(580)
						if (((tagArgs->__Field(HX_CSTRING("precision"),true) != null()))){
							HX_STACK_LINE(580)
							_g5 = tagArgs->__Field(HX_CSTRING("precision"),true);
						}
						else{
							HX_STACK_LINE(580)
							int _g4 = (argIndex)++;		HX_STACK_VAR(_g4,"_g4");
							HX_STACK_LINE(580)
							_g5 = hx::TCast< Int >::cast(args->__GetItem(_g4));
						}
						HX_STACK_LINE(580)
						tagArgs->__FieldRef(HX_CSTRING("precision")) = _g5;
						HX_STACK_LINE(581)
						int _g6 = (argIndex)++;		HX_STACK_VAR(_g6,"_g6");
						HX_STACK_LINE(581)
						Dynamic value = args->__GetItem(_g6);		HX_STACK_VAR(value,"value");
						HX_STACK_LINE(583)
						Dynamic formatFunction;		HX_STACK_VAR(formatFunction,"formatFunction");
						HX_STACK_LINE(585)
						switch( (int)(type->__Index())){
							case (int)1: {
								HX_STACK_LINE(585)
								::de::polygonal::_Printf::FloatType floatType = (::de::polygonal::_Printf::FormatDataType(type))->__Param(0);		HX_STACK_VAR(floatType,"floatType");
								HX_STACK_LINE(587)
								{
									HX_STACK_LINE(588)
									int _g7 = floatType->__Index();		HX_STACK_VAR(_g7,"_g7");
									HX_STACK_LINE(588)
									Dynamic _g8 = ::de::polygonal::Printf_obj::formatFloatFuncHash->get(_g7);		HX_STACK_VAR(_g8,"_g8");
									HX_STACK_LINE(588)
									formatFunction = _g8;
								}
							}
							;break;
							case (int)0: {
								HX_STACK_LINE(585)
								::de::polygonal::_Printf::IntegerType integerType = (::de::polygonal::_Printf::FormatDataType(type))->__Param(0);		HX_STACK_VAR(integerType,"integerType");
								HX_STACK_LINE(590)
								{
									HX_STACK_LINE(591)
									int _g9 = integerType->__Index();		HX_STACK_VAR(_g9,"_g9");
									HX_STACK_LINE(591)
									Dynamic _g10 = ::de::polygonal::Printf_obj::formatIntFuncHash->get(_g9);		HX_STACK_VAR(_g10,"_g10");
									HX_STACK_LINE(591)
									formatFunction = _g10;
								}
							}
							;break;
							case (int)2: {
								HX_STACK_LINE(594)
								Dynamic _g11 = ::de::polygonal::Printf_obj::formatStringFuncHash->get((int)2);		HX_STACK_VAR(_g11,"_g11");
								HX_STACK_LINE(594)
								formatFunction = _g11;
							}
							;break;
							case (int)3: {
								HX_STACK_LINE(597)
								HX_STACK_DO_THROW(HX_CSTRING("specifier 'p' is not supported"));
							}
							;break;
							case (int)4: {
								HX_STACK_LINE(600)
								HX_STACK_DO_THROW(HX_CSTRING("specifier 'n' is not supported"));
							}
							;break;
						}
						HX_STACK_LINE(603)
						::String _g12 = formatFunction(value,tagArgs).Cast< ::String >();		HX_STACK_VAR(_g12,"_g12");
						HX_STACK_LINE(603)
						hx::AddEq(output,_g12);
					}
				}
				;break;
			}
		}
	}
	HX_STACK_LINE(606)
	return output;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Printf_obj,format,return )

Array< ::Dynamic > Printf_obj::tokenize( ::String fmt){
	HX_STACK_FRAME("de.polygonal.Printf","tokenize",0xe3c03b9a,"de.polygonal.Printf.tokenize","de/polygonal/Printf.hx",610,0x0b01abed)
	HX_STACK_ARG(fmt,"fmt")
	HX_STACK_LINE(611)
	int length = fmt.length;		HX_STACK_VAR(length,"length");
	HX_STACK_LINE(612)
	::StringBuf lastStr = ::StringBuf_obj::__new();		HX_STACK_VAR(lastStr,"lastStr");
	HX_STACK_LINE(613)
	int i = (int)0;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(614)
	int c = (int)0;		HX_STACK_VAR(c,"c");
	HX_STACK_LINE(615)
	Array< ::Dynamic > tokens = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(tokens,"tokens");
	HX_STACK_LINE(616)
	while((true)){
		HX_STACK_LINE(616)
		if ((!(((i < length))))){
			HX_STACK_LINE(616)
			break;
		}
		HX_STACK_LINE(618)
		int c1;		HX_STACK_VAR(c1,"c1");
		HX_STACK_LINE(618)
		{
			HX_STACK_LINE(618)
			int i1 = (i)++;		HX_STACK_VAR(i1,"i1");
			HX_STACK_LINE(618)
			c1 = fmt.cca(i1);
		}
		HX_STACK_LINE(619)
		if (((c1 == (int)37))){
			HX_STACK_LINE(621)
			int _g;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(621)
			{
				HX_STACK_LINE(621)
				int i1 = (i)++;		HX_STACK_VAR(i1,"i1");
				HX_STACK_LINE(621)
				_g = fmt.cca(i1);
			}
			HX_STACK_LINE(621)
			c1 = _g;
			HX_STACK_LINE(622)
			if (((c1 == (int)37))){
				HX_STACK_LINE(623)
				::String _g1 = ::String::fromCharCode(c1);		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(623)
				lastStr->b->push(_g1);
			}
			else{
				HX_STACK_LINE(627)
				if (((lastStr->b->join(HX_CSTRING("")).length > (int)0))){
					HX_STACK_LINE(629)
					::String _g2 = lastStr->b->join(HX_CSTRING(""));		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(629)
					::de::polygonal::_Printf::FormatToken _g3 = ::de::polygonal::_Printf::FormatToken_obj::BareString(_g2);		HX_STACK_VAR(_g3,"_g3");
					HX_STACK_LINE(629)
					tokens->push(_g3);
					HX_STACK_LINE(630)
					::StringBuf _g4 = ::StringBuf_obj::__new();		HX_STACK_VAR(_g4,"_g4");
					HX_STACK_LINE(630)
					lastStr = _g4;
				}
				HX_STACK_LINE(634)
				::de::polygonal::_Printf::FormatToken token;		HX_STACK_VAR(token,"token");
				HX_STACK_LINE(637)
				if (((c1 == (int)40))){
					HX_STACK_LINE(639)
					int endPos = fmt.indexOf(HX_CSTRING(")"),i);		HX_STACK_VAR(endPos,"endPos");
					HX_STACK_LINE(640)
					if (((endPos == (int)-1))){
						HX_STACK_LINE(641)
						::de::polygonal::_Printf::FormatToken _g5 = ::de::polygonal::_Printf::FormatToken_obj::Unknown(HX_CSTRING("named param"),i);		HX_STACK_VAR(_g5,"_g5");
						HX_STACK_LINE(641)
						token = _g5;
					}
					else{
						HX_STACK_LINE(644)
						::String paramName = fmt.substr(i,(endPos - i));		HX_STACK_VAR(paramName,"paramName");
						HX_STACK_LINE(645)
						i = (endPos + (int)1);
						HX_STACK_LINE(646)
						::de::polygonal::_Printf::FormatToken _g6 = ::de::polygonal::_Printf::FormatToken_obj::Property(paramName);		HX_STACK_VAR(_g6,"_g6");
						HX_STACK_LINE(646)
						token = _g6;
					}
				}
				else{
					struct _Function_5_1{
						inline static Dynamic Block( ){
							HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","de/polygonal/Printf.hx",652,0x0b01abed)
							{
								hx::Anon __result = hx::Anon_obj::Create();
								__result->Add(HX_CSTRING("flags") , (int)0,false);
								__result->Add(HX_CSTRING("pos") , (int)-1,false);
								__result->Add(HX_CSTRING("width") , (int)-1,false);
								__result->Add(HX_CSTRING("precision") , (int)-1,false);
								return __result;
							}
							return null();
						}
					};
					HX_STACK_LINE(652)
					Dynamic params = _Function_5_1::Block();		HX_STACK_VAR(params,"params");
					HX_STACK_LINE(655)
					while((true)){
						HX_STACK_LINE(655)
						if ((!(((bool((bool((bool((bool((c1 == (int)45)) || bool((c1 == (int)43)))) || bool((c1 == (int)35)))) || bool((c1 == (int)48)))) || bool((c1 == (int)32))))))){
							HX_STACK_LINE(655)
							break;
						}
						HX_STACK_LINE(657)
						if (((c1 == (int)45))){
							HX_STACK_LINE(658)
							int _g7 = ::de::polygonal::_Printf::FormatFlags_obj::Minus->__Index();		HX_STACK_VAR(_g7,"_g7");
							HX_STACK_LINE(658)
							int _g8 = (int((int)1) << int(_g7));		HX_STACK_VAR(_g8,"_g8");
							HX_STACK_LINE(658)
							hx::OrEq(params->__FieldRef(HX_CSTRING("flags")),_g8);
						}
						else{
							HX_STACK_LINE(660)
							if (((c1 == (int)43))){
								HX_STACK_LINE(661)
								int _g9 = ::de::polygonal::_Printf::FormatFlags_obj::Plus->__Index();		HX_STACK_VAR(_g9,"_g9");
								HX_STACK_LINE(661)
								int _g10 = (int((int)1) << int(_g9));		HX_STACK_VAR(_g10,"_g10");
								HX_STACK_LINE(661)
								hx::OrEq(params->__FieldRef(HX_CSTRING("flags")),_g10);
							}
							else{
								HX_STACK_LINE(663)
								if (((c1 == (int)35))){
									HX_STACK_LINE(664)
									int _g11 = ::de::polygonal::_Printf::FormatFlags_obj::Sharp->__Index();		HX_STACK_VAR(_g11,"_g11");
									HX_STACK_LINE(664)
									int _g12 = (int((int)1) << int(_g11));		HX_STACK_VAR(_g12,"_g12");
									HX_STACK_LINE(664)
									hx::OrEq(params->__FieldRef(HX_CSTRING("flags")),_g12);
								}
								else{
									HX_STACK_LINE(666)
									if (((c1 == (int)48))){
										HX_STACK_LINE(667)
										int _g13 = ::de::polygonal::_Printf::FormatFlags_obj::Zero->__Index();		HX_STACK_VAR(_g13,"_g13");
										HX_STACK_LINE(667)
										int _g14 = (int((int)1) << int(_g13));		HX_STACK_VAR(_g14,"_g14");
										HX_STACK_LINE(667)
										hx::OrEq(params->__FieldRef(HX_CSTRING("flags")),_g14);
									}
									else{
										HX_STACK_LINE(669)
										if (((c1 == (int)32))){
											HX_STACK_LINE(670)
											int _g15 = ::de::polygonal::_Printf::FormatFlags_obj::Space->__Index();		HX_STACK_VAR(_g15,"_g15");
											HX_STACK_LINE(670)
											int _g16 = (int((int)1) << int(_g15));		HX_STACK_VAR(_g16,"_g16");
											HX_STACK_LINE(670)
											hx::OrEq(params->__FieldRef(HX_CSTRING("flags")),_g16);
										}
									}
								}
							}
						}
						HX_STACK_LINE(672)
						int _g17;		HX_STACK_VAR(_g17,"_g17");
						HX_STACK_LINE(672)
						{
							HX_STACK_LINE(672)
							int i1 = (i)++;		HX_STACK_VAR(i1,"i1");
							HX_STACK_LINE(672)
							_g17 = fmt.cca(i1);
						}
						HX_STACK_LINE(672)
						c1 = _g17;
					}
					HX_STACK_LINE(677)
					int _g18 = ::de::polygonal::_Printf::FormatFlags_obj::Minus->__Index();		HX_STACK_VAR(_g18,"_g18");
					HX_STACK_LINE(677)
					int _g19 = (int((int)1) << int(_g18));		HX_STACK_VAR(_g19,"_g19");
					HX_STACK_LINE(677)
					int _g20 = (int(params->__Field(HX_CSTRING("flags"),true)) & int(_g19));		HX_STACK_VAR(_g20,"_g20");
					struct _Function_5_2{
						inline static bool Block( Dynamic &params){
							HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","de/polygonal/Printf.hx",677,0x0b01abed)
							{
								HX_STACK_LINE(677)
								int _g21 = ::de::polygonal::_Printf::FormatFlags_obj::Zero->__Index();		HX_STACK_VAR(_g21,"_g21");
								HX_STACK_LINE(677)
								int _g22 = (int((int)1) << int(_g21));		HX_STACK_VAR(_g22,"_g22");
								HX_STACK_LINE(677)
								int _g23 = (int(params->__Field(HX_CSTRING("flags"),true)) & int(_g22));		HX_STACK_VAR(_g23,"_g23");
								HX_STACK_LINE(677)
								return (_g23 != (int)0);
							}
							return null();
						}
					};
					HX_STACK_LINE(677)
					if (((  (((_g20 != (int)0))) ? bool(_Function_5_2::Block(params)) : bool(false) ))){
						HX_STACK_LINE(682)
						int _g24 = ::de::polygonal::_Printf::FormatFlags_obj::Zero->__Index();		HX_STACK_VAR(_g24,"_g24");
						HX_STACK_LINE(682)
						int _g25 = (int((int)1) << int(_g24));		HX_STACK_VAR(_g25,"_g25");
						HX_STACK_LINE(682)
						int _g26 = ((int)268435455 - _g25);		HX_STACK_VAR(_g26,"_g26");
						HX_STACK_LINE(682)
						hx::AndEq(params->__FieldRef(HX_CSTRING("flags")),_g26);
					}
					HX_STACK_LINE(684)
					int _g27 = ::de::polygonal::_Printf::FormatFlags_obj::Space->__Index();		HX_STACK_VAR(_g27,"_g27");
					HX_STACK_LINE(684)
					int _g28 = (int((int)1) << int(_g27));		HX_STACK_VAR(_g28,"_g28");
					HX_STACK_LINE(684)
					int _g29 = (int(params->__Field(HX_CSTRING("flags"),true)) & int(_g28));		HX_STACK_VAR(_g29,"_g29");
					struct _Function_5_3{
						inline static bool Block( Dynamic &params){
							HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","de/polygonal/Printf.hx",684,0x0b01abed)
							{
								HX_STACK_LINE(684)
								int _g30 = ::de::polygonal::_Printf::FormatFlags_obj::Plus->__Index();		HX_STACK_VAR(_g30,"_g30");
								HX_STACK_LINE(684)
								int _g31 = (int((int)1) << int(_g30));		HX_STACK_VAR(_g31,"_g31");
								HX_STACK_LINE(684)
								int _g32 = (int(params->__Field(HX_CSTRING("flags"),true)) & int(_g31));		HX_STACK_VAR(_g32,"_g32");
								HX_STACK_LINE(684)
								return (_g32 != (int)0);
							}
							return null();
						}
					};
					HX_STACK_LINE(684)
					if (((  (((_g29 != (int)0))) ? bool(_Function_5_3::Block(params)) : bool(false) ))){
						HX_STACK_LINE(689)
						int _g33 = ::de::polygonal::_Printf::FormatFlags_obj::Space->__Index();		HX_STACK_VAR(_g33,"_g33");
						HX_STACK_LINE(689)
						int _g34 = (int((int)1) << int(_g33));		HX_STACK_VAR(_g34,"_g34");
						HX_STACK_LINE(689)
						int _g35 = ((int)268435455 - _g34);		HX_STACK_VAR(_g35,"_g35");
						HX_STACK_LINE(689)
						hx::AndEq(params->__FieldRef(HX_CSTRING("flags")),_g35);
					}
					HX_STACK_LINE(694)
					if (((c1 == (int)42))){
						HX_STACK_LINE(696)
						params->__FieldRef(HX_CSTRING("width")) = null();
						HX_STACK_LINE(697)
						int _g36;		HX_STACK_VAR(_g36,"_g36");
						HX_STACK_LINE(697)
						{
							HX_STACK_LINE(697)
							int i1 = (i)++;		HX_STACK_VAR(i1,"i1");
							HX_STACK_LINE(697)
							_g36 = fmt.cca(i1);
						}
						HX_STACK_LINE(697)
						c1 = _g36;
					}
					else{
						HX_STACK_LINE(700)
						if (((bool((c1 >= (int)48)) && bool((c1 <= (int)57))))){
							HX_STACK_LINE(702)
							params->__FieldRef(HX_CSTRING("width")) = (int)0;
							HX_STACK_LINE(703)
							while((true)){
								HX_STACK_LINE(703)
								if ((!(((bool((c1 >= (int)48)) && bool((c1 <= (int)57))))))){
									HX_STACK_LINE(703)
									break;
								}
								HX_STACK_LINE(705)
								params->__FieldRef(HX_CSTRING("width")) = ((c1 - (int)48) + (params->__Field(HX_CSTRING("width"),true) * (int)10));
								HX_STACK_LINE(706)
								int _g37;		HX_STACK_VAR(_g37,"_g37");
								HX_STACK_LINE(706)
								{
									HX_STACK_LINE(706)
									int i1 = (i)++;		HX_STACK_VAR(i1,"i1");
									HX_STACK_LINE(706)
									_g37 = fmt.cca(i1);
								}
								HX_STACK_LINE(706)
								c1 = _g37;
							}
							HX_STACK_LINE(710)
							if (((c1 == (int)36))){
								HX_STACK_LINE(712)
								params->__FieldRef(HX_CSTRING("pos")) = (params->__Field(HX_CSTRING("width"),true) - (int)1);
								HX_STACK_LINE(713)
								params->__FieldRef(HX_CSTRING("width")) = (int)-1;
								HX_STACK_LINE(714)
								int _g38;		HX_STACK_VAR(_g38,"_g38");
								HX_STACK_LINE(714)
								{
									HX_STACK_LINE(714)
									int i1 = (i)++;		HX_STACK_VAR(i1,"i1");
									HX_STACK_LINE(714)
									_g38 = fmt.cca(i1);
								}
								HX_STACK_LINE(714)
								c1 = _g38;
								HX_STACK_LINE(716)
								if (((c1 == (int)42))){
									HX_STACK_LINE(718)
									params->__FieldRef(HX_CSTRING("width")) = null();
									HX_STACK_LINE(719)
									int _g39;		HX_STACK_VAR(_g39,"_g39");
									HX_STACK_LINE(719)
									{
										HX_STACK_LINE(719)
										int i1 = (i)++;		HX_STACK_VAR(i1,"i1");
										HX_STACK_LINE(719)
										_g39 = fmt.cca(i1);
									}
									HX_STACK_LINE(719)
									c1 = _g39;
								}
								else{
									HX_STACK_LINE(721)
									if (((bool((c1 >= (int)48)) && bool((c1 <= (int)57))))){
										HX_STACK_LINE(723)
										params->__FieldRef(HX_CSTRING("width")) = (int)0;
										HX_STACK_LINE(724)
										while((true)){
											HX_STACK_LINE(724)
											if ((!(((bool((c1 >= (int)48)) && bool((c1 <= (int)57))))))){
												HX_STACK_LINE(724)
												break;
											}
											HX_STACK_LINE(726)
											params->__FieldRef(HX_CSTRING("width")) = ((c1 - (int)48) + (params->__Field(HX_CSTRING("width"),true) * (int)10));
											HX_STACK_LINE(727)
											int _g40;		HX_STACK_VAR(_g40,"_g40");
											HX_STACK_LINE(727)
											{
												HX_STACK_LINE(727)
												int i1 = (i)++;		HX_STACK_VAR(i1,"i1");
												HX_STACK_LINE(727)
												_g40 = fmt.cca(i1);
											}
											HX_STACK_LINE(727)
											c1 = _g40;
										}
									}
								}
							}
						}
					}
					HX_STACK_LINE(735)
					if (((c1 == (int)46))){
						HX_STACK_LINE(737)
						int _g41;		HX_STACK_VAR(_g41,"_g41");
						HX_STACK_LINE(737)
						{
							HX_STACK_LINE(737)
							int i1 = (i)++;		HX_STACK_VAR(i1,"i1");
							HX_STACK_LINE(737)
							_g41 = fmt.cca(i1);
						}
						HX_STACK_LINE(737)
						c1 = _g41;
						HX_STACK_LINE(738)
						if (((c1 == (int)42))){
							HX_STACK_LINE(740)
							params->__FieldRef(HX_CSTRING("precision")) = null();
							HX_STACK_LINE(741)
							int _g42;		HX_STACK_VAR(_g42,"_g42");
							HX_STACK_LINE(741)
							{
								HX_STACK_LINE(741)
								int i1 = (i)++;		HX_STACK_VAR(i1,"i1");
								HX_STACK_LINE(741)
								_g42 = fmt.cca(i1);
							}
							HX_STACK_LINE(741)
							c1 = _g42;
						}
						else{
							HX_STACK_LINE(744)
							if (((bool((c1 >= (int)48)) && bool((c1 <= (int)57))))){
								HX_STACK_LINE(746)
								params->__FieldRef(HX_CSTRING("precision")) = (int)0;
								HX_STACK_LINE(747)
								while((true)){
									HX_STACK_LINE(747)
									if ((!(((bool((c1 >= (int)48)) && bool((c1 <= (int)57))))))){
										HX_STACK_LINE(747)
										break;
									}
									HX_STACK_LINE(749)
									params->__FieldRef(HX_CSTRING("precision")) = ((c1 - (int)48) + (params->__Field(HX_CSTRING("precision"),true) * (int)10));
									HX_STACK_LINE(750)
									int _g43;		HX_STACK_VAR(_g43,"_g43");
									HX_STACK_LINE(750)
									{
										HX_STACK_LINE(750)
										int i1 = (i)++;		HX_STACK_VAR(i1,"i1");
										HX_STACK_LINE(750)
										_g43 = fmt.cca(i1);
									}
									HX_STACK_LINE(750)
									c1 = _g43;
								}
							}
							else{
								HX_STACK_LINE(754)
								params->__FieldRef(HX_CSTRING("precision")) = (int)0;
							}
						}
					}
					HX_STACK_LINE(759)
					while((true)){
						HX_STACK_LINE(759)
						if ((!(((bool((bool((c1 == (int)104)) || bool((c1 == (int)108)))) || bool((c1 == (int)76))))))){
							HX_STACK_LINE(759)
							break;
						}
						HX_STACK_LINE(761)
						switch( (int)(c1)){
							case (int)104: {
								HX_STACK_LINE(764)
								int _g44 = ::de::polygonal::_Printf::FormatFlags_obj::LengthH->__Index();		HX_STACK_VAR(_g44,"_g44");
								HX_STACK_LINE(764)
								int _g45 = (int((int)1) << int(_g44));		HX_STACK_VAR(_g45,"_g45");
								HX_STACK_LINE(764)
								hx::OrEq(params->__FieldRef(HX_CSTRING("flags")),_g45);
							}
							;break;
							case (int)108: {
								HX_STACK_LINE(766)
								int _g46 = ::de::polygonal::_Printf::FormatFlags_obj::Lengthl->__Index();		HX_STACK_VAR(_g46,"_g46");
								HX_STACK_LINE(766)
								int _g47 = (int((int)1) << int(_g46));		HX_STACK_VAR(_g47,"_g47");
								HX_STACK_LINE(766)
								hx::OrEq(params->__FieldRef(HX_CSTRING("flags")),_g47);
							}
							;break;
							case (int)76: {
								HX_STACK_LINE(768)
								int _g48 = ::de::polygonal::_Printf::FormatFlags_obj::LengthL->__Index();		HX_STACK_VAR(_g48,"_g48");
								HX_STACK_LINE(768)
								int _g49 = (int((int)1) << int(_g48));		HX_STACK_VAR(_g49,"_g49");
								HX_STACK_LINE(768)
								hx::OrEq(params->__FieldRef(HX_CSTRING("flags")),_g49);
							}
							;break;
						}
						HX_STACK_LINE(770)
						int _g50;		HX_STACK_VAR(_g50,"_g50");
						HX_STACK_LINE(770)
						{
							HX_STACK_LINE(770)
							int i1 = (i)++;		HX_STACK_VAR(i1,"i1");
							HX_STACK_LINE(770)
							_g50 = fmt.cca(i1);
						}
						HX_STACK_LINE(770)
						c1 = _g50;
					}
					HX_STACK_LINE(775)
					if (((bool((bool((c1 == (int)69)) || bool((c1 == (int)71)))) || bool((c1 == (int)88))))){
						HX_STACK_LINE(776)
						int _g51 = ::de::polygonal::_Printf::FormatFlags_obj::UpperCase->__Index();		HX_STACK_VAR(_g51,"_g51");
						HX_STACK_LINE(776)
						int _g52 = (int((int)1) << int(_g51));		HX_STACK_VAR(_g52,"_g52");
						HX_STACK_LINE(776)
						hx::OrEq(params->__FieldRef(HX_CSTRING("flags")),_g52);
					}
					HX_STACK_LINE(778)
					::de::polygonal::_Printf::FormatDataType type = ::de::polygonal::Printf_obj::dataTypeMap->get(c1);		HX_STACK_VAR(type,"type");
					HX_STACK_LINE(780)
					if (((type == null()))){
						HX_STACK_LINE(781)
						::String _g53 = ::String::fromCharCode(c1);		HX_STACK_VAR(_g53,"_g53");
						HX_STACK_LINE(781)
						::de::polygonal::_Printf::FormatToken _g54 = ::de::polygonal::_Printf::FormatToken_obj::Unknown(_g53,i);		HX_STACK_VAR(_g54,"_g54");
						HX_STACK_LINE(781)
						token = _g54;
					}
					else{
						HX_STACK_LINE(783)
						::de::polygonal::_Printf::FormatToken _g55 = ::de::polygonal::_Printf::FormatToken_obj::Tag(type,params);		HX_STACK_VAR(_g55,"_g55");
						HX_STACK_LINE(783)
						token = _g55;
					}
				}
				HX_STACK_LINE(787)
				tokens->push(token);
			}
		}
		else{
			HX_STACK_LINE(791)
			::String _g56 = ::String::fromCharCode(c1);		HX_STACK_VAR(_g56,"_g56");
			HX_STACK_LINE(791)
			lastStr->b->push(_g56);
		}
	}
	HX_STACK_LINE(794)
	if (((lastStr->b->join(HX_CSTRING("")).length > (int)0))){
		HX_STACK_LINE(795)
		::String _g57 = lastStr->b->join(HX_CSTRING(""));		HX_STACK_VAR(_g57,"_g57");
		HX_STACK_LINE(795)
		::de::polygonal::_Printf::FormatToken _g58 = ::de::polygonal::_Printf::FormatToken_obj::BareString(_g57);		HX_STACK_VAR(_g58,"_g58");
		HX_STACK_LINE(795)
		tokens->push(_g58);
	}
	HX_STACK_LINE(796)
	return tokens;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Printf_obj,tokenize,return )

::String Printf_obj::formatBinary( int value,Dynamic args){
	HX_STACK_FRAME("de.polygonal.Printf","formatBinary",0x694583b7,"de.polygonal.Printf.formatBinary","de/polygonal/Printf.hx",800,0x0b01abed)
	HX_STACK_ARG(value,"value")
	HX_STACK_ARG(args,"args")
	HX_STACK_LINE(801)
	::String output = HX_CSTRING("");		HX_STACK_VAR(output,"output");
	HX_STACK_LINE(802)
	int flags = args->__Field(HX_CSTRING("flags"),true);		HX_STACK_VAR(flags,"flags");
	HX_STACK_LINE(803)
	Dynamic precision = args->__Field(HX_CSTRING("precision"),true);		HX_STACK_VAR(precision,"precision");
	HX_STACK_LINE(804)
	Dynamic width = args->__Field(HX_CSTRING("width"),true);		HX_STACK_VAR(width,"width");
	HX_STACK_LINE(806)
	if (((precision == (int)-1))){
		HX_STACK_LINE(806)
		precision = (int)1;
	}
	HX_STACK_LINE(808)
	if (((value != (int)0))){
		HX_STACK_LINE(810)
		int _g = ::de::polygonal::_Printf::FormatFlags_obj::LengthH->__Index();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(810)
		int _g1 = (int((int)1) << int(_g));		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(810)
		int _g2 = (int(flags) & int(_g1));		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(810)
		if (((_g2 != (int)0))){
			HX_STACK_LINE(811)
			hx::AndEq(value,(int)65535);
		}
		HX_STACK_LINE(814)
		int i = value;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(815)
		while((true)){
			HX_STACK_LINE(817)
			output = (((  (((((int(i) & int((int)1))) > (int)0))) ? ::String(HX_CSTRING("1")) : ::String(HX_CSTRING("0")) )) + output);
			HX_STACK_LINE(818)
			hx::UShrEq(i,(int)1);
			HX_STACK_LINE(815)
			if ((!(((i > (int)0))))){
				HX_STACK_LINE(815)
				break;
			}
		}
		HX_STACK_LINE(822)
		if (((precision > (int)1))){
			HX_STACK_LINE(824)
			if (((precision > output.length))){
				HX_STACK_LINE(825)
				::String _g3 = ::de::polygonal::Printf_obj::lpad(output,HX_CSTRING("0"),precision);		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(825)
				output = _g3;
			}
			HX_STACK_LINE(827)
			int _g4 = ::de::polygonal::_Printf::FormatFlags_obj::Sharp->__Index();		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(827)
			int _g5 = (int((int)1) << int(_g4));		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(827)
			int _g6 = (int(flags) & int(_g5));		HX_STACK_VAR(_g6,"_g6");
			HX_STACK_LINE(827)
			if (((_g6 != (int)0))){
				HX_STACK_LINE(827)
				output = (HX_CSTRING("b") + output);
			}
		}
	}
	HX_STACK_LINE(832)
	int _g7 = ::de::polygonal::_Printf::FormatFlags_obj::Minus->__Index();		HX_STACK_VAR(_g7,"_g7");
	HX_STACK_LINE(832)
	int _g8 = (int((int)1) << int(_g7));		HX_STACK_VAR(_g8,"_g8");
	HX_STACK_LINE(832)
	int _g9 = (int(flags) & int(_g8));		HX_STACK_VAR(_g9,"_g9");
	HX_STACK_LINE(832)
	if (((_g9 != (int)0))){
		HX_STACK_LINE(833)
		if (((width > output.length))){
			HX_STACK_LINE(833)
			return ::de::polygonal::Printf_obj::rpad(output,HX_CSTRING(" "),width);
		}
		else{
			HX_STACK_LINE(833)
			return output;
		}
	}
	else{
		HX_STACK_LINE(835)
		if (((width > output.length))){
			HX_STACK_LINE(835)
			int _g10 = ::de::polygonal::_Printf::FormatFlags_obj::Zero->__Index();		HX_STACK_VAR(_g10,"_g10");
			HX_STACK_LINE(835)
			int _g11 = (int((int)1) << int(_g10));		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(835)
			int _g12 = (int(flags) & int(_g11));		HX_STACK_VAR(_g12,"_g12");
			HX_STACK_LINE(835)
			::String _g13;		HX_STACK_VAR(_g13,"_g13");
			HX_STACK_LINE(835)
			if (((_g12 != (int)0))){
				HX_STACK_LINE(835)
				_g13 = HX_CSTRING("0");
			}
			else{
				HX_STACK_LINE(835)
				_g13 = HX_CSTRING(" ");
			}
			HX_STACK_LINE(835)
			return ::de::polygonal::Printf_obj::lpad(output,_g13,width);
		}
		else{
			HX_STACK_LINE(835)
			return output;
		}
	}
	HX_STACK_LINE(832)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Printf_obj,formatBinary,return )

::String Printf_obj::formatOctal( int value,Dynamic args){
	HX_STACK_FRAME("de.polygonal.Printf","formatOctal",0x61c5fed5,"de.polygonal.Printf.formatOctal","de/polygonal/Printf.hx",839,0x0b01abed)
	HX_STACK_ARG(value,"value")
	HX_STACK_ARG(args,"args")
	HX_STACK_LINE(840)
	::String output = HX_CSTRING("");		HX_STACK_VAR(output,"output");
	HX_STACK_LINE(841)
	int flags = args->__Field(HX_CSTRING("flags"),true);		HX_STACK_VAR(flags,"flags");
	HX_STACK_LINE(842)
	Dynamic precision = args->__Field(HX_CSTRING("precision"),true);		HX_STACK_VAR(precision,"precision");
	HX_STACK_LINE(843)
	Dynamic width = args->__Field(HX_CSTRING("width"),true);		HX_STACK_VAR(width,"width");
	HX_STACK_LINE(845)
	if (((precision == (int)-1))){
		HX_STACK_LINE(845)
		precision = (int)1;
	}
	HX_STACK_LINE(847)
	if (((value != (int)0))){
		HX_STACK_LINE(849)
		int _g = ::de::polygonal::_Printf::FormatFlags_obj::LengthH->__Index();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(849)
		int _g1 = (int((int)1) << int(_g));		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(849)
		int _g2 = (int(flags) & int(_g1));		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(849)
		if (((_g2 != (int)0))){
			HX_STACK_LINE(849)
			hx::AndEq(value,(int)65535);
		}
		HX_STACK_LINE(851)
		::String _g3 = ::de::polygonal::Printf_obj::toOct(value);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(851)
		output = _g3;
		HX_STACK_LINE(853)
		int _g4 = ::de::polygonal::_Printf::FormatFlags_obj::Sharp->__Index();		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(853)
		int _g5 = (int((int)1) << int(_g4));		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(853)
		int _g6 = (int(flags) & int(_g5));		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(853)
		if (((_g6 != (int)0))){
			HX_STACK_LINE(853)
			output = (HX_CSTRING("0") + output);
		}
		HX_STACK_LINE(855)
		if (((bool((precision > (int)1)) && bool((output.length < precision))))){
			HX_STACK_LINE(856)
			::String _g7 = ::de::polygonal::Printf_obj::lpad(output,HX_CSTRING("0"),precision);		HX_STACK_VAR(_g7,"_g7");
			HX_STACK_LINE(856)
			output = _g7;
		}
	}
	HX_STACK_LINE(860)
	int _g8 = ::de::polygonal::_Printf::FormatFlags_obj::Minus->__Index();		HX_STACK_VAR(_g8,"_g8");
	HX_STACK_LINE(860)
	int _g9 = (int((int)1) << int(_g8));		HX_STACK_VAR(_g9,"_g9");
	HX_STACK_LINE(860)
	int _g10 = (int(flags) & int(_g9));		HX_STACK_VAR(_g10,"_g10");
	HX_STACK_LINE(860)
	if (((_g10 != (int)0))){
		HX_STACK_LINE(861)
		if (((width > output.length))){
			HX_STACK_LINE(861)
			return ::de::polygonal::Printf_obj::rpad(output,HX_CSTRING(" "),width);
		}
		else{
			HX_STACK_LINE(861)
			return output;
		}
	}
	else{
		HX_STACK_LINE(863)
		if (((width > output.length))){
			HX_STACK_LINE(863)
			int _g11 = ::de::polygonal::_Printf::FormatFlags_obj::Zero->__Index();		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(863)
			int _g12 = (int((int)1) << int(_g11));		HX_STACK_VAR(_g12,"_g12");
			HX_STACK_LINE(863)
			int _g13 = (int(flags) & int(_g12));		HX_STACK_VAR(_g13,"_g13");
			HX_STACK_LINE(863)
			::String _g14;		HX_STACK_VAR(_g14,"_g14");
			HX_STACK_LINE(863)
			if (((_g13 != (int)0))){
				HX_STACK_LINE(863)
				_g14 = HX_CSTRING("0");
			}
			else{
				HX_STACK_LINE(863)
				_g14 = HX_CSTRING(" ");
			}
			HX_STACK_LINE(863)
			return ::de::polygonal::Printf_obj::lpad(output,_g14,width);
		}
		else{
			HX_STACK_LINE(863)
			return output;
		}
	}
	HX_STACK_LINE(860)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Printf_obj,formatOctal,return )

::String Printf_obj::formatHexadecimal( int value,Dynamic args){
	HX_STACK_FRAME("de.polygonal.Printf","formatHexadecimal",0x0abf8cb5,"de.polygonal.Printf.formatHexadecimal","de/polygonal/Printf.hx",867,0x0b01abed)
	HX_STACK_ARG(value,"value")
	HX_STACK_ARG(args,"args")
	HX_STACK_LINE(868)
	::String output = HX_CSTRING("");		HX_STACK_VAR(output,"output");
	HX_STACK_LINE(869)
	int flags = args->__Field(HX_CSTRING("flags"),true);		HX_STACK_VAR(flags,"flags");
	HX_STACK_LINE(870)
	Dynamic precision = args->__Field(HX_CSTRING("precision"),true);		HX_STACK_VAR(precision,"precision");
	HX_STACK_LINE(871)
	Dynamic width = args->__Field(HX_CSTRING("width"),true);		HX_STACK_VAR(width,"width");
	HX_STACK_LINE(873)
	if (((precision == (int)-1))){
		HX_STACK_LINE(873)
		precision = (int)1;
	}
	HX_STACK_LINE(875)
	if (((value != (int)0))){
		HX_STACK_LINE(877)
		int _g = ::de::polygonal::_Printf::FormatFlags_obj::LengthH->__Index();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(877)
		int _g1 = (int((int)1) << int(_g));		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(877)
		int _g2 = (int(flags) & int(_g1));		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(877)
		if (((_g2 != (int)0))){
			HX_STACK_LINE(878)
			hx::AndEq(value,(int)65535);
		}
		HX_STACK_LINE(880)
		::String _g5;		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(880)
		{
			HX_STACK_LINE(880)
			int x = value;		HX_STACK_VAR(x,"x");
			HX_STACK_LINE(880)
			::String s = HX_CSTRING("");		HX_STACK_VAR(s,"s");
			HX_STACK_LINE(880)
			::String hexChars = HX_CSTRING("0123456789ABCDEF");		HX_STACK_VAR(hexChars,"hexChars");
			HX_STACK_LINE(880)
			while((true)){
				HX_STACK_LINE(880)
				::String _g3 = hexChars.charAt((int(x) & int((int)15)));		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(880)
				::String _g4 = (_g3 + s);		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(880)
				s = _g4;
				HX_STACK_LINE(880)
				hx::UShrEq(x,(int)4);
				HX_STACK_LINE(880)
				if ((!(((x > (int)0))))){
					HX_STACK_LINE(880)
					break;
				}
			}
			HX_STACK_LINE(880)
			_g5 = s;
		}
		HX_STACK_LINE(880)
		output = _g5;
		HX_STACK_LINE(882)
		if (((bool((precision > (int)1)) && bool((output.length < precision))))){
			HX_STACK_LINE(883)
			::String _g6 = ::de::polygonal::Printf_obj::lpad(output,HX_CSTRING("0"),precision);		HX_STACK_VAR(_g6,"_g6");
			HX_STACK_LINE(883)
			output = _g6;
		}
		HX_STACK_LINE(885)
		int _g7 = ::de::polygonal::_Printf::FormatFlags_obj::Sharp->__Index();		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(885)
		int _g8 = (int((int)1) << int(_g7));		HX_STACK_VAR(_g8,"_g8");
		HX_STACK_LINE(885)
		int _g9 = (int(flags) & int(_g8));		HX_STACK_VAR(_g9,"_g9");
		HX_STACK_LINE(885)
		if (((  (((_g9 != (int)0))) ? bool((value != (int)0)) : bool(false) ))){
			HX_STACK_LINE(886)
			output = (HX_CSTRING("0x") + output);
		}
		HX_STACK_LINE(888)
		int _g10 = ::de::polygonal::_Printf::FormatFlags_obj::UpperCase->__Index();		HX_STACK_VAR(_g10,"_g10");
		HX_STACK_LINE(888)
		int _g11 = (int((int)1) << int(_g10));		HX_STACK_VAR(_g11,"_g11");
		HX_STACK_LINE(888)
		int _g12 = (int(flags) & int(_g11));		HX_STACK_VAR(_g12,"_g12");
		HX_STACK_LINE(888)
		::String _g13;		HX_STACK_VAR(_g13,"_g13");
		HX_STACK_LINE(888)
		if (((_g12 != (int)0))){
			HX_STACK_LINE(888)
			_g13 = output.toUpperCase();
		}
		else{
			HX_STACK_LINE(888)
			_g13 = output.toLowerCase();
		}
		HX_STACK_LINE(888)
		output = _g13;
	}
	HX_STACK_LINE(892)
	int _g14 = ::de::polygonal::_Printf::FormatFlags_obj::Minus->__Index();		HX_STACK_VAR(_g14,"_g14");
	HX_STACK_LINE(892)
	int _g15 = (int((int)1) << int(_g14));		HX_STACK_VAR(_g15,"_g15");
	HX_STACK_LINE(892)
	int _g16 = (int(flags) & int(_g15));		HX_STACK_VAR(_g16,"_g16");
	HX_STACK_LINE(892)
	if (((_g16 != (int)0))){
		HX_STACK_LINE(893)
		if (((width > output.length))){
			HX_STACK_LINE(893)
			return ::de::polygonal::Printf_obj::rpad(output,HX_CSTRING(" "),width);
		}
		else{
			HX_STACK_LINE(893)
			return output;
		}
	}
	else{
		HX_STACK_LINE(895)
		if (((width > output.length))){
			HX_STACK_LINE(895)
			int _g17 = ::de::polygonal::_Printf::FormatFlags_obj::Zero->__Index();		HX_STACK_VAR(_g17,"_g17");
			HX_STACK_LINE(895)
			int _g18 = (int((int)1) << int(_g17));		HX_STACK_VAR(_g18,"_g18");
			HX_STACK_LINE(895)
			int _g19 = (int(flags) & int(_g18));		HX_STACK_VAR(_g19,"_g19");
			HX_STACK_LINE(895)
			::String _g20;		HX_STACK_VAR(_g20,"_g20");
			HX_STACK_LINE(895)
			if (((_g19 != (int)0))){
				HX_STACK_LINE(895)
				_g20 = HX_CSTRING("0");
			}
			else{
				HX_STACK_LINE(895)
				_g20 = HX_CSTRING(" ");
			}
			HX_STACK_LINE(895)
			return ::de::polygonal::Printf_obj::lpad(output,_g20,width);
		}
		else{
			HX_STACK_LINE(895)
			return output;
		}
	}
	HX_STACK_LINE(892)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Printf_obj,formatHexadecimal,return )

::String Printf_obj::formatUnsignedDecimal( int value,Dynamic args){
	HX_STACK_FRAME("de.polygonal.Printf","formatUnsignedDecimal",0x15d145a6,"de.polygonal.Printf.formatUnsignedDecimal","de/polygonal/Printf.hx",899,0x0b01abed)
	HX_STACK_ARG(value,"value")
	HX_STACK_ARG(args,"args")
	HX_STACK_LINE(900)
	::String output;		HX_STACK_VAR(output,"output");
	HX_STACK_LINE(901)
	Dynamic precision = args->__Field(HX_CSTRING("precision"),true);		HX_STACK_VAR(precision,"precision");
	HX_STACK_LINE(903)
	if (((value >= (int)0))){
		HX_STACK_LINE(904)
		::String _g = ::de::polygonal::Printf_obj::formatSignedDecimal(value,args);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(904)
		output = _g;
	}
	else{
		HX_STACK_LINE(907)
		::haxe::Int64 x = ::haxe::Int64_obj::__new((int)0,value);		HX_STACK_VAR(x,"x");
		HX_STACK_LINE(908)
		::String _g1 = x->toString();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(908)
		output = _g1;
		HX_STACK_LINE(909)
		if (((bool((precision > (int)1)) && bool((output.length < precision))))){
			HX_STACK_LINE(910)
			::String _g2 = ::de::polygonal::Printf_obj::lpad(output,HX_CSTRING("0"),precision);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(910)
			output = _g2;
		}
		HX_STACK_LINE(911)
		::String _g3 = ::de::polygonal::Printf_obj::padNumber(output,value,args->__Field(HX_CSTRING("flags"),true),args->__Field(HX_CSTRING("width"),true));		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(911)
		output = _g3;
	}
	HX_STACK_LINE(914)
	return output;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Printf_obj,formatUnsignedDecimal,return )

::String Printf_obj::formatNaturalFloat( Float value,Dynamic args){
	HX_STACK_FRAME("de.polygonal.Printf","formatNaturalFloat",0x498e7f29,"de.polygonal.Printf.formatNaturalFloat","de/polygonal/Printf.hx",918,0x0b01abed)
	HX_STACK_ARG(value,"value")
	HX_STACK_ARG(args,"args")
	HX_STACK_LINE(920)
	args->__FieldRef(HX_CSTRING("precision")) = (int)0;
	HX_STACK_LINE(922)
	::String formatedFloat = ::de::polygonal::Printf_obj::formatNormalFloat(value,args);		HX_STACK_VAR(formatedFloat,"formatedFloat");
	HX_STACK_LINE(923)
	::String formatedScientific = ::de::polygonal::Printf_obj::formatScientific(value,args);		HX_STACK_VAR(formatedScientific,"formatedScientific");
	HX_STACK_LINE(925)
	int _g = ::de::polygonal::_Printf::FormatFlags_obj::Sharp->__Index();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(925)
	int _g1 = (int((int)1) << int(_g));		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(925)
	int _g2 = (int(args->__Field(HX_CSTRING("flags"),true)) & int(_g1));		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(925)
	if (((_g2 != (int)0))){
		HX_STACK_LINE(927)
		int _g3 = formatedFloat.indexOf(HX_CSTRING("."),null());		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(927)
		if (((_g3 != (int)-1))){
			HX_STACK_LINE(929)
			int pos = (formatedFloat.length - (int)1);		HX_STACK_VAR(pos,"pos");
			HX_STACK_LINE(930)
			while((true)){
				HX_STACK_LINE(930)
				int _g4 = formatedFloat.cca(pos);		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(930)
				if ((!(((_g4 == (int)48))))){
					HX_STACK_LINE(930)
					break;
				}
				HX_STACK_LINE(930)
				(pos)--;
			}
			HX_STACK_LINE(931)
			::String _g5 = formatedFloat.substr((int)0,pos);		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(931)
			formatedFloat = _g5;
		}
	}
	HX_STACK_LINE(935)
	if (((formatedFloat.length <= formatedScientific.length))){
		HX_STACK_LINE(935)
		return formatedFloat;
	}
	else{
		HX_STACK_LINE(935)
		return formatedScientific;
	}
	HX_STACK_LINE(935)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Printf_obj,formatNaturalFloat,return )

::String Printf_obj::formatScientific( Float value,Dynamic args){
	HX_STACK_FRAME("de.polygonal.Printf","formatScientific",0xf3011c5f,"de.polygonal.Printf.formatScientific","de/polygonal/Printf.hx",939,0x0b01abed)
	HX_STACK_ARG(value,"value")
	HX_STACK_ARG(args,"args")
	HX_STACK_LINE(940)
	::String output = HX_CSTRING("");		HX_STACK_VAR(output,"output");
	HX_STACK_LINE(941)
	int flags = args->__Field(HX_CSTRING("flags"),true);		HX_STACK_VAR(flags,"flags");
	HX_STACK_LINE(942)
	Dynamic precision = args->__Field(HX_CSTRING("precision"),true);		HX_STACK_VAR(precision,"precision");
	HX_STACK_LINE(943)
	if (((precision == (int)-1))){
		HX_STACK_LINE(943)
		precision = (int)6;
	}
	HX_STACK_LINE(945)
	int sign;		HX_STACK_VAR(sign,"sign");
	HX_STACK_LINE(945)
	int exponent;		HX_STACK_VAR(exponent,"exponent");
	HX_STACK_LINE(947)
	if (((value == (int)0))){
		HX_STACK_LINE(949)
		sign = (int)0;
		HX_STACK_LINE(950)
		exponent = (int)0;
		HX_STACK_LINE(951)
		hx::AddEq(output,HX_CSTRING("0"));
		HX_STACK_LINE(952)
		if (((precision > (int)0))){
			HX_STACK_LINE(954)
			hx::AddEq(output,HX_CSTRING("."));
			HX_STACK_LINE(955)
			{
				HX_STACK_LINE(955)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(955)
				while((true)){
					HX_STACK_LINE(955)
					if ((!(((_g < precision))))){
						HX_STACK_LINE(955)
						break;
					}
					HX_STACK_LINE(955)
					int i = (_g)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(955)
					hx::AddEq(output,HX_CSTRING("0"));
				}
			}
		}
	}
	else{
		HX_STACK_LINE(960)
		if (((value > 0.))){
			HX_STACK_LINE(960)
			sign = (int)1;
		}
		else{
			HX_STACK_LINE(960)
			if (((value < 0.))){
				HX_STACK_LINE(960)
				sign = (int)-1;
			}
			else{
				HX_STACK_LINE(960)
				sign = (int)0;
			}
		}
		HX_STACK_LINE(961)
		Float _g = ::Math_obj::abs(value);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(961)
		value = _g;
		HX_STACK_LINE(962)
		Float _g1 = ::Math_obj::log(value);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(962)
		Float _g2 = (Float(_g1) / Float(2.302585092994046));		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(962)
		int _g3 = ::Math_obj::floor(_g2);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(962)
		exponent = _g3;
		HX_STACK_LINE(963)
		Float _g4 = ::Math_obj::pow((int)10,exponent);		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(963)
		Float _g5 = (Float(value) / Float(_g4));		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(963)
		value = _g5;
		HX_STACK_LINE(964)
		Float p = ::Math_obj::pow(0.1,precision);		HX_STACK_VAR(p,"p");
		HX_STACK_LINE(965)
		Float _g7;		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(965)
		{
			HX_STACK_LINE(965)
			int min = (int)-2147483647;		HX_STACK_VAR(min,"min");
			HX_STACK_LINE(965)
			Float t = (Float(value) / Float(p));		HX_STACK_VAR(t,"t");
			HX_STACK_LINE(965)
			if (((bool((t < (int)2147483647)) && bool((t > min))))){
				HX_STACK_LINE(965)
				int _g6 = ::Math_obj::round(t);		HX_STACK_VAR(_g6,"_g6");
				HX_STACK_LINE(965)
				_g7 = (_g6 * p);
			}
			else{
				HX_STACK_LINE(965)
				if (((t > (int)0))){
					HX_STACK_LINE(965)
					t = (t + .5);
				}
				else{
					HX_STACK_LINE(965)
					if (((t < (int)0))){
						HX_STACK_LINE(965)
						t = (t - .5);
					}
					else{
						HX_STACK_LINE(965)
						t = t;
					}
				}
				HX_STACK_LINE(965)
				_g7 = (((t - hx::Mod(t,(int)1))) * p);
			}
		}
		HX_STACK_LINE(965)
		value = _g7;
	}
	HX_STACK_LINE(968)
	::String _g11;		HX_STACK_VAR(_g11,"_g11");
	HX_STACK_LINE(968)
	if (((sign < (int)0))){
		HX_STACK_LINE(968)
		_g11 = HX_CSTRING("-");
	}
	else{
		HX_STACK_LINE(968)
		int _g8 = ::de::polygonal::_Printf::FormatFlags_obj::Plus->__Index();		HX_STACK_VAR(_g8,"_g8");
		HX_STACK_LINE(968)
		int _g9 = (int((int)1) << int(_g8));		HX_STACK_VAR(_g9,"_g9");
		HX_STACK_LINE(968)
		int _g10 = (int(flags) & int(_g9));		HX_STACK_VAR(_g10,"_g10");
		HX_STACK_LINE(968)
		if (((_g10 != (int)0))){
			HX_STACK_LINE(968)
			_g11 = HX_CSTRING("+");
		}
		else{
			HX_STACK_LINE(968)
			_g11 = HX_CSTRING("");
		}
	}
	HX_STACK_LINE(968)
	hx::AddEq(output,_g11);
	HX_STACK_LINE(970)
	if (((value != (int)0))){
		HX_STACK_LINE(971)
		::String _g12 = ::de::polygonal::Printf_obj::str(value).substr((int)0,(precision + (int)2));		HX_STACK_VAR(_g12,"_g12");
		HX_STACK_LINE(971)
		::String _g13 = ::de::polygonal::Printf_obj::rpad(_g12,HX_CSTRING("0"),(precision + (int)2));		HX_STACK_VAR(_g13,"_g13");
		HX_STACK_LINE(971)
		hx::AddEq(output,_g13);
	}
	HX_STACK_LINE(972)
	int _g14 = ::de::polygonal::_Printf::FormatFlags_obj::UpperCase->__Index();		HX_STACK_VAR(_g14,"_g14");
	HX_STACK_LINE(972)
	int _g15 = (int((int)1) << int(_g14));		HX_STACK_VAR(_g15,"_g15");
	HX_STACK_LINE(972)
	int _g16 = (int(flags) & int(_g15));		HX_STACK_VAR(_g16,"_g16");
	HX_STACK_LINE(972)
	::String _g17;		HX_STACK_VAR(_g17,"_g17");
	HX_STACK_LINE(972)
	if (((_g16 != (int)0))){
		HX_STACK_LINE(972)
		_g17 = HX_CSTRING("E");
	}
	else{
		HX_STACK_LINE(972)
		_g17 = HX_CSTRING("e");
	}
	HX_STACK_LINE(972)
	hx::AddEq(output,_g17);
	HX_STACK_LINE(973)
	if (((exponent >= (int)0))){
		HX_STACK_LINE(973)
		hx::AddEq(output,HX_CSTRING("+"));
	}
	else{
		HX_STACK_LINE(973)
		hx::AddEq(output,HX_CSTRING("-"));
	}
	HX_STACK_LINE(975)
	if (((exponent < (int)10))){
		HX_STACK_LINE(976)
		hx::AddEq(output,HX_CSTRING("00"));
	}
	else{
		HX_STACK_LINE(978)
		if (((exponent < (int)100))){
			HX_STACK_LINE(979)
			hx::AddEq(output,HX_CSTRING("0"));
		}
	}
	HX_STACK_LINE(981)
	int _g18 = ::de::polygonal::Printf_obj::iabs(exponent);		HX_STACK_VAR(_g18,"_g18");
	HX_STACK_LINE(981)
	::String _g19 = ::de::polygonal::Printf_obj::str(_g18);		HX_STACK_VAR(_g19,"_g19");
	HX_STACK_LINE(981)
	hx::AddEq(output,_g19);
	HX_STACK_LINE(982)
	return output;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Printf_obj,formatScientific,return )

::String Printf_obj::formatSignedDecimal( int value,Dynamic args){
	HX_STACK_FRAME("de.polygonal.Printf","formatSignedDecimal",0x590b191f,"de.polygonal.Printf.formatSignedDecimal","de/polygonal/Printf.hx",986,0x0b01abed)
	HX_STACK_ARG(value,"value")
	HX_STACK_ARG(args,"args")
	HX_STACK_LINE(987)
	::String output;		HX_STACK_VAR(output,"output");
	HX_STACK_LINE(988)
	int flags = args->__Field(HX_CSTRING("flags"),true);		HX_STACK_VAR(flags,"flags");
	HX_STACK_LINE(989)
	Dynamic precision = args->__Field(HX_CSTRING("precision"),true);		HX_STACK_VAR(precision,"precision");
	HX_STACK_LINE(990)
	Dynamic width = args->__Field(HX_CSTRING("width"),true);		HX_STACK_VAR(width,"width");
	HX_STACK_LINE(992)
	if (((bool((precision == (int)0)) && bool((value == (int)0))))){
		HX_STACK_LINE(993)
		output = HX_CSTRING("");
	}
	else{
		HX_STACK_LINE(996)
		int _g = ::de::polygonal::_Printf::FormatFlags_obj::LengthH->__Index();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(996)
		int _g1 = (int((int)1) << int(_g));		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(996)
		int _g2 = (int(flags) & int(_g1));		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(996)
		if (((_g2 != (int)0))){
			HX_STACK_LINE(997)
			hx::AndEq(value,(int)65535);
		}
		HX_STACK_LINE(999)
		int _g3 = ::de::polygonal::Printf_obj::iabs(value);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(999)
		::String _g4 = ::de::polygonal::Printf_obj::str(_g3);		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(999)
		output = _g4;
		HX_STACK_LINE(1001)
		if (((bool((precision > (int)1)) && bool((output.length < precision))))){
			HX_STACK_LINE(1002)
			::String _g5 = ::de::polygonal::Printf_obj::lpad(output,HX_CSTRING("0"),precision);		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(1002)
			output = _g5;
		}
		HX_STACK_LINE(1004)
		int _g6 = ::de::polygonal::_Printf::FormatFlags_obj::Zero->__Index();		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(1004)
		int _g7 = (int((int)1) << int(_g6));		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(1004)
		int _g8 = (int(flags) & int(_g7));		HX_STACK_VAR(_g8,"_g8");
		HX_STACK_LINE(1004)
		if (((_g8 != (int)0))){
			HX_STACK_LINE(1005)
			::String _g9 = ::de::polygonal::Printf_obj::lpad(output,HX_CSTRING("0"),(  (((value < (int)0))) ? int((width - (int)1)) : int(width) ));		HX_STACK_VAR(_g9,"_g9");
			HX_STACK_LINE(1005)
			output = _g9;
		}
		HX_STACK_LINE(1007)
		if (((value < (int)0))){
			HX_STACK_LINE(1008)
			output = (HX_CSTRING("-") + output);
		}
	}
	HX_STACK_LINE(1011)
	if (((value >= (int)0))){
		HX_STACK_LINE(1013)
		int _g10 = ::de::polygonal::_Printf::FormatFlags_obj::Plus->__Index();		HX_STACK_VAR(_g10,"_g10");
		HX_STACK_LINE(1013)
		int _g11 = (int((int)1) << int(_g10));		HX_STACK_VAR(_g11,"_g11");
		HX_STACK_LINE(1013)
		int _g12 = (int(flags) & int(_g11));		HX_STACK_VAR(_g12,"_g12");
		HX_STACK_LINE(1013)
		if (((_g12 != (int)0))){
			HX_STACK_LINE(1014)
			output = (HX_CSTRING("+") + output);
		}
		else{
			HX_STACK_LINE(1016)
			int _g13 = ::de::polygonal::_Printf::FormatFlags_obj::Space->__Index();		HX_STACK_VAR(_g13,"_g13");
			HX_STACK_LINE(1016)
			int _g14 = (int((int)1) << int(_g13));		HX_STACK_VAR(_g14,"_g14");
			HX_STACK_LINE(1016)
			int _g15 = (int(flags) & int(_g14));		HX_STACK_VAR(_g15,"_g15");
			HX_STACK_LINE(1016)
			if (((_g15 != (int)0))){
				HX_STACK_LINE(1017)
				output = (HX_CSTRING(" ") + output);
			}
		}
	}
	HX_STACK_LINE(1020)
	int _g16 = ::de::polygonal::_Printf::FormatFlags_obj::Minus->__Index();		HX_STACK_VAR(_g16,"_g16");
	HX_STACK_LINE(1020)
	int _g17 = (int((int)1) << int(_g16));		HX_STACK_VAR(_g17,"_g17");
	HX_STACK_LINE(1020)
	int _g18 = (int(flags) & int(_g17));		HX_STACK_VAR(_g18,"_g18");
	HX_STACK_LINE(1020)
	if (((_g18 != (int)0))){
		HX_STACK_LINE(1021)
		::String _g19 = ::de::polygonal::Printf_obj::rpad(output,HX_CSTRING(" "),args->__Field(HX_CSTRING("width"),true));		HX_STACK_VAR(_g19,"_g19");
		HX_STACK_LINE(1021)
		output = _g19;
	}
	else{
		HX_STACK_LINE(1023)
		::String _g20 = ::de::polygonal::Printf_obj::lpad(output,HX_CSTRING(" "),args->__Field(HX_CSTRING("width"),true));		HX_STACK_VAR(_g20,"_g20");
		HX_STACK_LINE(1023)
		output = _g20;
	}
	HX_STACK_LINE(1025)
	return output;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Printf_obj,formatSignedDecimal,return )

::String Printf_obj::formatString( ::String x,Dynamic args){
	HX_STACK_FRAME("de.polygonal.Printf","formatString",0x8d69f087,"de.polygonal.Printf.formatString","de/polygonal/Printf.hx",1029,0x0b01abed)
	HX_STACK_ARG(x,"x")
	HX_STACK_ARG(args,"args")
	HX_STACK_LINE(1030)
	::String output = x;		HX_STACK_VAR(output,"output");
	HX_STACK_LINE(1031)
	Dynamic precision = args->__Field(HX_CSTRING("precision"),true);		HX_STACK_VAR(precision,"precision");
	HX_STACK_LINE(1032)
	Dynamic width = args->__Field(HX_CSTRING("width"),true);		HX_STACK_VAR(width,"width");
	HX_STACK_LINE(1034)
	if (((precision > (int)0))){
		HX_STACK_LINE(1035)
		::String _g = x.substr((int)0,precision);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(1035)
		output = _g;
	}
	HX_STACK_LINE(1037)
	int k = output.length;		HX_STACK_VAR(k,"k");
	HX_STACK_LINE(1038)
	if (((bool((width > (int)0)) && bool((k < width))))){
		HX_STACK_LINE(1040)
		int _g1 = ::de::polygonal::_Printf::FormatFlags_obj::Minus->__Index();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(1040)
		int _g2 = (int((int)1) << int(_g1));		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(1040)
		int _g3 = (int(args->__Field(HX_CSTRING("flags"),true)) & int(_g2));		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(1040)
		if (((_g3 != (int)0))){
			HX_STACK_LINE(1041)
			::String _g4 = ::de::polygonal::Printf_obj::rpad(output,HX_CSTRING(" "),width);		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(1041)
			output = _g4;
		}
		else{
			HX_STACK_LINE(1043)
			::String _g5 = ::de::polygonal::Printf_obj::lpad(output,HX_CSTRING(" "),width);		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(1043)
			output = _g5;
		}
	}
	HX_STACK_LINE(1046)
	return output;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Printf_obj,formatString,return )

::String Printf_obj::formatNormalFloat( Float value,Dynamic args){
	HX_STACK_FRAME("de.polygonal.Printf","formatNormalFloat",0xeeb11a7f,"de.polygonal.Printf.formatNormalFloat","de/polygonal/Printf.hx",1050,0x0b01abed)
	HX_STACK_ARG(value,"value")
	HX_STACK_ARG(args,"args")
	HX_STACK_LINE(1051)
	::String output;		HX_STACK_VAR(output,"output");
	HX_STACK_LINE(1053)
	int flags = args->__Field(HX_CSTRING("flags"),true);		HX_STACK_VAR(flags,"flags");
	HX_STACK_LINE(1054)
	Dynamic precision = args->__Field(HX_CSTRING("precision"),true);		HX_STACK_VAR(precision,"precision");
	HX_STACK_LINE(1055)
	Dynamic width = args->__Field(HX_CSTRING("width"),true);		HX_STACK_VAR(width,"width");
	HX_STACK_LINE(1058)
	if (((precision == (int)-1))){
		HX_STACK_LINE(1058)
		precision = (int)6;
	}
	HX_STACK_LINE(1060)
	if (((precision == (int)0))){
		HX_STACK_LINE(1062)
		int _g = ::Math_obj::round(value);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(1062)
		int _g1 = ::de::polygonal::Printf_obj::iabs(_g);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(1062)
		::String _g2 = ::de::polygonal::Printf_obj::str(_g1);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(1062)
		output = _g2;
		HX_STACK_LINE(1065)
		int _g3 = ::de::polygonal::_Printf::FormatFlags_obj::Sharp->__Index();		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(1065)
		int _g4 = (int((int)1) << int(_g3));		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(1065)
		int _g5 = (int(flags) & int(_g4));		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(1065)
		if (((_g5 != (int)0))){
			HX_STACK_LINE(1065)
			hx::AddEq(output,HX_CSTRING("."));
		}
	}
	else{
		HX_STACK_LINE(1070)
		Float _g7;		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(1070)
		{
			HX_STACK_LINE(1070)
			Float y = ::Math_obj::pow(.1,precision);		HX_STACK_VAR(y,"y");
			HX_STACK_LINE(1070)
			int min = (int)-2147483647;		HX_STACK_VAR(min,"min");
			HX_STACK_LINE(1070)
			Float t = (Float(value) / Float(y));		HX_STACK_VAR(t,"t");
			HX_STACK_LINE(1070)
			if (((bool((t < (int)2147483647)) && bool((t > min))))){
				HX_STACK_LINE(1070)
				int _g6 = ::Math_obj::round(t);		HX_STACK_VAR(_g6,"_g6");
				HX_STACK_LINE(1070)
				_g7 = (_g6 * y);
			}
			else{
				HX_STACK_LINE(1070)
				if (((t > (int)0))){
					HX_STACK_LINE(1070)
					t = (t + .5);
				}
				else{
					HX_STACK_LINE(1070)
					if (((t < (int)0))){
						HX_STACK_LINE(1070)
						t = (t - .5);
					}
					else{
						HX_STACK_LINE(1070)
						t = t;
					}
				}
				HX_STACK_LINE(1070)
				_g7 = (((t - hx::Mod(t,(int)1))) * y);
			}
		}
		HX_STACK_LINE(1070)
		value = _g7;
		HX_STACK_LINE(1071)
		Dynamic decimalPlaces = precision;		HX_STACK_VAR(decimalPlaces,"decimalPlaces");
		HX_STACK_LINE(1072)
		if ((::Math_obj::isNaN(value))){
			HX_STACK_LINE(1073)
			output = HX_CSTRING("NaN");
		}
		else{
			HX_STACK_LINE(1076)
			Float _g8 = ::Math_obj::pow((int)10,decimalPlaces);		HX_STACK_VAR(_g8,"_g8");
			HX_STACK_LINE(1076)
			int t = ::Std_obj::_int(_g8);		HX_STACK_VAR(t,"t");
			HX_STACK_LINE(1077)
			int _g9 = ::Std_obj::_int((value * t));		HX_STACK_VAR(_g9,"_g9");
			HX_STACK_LINE(1077)
			Float _g10 = (Float(_g9) / Float(t));		HX_STACK_VAR(_g10,"_g10");
			HX_STACK_LINE(1077)
			::String _g11 = ::de::polygonal::Printf_obj::str(_g10);		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(1077)
			output = _g11;
			HX_STACK_LINE(1078)
			int i = output.indexOf(HX_CSTRING("."),null());		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(1079)
			if (((i != (int)-1))){
				HX_STACK_LINE(1081)
				int _g = output.substr((i + (int)1),null()).length;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(1081)
				while((true)){
					HX_STACK_LINE(1081)
					if ((!(((_g < decimalPlaces))))){
						HX_STACK_LINE(1081)
						break;
					}
					HX_STACK_LINE(1081)
					int i1 = (_g)++;		HX_STACK_VAR(i1,"i1");
					HX_STACK_LINE(1082)
					hx::AddEq(output,HX_CSTRING("0"));
				}
			}
			else{
				HX_STACK_LINE(1086)
				hx::AddEq(output,HX_CSTRING("."));
				HX_STACK_LINE(1087)
				{
					HX_STACK_LINE(1087)
					int _g = (int)0;		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(1087)
					while((true)){
						HX_STACK_LINE(1087)
						if ((!(((_g < decimalPlaces))))){
							HX_STACK_LINE(1087)
							break;
						}
						HX_STACK_LINE(1087)
						int i1 = (_g)++;		HX_STACK_VAR(i1,"i1");
						HX_STACK_LINE(1088)
						hx::AddEq(output,HX_CSTRING("0"));
					}
				}
			}
		}
	}
	HX_STACK_LINE(1093)
	int _g12 = ::de::polygonal::_Printf::FormatFlags_obj::Plus->__Index();		HX_STACK_VAR(_g12,"_g12");
	HX_STACK_LINE(1093)
	int _g13 = (int((int)1) << int(_g12));		HX_STACK_VAR(_g13,"_g13");
	HX_STACK_LINE(1093)
	int _g14 = (int(flags) & int(_g13));		HX_STACK_VAR(_g14,"_g14");
	HX_STACK_LINE(1093)
	if (((  (((_g14 != (int)0))) ? bool((value >= (int)0)) : bool(false) ))){
		HX_STACK_LINE(1094)
		output = (HX_CSTRING("+") + output);
	}
	else{
		HX_STACK_LINE(1096)
		int _g15 = ::de::polygonal::_Printf::FormatFlags_obj::Space->__Index();		HX_STACK_VAR(_g15,"_g15");
		HX_STACK_LINE(1096)
		int _g16 = (int((int)1) << int(_g15));		HX_STACK_VAR(_g16,"_g16");
		HX_STACK_LINE(1096)
		int _g17 = (int(flags) & int(_g16));		HX_STACK_VAR(_g17,"_g17");
		HX_STACK_LINE(1096)
		if (((  (((_g17 != (int)0))) ? bool((value >= (int)0)) : bool(false) ))){
			HX_STACK_LINE(1097)
			output = (HX_CSTRING(" ") + output);
		}
	}
	HX_STACK_LINE(1099)
	int _g18 = ::de::polygonal::_Printf::FormatFlags_obj::Zero->__Index();		HX_STACK_VAR(_g18,"_g18");
	HX_STACK_LINE(1099)
	int _g19 = (int((int)1) << int(_g18));		HX_STACK_VAR(_g19,"_g19");
	HX_STACK_LINE(1099)
	int _g20 = (int(flags) & int(_g19));		HX_STACK_VAR(_g20,"_g20");
	HX_STACK_LINE(1099)
	if (((_g20 != (int)0))){
		HX_STACK_LINE(1100)
		::String _g21 = ::de::polygonal::Printf_obj::lpad(output,HX_CSTRING("0"),(  (((value < (int)0))) ? int((width - (int)1)) : int(width) ));		HX_STACK_VAR(_g21,"_g21");
		HX_STACK_LINE(1100)
		output = _g21;
	}
	HX_STACK_LINE(1102)
	int _g22 = ::de::polygonal::_Printf::FormatFlags_obj::Minus->__Index();		HX_STACK_VAR(_g22,"_g22");
	HX_STACK_LINE(1102)
	int _g23 = (int((int)1) << int(_g22));		HX_STACK_VAR(_g23,"_g23");
	HX_STACK_LINE(1102)
	int _g24 = (int(flags) & int(_g23));		HX_STACK_VAR(_g24,"_g24");
	HX_STACK_LINE(1102)
	if (((_g24 != (int)0))){
		HX_STACK_LINE(1103)
		::String _g25 = ::de::polygonal::Printf_obj::rpad(output,HX_CSTRING(" "),width);		HX_STACK_VAR(_g25,"_g25");
		HX_STACK_LINE(1103)
		output = _g25;
	}
	else{
		HX_STACK_LINE(1105)
		::String _g26 = ::de::polygonal::Printf_obj::lpad(output,HX_CSTRING(" "),width);		HX_STACK_VAR(_g26,"_g26");
		HX_STACK_LINE(1105)
		output = _g26;
	}
	HX_STACK_LINE(1107)
	return output;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Printf_obj,formatNormalFloat,return )

::String Printf_obj::formatCharacter( int x,Dynamic args){
	HX_STACK_FRAME("de.polygonal.Printf","formatCharacter",0x70fb49b3,"de.polygonal.Printf.formatCharacter","de/polygonal/Printf.hx",1111,0x0b01abed)
	HX_STACK_ARG(x,"x")
	HX_STACK_ARG(args,"args")
	HX_STACK_LINE(1112)
	::String output = ::String::fromCharCode(x);		HX_STACK_VAR(output,"output");
	HX_STACK_LINE(1113)
	if (((args->__Field(HX_CSTRING("width"),true) > (int)1))){
		HX_STACK_LINE(1116)
		int _g = ::de::polygonal::_Printf::FormatFlags_obj::Minus->__Index();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(1116)
		int _g1 = (int((int)1) << int(_g));		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(1116)
		int _g2 = (int(args->__Field(HX_CSTRING("flags"),true)) & int(_g1));		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(1116)
		if (((_g2 != (int)0))){
			HX_STACK_LINE(1117)
			::String _g3 = ::de::polygonal::Printf_obj::rpad(output,HX_CSTRING(" "),args->__Field(HX_CSTRING("width"),true));		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(1117)
			output = _g3;
		}
		else{
			HX_STACK_LINE(1119)
			::String _g4 = ::de::polygonal::Printf_obj::lpad(output,HX_CSTRING(" "),args->__Field(HX_CSTRING("width"),true));		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(1119)
			output = _g4;
		}
	}
	HX_STACK_LINE(1122)
	return output;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Printf_obj,formatCharacter,return )

::String Printf_obj::padNumber( ::String x,Float n,int flags,int width){
	HX_STACK_FRAME("de.polygonal.Printf","padNumber",0xad0131fd,"de.polygonal.Printf.padNumber","de/polygonal/Printf.hx",1126,0x0b01abed)
	HX_STACK_ARG(x,"x")
	HX_STACK_ARG(n,"n")
	HX_STACK_ARG(flags,"flags")
	HX_STACK_ARG(width,"width")
	HX_STACK_LINE(1127)
	int k = x.length;		HX_STACK_VAR(k,"k");
	HX_STACK_LINE(1128)
	if (((bool((width > (int)0)) && bool((k < width))))){
		HX_STACK_LINE(1131)
		int _g = ::de::polygonal::_Printf::FormatFlags_obj::Minus->__Index();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(1131)
		int _g1 = (int((int)1) << int(_g));		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(1131)
		int _g2 = (int(flags) & int(_g1));		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(1131)
		if (((_g2 != (int)0))){
			HX_STACK_LINE(1132)
			::String _g3 = ::de::polygonal::Printf_obj::rpad(x,HX_CSTRING(" "),width);		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(1132)
			x = _g3;
		}
		else{
			HX_STACK_LINE(1135)
			if (((n >= (int)0))){
				HX_STACK_LINE(1136)
				int _g4 = ::de::polygonal::_Printf::FormatFlags_obj::Zero->__Index();		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(1136)
				int _g5 = (int((int)1) << int(_g4));		HX_STACK_VAR(_g5,"_g5");
				HX_STACK_LINE(1136)
				int _g6 = (int(flags) & int(_g5));		HX_STACK_VAR(_g6,"_g6");
				HX_STACK_LINE(1136)
				::String _g7;		HX_STACK_VAR(_g7,"_g7");
				HX_STACK_LINE(1136)
				if (((_g6 != (int)0))){
					HX_STACK_LINE(1136)
					_g7 = HX_CSTRING("0");
				}
				else{
					HX_STACK_LINE(1136)
					_g7 = HX_CSTRING(" ");
				}
				HX_STACK_LINE(1136)
				::String _g8 = ::de::polygonal::Printf_obj::lpad(x,_g7,width);		HX_STACK_VAR(_g8,"_g8");
				HX_STACK_LINE(1136)
				x = _g8;
			}
			else{
				HX_STACK_LINE(1139)
				int _g9 = ::de::polygonal::_Printf::FormatFlags_obj::Zero->__Index();		HX_STACK_VAR(_g9,"_g9");
				HX_STACK_LINE(1139)
				int _g10 = (int((int)1) << int(_g9));		HX_STACK_VAR(_g10,"_g10");
				HX_STACK_LINE(1139)
				int _g11 = (int(flags) & int(_g10));		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(1139)
				if (((_g11 != (int)0))){
					HX_STACK_LINE(1142)
					::String _g12 = x.substr((int)1,null());		HX_STACK_VAR(_g12,"_g12");
					HX_STACK_LINE(1142)
					::String _g13 = ::de::polygonal::Printf_obj::lpad(_g12,HX_CSTRING("0"),width);		HX_STACK_VAR(_g13,"_g13");
					HX_STACK_LINE(1142)
					::String _g14 = (HX_CSTRING("-") + _g13);		HX_STACK_VAR(_g14,"_g14");
					HX_STACK_LINE(1142)
					x = _g14;
				}
				else{
					HX_STACK_LINE(1145)
					::String _g15 = ::de::polygonal::Printf_obj::lpad(x,HX_CSTRING(" "),width);		HX_STACK_VAR(_g15,"_g15");
					HX_STACK_LINE(1145)
					x = _g15;
				}
			}
		}
	}
	HX_STACK_LINE(1150)
	return x;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Printf_obj,padNumber,return )

::String Printf_obj::lpad( ::String s,::String c,int l){
	HX_STACK_FRAME("de.polygonal.Printf","lpad",0x8c47a686,"de.polygonal.Printf.lpad","de/polygonal/Printf.hx",1154,0x0b01abed)
	HX_STACK_ARG(s,"s")
	HX_STACK_ARG(c,"c")
	HX_STACK_ARG(l,"l")
	HX_STACK_LINE(1155)
	if (((c.length <= (int)0))){
		HX_STACK_LINE(1155)
		HX_STACK_DO_THROW(HX_CSTRING("c.length <= 0"));
	}
	HX_STACK_LINE(1156)
	while((true)){
		HX_STACK_LINE(1156)
		if ((!(((s.length < l))))){
			HX_STACK_LINE(1156)
			break;
		}
		HX_STACK_LINE(1156)
		s = (c + s);
	}
	HX_STACK_LINE(1157)
	return s;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Printf_obj,lpad,return )

::String Printf_obj::rpad( ::String s,::String c,int l){
	HX_STACK_FRAME("de.polygonal.Printf","rpad",0x903eee40,"de.polygonal.Printf.rpad","de/polygonal/Printf.hx",1161,0x0b01abed)
	HX_STACK_ARG(s,"s")
	HX_STACK_ARG(c,"c")
	HX_STACK_ARG(l,"l")
	HX_STACK_LINE(1162)
	if (((c.length <= (int)0))){
		HX_STACK_LINE(1162)
		HX_STACK_DO_THROW(HX_CSTRING("c.length <= 0"));
	}
	HX_STACK_LINE(1163)
	while((true)){
		HX_STACK_LINE(1163)
		if ((!(((s.length < l))))){
			HX_STACK_LINE(1163)
			break;
		}
		HX_STACK_LINE(1163)
		s = (s + c);
	}
	HX_STACK_LINE(1164)
	return s;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Printf_obj,rpad,return )

::String Printf_obj::toHex( int x){
	HX_STACK_FRAME("de.polygonal.Printf","toHex",0xcce28521,"de.polygonal.Printf.toHex","de/polygonal/Printf.hx",1168,0x0b01abed)
	HX_STACK_ARG(x,"x")
	HX_STACK_LINE(1174)
	::String s = HX_CSTRING("");		HX_STACK_VAR(s,"s");
	HX_STACK_LINE(1175)
	::String hexChars = HX_CSTRING("0123456789ABCDEF");		HX_STACK_VAR(hexChars,"hexChars");
	HX_STACK_LINE(1176)
	while((true)){
		HX_STACK_LINE(1178)
		::String _g = hexChars.charAt((int(x) & int((int)15)));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(1178)
		::String _g1 = (_g + s);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(1178)
		s = _g1;
		HX_STACK_LINE(1179)
		hx::UShrEq(x,(int)4);
		HX_STACK_LINE(1176)
		if ((!(((x > (int)0))))){
			HX_STACK_LINE(1176)
			break;
		}
	}
	HX_STACK_LINE(1183)
	return s;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Printf_obj,toHex,return )

::String Printf_obj::toOct( int x){
	HX_STACK_FRAME("de.polygonal.Printf","toOct",0xcce7d326,"de.polygonal.Printf.toOct","de/polygonal/Printf.hx",1187,0x0b01abed)
	HX_STACK_ARG(x,"x")
	HX_STACK_LINE(1188)
	::String s = HX_CSTRING("");		HX_STACK_VAR(s,"s");
	HX_STACK_LINE(1189)
	int t = x;		HX_STACK_VAR(t,"t");
	HX_STACK_LINE(1190)
	while((true)){
		HX_STACK_LINE(1192)
		s = (((int(t) & int((int)7))) + s);
		HX_STACK_LINE(1193)
		hx::UShrEq(t,(int)3);
		HX_STACK_LINE(1190)
		if ((!(((t > (int)0))))){
			HX_STACK_LINE(1190)
			break;
		}
	}
	HX_STACK_LINE(1196)
	return s;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Printf_obj,toOct,return )

int Printf_obj::iabs( int x){
	HX_STACK_FRAME("de.polygonal.Printf","iabs",0x8a40a1c8,"de.polygonal.Printf.iabs","de/polygonal/Printf.hx",1199,0x0b01abed)
	HX_STACK_ARG(x,"x")
	HX_STACK_LINE(1199)
	Float _g = ::Math_obj::abs(x);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(1199)
	return ::Std_obj::_int(_g);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Printf_obj,iabs,return )

::String Printf_obj::str( Dynamic x){
	HX_STACK_FRAME("de.polygonal.Printf","str",0xe3f34772,"de.polygonal.Printf.str","de/polygonal/Printf.hx",1201,0x0b01abed)
	HX_STACK_ARG(x,"x")
	HX_STACK_LINE(1201)
	return ::Std_obj::string(x);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Printf_obj,str,return )

int Printf_obj::codeAt( ::String x,int i){
	HX_STACK_FRAME("de.polygonal.Printf","codeAt",0xbfc29f5f,"de.polygonal.Printf.codeAt","de/polygonal/Printf.hx",1203,0x0b01abed)
	HX_STACK_ARG(x,"x")
	HX_STACK_ARG(i,"i")
	HX_STACK_LINE(1203)
	return x.cca(i);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Printf_obj,codeAt,return )

bool Printf_obj::isDigit( int x){
	HX_STACK_FRAME("de.polygonal.Printf","isDigit",0x336624a4,"de.polygonal.Printf.isDigit","de/polygonal/Printf.hx",1205,0x0b01abed)
	HX_STACK_ARG(x,"x")
	HX_STACK_LINE(1205)
	return (bool((x >= (int)48)) && bool((x <= (int)57)));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Printf_obj,isDigit,return )

Float Printf_obj::roundTo( Float x,Float y){
	HX_STACK_FRAME("de.polygonal.Printf","roundTo",0x4a2804aa,"de.polygonal.Printf.roundTo","de/polygonal/Printf.hx",1208,0x0b01abed)
	HX_STACK_ARG(x,"x")
	HX_STACK_ARG(y,"y")
	HX_STACK_LINE(1214)
	int min = (int)-2147483647;		HX_STACK_VAR(min,"min");
	HX_STACK_LINE(1215)
	Float t = (Float(x) / Float(y));		HX_STACK_VAR(t,"t");
	HX_STACK_LINE(1216)
	if (((bool((t < (int)2147483647)) && bool((t > min))))){
		HX_STACK_LINE(1217)
		int _g = ::Math_obj::round(t);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(1217)
		return (_g * y);
	}
	else{
		HX_STACK_LINE(1220)
		if (((t > (int)0))){
			HX_STACK_LINE(1220)
			t = (t + .5);
		}
		else{
			HX_STACK_LINE(1220)
			if (((t < (int)0))){
				HX_STACK_LINE(1220)
				t = (t - .5);
			}
			else{
				HX_STACK_LINE(1220)
				t = t;
			}
		}
		HX_STACK_LINE(1221)
		return (((t - hx::Mod(t,(int)1))) * y);
	}
	HX_STACK_LINE(1216)
	return 0.;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Printf_obj,roundTo,return )


Printf_obj::Printf_obj()
{
}

Dynamic Printf_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"str") ) { return str_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"init") ) { return init_dyn(); }
		if (HX_FIELD_EQ(inName,"lpad") ) { return lpad_dyn(); }
		if (HX_FIELD_EQ(inName,"rpad") ) { return rpad_dyn(); }
		if (HX_FIELD_EQ(inName,"iabs") ) { return iabs_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"toHex") ) { return toHex_dyn(); }
		if (HX_FIELD_EQ(inName,"toOct") ) { return toOct_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"format") ) { return format_dyn(); }
		if (HX_FIELD_EQ(inName,"codeAt") ) { return codeAt_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"isDigit") ) { return isDigit_dyn(); }
		if (HX_FIELD_EQ(inName,"roundTo") ) { return roundTo_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"tokenize") ) { return tokenize_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"padNumber") ) { return padNumber_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"dataTypeMap") ) { return dataTypeMap; }
		if (HX_FIELD_EQ(inName,"formatOctal") ) { return formatOctal_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_initialized") ) { return _initialized; }
		if (HX_FIELD_EQ(inName,"formatBinary") ) { return formatBinary_dyn(); }
		if (HX_FIELD_EQ(inName,"formatString") ) { return formatString_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"makeDataTypeMap") ) { return makeDataTypeMap_dyn(); }
		if (HX_FIELD_EQ(inName,"formatCharacter") ) { return formatCharacter_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"formatScientific") ) { return formatScientific_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"formatIntFuncHash") ) { return formatIntFuncHash; }
		if (HX_FIELD_EQ(inName,"formatHexadecimal") ) { return formatHexadecimal_dyn(); }
		if (HX_FIELD_EQ(inName,"formatNormalFloat") ) { return formatNormalFloat_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"formatNaturalFloat") ) { return formatNaturalFloat_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"formatFloatFuncHash") ) { return formatFloatFuncHash; }
		if (HX_FIELD_EQ(inName,"formatSignedDecimal") ) { return formatSignedDecimal_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"formatStringFuncHash") ) { return formatStringFuncHash; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"formatUnsignedDecimal") ) { return formatUnsignedDecimal_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Printf_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 11:
		if (HX_FIELD_EQ(inName,"dataTypeMap") ) { dataTypeMap=inValue.Cast< ::haxe::ds::IntMap >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_initialized") ) { _initialized=inValue.Cast< bool >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"formatIntFuncHash") ) { formatIntFuncHash=inValue.Cast< ::haxe::ds::IntMap >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"formatFloatFuncHash") ) { formatFloatFuncHash=inValue.Cast< ::haxe::ds::IntMap >(); return inValue; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"formatStringFuncHash") ) { formatStringFuncHash=inValue.Cast< ::haxe::ds::IntMap >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Printf_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("dataTypeMap"),
	HX_CSTRING("formatIntFuncHash"),
	HX_CSTRING("formatFloatFuncHash"),
	HX_CSTRING("formatStringFuncHash"),
	HX_CSTRING("_initialized"),
	HX_CSTRING("init"),
	HX_CSTRING("makeDataTypeMap"),
	HX_CSTRING("format"),
	HX_CSTRING("tokenize"),
	HX_CSTRING("formatBinary"),
	HX_CSTRING("formatOctal"),
	HX_CSTRING("formatHexadecimal"),
	HX_CSTRING("formatUnsignedDecimal"),
	HX_CSTRING("formatNaturalFloat"),
	HX_CSTRING("formatScientific"),
	HX_CSTRING("formatSignedDecimal"),
	HX_CSTRING("formatString"),
	HX_CSTRING("formatNormalFloat"),
	HX_CSTRING("formatCharacter"),
	HX_CSTRING("padNumber"),
	HX_CSTRING("lpad"),
	HX_CSTRING("rpad"),
	HX_CSTRING("toHex"),
	HX_CSTRING("toOct"),
	HX_CSTRING("iabs"),
	HX_CSTRING("str"),
	HX_CSTRING("codeAt"),
	HX_CSTRING("isDigit"),
	HX_CSTRING("roundTo"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Printf_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Printf_obj::dataTypeMap,"dataTypeMap");
	HX_MARK_MEMBER_NAME(Printf_obj::formatIntFuncHash,"formatIntFuncHash");
	HX_MARK_MEMBER_NAME(Printf_obj::formatFloatFuncHash,"formatFloatFuncHash");
	HX_MARK_MEMBER_NAME(Printf_obj::formatStringFuncHash,"formatStringFuncHash");
	HX_MARK_MEMBER_NAME(Printf_obj::_initialized,"_initialized");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Printf_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Printf_obj::dataTypeMap,"dataTypeMap");
	HX_VISIT_MEMBER_NAME(Printf_obj::formatIntFuncHash,"formatIntFuncHash");
	HX_VISIT_MEMBER_NAME(Printf_obj::formatFloatFuncHash,"formatFloatFuncHash");
	HX_VISIT_MEMBER_NAME(Printf_obj::formatStringFuncHash,"formatStringFuncHash");
	HX_VISIT_MEMBER_NAME(Printf_obj::_initialized,"_initialized");
};

#endif

Class Printf_obj::__mClass;

void Printf_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("de.polygonal.Printf"), hx::TCanCast< Printf_obj> ,sStaticFields,sMemberFields,
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

void Printf_obj::__boot()
{
	_initialized= false;
}

} // end namespace de
} // end namespace polygonal
