#ifndef INCLUDED_de_polygonal__Printf_IntegerType
#define INCLUDED_de_polygonal__Printf_IntegerType

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(de,polygonal,_Printf,IntegerType)
namespace de{
namespace polygonal{
namespace _Printf{


class IntegerType_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef IntegerType_obj OBJ_;

	public:
		IntegerType_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("de.polygonal._Printf.IntegerType"); }
		::String __ToString() const { return HX_CSTRING("IntegerType.") + tag; }

		static ::de::polygonal::_Printf::IntegerType IBin;
		static inline ::de::polygonal::_Printf::IntegerType IBin_dyn() { return IBin; }
		static ::de::polygonal::_Printf::IntegerType ICharacter;
		static inline ::de::polygonal::_Printf::IntegerType ICharacter_dyn() { return ICharacter; }
		static ::de::polygonal::_Printf::IntegerType IHex;
		static inline ::de::polygonal::_Printf::IntegerType IHex_dyn() { return IHex; }
		static ::de::polygonal::_Printf::IntegerType IOctal;
		static inline ::de::polygonal::_Printf::IntegerType IOctal_dyn() { return IOctal; }
		static ::de::polygonal::_Printf::IntegerType ISignedDecimal;
		static inline ::de::polygonal::_Printf::IntegerType ISignedDecimal_dyn() { return ISignedDecimal; }
		static ::de::polygonal::_Printf::IntegerType IUnsignedDecimal;
		static inline ::de::polygonal::_Printf::IntegerType IUnsignedDecimal_dyn() { return IUnsignedDecimal; }
};

} // end namespace de
} // end namespace polygonal
} // end namespace _Printf

#endif /* INCLUDED_de_polygonal__Printf_IntegerType */ 
