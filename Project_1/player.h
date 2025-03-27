#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
public:
    Player(float x = 0, float y = 0);
    
    void move(float dx, float dy);
    void update();
    void draw() const;
    
    float getX() const;
    float getY() const;
    float getWidth() const;
    float getHeight() const;
    float getSpeed() const;
    
    void setPosition(float x, float y);
    
private:
    float x, y;
    float width, height;
    float speed;
    std::string texturePath;
};

#endif // PLAYER_H