#include "Board.hpp"

bool Board::generateTile() {
  // generate tile of either 2 or 4 at random available position, printf error if no position available
  int availablePositions = 0;
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      if (values[i][j] == 0) {
        ++availablePositions;
      }
    }
  }
  if (availablePositions == 0) {
    return false;
  }

  int x = rand() % 4;
  int y = rand() % 4;
  while (values[x][y] != 0) {
    x = rand() % 4;
    y = rand() % 4;
  }
  values[x][y] = (rand() % 2 + 1) * 2;
  return true;
}