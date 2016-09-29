CC = g++
TAGS = -lSDL2 -lSDL2_image -Wall -std=c++11 -lBox2d
LIBS = $(shell sdl2-config --libs)
TARGET = -o build/game
FILES = src/*.cpp

all: $(FILES)
	$(CC) $(TARGET) $(FILES) $(TAGS) $(LIBS)

debug: $(FILES)
	$(CC) $(TARGET) $(FILES) $(TAGS) $(LIBS) -g -O0
