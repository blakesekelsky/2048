#include "Game.hpp"
#include <SDL2/SDL_ttf.h>

Game::Game() : board(nullptr) { 
}
Game::~Game() {}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen){
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
  window = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen ? SDL_WINDOW_FULLSCREEN : 0);
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

  // init board
  board = new Board();

  running = true;
}

void Game::handleEvents(){
  while (SDL_PollEvent(&event)) {
    if (event.type == SDL_QUIT) {
      running = false;
    }
  }
}

void Game::update(){
  // update tile values
  board->update();
}

void Game::render(){
  // clear renderer
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  SDL_RenderClear(renderer);

  // render board
  board->render(renderer);
  
  // draw to screen
  SDL_RenderPresent(renderer);
}

void Game::destroy(){
  // free resources
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  TTF_Quit();
  printf("SDL closed\n");
}