#ifndef GAME_BODY_H
#define GAME_BODY_H

#include <iostream>
#include <Box2D/Box2D.h>
#include <SDL2/SDL.h>

class GameBody {
public:
    // Dynamic body constructor
    GameBody(b2World* world, const std::string texture, b2Vec2 pos, b2Vec2 dim,
	      float density, float friction, float restitution);

    // Static body constructor
    GameBody(b2World* world, const std::string texture, b2Vec2 pos, b2Vec2 dim);

    ~GameBody();

    // Get the texture of the game body
    const std::string GetTexture() const noexcept;

    // get the box2d body representation of the body
    b2Body* GetBody() const noexcept;

    SDL_Rect GetTexRect() const noexcept;

    SDL_Rect GetPosRect() const noexcept;
private:
    std::string texture_;
    b2Body* body_ = NULL;
    const float width_;
    const float height_;
};

#endif
