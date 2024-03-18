#ifndef BOARD_HPP
#define BOARD_HPP

#include <SDL2/SDL.h>
#include "Tile.hpp"

class Board {
  private:
    int score = 0;
    int values[4][4] = {0};
    Tile tiles[4][4] = {Tile()};

  public:
    Board() {}

    bool generateTile();
    void printScore() { printf("Score: %d\n", score); }

    void leftSwipe();
    void rightSwipe();
    void upSwipe();
    void downSwipe();

    void update() {
      // if score is 0, generate two tiles
      if (score == 0) {
        generateTile();
        generateTile();
      }

      // update tiles
      for ( int i : {0, 1, 2, 3} ) {
        for ( int j : {0, 1, 2, 3} ) {
          tiles[i][j] = Tile(4 + (119 * i), 4 + (119 * j), 115, values[i][j]);
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

      // render score
      Tile scoreTile = Tile(370, 480, 96, 75, score);
      scoreTile.render(renderer);
    }
};

#endif
