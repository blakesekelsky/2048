#ifndef TILE_HPP
#define TILE_HPP

#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h>
#include <iostream>
#include <string>

class Tile {
  private:
    SDL_Rect tileRect = {0,0,0,0};

    int value = 0;
    SDL_Surface *msgSurface = nullptr;
    SDL_Texture *msgTexture = nullptr;
    SDL_Color textColor = {255,255,255};
    TTF_Font *font = nullptr;

    void destroy() {
      SDL_FreeSurface(msgSurface);
      SDL_DestroyTexture(msgTexture);
      TTF_CloseFont(font);
    }

  public:
    Tile() {}
    Tile(int xpos, int ypos, int size, int val) : tileRect({ xpos,ypos,size,size }), value(val) {}

    void render(SDL_Renderer *renderer) {
      // open font
      font = TTF_OpenFont("assets/SunnySpellsBasic.ttf", 100);
      if (!font) {
        std::cerr << "Failed to load font: " << TTF_GetError() << std::endl;
      }

      // draw tile
      SDL_SetRenderDrawColor(renderer,0,0,0,255);
      SDL_RenderFillRect(renderer, &tileRect);

      // draw text
      msgSurface = TTF_RenderText_Solid(font, std::to_string(value).c_str(), textColor);
      msgTexture = SDL_CreateTextureFromSurface(renderer, msgSurface);
      SDL_RenderCopy(renderer, msgTexture, NULL, &tileRect);

      // destroy text
      destroy();
    }
};

#endif