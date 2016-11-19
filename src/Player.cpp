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
	switch (e.type) {
	case SDLK_LEFT: {
	    dir_ = Dir::LEFT;
	    b2Vec2 vel = this->GetBody()->GetLinearVelocity();
	    if (vel.x < -base_vel_) {
		break;
	    }
	    this->GetBody()->SetLinearVelocity(b2Vec2(vel.x - 0.1, 0));
	    break;
	}
	case SDLK_RIGHT: {
	    this->GetBody()->SetLinearVelocity(b2Vec2(base_vel_, 0));
	    dir_ = Dir::RIGHT;
	    break;
	}
	default:
	    break;
	}

    }

    if (e.type == SDL_KEYUP) {
	this->GetBody()->SetLinearVelocity(b2Vec2(0, 0));
    }
}
