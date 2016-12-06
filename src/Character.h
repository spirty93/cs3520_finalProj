#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <Box2D/Box2D.h>
#include <SDL2/SDL.h>

#include "Dir.h"
#include "GameBody.h"

/*
 * A class that handles game character. Game characters can be eniemies or player
 */
class Character :public GameBody {
public:
    /*
     * @param world the sdl 2 representation of the world
     * @param texture the texture associated with the object
     * @param pos a b2Vec2 that represents the position of the object in the world
     * @param dim a b2Vec2 that represents the size of the object
     * @param density represents the worlds density with respect to the rest of the objects
     * @param friction the friction of the body
     * @param restitution the restitution of the body
     * @param hp number of times player can die
     * @param base_vel the base vel with which character moves
     *
     * Overlaod from GameBody A constructor for the character.
     */
    Character(b2World* world, const std::string texture, b2Vec2 pos, b2Vec2 dim,
	  float density, float friction, float restitution, int hp, int base_vel);
    ~Character();
    /*
     * @param dir
     * Move in a specific direction
     */
    virtual void Move(Dir dir) = 0;
    /*
     * @param dir
     * Jump in a specific direction
     */
    virtual void Jump(Dir dir) = 0;
    /*
     * Return the currently facing direction
     */
    Dir GetDir();
    /*
     * Perform an attack
     */
    virtual void Attack() = 0;
    /*
     * Get the entity type
     */
    virtual std::string GetType();
protected:
    Dir dir_ = Dir::RIGHT; // the direction where player is facing
    int hp_; // amount of healthpoints
    int base_vel_; // basic velocity
};

#endif
