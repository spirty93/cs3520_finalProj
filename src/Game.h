#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <Box2D/Box2D.h>
#include <map>
#include <algorithm>

#include "Level.h"

class Game {
private:
    SDL_Window* gameWindow = NULL;
    SDL_Renderer* gameRenderer = NULL;
    b2World* world;
    Level l;
    std::map<std::string, SDL_Texture*> textureMap;

    void init();
    void load_resources();
    const int window_width;
    const int window_height;
    bool resources_loaded_ = false;
public:
    Game(const int width, const int height);
    ~Game();
    bool run();
};

#endif
