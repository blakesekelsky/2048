#ifndef BOARD_HPP
#define BOARD_HPP

#include <SDL2/SDL.h>
#include "Tile.hpp"
#include <string>

class Board {
  private:
    int score = 0;
    int values[4][4] = {0};
    Tile tiles[4][4] = {Tile()};

  public:
    Board() {
      // generate starting tiles
      if (score == 0) {
        generateTile();
        generateTile();
      }
    }

    void generateTile();
    void makeCopy(int srcValues[4][4], int destValues[4][4]);
    bool compareCopy(int oldValues[4][4], int newValues[4][4]);
    bool isPossibleNextMove();

    bool swipeUp();
    bool swipeDown();
    bool swipeLeft();
    bool swipeRight();

    void handleEvents(SDL_Window *window, SDL_Event event) {
      if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
          case SDLK_UP:
            if (swipeUp()) {
              generateTile();
              if (!isPossibleNextMove()) {
                std::string title = "Game Over! Final score: " + std::to_string(score);
                SDL_SetWindowTitle(window, title.c_str());
              } else {
                SDL_SetWindowTitle(window, std::to_string(score).c_str());
              }
            }
            break;
          case SDLK_DOWN:
            if (swipeDown()) {
              generateTile();
              if (!isPossibleNextMove()) {
                std::string title = "Game Over! Final score: " + std::to_string(score);
                SDL_SetWindowTitle(window, title.c_str());
              } else {
                SDL_SetWindowTitle(window, std::to_string(score).c_str());
              }
            }
            break;
          case SDLK_LEFT:
            if (swipeLeft()) {
              generateTile();
              if (!isPossibleNextMove()) {
                std::string title = "Game Over! Final score: " + std::to_string(score);
                SDL_SetWindowTitle(window, title.c_str());
              } else {
                SDL_SetWindowTitle(window, std::to_string(score).c_str());
              }
            }
            break;
          case SDLK_RIGHT:
            if (swipeRight()) {
              generateTile();
              if (!isPossibleNextMove()) {
                std::string title = "Game Over! Final score: " + std::to_string(score);
                SDL_SetWindowTitle(window, title.c_str());
              } else {
                SDL_SetWindowTitle(window, std::to_string(score).c_str());
              }
            }
            break;
        }
      }
    }

    void update() {
      // update tiles
      for ( int i : {0, 1, 2, 3} ) {
        for ( int j : {0, 1, 2, 3} ) {
          // i = x, j = y
          tiles[i][j] = Tile(4 + (119 * j), 4 + (119 * i), 115, values[i][j]);
        }
      }
    }

    void render(SDL_Renderer *renderer) {
      // render board
      for ( int i : {0, 1, 2, 3} ) {
        for ( int j : {0, 1, 2, 3} ) {
          tiles[i][j].render(renderer);
        }
      }
    }
};

#endif
