#ifndef PHYS_BODY_H
#define PHYS_BODY_H

#include <Box2D/Box2D.h>
#include <SDL2/SDL.h>

class PhysBody {
 private:
    SDL_Texture* texture = NULL;
    b2Body* body = NULL;
 public:
    PhysBody(SDL_Texture* texture);
    ~PhysBody();
    SDL_Texture* GetTexture();
    b2Body* GetBody();
};

#endif
