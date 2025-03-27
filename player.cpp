#include "player.h"
#include <iostream>

Player::Player(float x, float y) : x(x), y(y), width(32), height(64), speed(3.0f) {
    texturePath = "assets/player.png"; // Would be loaded in actual implementation
}

void Player::move(float dx, float dy) {
    // Normalize diagonal movement
    if (dx != 0 && dy != 0) {
        dx *= 0.7071f; // 1/sqrt(2)
        dy *= 0.7071f;
    }
    
    x += dx * speed;
    y += dy * speed;
}

void Player::update() {
    // Could add animation updates here
}

void Player::draw() const {
    // In a real implementation, this would use a graphics library
    std::cout << "Drawing player at (" << x << ", " << y << ")\n";
}

float Player::getX() const { return x; }

float Player::getY() const { return y; }

float Player::getWidth() const { return width; }

float Player::getHeight() const { return height; }

float Player::getSpeed() const { return speed; }

void Player::setPosition(float x, float y) {
    this->x = x;
    this->y = y;
}