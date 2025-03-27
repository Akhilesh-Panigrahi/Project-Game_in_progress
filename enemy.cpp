#include "enemy.h"
#include <cmath>
#include <iostream>

Enemy::Enemy(float x, float y, Type type) : 
    x(x), y(y), type(type), alive(true) {
    
    switch(type) {
        case Type::KNIGHT:
            width = 40;
            height = 60;
            health = 100;
            speed = 1.5f;
            texturePath = "assets/medieval_knight.png";
            break;
        case Type::DRONE:
            width = 30;
            height = 30;
            health = 60;
            speed = 2.5f;
            texturePath = "assets/future_drone.png";
            break;
        case Type::BOSS:
            width = 80;
            height = 100;
            health = 300;
            speed = 1.0f;
            texturePath = "assets/boss.png";
            break;
    }
}

void Enemy::update(const Player& player) {
    if (!alive) return;
    
    moveTowardsPlayer(player);
    
    // Simple AI: if close enough, attack (in a real game, this would be more complex)
    float dx = player.getX() - x;
    float dy = player.getY() - y;
    float distance = sqrt(dx*dx + dy*dy);
    
    if (distance < 50) {
        // Attack logic would go here
    }
}

void Enemy::draw() const {
    if (!alive) return;
    std::cout << "Drawing " << (type == Type::KNIGHT ? "knight" : 
                              (type == Type::DRONE ? "drone" : "boss"))
              << " at (" << x << ", " << y << ")\n";
}

void Enemy::takeDamage(float amount) {
    health -= amount;
    if (health <= 0) {
        alive = false;
    }
}

bool Enemy::isColliding(float px, float py, float pwidth, float pheight) const {
    return alive && (px < x + width) && (px + pwidth > x) &&
           (py < y + height) && (py + pheight > y);
}

void Enemy::moveTowardsPlayer(const Player& player) {
    float dx = player.getX() - x;
    float dy = player.getY() - y;
    
    // Normalize direction
    float length = sqrt(dx*dx + dy*dy);
    if (length > 0) {
        dx /= length;
        dy /= length;
    }
    
    x += dx * speed;
    y += dy * speed;
}

float Enemy::getX() const { return x; }

float Enemy::getY() const { return y; }

float Enemy::getWidth() const { return width; }

float Enemy::getHeight() const { return height; }

bool Enemy::isAlive() const { return alive; }

Enemy::Type Enemy::getType() const { return type; }