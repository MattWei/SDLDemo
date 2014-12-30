LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := main

SRC_PATH := ../../../common/
SDL_PATH := ../../../../SDL2-2.0.3/

LOCAL_SRC_FILES := $(SRC_PATH)/main.cpp \
	$(SRC_PATH)/Game.cpp

LOCAL_LDLIBS    := -llog -landroid -lEGL -lGLESv1_CM

LOCAL_C_INCLUDES += $(SDL_PATH)/include/

LOCAL_CFLAGS += -I$(SDL_PATH)/include/

LOCAL_STATIC_LIBRARIES := googletest_main
LOCAL_STATIC_LIBRARIES := SDL2_static

include $(BUILD_SHARED_LIBRARY)

$(call import-module,SDL2-2.0.3)
