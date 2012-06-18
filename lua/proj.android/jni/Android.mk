LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_CFLAGS    := -DKILLA -DKILLA_COMPAT_ALL -DNDK_ANDROID

LOCAL_MODULE    := lua_shared

LOCAL_MODULE_FILENAME := liblua

LOCAL_SRC_FILES :=../../killa/kapi.c \
                  ../../killa/kauxlib.c \
		  ../../killa/kbaselib.c \
		  ../../killa/kcode.c \
		  ../../killa/kdblib.c \
		  ../../killa/kdebug.c \
		  ../../killa/kdo.c \
		  ../../killa/kdump.c \
		  ../../killa/kfunc.c \
		  ../../killa/kgc.c \
		  ../../killa/kinit.c \
		  ../../killa/kiolib.c \
		  ../../killa/klex.c \
		  ../../killa/kmathlib.c \
		  ../../killa/kmem.c \
		  ../../killa/kobject.c \
		  ../../killa/kopcodes.c \
		  ../../killa/koslib.c \
		  ../../killa/kparser.c \
		  ../../killa/kstate.c \
		  ../../killa/kstring.c \
		  ../../killa/kstrlib.c \
		  ../../killa/ktable.c \
		  ../../killa/ktablib.c \
		  ../../killa/ktm.c \
		  ../../killa/killa.c \
		  ../../killa/kundump.c \
		  ../../killa/kvm.c \
		  ../../killa/kzio.c \
          ../../killa/kbitlib.c \
		  ../../killa/kcorolib.c \
		  ../../killa/kctype.c \
		  ../../killa/koadlib.c \
		  ../../tolua/tolua_event.c \
		  ../../tolua/tolua_is.c \
		  ../../tolua/tolua_map.c \
		  ../../tolua/tolua_push.c \
		  ../../tolua/tolua_to.c
		  
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/../../killa \
                           $(LOCAL_PATH)/../../tolua \
                           $(LOCAL_PATH)/../../cocos2dx_support 
		  
		  
LOCAL_C_INCLUDES := $(LOCAL_PATH)/ \
                    $(LOCAL_PATH)/../../killa
                    

include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)

LOCAL_CFLAGS    := -DKILLA -DKILLA_COMPAT_ALL -DNDK_ANDROID

LOCAL_MODULE    := cocos_lua_static

LOCAL_MODULE_FILENAME := liblua

LOCAL_SRC_FILES :=../../killa/kapi.c \
                  ../../killa/kauxlib.c \
		  ../../killa/kbaselib.c \
		  ../../killa/kcode.c \
		  ../../killa/kdblib.c \
		  ../../killa/kdebug.c \
		  ../../killa/kdo.c \
		  ../../killa/kdump.c \
		  ../../killa/kfunc.c \
		  ../../killa/kgc.c \
		  ../../killa/kinit.c \
		  ../../killa/kiolib.c \
		  ../../killa/klex.c \
		  ../../killa/kmathlib.c \
		  ../../killa/kmem.c \
		  ../../killa/kobject.c \
		  ../../killa/kopcodes.c \
		  ../../killa/koslib.c \
		  ../../killa/kparser.c \
		  ../../killa/kstate.c \
		  ../../killa/kstring.c \
		  ../../killa/kstrlib.c \
		  ../../killa/ktable.c \
		  ../../killa/ktablib.c \
		  ../../killa/ktm.c \
		  ../../killa/killa.c \
		  ../../killa/kundump.c \
		  ../../killa/kvm.c \
		  ../../killa/kzio.c \
		  ../../killa/kbitlib.c \
		  ../../killa/kcorolib.c \
		  ../../killa/kctype.c \
		  ../../killa/koadlib.c \
		  ../../tolua/tolua_event.c \
		  ../../tolua/tolua_is.c \
		  ../../tolua/tolua_map.c \
		  ../../tolua/tolua_push.c \
		  ../../tolua/tolua_to.c
		  
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/../../killa \
                           $(LOCAL_PATH)/../../tolua \
                           $(LOCAL_PATH)/../../cocos2dx_support 
		  
		  
LOCAL_C_INCLUDES := $(LOCAL_PATH)/ \
                    $(LOCAL_PATH)/../../killa
                    

include $(BUILD_STATIC_LIBRARY)
