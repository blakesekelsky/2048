#ifndef BOARD_HPP
#define BOARD_HPP

#include <SDL2/SDL.h>
#include "Tile.hpp"

struct Board {
  int values[4][4] = {0};
  Tile tiles[4][4] = {Tile()};

  Board() {
    
  }

  void update() {
    // update tiles
    for ( int i : {0, 1, 2, 3} ) {
      for ( int j : {0, 1, 2, 3} ) {
        tiles[i][j].value = values[i][j];
      }
    }

    // update board
    for ( int i : {0, 1, 2, 3} ) {
      for ( int j : {0, 1, 2, 3} ) {
        tiles[i][j] = Tile(2 + (112 * i), 2 + (112 * j), 110, values[i][j]);
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
