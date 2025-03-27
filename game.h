#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "map.h"
#include "enemy.h"
#include "objective.h"
#include <vector>
#include <chrono>

class Game {
public:
    Game(int width, int height);
    ~Game();
    
    void init();
    void run();
    void cleanup();
    
    void handleInput();
    void update(float deltaTime);
    void render();
    
    bool isRunning() const;
    
private:
    bool running;
    int screenWidth, screenHeight;
    Player player;
    Map map;
    std::vector<Enemy> enemies;
    Objective objectives;
    
    // Timing variables
    std::chrono::high_resolution_clock::time_point lastFrameTime;
    float accumulatedTime;
    const float targetFrameTime = 1.0f / 60.0f; // 60 FPS
    
    void spawnEnemies();
    void checkPlayerEnemyCollisions();
};

#endif // GAME_H