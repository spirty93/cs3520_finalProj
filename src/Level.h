#ifndef LEVEL_H
#define LEVEL_H

#include <iostream>

#include "GameBody.h"
#include "Player.h"

class Level {
private:
    std::map<std::string, GameBody&> worldObjects;
public:
    Level(std::string level_name);
    ~Level();

    GameBody& getObject(std::string obj_name);
};

#endif
