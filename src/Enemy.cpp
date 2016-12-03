#include "Enemy.h"

Enemy::Enemy(b2World* world, const std::string texture, b2Vec2 pos, b2Vec2 dim,
	     float density, float friction, float restitution, int hp, int base_vel):
    Character(world, texture, pos, dim, density, friction, restitution, hp, base_vel) {}

Enemy::~Enemy() {}

void Enemy::Move(Dir dir) {

}

void Enemy::Jump(Dir dir) {

}

void Enemy::Attack() {

}

std::string Enemy::GetType() {
    return "enemy";
}

void Enemy::HandleCollision(std::string other) {
    if (other == "object") return;
    std::cout << "Collinding with " << other << std::endl;
    if (other == "player") {
	std::cout << "Enemy hit. About to die" << std::endl;
    }
}
