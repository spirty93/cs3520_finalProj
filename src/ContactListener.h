#ifndef CONTACT_LISTENER_H
#define CONTACT_LISTENER_H

#include <iostream>
#include <Box2D/Box2D.h>

class ContactListener: public b2ContactListener {
    void BeginContact(b2Contact* contact);
    void EndContact(b2Contact* contact);
};

#endif
