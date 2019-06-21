LOCAL_PATH := $(call my-dir)


include $(CLEAR_VARS)
LOCAL_LDFLAGS := -Wl,-v #very important,can see gcc config
LOCAL_MODULE  := ThreadTest

LOCAL_C_INCLUDES := $(LOCAL_PATH) \

#link static libraries
LOCAL_LDLIBS    := -llog -lc\

LOCAL_SRC_FILES := ./ThreadTest.cpp

include $(BUILD_SHARED_LIBRARY)

##############################################################################
include $(CLEAR_VARS)
LOCAL_LDFLAGS := -Wl,-v #very important,can see gcc config
LOCAL_MODULE  := JNITest
					
LOCAL_C_INCLUDES := $(LOCAL_PATH) \

#link static libraries
LOCAL_LDLIBS    := -llog -lc\

LOCAL_SRC_FILES := ./JNITest.cpp \
				   ./DllHelper.cpp

include $(BUILD_SHARED_LIBRARY)
