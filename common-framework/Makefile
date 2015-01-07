TARGET := sdlDemo

#SDL_PATH := /Users/weimj/sources/SDLLearning/SDLGameDemo/libSDL_Mac

SDL_PATH := /opt/local/
CFLAGS += -I$(SDL_PATH)/include/SDL2
LDFLAGS += -L$(SDL_PATH)/lib -lSDL2main -lSDL2 -lSDL2_image -ltinyxml \
	-framework OpenGL -framework Cocoa

OBJS := $(patsubst %.cpp,%.o,$(wildcard *.cpp))

CC := g++

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) `$(SDL_PATH)/bin/sdl2-config --cflags --libs` $(CFLAGS) $(LDFLAGS) $(OBJS) -o $@

$(OBJS): %.o: %.cpp
	$(CC) -c $(CFLAGS) $< -o $@

.PHONY:
clean:
	rm -rf *.o main