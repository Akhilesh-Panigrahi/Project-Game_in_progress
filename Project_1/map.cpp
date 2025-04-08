#include "map.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

Map::Map(int width, int height) : width(width), height(height) {
    backgroundPath = "assets/future_medieval_bg.png";
    srand(time(0));
}

Map::~Map() {
    obstacles.clear();
}

void Map::generate() {
    // Generate random obstacles
    for (int i = 0; i < 20; ++i) {
        float x = rand() % (width - 100);
        float y = rand() % (height - 150);
        
        Obstacle::Type type;
        int r = rand() % 3;
        if (r == 0) type = Obstacle::Type::BUILDING;
        else if (r == 1) type = Obstacle::Type::TREE;
        else type = Obstacle::Type::ROCK;
        
        obstacles.emplace_back(x, y, type);
    }
}

void Map::draw() const {
    std::cout << "Drawing background\n";
    for (const auto& obstacle : obstacles) {
        obstacle.draw();
    }
}

bool Map::isColliding(float x, float y, float width, float height) const {
    for (const auto& obstacle : obstacles) {
        if (obstacle.isColliding(x, y, width, height)) {
            return true;
        }
    }
    return false;
}