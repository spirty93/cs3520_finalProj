#include "PhysBody.h"

PhysBody::PhysBody(const SDL_Texture* texture) {
    this->texture = texture;
}

PhysBody::~PhysBody() {

}

SDL_Texture* PhysBody::GetTexture() {
    return texture;
}

b2Body* PhysBody::GetBody() {
    return body;
}
