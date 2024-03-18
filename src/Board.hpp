#ifndef BOARD_HPP
#define BOARD_HPP

#include <SDL2/SDL.h>
#include "Tile.hpp"

struct Board {
  int values[4][4] = {0};
  Tile tiles[4][4] = {Tile()};

  Board() {
    
  }

  void render(SDL_Renderer *renderer) {
    // create tiles
    for ( int i : {0, 1, 2, 3} ) {
      for ( int j : {0, 1, 2, 3} ) {
        tiles[i][j] = Tile(2 + (112 * i), 2 + (112 * j), 110, values[i][j]);
        printf("Tile created at %d, %d with value %d \n", tiles[i][j].textRect.x, tiles[i][j].textRect.y, tiles[i][j].value);
      }
    }

    // render board
    for ( int i : {0, 1, 2, 3} ) {
      for ( int j : {0, 1, 2, 3} ) {
        tiles[i][j].render(renderer);
      }
    }
  }
};

#endif
