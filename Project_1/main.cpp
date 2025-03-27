#include "game.h"
#include <iostream>

int main() {
    std::cout << "Starting Futuristic Medieval Game\n";
    
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;
    
    Game game(SCREEN_WIDTH, SCREEN_HEIGHT);
    game.run();
    
    std::cout << "Game exited\n";
    return 0;
}