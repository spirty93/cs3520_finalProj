#ifndef LEVEL_H
#define LEVEL_H

#include <iostream>
#include <map>
#include <Box2D/Box2D.h>

#include "GameBody.h"
#include "Player.h"

class Level {
public:
    std::map<std::string, GameBody*> worldObjects;
    Level(std::string level_name);
    ~Level();

    GameBody* getObject(const std::string obj_name) const noexcept;
    void addObject(const std::string obj_name, GameBody* obj) noexcept;
    Player* getPlayerObj();
    void setPlayerObj(Player* player) noexcept;
    void reset() noexcept;
private:
    std::string name_ = "";
    Player* player_ = nullptr;
};

#endif
