#include "Game.hpp"

int main() {
  Game *game = new Game("2048", 480, 480, false);  

  while (game->isRunning()) {
    game->handleEvents();
    game->update();
    game->render(); 
  }
  delete game;
  
  return 0;
}