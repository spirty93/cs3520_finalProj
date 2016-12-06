#ifndef LEVEL_H
#define LEVEL_H

#include <iostream>
#include <map>
#include <vector>
#include <Box2D/Box2D.h>

#include "GameBody.h"
#include "Player.h"


/*
 * An abstract level class
 */
class Level {
public:
    std::map<std::string, GameBody*> worldObjects; // mapping from name of the object ot object
    std::vector<std::tuple<SDL_Texture*, b2Vec2>> texts; // the texts vector
    Level(std::string level_name); //constructor for the level
    ~Level();

    /*
     * @param objName the name of the object to be get from the mapping
     */
    GameBody* getObject(const std::string objName) const noexcept;
    /*
     * @param objName the name of the object to be added to the mapping
     */
    void addObject(const std::string objName, GameBody* obj) noexcept;
    /*
     * Getter for player object
     */
    Player* getPlayerObj();
    /*
     * @param player object representing a player
     */
    void setPlayerObj(Player* player) noexcept;
    /*
     * Reset the level state
     */
    void reset() noexcept;
    /*
     * Change the level state to progress the world on each tick
     */
    void go() noexcept;
    /*
     * Change the level state to not progress the world on each tick
     */
    void pause() noexcept;
    /*
     * Check if level has to make progress on ticks
     */
    bool isRunning() noexcept;
private:
    std::string name_ = "";  // name of the level
    Player* player_ = nullptr; // player pointer
    bool running_ = false; //  is level running
};

#endif
