#include "Character.h"

Character::Character(b2World* world, const std::string texture, b2Vec2 pos, b2Vec2 dim,
		     float density, float friction, float restitution, int hp, int base_vel):
    GameBody(world, texture, pos, dim, density, friction, restitution), hp_(hp), base_vel_(base_vel) {
}

Character::~Character() {}

Dir Character::GetDir() {
    return dir_;
}
