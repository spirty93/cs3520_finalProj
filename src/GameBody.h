#ifndef GAME_BODY_H
#define GAME_BODY_H

#include <iostream>
#include <Box2D/Box2D.h>
#include <SDL2/SDL.h>

class GameBody {
private:
    SDL_Texture* texture = NULL;
    b2Body* body = NULL;
public:
    // Dynamic body constructor
    GameBody(b2World& world, const SDL_Texture* texture, b2Vec2 pos, b2Vec2 dim,
	      float density, float friction, float restitution);

    // Static body constructor
    GameBody(b2World& world, const SDL_Texture* texture, b2Vec2 pos, b2Vec2 dim);

    ~GameBody();

    // Get the texture of the game body
    SDL_Texture* GetTexture();

    // get the box2d body representation of the body
    b2Body* GetBody();

};

#endif
