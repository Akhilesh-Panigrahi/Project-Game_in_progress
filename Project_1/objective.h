#ifndef OBJECTIVE_H
#define OBJECTIVE_H

#include <string>
#include <vector>
#include "enemy.h"

class Objective {
public:
    enum class Type {
        REACH_LOCATION,
        DEFEAT_ENEMIES,
        COLLECT_ITEMS,
        SURVIVE_TIME
    };
    
    struct ObjectiveData {
        Type type;
        std::string description;
        bool completed;
        union {
            struct { float targetX, targetY; float radius; } location;
            struct { int requiredCount; int defeated; } enemies;
            struct { int requiredItems; int collected; } items;
            struct { float timeRequired; float timeElapsed; } survival;
        };
    };
    
    Objective();
    
    void addObjective(Type type, const std::string& description, void* targetData = nullptr);
    void update(float deltaTime, const Player& player, const std::vector<Enemy>& enemies);
    void draw() const;
    
    bool allObjectivesCompleted() const;
    const std::vector<ObjectiveData>& getObjectives() const;
    
private:
    std::vector<ObjectiveData> objectives;
    
    void checkLocationObjectives(const Player& player);
    void checkEnemyObjectives(const std::vector<Enemy>& enemies);
    void checkTimeObjectives(float deltaTime);
};

#endif // OBJECTIVE_H