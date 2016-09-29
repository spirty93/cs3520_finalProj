#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <SDL2/SDL.h>
#include <Box2D/Box2D.h>
#include<SDL2/SDL_image.h>

class Game {
 private:
    SDL_Window* gameWindow = NULL;
    SDL_Renderer* gameRenderer = NULL;
    b2World* world;

    void init();
    void load_resources();
    int window_width;
    int window_height;
 public:
    Game(const int width, const int height);
    ~Game();
    bool run();
};

#endif
