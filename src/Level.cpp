#include "Level.h"

Level::Level(std::string level_name): name_(level_name) {}

Level::~Level() {}

GameBody* Level::getObject(const std::string obj_name) const noexcept {
    return worldObjects.at(obj_name);
}

void Level::addObject(const std::string obj_name, GameBody* obj) noexcept {
    worldObjects.insert(std::pair<std::string, GameBody*>(obj_name, obj));
}
