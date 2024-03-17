#include "Game.hpp"

int main() {
  Game *game = new Game();
  
  game->init("2048", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, false);
  while (game->isRunning()) {
    game->handleEvents();
    game->update();
    game->render(); 
  }

  game->destroy();
  return 0;
}