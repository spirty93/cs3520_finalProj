#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <Box2D/Box2D.h>
#include <SDL2/SDL.h>

#include "Dir.h"
#include "Character.h"

class Player :public Character {
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
    Player(b2World* world, const std::string texture, b2Vec2 pos, b2Vec2 dim,
	   float density, float friction, float restitution, int hp, int base_vel);
    ~Player();
    /*
     * @param dir
     * Move in a specific direction
     */
    void Move(Dir dir);
    /*
     * @param dir
     * Jump in a specific direction
     */
    void Jump(Dir dir);
    /*
     * Perform an attack
     */
    void Attack();
    /*
     * @param e SDL_Event that are specific to the player
     */
    void processEvent(SDL_Event& e);
    /*
     * get the type of the object
     */
    std::string GetType();
    /*
     * @param other string representing the object
     * Collision handler for the body.
     */
    void HandleCollision(std::string type);
    /*
     * @return boolean true if the object has to be removed
     * Handle the event of dying.
     */
    bool Die() noexcept;
private:
    const b2Vec2 base_pos_; // save base pos to reset pos when dead
};

#endif
