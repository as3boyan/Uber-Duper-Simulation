#include <hxcpp.h>

#ifndef INCLUDED_cpp_Lib
#include <cpp/Lib.h>
#endif
#ifndef INCLUDED_haxe_io_Output
#include <haxe/io/Output.h>
#endif
#ifndef INCLUDED_sys_io_File
#include <sys/io/File.h>
#endif
#ifndef INCLUDED_sys_io_FileOutput
#include <sys/io/FileOutput.h>
#endif
namespace sys{
namespace io{

Void File_obj::__construct()
{
	return null();
}

//File_obj::~File_obj() { }

Dynamic File_obj::__CreateEmpty() { return  new File_obj; }
hx::ObjectPtr< File_obj > File_obj::__new()
{  hx::ObjectPtr< File_obj > result = new File_obj();
	result->__construct();
	return result;}

Dynamic File_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< File_obj > result = new File_obj();
	result->__construct();
	return result;}

::sys::io::FileOutput File_obj::write( ::String path,hx::Null< bool >  __o_binary){
bool binary = __o_binary.Default(true);
	HX_STACK_FRAME("sys.io.File","write",0xfec8a9f4,"sys.io.File.write","D:\\Denis\\PortableSoft\\HaxeToolkit\\haxe\\std/cpp/_std/sys/io/File.hx",53,0x2ed6c888)
	HX_STACK_ARG(path,"path")
	HX_STACK_ARG(binary,"binary")
{
		HX_STACK_LINE(54)
		Dynamic _g = ::sys::io::File_obj::file_open(path,(  ((binary)) ? ::String(HX_CSTRING("wb")) : ::String(HX_CSTRING("w")) ));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(54)
		return ::sys::io::FileOutput_obj::__new(_g);
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(File_obj,write,return )

Dynamic File_obj::file_open;


File_obj::File_obj()
{
}

Dynamic File_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"write") ) { return write_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"file_open") ) { return file_open; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic File_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"file_open") ) { file_open=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void File_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("write"),
	HX_CSTRING("file_open"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(File_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(File_obj::file_open,"file_open");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(File_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(File_obj::file_open,"file_open");
};

#endif

Class File_obj::__mClass;

void File_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("sys.io.File"), hx::TCanCast< File_obj> ,sStaticFields,sMemberFields,
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

void File_obj::__boot()
{
	file_open= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("file_open"),(int)2);
}

} // end namespace sys
} // end namespace io
