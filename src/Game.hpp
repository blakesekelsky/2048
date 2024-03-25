#ifndef GAME_HPP
#define GAME_HPP

#include <SDL2/SDL.h>
#include "Board.hpp"

class Game {
  public:
    Game(const char *title, int width, int height, bool fullscreen);
    ~Game();

    void handleEvents();
    void update();
    void render();

    bool isRunning() { return running; }
  private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event event;
    
    bool running = false;
    Board *board;
};

#endif