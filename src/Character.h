#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <Box2D/Box2D.h>
#include <SDL2/SDL.h>

#include "Dir.h"
#include "GameBody.h"

class Character :public GameBody {
public:
    Character(b2World* world, const std::string texture, b2Vec2 pos, b2Vec2 dim,
	  float density, float friction, float restitution, int hp, int base_vel);
    ~Character();
    // Move in a specific direction
    virtual void Move(Dir dir) = 0;
    // Jump in a given direction
    virtual void Jump(Dir dir) = 0;
    // Get dir character is facing
    Dir GetDir();
    // Perform attack
    virtual void Attack() = 0;
    virtual std::string GetType();
protected:
    Dir dir_ = Dir::RIGHT;
    int hp_;
    int base_vel_;
};

#endif
