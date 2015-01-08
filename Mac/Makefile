TARGET := sdlDemo

#SDL_PATH := /Users/weimj/sources/SDLLearning/SDLGameDemo/libSDL_Mac

SDL_PATH := /opt/local/
CFLAGS += -I$(SDL_PATH)/include/SDL2 -I../SDLGameDev2 -I../common-framework -I/opt/local/include/
LDFLAGS += -L$(SDL_PATH)/lib -lSDL2main -lSDL2 -lSDL2_image -ltinyxml \
	-framework OpenGL -framework Cocoa

OBJS := $(patsubst %.cpp,%.o,$(wildcard ../common-framework/*.cpp))
OBJS += $(patsubst %.cpp,%.o,$(wildcard ../SDLGameDev2/*.cpp))

CC := g++

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -std=c++11 `$(SDL_PATH)/bin/sdl2-config --cflags --libs` $(CFLAGS) $(LDFLAGS) $(OBJS) -o $@

$(OBJS): %.o: %.cpp
	$(CC) -std=c++11 -c $(CFLAGS) $< -o $@

.PHONY:
clean:
	rm -rf *.o main ../SDLGameDev2/*.o ../common-framework/*.o