#ifndef PORTAL_H
#define PORTAL_H

#include <iostream>
#include <Box2D/Box2D.h>
#include <SDL2/SDL.h>

#include "Game.h"
#include "GameBody.h"

class Portal: public GameBody {
public:
    Portal(b2World* world, const std::string texture, b2Vec2 pos, b2Vec2 dim, Game* game, std::string to);
    ~Portal();
    void HandleCollision(std::string other);
private:
    Game* game_;
    std::string to_;
};

#endif
