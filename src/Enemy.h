#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
#include <Box2D/Box2D.h>
#include <SDL2/SDL.h>

#include "Character.h"

/*
 * A class handling the enemy objects.
 */
class Enemy :public Character {
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
    Enemy(b2World* world, const std::string texture, b2Vec2 pos, b2Vec2 dim,
	  float density, float friction, float restitution, int hp, int base_vel);
    ~Enemy();
    /*
     * @param dir
     * Move in a specific direction
     */
    void Move(Dir dir);
    /*
     * Return the currently facing direction
     */
    void Jump(Dir dir);
    /*
     * Perform an attack
     */
    void Attack();
    /*
     * Get the entity type
     */
    std::string GetType();
    /*
     * @param other string type of other entity
     * Handle the collison
     */
    void HandleCollision(std::string other);
};

#endif
