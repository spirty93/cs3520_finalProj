#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <iostream>
#include <Box2D/Box2D.h>
#include <SDL2/SDL.h>


#include "Dir.h"
#include "GameBody.h"

class Projectile :public GameBody {
private:
    Dir dir = NULL;
public:
    Projectile(b2World& world, const SDL_Texture* texture, b2Vec2 pos, b2Vec2 dim,
	       float density, float friction, float restitution, int hp, int base_vel, const Dir::dir dir);
    ~Character();
    // Update the projectile position
    void Update();
    // Jump in a given direction
    Dir& GetDir();
};

#endif
