CC = g++
TAGS = -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -Wall -std=c++11 -lBox2d
TARGET = -o build/game
FILES = src/*.cpp

all: $(FILES)
	$(CC) $(TARGET) $(FILES) $(TAGS)
	cp -r resources build/

debug: $(FILES)
	$(CC) $(TARGET) $(FILES) $(TAGS) -g -O0

run: all
	./build/game
