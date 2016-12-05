#ifndef GAME_BODY_H
#define GAME_BODY_H

#include <iostream>
#include <Box2D/Box2D.h>
#include <SDL2/SDL.h>

class GameBody {
public:
    /*
     * @param world the sdl 2 representation of the world
     * @param texture the texture associated with the object
     * @param pos a b2Vec2 that represents the position of the object in the world
     * @param dim a b2Vec2 that represents the size of the object
     * @param density represents the worlds density with respect to the rest of the objects
     * @param friction the friction of the body
     * @param restitution the restitution of the body
     *
     * Constucts the instance of the body that is able to move through the world and is affected
     * by the external forces
     */
    GameBody(b2World* world, const std::string texture, b2Vec2 pos, b2Vec2 dim,
	      float density, float friction, float restitution);
    /*
     * @param world the sdl 2 representation of the world
     * @param texture the texture associated with the object
     * @param pos a b2Vec2 that represents the position of the object in the world
     * @param dim a b2Vec2 that represents the size of the object
     *
     * Constucts the instance of the body that is not able to move through the world and is not affected
     * by the external forces
     */
    GameBody(b2World* world, const std::string texture, b2Vec2 pos, b2Vec2 dim);
    /*
     * Default destructor
     */
    ~GameBody();
    /*
     * @return string the texture represented by a string
     * Getter method for a texture param
     */
    const std::string GetTexture() const noexcept;
    /*
     * @return b2Body that is associated with this object
     */
    b2Body* GetBody() const noexcept;
    /*
     * @return SDL_Rect computes the size that box2d uses to the rectangle
     * used by SDL to draw images
     */
    SDL_Rect GetTexRect() const noexcept;
    /*
     * @return SDL_Rect computes the coordinates that box2d uses to the rectangle
     * used by SDL to draw images
     */
    SDL_Rect GetPosRect() const noexcept;
    /*
     * @return string a special string that is unique to each object type
     */
    virtual std::string GetType();
    /*
     * @param other string representing the object
     * Collision handler for the body.
     */
    virtual void HandleCollision(std::string other);
    /*
     * @return boolean true if object needs to be removed on next cycle of game loop
     * getter for the dead property
     */
    const bool isDead() const noexcept;
    /*
     * @return boolean true if the object has to be removed
     * Handle the event of dying.
     */
    virtual bool Die() noexcept;
private:
    std::string texture_; // texture assosciated with this object
    b2Body* body_ = NULL; // the body pointer
    const float width_; // the width of the object
    const float height_; // the height of the object
protected:
    bool dead_ = false; // flag for the dead object
};

#endif
