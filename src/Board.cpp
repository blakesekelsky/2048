#include "Board.hpp"

bool Board::generateTile() {
  int availablePositions = 0;
  for (int i : {0, 1, 2, 3}) {
    for (int j : {0, 1, 2, 3}) {
      if (values[i][j] == 0) {
        ++availablePositions;
      }
    }
  }
  if (availablePositions == 0) {
    return false;
  }

  // place random tile
  int x = rand() % 4;
  int y = rand() % 4;
  while (values[x][y] != 0) {
    x = rand() % 4;
    y = rand() % 4;
  }
  values[x][y] = (rand() % 2 + 1) * 2;
  score += values[x][y];
  return true;
}


void Board::leftSwipe(){ printf("left swipe\n"); }
void Board::rightSwipe(){ printf("right swipe\n"); }
void Board::upSwipe(){ printf("up swipe\n"); }
void Board::downSwipe(){ printf("down swipe\n"); }