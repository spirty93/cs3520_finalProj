CC = g++
TAGS = -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -Wall -std=c++11 -lBox2d
LIBS = $(shell sdl2-config --libs)
TARGET = -o build/game
FILES = src/*.cpp

all: $(FILES)
	$(CC) $(TARGET) $(FILES) $(TAGS) $(LIBS)

debug: $(FILES)
	$(CC) $(TARGET) $(FILES) $(TAGS) $(LIBS) -g -O0

run: all
	./build/game
