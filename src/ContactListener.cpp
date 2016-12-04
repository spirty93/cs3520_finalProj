#include "ContactListener.h"
#include "GameBody.h"

void ContactListener::BeginContact(b2Contact* contact) {
    void* bodyAUserData = contact->GetFixtureA()->GetBody()->GetUserData();
    void* bodyBUserData = contact->GetFixtureB()->GetBody()->GetUserData();
    if (bodyAUserData && bodyBUserData) {
	GameBody* a = static_cast<GameBody*>(bodyAUserData);
	GameBody* b = static_cast<GameBody*>(bodyBUserData);

	const std::string typeA = a->GetType();
	const std::string typeB = b->GetType();

	a->HandleCollision(typeB);
	b->HandleCollision(typeA);
    }

    if (bodyBUserData) {
    }

}

void ContactListener::EndContact(b2Contact* contact) {
    //check if fixture A was a ball
    void* bodyAUserData = contact->GetFixtureA()->GetBody()->GetUserData();
    void* bodyBUserData = contact->GetFixtureB()->GetBody()->GetUserData();

}
