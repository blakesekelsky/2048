#ifndef TILE_HPP
#define TILE_HPP

#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h>
#include <iostream>
#include <string>

class Tile {
  private:
    SDL_Rect tileRect = {0,0,0,0};
    SDL_Rect textRect = {0,0,0,0};
    SDL_Surface *msgSurface = nullptr;
    SDL_Texture *msgTexture = nullptr;
    TTF_Font *font = nullptr;
    int value = 0;
    SDL_Color textColor = {255,255,255};

    void initFont() {
      font = TTF_OpenFont("assets/MouldyCheeseRegular.ttf", 100);
      if (!font) {
        std::cerr << "Failed to load font: " << TTF_GetError() << std::endl;
      }
    }

    void destroy() {
      SDL_FreeSurface(msgSurface);
      SDL_DestroyTexture(msgTexture);
      TTF_CloseFont(font);
    }

  public:
    Tile() {}
    Tile(int x, int y, int size, int val) : tileRect({ x,y,size,size }), textRect({ x+5,y+20,size-10,size-10 }), value(val) {}
    Tile(int x, int y, int w, int h, int val) : tileRect({ x,y,w,h }), textRect({ x+5,y+20,w-10,h-10 }), value(val) {}

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
      msgSurface = TTF_RenderText_Solid(font, std::to_string(value).c_str(), textColor);
      msgTexture = SDL_CreateTextureFromSurface(renderer, msgSurface);
      SDL_RenderCopy(renderer, msgTexture, NULL, &textRect);

      // destroy text
      destroy();
    }
};

#endif