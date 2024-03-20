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

void Board::makeCopy(int oldValues[4][4]) {
  for (int i : {0, 1, 2, 3}) {
    for (int j : {0, 1, 2, 3}) {
      oldValues[i][j] = values[i][j];
    }
  }
}

bool Board::compareCopy(int oldValues[4][4]) {
  for (int i : {0, 1, 2, 3}) {
    for (int j : {0, 1, 2, 3}) {
      if (oldValues[i][j] != values[i][j]) {
        return false;
      }
    }
  }
  return true;
}

bool Board::leftSwipe(){
  // make a copy of the array to compare later
  int oldValues[4][4];
  makeCopy(oldValues);

  // shift all non-zero values all the way to the left
  for (int i : {0, 1, 2, 3}) {
    for (int j : {0, 1, 2, 3}) {
      if (values[i][j] == 0) {
        for (int k = j + 1; k < 4; ++k) {
          if (values[i][k] != 0) {
            values[i][j] = values[i][k];
            values[i][k] = 0;
            break;
          }
        }
      }
    }
  }

  // combine like values
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 3; j++) {
      if (values[i][j] != 0 && values[i][j] == values[i][j + 1]) {
        values[i][j] *= 2;
        values[i][j + 1] = 0;
        score += values[i][j];
        j++;
      }
    }
  }

  // shift all non-zero values all the way to the left
  for (int i : {0, 1, 2, 3}) {
    for (int j : {0, 1, 2, 3}) {
      if (values[i][j] == 0) {
        for (int k = j + 1; k < 4; ++k) {
          if (values[i][k] != 0) {
            values[i][j] = values[i][k];
            values[i][k] = 0;
            break;
          }
        }
      }
    }
  }

  // if array has changed, move is valid
  return !compareCopy(oldValues);
}

bool Board::rightSwipe(){ 
  int oldValues[4][4];
  makeCopy(oldValues);

  // shift all non-zero values all the way to the right
  for (int i : {0, 1, 2, 3}) {
    for (int j : {3, 2, 1, 0}) {
      if (values[i][j] == 0) {
        for (int k = j - 1; k >= 0; --k) {
          if (values[i][k] != 0) {
            values[i][j] = values[i][k];
            values[i][k] = 0;
            break;
          }
        }
      }
    }
  }

  // combine like values
  for (int i = 0; i < 4; i++) {
    for (int j = 3; j > 0; j--) {
      if (values[i][j] != 0 && values[i][j] == values[i][j - 1]) {
        values[i][j] *= 2;
        values[i][j - 1] = 0;
        score += values[i][j];
        j--;
      }
    }
  }

  // shift all non-zero values all the way to the right
  for (int i : {0, 1, 2, 3}) {
    for (int j : {3, 2, 1, 0}) {
      if (values[i][j] == 0) {
        for (int k = j - 1; k >= 0; --k) {
          if (values[i][k] != 0) {
            values[i][j] = values[i][k];
            values[i][k] = 0;
            break;
          }
        }
      }
    }
  }

  // if array has changed, move is valid
  return !compareCopy(oldValues);
}

bool Board::upSwipe(){ 
  // make a copy of the array to compare later
  int oldValues[4][4];
  makeCopy(oldValues);

  // shift all non-zero values all the way to the top
  for (int i : {0, 1, 2, 3}) {
    for (int j : {0, 1, 2, 3}) {
      if (values[j][i] == 0) {
        for (int k = j + 1; k < 4; ++k) {
          if (values[k][i] != 0) {
            values[j][i] = values[k][i];
            values[k][i] = 0;
            break;
          }
        }
      }
    }
  }

  // combine like values
  for (int i = 0; i < 4; i++) { 
    for (int j = 0; j < 3; j++) {
      if (values[j][i] != 0 && values[j][i] == values[j + 1][i]) {
        values[j][i] *= 2;
        values[j + 1][i] = 0;
        score += values[j][i];
        j++;
      }
    }
  }

  // shift all non-zero values all the way to the top
  for (int i : {0, 1, 2, 3}) {
    for (int j : {0, 1, 2, 3}) {
      if (values[j][i] == 0) {
        for (int k = j + 1; k < 4; ++k) {
          if (values[k][i] != 0) {
            values[j][i] = values[k][i];
            values[k][i] = 0;
            break;
          }
        }
      }
    }
  }

  // if array has changed, move is valid
  return !compareCopy(oldValues);
}

bool Board::downSwipe(){ 
  // make a copy of the array to compare later
  int oldValues[4][4];
  makeCopy(oldValues);

  // shift all non-zero values all the way to the bottom
  for (int i : {0, 1, 2, 3}) {
    for (int j : {3, 2, 1, 0}) {
      if (values[j][i] == 0) {
        for (int k = j - 1; k >= 0; --k) {
          if (values[k][i] != 0) {
            values[j][i] = values[k][i];
            values[k][i] = 0;
            break;
          }
        }
      }
    }
  }

  // combine like values
  for (int i = 0; i < 4; i++) {
    for (int j = 3; j > 0; j--) {
      if (values[j][i] != 0 && values[j][i] == values[j - 1][i]) {
        values[j][i] *= 2;
        values[j - 1][i] = 0;
        score += values[j][i];
        j--;
      }
    }
  }

  // shift all non-zero values all the way to the bottom
  for (int i : {0, 1, 2, 3}) {
    for (int j : {3, 2, 1, 0}) {
      if (values[j][i] == 0) {
        for (int k = j - 1; k >= 0; --k) {
          if (values[k][i] != 0) {
            values[j][i] = values[k][i];
            values[k][i] = 0;
            break;
          }
        }
      }
    }
  }

  // if array has changed, move is valid
  return !compareCopy(oldValues);
}