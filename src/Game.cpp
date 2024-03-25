#include "Game.hpp"
#include <SDL2/SDL_ttf.h>

Game::Game(const char *title, int width, int height, bool fullscreen) : board(nullptr) {
  if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
    printf("SDL initialized\n");
  } else {
    printf("SDL initialization failed: %s", SDL_GetError());
    running = false;
    return;
  }
  
  if (TTF_Init() == 0) {
    printf("TTF initialized\n");
  } else {
    printf("TTF initialization failed: %s\n", TTF_GetError());
    running = false;
    return;
  }

  // init window
  window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, fullscreen ? SDL_WINDOW_FULLSCREEN : 0);
  if (window) {
    printf("Window created\n");
  } else {
    printf("Window not created: %s", SDL_GetError());
    running = false;
    return;
  } 

  // init renderer
  Game::renderer = SDL_CreateRenderer(window, -1, 0);
  if (renderer) {
    printf("Renderer created\n");
  } else {
    printf("Renderer not created: %s", SDL_GetError());
    running = false;
    return;
  }

  board = new Board();
  running = true;
}
Game::~Game() {
  delete board;
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  TTF_Quit();
  SDL_Quit();
}

void Game::handleEvents(){
  while (SDL_PollEvent(&event)) {
    if (event.type == SDL_QUIT) {
      running = false;
    }

    board->handleEvents(window, event);
  }
}

void Game::update(){
  board->update();
}

void Game::render(){
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  SDL_RenderClear(renderer);

  board->render(renderer);
  
  SDL_RenderPresent(renderer);
}