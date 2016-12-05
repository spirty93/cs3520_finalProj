#ifndef CONTACT_LISTENER_H
#define CONTACT_LISTENER_H

#include <iostream>
#include <Box2D/Box2D.h>

/*
 * Custom class to to the handling of objects colliding.
 */
class ContactListener: public b2ContactListener {
    /*
     * @param b2Contact the tuple of objects colliding
     * The overload of the function that does the begin of contact evaluation
     */
    void BeginContact(b2Contact* contact);
    /*
     * @param b2Contact the tuple of objects colliding
     * The overload of the function that does the end contact evaluation
     */
    void EndContact(b2Contact* contact);
};

#endif
