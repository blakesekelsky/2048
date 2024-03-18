#ifndef GAME_HPP
#define GAME_HPP

#include <SDL2/SDL.h>
#include "Board.hpp"

class Game {
  public:
    Game();
    ~Game();

    void init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen);
    void handleEvents();
    void update();
    void render();
    void destroy();

    bool isRunning() { return running; }
  private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event event;
    
    bool running = false;

    Board *board;
    int score = 0;
};

#endif