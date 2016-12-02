#include "ContactListener.h"

void ContactListener::BeginContact(b2Contact* contact) {
    void* bodyUserData = contact->GetFixtureA()->GetBody()->GetUserData();

    //check if fixture B was a ball
    bodyUserData = contact->GetFixtureB()->GetBody()->GetUserData();
}

void ContactListener::EndContact(b2Contact* contact) {
    //check if fixture A was a ball
    void* bodyUserData = contact->GetFixtureA()->GetBody()->GetUserData();

    //check if fixture B was a ball
    bodyUserData = contact->GetFixtureB()->GetBody()->GetUserData();
}
