#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <Box2D/Box2D.h>
#include <SDL2/SDL.h>

#include "Dir.h"
#include "Character.h"

class Player :public Character {
public:
    Player(b2World* world, const std::string texture, b2Vec2 pos, b2Vec2 dim,
	   float density, float friction, float restitution, int hp, int base_vel);
    ~Player();

    // Move player in a specific direction
    void Move(Dir dir);
    // Jump in a given direction
    void Jump(Dir dir);
    // Perform attack
    void Attack();
    // Process the event
    void processEvent(SDL_Event& e);
    std::string GetType();
    void HandleCollision(std::string type);
};

#endif
