#include "obstacle.h"
#include <iostream>

Obstacle::Obstacle(float x, float y, Type type) : x(x), y(y), type(type) {
    switch(type) {
        case Type::BUILDING:
            width = 100;
            height = 150;
            texturePath = "assets/futuristic_building.png";
            break;
        case Type::TREE:
            width = 60;
            height = 100;
            texturePath = "assets/future_tree.png";
            break;
        case Type::ROCK:
            width = 40;
            height = 40;
            texturePath = "assets/rock.png";
            break;
    }
}

void Obstacle::draw() const {
    std::cout << "Drawing " << (type == Type::BUILDING ? "building" : 
                              (type == Type::TREE ? "tree" : "rock"))
              << " at (" << x << ", " << y << ")\n";
}

float Obstacle::getX() const { return x; }
float Obstacle::getY() const { return y; }
float Obstacle::getWidth() const { return width; }
float Obstacle::getHeight() const { return height; }

bool Obstacle::isColliding(float px, float py, float pwidth, float pheight) const {
    return (px < x + width) && (px + pwidth > x) &&
           (py < y + height) && (py + pheight > y);
}