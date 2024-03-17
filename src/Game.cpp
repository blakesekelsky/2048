#include "Game.hpp"

Game::Game() {}
Game::~Game() {}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen){
  // init SDL
  if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
    printf("SDL initialized\n");
  } else {
    printf("SDL not initialized\n");
    running = false;
    return;
  }

  // init window
  window = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen ? SDL_WINDOW_FULLSCREEN : 0);
  if (window) {
    printf("Window created\n");
  } else {
    printf("Window not created\n");
    running = false;
    return;
  } 

  // init renderer
  renderer = SDL_CreateRenderer(window, -1, 0);
  if (renderer) {
    printf("Renderer created\n");
    running = true;
  } else {
    printf("Renderer not created\n");
    running = false;
    return;
  }
}

void Game::handleEvents(){
  while (SDL_PollEvent(&event)) {
    if (event.type == SDL_QUIT) {
      running = false;
    }
  }
}

void Game::update(){}

void Game::render(){
  // clear renderer
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  SDL_RenderClear(renderer);

  // test rectangles
  SDL_Rect rect = { 10, 10, 100, 100 };
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderFillRect(renderer, &rect);
  SDL_Rect rect2 = { 40, 40, 100, 100 };
  SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
  SDL_RenderFillRect(renderer, &rect2);
  SDL_Rect rect3 = { 70, 70, 100, 100 };
  SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
  SDL_RenderFillRect(renderer, &rect3);
  
  // draw to screen
  SDL_RenderPresent(renderer);
}

void Game::destroy(){
  // free resources
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  printf("SDL closed\n");
}