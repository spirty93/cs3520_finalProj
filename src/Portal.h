#ifndef PORTAL_H
#define PORTAL_H

#include <iostream>
#include <Box2D/Box2D.h>
#include <SDL2/SDL.h>

#include "Game.h"
#include "GameBody.h"

class Portal: public GameBody {
public:
    /*
     * @param world the sdl 2 representation of the world
     * @param texture the texture associated with the object
     * @param pos a b2Vec2 that represents the position of the object in the world
     * @param dim a b2Vec2 that represents the size of the object
     *
     * Constucts the instance of the body that is not able to move through the world and is not affected
     * by the external forces
     */
    Portal(b2World* world, const std::string texture, b2Vec2 pos, b2Vec2 dim, Game* game, std::string to);
    ~Portal();
    /*
     * @param other string representing the object
     * Collision handler for the body.
     */
    void HandleCollision(std::string other);
private:
    Game* game_; // pointer to the game instance
    std::string to_; // the level pointing to
};

#endif
