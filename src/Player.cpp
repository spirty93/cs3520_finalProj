#include "Player.h"

Player::Player(b2World* world, const std::string texture, b2Vec2 pos, b2Vec2 dim,
       float density, float friction, float restitution, int hp, int base_vel) :
    Character(world, texture, pos, dim, density, friction, restitution, hp, base_vel) {
}

Player::~Player() {};

void Player::Move(Dir dir) {
    dir_ = dir;
}

void Player::Jump(Dir dir) {
    dir_ = dir;
}

void Player::Attack() {

}

void Player::processEvent(SDL_Event& e) {
    if (e.type == SDL_KEYDOWN) {
	b2Vec2 vel =this->GetBody()->GetLinearVelocity();
	switch (e.key.keysym.sym) {
	case SDLK_RIGHT:
	    vel.x = 2 * base_vel_;
	    this->GetBody()->SetLinearVelocity(vel);
	    break;
	case SDLK_LEFT:
	    vel.x = 2 * -base_vel_;
	    this->GetBody()->SetLinearVelocity(vel);
	    break;
	case SDLK_UP:
	    vel.y = -50;
	    this->GetBody()->SetLinearVelocity(vel);
	    break;
	}
    }

    if (e.type == SDL_KEYUP) {
	b2Vec2 vel =this->GetBody()->GetLinearVelocity();
	vel.x = 0;
	this->GetBody()->SetLinearVelocity(vel);
    }
}

std::string Player::GetType() {
    return "player";
}

void Player::HandleCollision(std::string other) {
    if (other == "object") return;
    std::cout << "Collinding with " << other << std::endl;
    if (other == "enemy") {
	std::cout << "Enemy hit. About to die" << std::endl;
    }
}
