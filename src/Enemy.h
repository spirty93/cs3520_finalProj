#ifndef ENEMY_H
#define ENEMY_H

class Enemy :public Character {
public:
    Enemy(b2World& world, const SDL_Texture* texture, b2Vec2 pos, b2Vec2 dim,
	  float density, float friction, float restitution, int hp, int base_vel);
    ~Enemy();
    // Move enemy in a specified direction
    void Move(Dir dir);
    // Jump in a given direction
    void Jump(Dir dir);
    // Attack the player
    void Attack();
};

#endif
