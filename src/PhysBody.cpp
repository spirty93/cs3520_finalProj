#include "PhysBody.h"

PhysBody::PhysBody(b2World& world ,const SDL_Texture* texture) {
    this->texture = texture;
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(0.0f, 0.0f);
    body = world.CreateBody(&bodyDef);
    b2FixtureDef fixtureDef;
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(1.0f, 1.0f);
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    body->CreateFixture(&fixtureDef);
}

PhysBody::~PhysBody() {

}

const SDL_Texture* PhysBody::GetTexture() {
    return texture;
}

b2Body* PhysBody::GetBody() {
    return body;
}


b2Vec2 PhysBody::GetPosition() {
    body->GetPosition();
}

float PhysBody::GetAngle() {
    body->GetAngle();
}
