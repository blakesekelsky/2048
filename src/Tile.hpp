#ifndef TILE_HPP
#define TILE_HPP

#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h>
#include <iostream>
#include <string>

struct Tile {
  SDL_Rect tileRect = {0,0,0,0};
  SDL_Rect textRect = {0,0,0,0};
  SDL_Color textColor = {255,255,255};
  TTF_Font *font = nullptr;
  int value = 0;

  Tile() {}
  Tile(int x, int y, int size, int val) : tileRect({ x,y,size,size }), textRect({ x,y,size,size }), value(val) {}

  void initFont() {
    font = TTF_OpenFont("assets/FantasqueSansMonoBold.ttf", 24);
    if (!font) {
      std::cerr << "Failed to load font: " << TTF_GetError() << std::endl;
    }
  }

  void render(SDL_Renderer *renderer) {
    // verify font
    if (!font) {
      initFont();
      if (!font) return;
    }

    // draw tile
    SDL_SetRenderDrawColor(renderer,0,0,0,255);
    SDL_RenderFillRect(renderer, &tileRect);

    // draw text
    SDL_Surface *msgSurface = TTF_RenderText_Solid(font, std::to_string(value).c_str(), textColor);
    SDL_Texture *msgTexture = SDL_CreateTextureFromSurface(renderer, msgSurface);
    SDL_RenderCopy(renderer, msgTexture, NULL, &textRect);

    destroy(msgSurface, msgTexture);
  }

  void destroy(SDL_Surface *msgSurface, SDL_Texture *msgTexture) {
    SDL_FreeSurface(msgSurface);
    SDL_DestroyTexture(msgTexture);
    TTF_CloseFont(font);
  }
};

#endif