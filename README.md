# 🛡️⚔️ Futuristic Medieval 2D Game

Welcome to **Futuristic Medieval**, a simple yet stylish 2D game prototype built with modern C++! Travel through a cyber-fantasy world where knights and drones clash, objectives await, and your mission is to win by completing them all.

## 🎮 Overview

This game is a lightweight demo using console output to simulate a real-time game loop with basic object interaction. It’s structured like a traditional game engine with:

- Game loop (init, run, update, render)
- Player movement and collision
- Enemy AI and interaction
- Objective system
- Frame rate control (60 FPS target)

While the visuals are minimal (console-based), the architecture mimics that of real 2D engines—perfect for expanding into graphics libraries like SDL or SFML later.

---

## 🗂️ Project Structure

```bash
.
├── main.cpp          # Game entry point
├── game.h/.cpp       # Core game loop and logic
├── player.h/.cpp     # Player class with movement, stats, etc.
├── map.h/.cpp        # Map generator and collision system
├── enemy.h/.cpp      # Enemy logic and types (knight, drone, boss)
├── objective.h/.cpp  # Game objectives and progression
