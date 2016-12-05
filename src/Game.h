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
    /*
     * @param width: the width of the game window
     * @param height: the height of the game window
     * Constructor for the game instance
     */
    Game(const int width, const int height);
    /*
     * Game instance destructor
     */
    ~Game();
    /*
     * Starts the main loop of the program
     */
    bool run();
    /*
     * @param the string representation of the level going to
     * The level change callback
     */
    bool triggerLoadLevel(std::string to);
private:
    SDL_Window* gameWindow = NULL; //game widndow instance
    SDL_Renderer* gameRenderer = NULL; //renderer instance
    Level l; // level instance
    b2World* world; // the box2d world

    std::map<std::string, SDL_Texture*> textureMap; // string to texture map

    /*
     * The init method. Initializes the window and sdl and box2d specific features

     */
    void init();
    /*
     * load the level specific stuff. Create instances of gameojects
     */
    void load_resources();

    const int window_width_; // window width
    const int window_height_; // window height
    bool resources_loaded_ = false; // flag to see if we already loaded all resources

    // the destination level if not an empty string will start the level load on next run cycle
    std::string level_to_ = "";
};

#endif
