#ifndef ENEMY_H
#define ENEMY_H

#include "player.h"
#include <string>

class Enemy {
public:
    enum class Type { KNIGHT, DRONE, BOSS };
    
    Enemy(float x, float y, Type type);
    
    void update(const Player& player);
    void draw() const;
    
    float getX() const;
    float getY() const;
    float getWidth() const;
    float getHeight() const;
    bool isAlive() const;
    Type getType() const;
    
    void takeDamage(float amount);
    bool isColliding(float px, float py, float pwidth, float pheight) const;
    
private:
    float x, y;
    float width, height;
    float health;
    float speed;
    Type type;
    bool alive;
    std::string texturePath;
    
    void moveTowardsPlayer(const Player& player);
};

#endif // ENEMY_H