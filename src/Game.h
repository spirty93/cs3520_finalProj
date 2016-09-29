#include <iostream>
#include <SDL2/SDL.h>
#include <Box2D/Box2D.h>

class Game {
 private:
    SDL_Window* gameWindow = NULL;
    SDL_Surface* gameScreenSurface = NULL;
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
