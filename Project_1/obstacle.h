#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <string>

class Obstacle {
public:
    enum class Type { BUILDING, TREE, ROCK };
    
    Obstacle(float x, float y, Type type);
    
    void draw() const;
    
    float getX() const;
    float getY() const;
    float getWidth() const;
    float getHeight() const;
    
    bool isColliding(float px, float py, float pwidth, float pheight) const;
    
private:
    float x, y;
    float width, height;
    Type type;
    std::string texturePath;
};

#endif // OBSTACLE_H