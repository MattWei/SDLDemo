LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := main

SRC_PATH := ../../../common/
SDL_INCLUDE := SDL
SDL_SRC_PATH := ../../../../SDL2-2.0.3/

LOCAL_SRC_FILES := $(SDL_SRC_PATH)/src/main/android/SDL_android_main.c \
	$(SRC_PATH)/main.cpp \
	$(SRC_PATH)/Game.cpp

LOCAL_LDLIBS    := -llog -landroid -lEGL -lGLESv1_CM

LOCAL_C_INCLUDES += $(SDL_INCLUDE)/include/

LOCAL_CFLAGS += -I$(SDL_INCLUDE)/include/

LOCAL_STATIC_LIBRARIES := googletest_main
LOCAL_SHARED_LIBRARIES := SDL2 SDL2_image SDL2_mixer SDL2_net SDL2_ttf

include $(BUILD_SHARED_LIBRARY)

$(call import-module,SDL2-2.0.3)
