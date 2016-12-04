#include "Portal.h"

Portal::Portal(b2World* world, const std::string texture, b2Vec2 pos, b2Vec2 dim, Game* game, std::string to) :
    GameBody(world, texture, pos, dim), game_(game), to_(to) {
}

void Portal::HandleCollision(std::string other) {
    if (other == "player") {
	game_->triggerLoadLevel(to_);
    }
}
