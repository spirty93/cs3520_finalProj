#include "GameBody.h"

GameBody::GameBody(b2World* world, const std::string texture, b2Vec2 pos, b2Vec2 dim,
		   float density, float friction, float restitution): texture_(texture), width_(dim.x), height_(dim.y) {
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position = pos;
    bodyDef.angle = 0;

    b2Body* myBody = world->CreateBody(&bodyDef);

    b2PolygonShape boxShape;
    boxShape.SetAsBox(dim.x / 2, dim.y / 2);

    b2FixtureDef boxFixtureDef;
    boxFixtureDef.shape = &boxShape;
    boxFixtureDef.density = 1;
    myBody->CreateFixture(&boxFixtureDef);
    body_ = myBody;

}

GameBody::GameBody(b2World* world, const std::string texture, b2Vec2 pos,
		   b2Vec2 dim): texture_(texture), width_(dim.x), height_(dim.y) {
    b2BodyDef bodyDef;
    bodyDef.type = b2_staticBody;
    bodyDef.position.Set(pos.x + width_ / 2, pos.y + height_ / 2);
    b2Body* myBody = world->CreateBody(&bodyDef);


    b2PolygonShape boxShape;

    boxShape.SetAsBox(dim.x / 2, dim.y / 2);

    b2FixtureDef boxFixtureDef;

    boxFixtureDef.shape = &boxShape;

    myBody->CreateFixture(&boxFixtureDef);
    body_ = myBody;
}

GameBody::~GameBody() {

}

const std::string GameBody::GetTexture() const noexcept{
    return texture_;
}

b2Body* GameBody::GetBody() const noexcept {
    return body_;
}

SDL_Rect GameBody::GetTexRect() const noexcept {
    SDL_Rect rect;

    rect.x = 0;
    rect.y = 0;
    rect.w = width_;
    rect.h = height_;

    return rect;
}

SDL_Rect GameBody::GetPosRect() const noexcept {
    SDL_Rect rect;

    const b2Vec2& pos = body_->GetPosition();

    rect.x = pos.x - width_ / 2;
    rect.y = pos.y - height_ / 2;
    rect.w = pos.x + width_ / 2;
    rect.h = pos.y + height_ / 2;

    return rect;
}
