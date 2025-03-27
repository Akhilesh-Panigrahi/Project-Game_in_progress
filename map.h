#ifndef MAP_H
#define MAP_H

#include <vector>
#include "obstacle.h"

class Map {
public:
    Map(int width, int height);
    ~Map();
    
    void generate();
    void draw() const;
    
    bool isColliding(float x, float y, float width, float height) const;
    
private:
    int width, height;
    std::vector<Obstacle> obstacles;
    std::string backgroundPath;
};

#endif // MAP_H