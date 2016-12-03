#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
#include <Box2D/Box2D.h>
#include <SDL2/SDL.h>

#include "Character.h"

class Enemy :public Character {
public:
    Enemy(b2World* world, const std::string texture, b2Vec2 pos, b2Vec2 dim,
	  float density, float friction, float restitution, int hp, int base_vel);
    ~Enemy();
    // Move enemy in a specified direction
    void Move(Dir dir);
    // Jump in a given direction
    void Jump(Dir dir);
    // Attack the player
    void Attack();
    std::string GetType();
    void HandleCollision(std::string other);
};

#endif
