#include <iostream>
#include <SDL2/SDL.h>

int main() {
    bool running = false;

    // initialize SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
      printf("SDL initialized\n");
    } else {
      printf("SDL not initialized\n");
      return -1;
    }

    // create window
    SDL_Window *window = SDL_CreateWindow("2048", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);
    if (window) {
      printf("Window created\n");
    } else {
      printf("Window not created\n");
      return -1;
    } 

    // create renderer
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer) {
      printf("Renderer created\n");
      running = true;
    } else {
      printf("Renderer not created\n");
      return -1;
    }

    while (running) {
      SDL_Event event;
      while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
          running = false;
        }
      }
      
      // clear renderer
      SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
      SDL_RenderClear(renderer);

      // test rectangle
      SDL_Rect rect = { 10, 10, 100, 100 };
      SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
      SDL_RenderFillRect(renderer, &rect);
      
      // draw to screen
      SDL_RenderPresent(renderer);
    }

    // free resources
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    printf("SDL closed\n");
}