#include "game.h"
#include <iostream>
#include <thread>

Game::Game(int width, int height) : 
    screenWidth(width), screenHeight(height), running(false), 
    player(width/2, height/2), map(width, height),
    accumulatedTime(0) {}

Game::~Game() {
    cleanup();
}

void Game::init() {
    map.generate();
    spawnEnemies();
    running = true;
    lastFrameTime = std::chrono::high_resolution_clock::now();
    std::cout << "Game initialized\n";
}

void Game::run() {
    init();
    
    while (isRunning()) {
        // Calculate delta time
        auto currentTime = std::chrono::high_resolution_clock::now();
        float deltaTime = std::chrono::duration<float>(currentTime - lastFrameTime).count();
        lastFrameTime = currentTime;
        
        accumulatedTime += deltaTime;
        
        // Fixed timestep update
        while (accumulatedTime >= targetFrameTime) {
            handleInput();
            update(targetFrameTime);
            accumulatedTime -= targetFrameTime;
        }
        
        render();
        
        // Simple frame rate limiter
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}

void Game::cleanup() {
    running = false;
    std::cout << "Game cleaned up\n";
}

void Game::handleInput() {
    // In a real implementation, this would use proper input handling
    // For demo, we'll just simulate some input
    float dx = 0, dy = 0;
    
    // Simulate movement (in real game, this would come from keyboard)
    // Let's pretend player is moving diagonally down-right
    dx = 1;
    dy = 1;
    
    // Check for collision before moving
    float newX = player.getX() + dx * player.getSpeed();
    float newY = player.getY() + dy * player.getSpeed();
    
    if (!map.isColliding(newX, newY, player.getWidth(), player.getHeight())) {
        player.move(dx, dy);
    }
}

void Game::update(float deltaTime) {
    player.update();
    
    for (auto& enemy : enemies) {
        enemy.update(player);
    }
    
    checkPlayerEnemyCollisions();
    objectives.update(deltaTime, player, enemies);
    
    if (objectives.allObjectivesCompleted()) {
        std::cout << "All objectives completed! You win!\n";
        running = false;
    }
}

void Game::render() {
    std::cout << "--- Rendering Frame ---\n";
    map.draw();
    player.draw();
    
    for (const auto& enemy : enemies) {
        enemy.draw();
    }
    
    objectives.draw();
    std::cout << "-----------------------\n";
}

void Game::spawnEnemies() {
    enemies.emplace_back(200, 200, Enemy::Type::KNIGHT);
    enemies.emplace_back(600, 150, Enemy::Type::DRONE);
    enemies.emplace_back(400, 400, Enemy::Type::KNIGHT);
    enemies.emplace_back(300, 500, Enemy::Type::DRONE);
    enemies.emplace_back(700, 300, Enemy::Type::BOSS);
}

void Game::checkPlayerEnemyCollisions() {
    for (auto& enemy : enemies) {
        if (enemy.isAlive() && enemy.isColliding(
            player.getX(), player.getY(), 
            player.getWidth(), player.getHeight())) {
            
            // In a real game, this would deal damage to the player
            // For demo, we'll just have enemies die when touched
            enemy.takeDamage(100);
        }
    }
}

bool Game::isRunning() const {
    return running;
}