#include "objective.h"
#include <cmath>
#include <iostream>

Objective::Objective() {
    // Example objectives
    addObjective(Type::REACH_LOCATION, "Reach the ancient tower", 
                 new float[3]{500.0f, 300.0f, 50.0f});
    addObjective(Type::DEFEAT_ENEMIES, "Defeat 3 enemies", 
                 new int[1]{3});
    addObjective(Type::SURVIVE_TIME, "Survive for 30 seconds", 
                 new float[1]{30.0f});
}

void Objective::addObjective(Type type, const std::string& description, void* targetData) {
    ObjectiveData newObj;
    newObj.type = type;
    newObj.description = description;
    newObj.completed = false;
    
    switch(type) {
        case Type::REACH_LOCATION:
            if (targetData) {
                float* data = static_cast<float*>(targetData);
                newObj.location.targetX = data[0];
                newObj.location.targetY = data[1];
                newObj.location.radius = data[2];
                delete[] data;
            }
            break;
        case Type::DEFEAT_ENEMIES:
            if (targetData) {
                int* data = static_cast<int*>(targetData);
                newObj.enemies.requiredCount = data[0];
                newObj.enemies.defeated = 0;
                delete[] data;
            }
            break;
        case Type::COLLECT_ITEMS:
            if (targetData) {
                int* data = static_cast<int*>(targetData);
                newObj.items.requiredItems = data[0];
                newObj.items.collected = 0;
                delete[] data;
            }
            break;
        case Type::SURVIVE_TIME:
            if (targetData) {
                float* data = static_cast<float*>(targetData);
                newObj.survival.timeRequired = data[0];
                newObj.survival.timeElapsed = 0.0f;
                delete[] data;
            }
            break;
    }
    
    objectives.push_back(newObj);
}

void Objective::update(float deltaTime, const Player& player, const std::vector<Enemy>& enemies) {
    checkLocationObjectives(player);
    checkEnemyObjectives(enemies);
    checkTimeObjectives(deltaTime);
}

void Objective::draw() const {
    std::cout << "=== Objectives ===\n";
    for (const auto& obj : objectives) {
        std::cout << (obj.completed ? "[X] " : "[ ] ") << obj.description;
        
        if (!obj.completed) {
            switch(obj.type) {
                case Type::DEFEAT_ENEMIES:
                    std::cout << " (" << obj.enemies.defeated << "/" << obj.enemies.requiredCount << ")";
                    break;
                case Type::SURVIVE_TIME:
                    std::cout << " (" << obj.survival.timeElapsed << "/" << obj.survival.timeRequired << "s)";
                    break;
                default:
                    break;
            }
        }
        
        std::cout << "\n";
    }
    std::cout << "==================\n";
}

bool Objective::allObjectivesCompleted() const {
    for (const auto& obj : objectives) {
        if (!obj.completed) return false;
    }
    return true;
}

const std::vector<Objective::ObjectiveData>& Objective::getObjectives() const {
    return objectives;
}

void Objective::checkLocationObjectives(const Player& player) {
    for (auto& obj : objectives) {
        if (obj.completed || obj.type != Type::REACH_LOCATION) continue;
        
        float dx = player.getX() - obj.location.targetX;
        float dy = player.getY() - obj.location.targetY;
        float distance = sqrt(dx*dx + dy*dy);
        
        if (distance <= obj.location.radius) {
            obj.completed = true;
        }
    }
}

void Objective::checkEnemyObjectives(const std::vector<Enemy>& enemies) {
    for (auto& obj : objectives) {
        if (obj.completed || obj.type != Type::DEFEAT_ENEMIES) continue;
        
        int defeated = 0;
        for (const auto& enemy : enemies) {
            if (!enemy.isAlive()) defeated++;
        }
        
        obj.enemies.defeated = defeated;
        if (defeated >= obj.enemies.requiredCount) {
            obj.completed = true;
        }
    }
}

void Objective::checkTimeObjectives(float deltaTime) {
    for (auto& obj : objectives) {
        if (obj.completed || obj.type != Type::SURVIVE_TIME) continue;
        
        obj.survival.timeElapsed += deltaTime;
        if (obj.survival.timeElapsed >= obj.survival.timeRequired) {
            obj.completed = true;
        }
    }
}