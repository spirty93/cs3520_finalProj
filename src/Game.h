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
public:
    Game(const int width, const int height);
    ~Game();
    bool run();
    bool triggerLoadLevel(std::string to);
private:
    SDL_Window* gameWindow = NULL;
    SDL_Renderer* gameRenderer = NULL;
    Level l;
    b2World* world;

    std::map<std::string, SDL_Texture*> textureMap;

    void init();
    void load_resources();
    const int window_width;
    const int window_height;
    bool resources_loaded_ = false;
    std::string level_to_ = "";
};

#endif
