#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <Box2D/Box2D.h>
#include <SDL2/SDL.h>

#include "Dir.h"
#include "GameBody.h"

class Character :public GameBody {
private:
    Dir dir = Dir::UP;
public:
    Character(b2World& world, const SDL_Texture* texture, b2Vec2 pos, b2Vec2 dim,
	  float density, float friction, float restitution, int hp, int base_vel);
    ~Character();
    // Move in a specific direction
    virtual void Move(Dir dir);
    // Jump in a given direction
    virtual void Jump(Dir dir);
    // Get dir character is facing
    Dir GetDir();
    // Perform attack
    virtual void Attack();
};

#endif
