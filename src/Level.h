#ifndef LEVEL_H
#define LEVEL_H

#include <iostream>
#include <map>
#include <vector>
#include <Box2D/Box2D.h>

#include "GameBody.h"
#include "Player.h"

class Level {
public:
    std::map<std::string, GameBody*> worldObjects;
    std::vector<std::tuple<SDL_Texture*, b2Vec2>> texts;
    Level(std::string level_name);
    ~Level();

    GameBody* getObject(const std::string obj_name) const noexcept;
    void addObject(const std::string obj_name, GameBody* obj) noexcept;
    Player* getPlayerObj();
    void setPlayerObj(Player* player) noexcept;
    void reset() noexcept;
    void go() noexcept;
    void pause() noexcept;
    bool isRunning() noexcept;
private:
    std::string name_ = "";
    Player* player_ = nullptr;
    bool running_ = false;
};

#endif
