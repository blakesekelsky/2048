#include "Board.hpp"
#include <ctime>

void Board::generateTile() {
  int unusedTiles = 0;
  for (int i : {0,1,2,3}) {
    for (int j : {0,1,2,3}) {
      if (values[i][j] == 0) {
        unusedTiles++;
      }
    }
  }

  if (unusedTiles == 0) {
    printf("No more tiles left\n");
    return;
  }

  srand(time(NULL));
  int i = rand() % 4;
  int j = rand() % 4;
  while (values[i][j] != 0) {
    i = rand() % 4;
    j = rand() % 4;
  }
  values[i][j] = (rand() % 2 + 1) * 2;
}

void Board::makeCopy(int srcValues[4][4], int destValues[4][4]) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      destValues[i][j] = srcValues[i][j];
    }
  }
}

bool Board::compareCopy(int oldValues[4][4], int newValues[4][4]) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (oldValues[i][j] != newValues[i][j]) {
        return false;
      }
    }
  }
  return true;
}

bool Board::swipeUp() {
  // make a copy of values
  int oldValues[4][4];
  makeCopy(values, oldValues);

  //shift values up
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (values[j][i] == 0) {
        for (int k = j+1; k<4; k++) {
          if (values[k][i] != 0) {
            values[j][i] = values[k][i];
            values[k][i] = 0;
            break;
          }
        }
      }
    }
  }

  //merge values up
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 3; j++) {
      if (values[j][i] != 0 && values[j][i] == values[j+1][i]) {
        values[j][i] *= 2;
        values[j+1][i] = 0;
        score += values[j][i];
        j++;
      }
    }
  }

  //shift values up
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (values[j][i] == 0) {
        for (int k = j+1; k<4; k++) {
          if (values[k][i] != 0) {
            values[j][i] = values[k][i];
            values[k][i] = 0;
            break;
          }
        }
      }
    }
  }

  //return if old and new values are a copy(invalid move)
  return !compareCopy(oldValues, values);
}

bool Board::swipeDown() {
  // make copy
  int oldValues[4][4];
  makeCopy(values, oldValues);

  // shift values down
  for (int i = 0; i < 4; i++) {
    for (int j = 3; j > 0; j--) {
      if (values[j][i] == 0) {
        for (int k = j - 1; k >=0; k--) {
          if (values[k][i] != 0) {
            values[j][i] = values[k][i];
            values[k][i] = 0;
            break;
          }
        }
      }
    }
  }

  // merge values down
  for (int i = 0; i < 4; i++) {
    for (int j = 3; j > 0; j--) {
      if (values[j][i] != 0 && values[j][i] == values[j-1][i]) {
        values[j][i] *= 2;
        values[j-1][i] = 0;
        score += values[j][i];
        j--;
      }
    }
  }

  // shift values down
  for (int i = 0; i < 4; i++) {
    for (int j = 3; j > 0; j--) {
      if (values[j][i] == 0) {
        for (int k = j - 1; k >=0; k--) {
          if (values[k][i] != 0) {
            values[j][i] = values[k][i];
            values[k][i] = 0;
            break;
          }
        }
      }
    }
  }

  // compare copy
  return !compareCopy(oldValues, values);
}

bool Board::swipeLeft() {
  // make copy
  int oldValues[4][4];
  makeCopy(values, oldValues);

  //shift values left
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (values[i][j] == 0) {
        for (int k = j+1; k < 4; k++) {
          if (values[i][k] != 0) {
            values[i][j] = values[i][k];
            values[i][k] = 0;
            break;
          }
        }
      }
    }
  }

  // merge values left
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 3; j++) {
      if (values[i][j] != 0 && values[i][j] == values[i][j+1]) {
        values[i][j] *= 2;
        values[i][j+1] = 0;
        score += values[i][j];
        j++;
      }
    }
  }

  // shift values left
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (values[i][j] == 0) {
        for (int k = j+1; k < 4; k++) {
          if (values[i][k] != 0) {
            values[i][j] = values[i][k];
            values[i][k] = 0;
            break;
          }
        }
      }
    }
  }

  // compare copy
  return !compareCopy(oldValues, values);
}

bool Board::swipeRight() {
  // make copy
  int oldValues[4][4];
  makeCopy(values, oldValues);

  //shift values right
  for (int i = 0; i < 4; i++) {
    for (int j = 3; j > 0; j--) {
      if (values[i][j] == 0) {
        for (int k = j-1; k >= 0; k--) {
          if (values[i][k] != 0) {
            values[i][j] = values[i][k];
            values[i][k] = 0;
            break;
          }
        }
      }
    }
  }

  // merge values right
  for (int i = 0; i < 4; i++) {
    for (int j = 3; j > 0; j--) {
      if (values[i][j] != 0 && values[i][j] == values[i][j-1]) {
        values[i][j] *= 2;
        values[i][j-1] = 0;
        score += values[i][j];
        j--;
      }
    }
  }


  // shift values right
  for (int i = 0; i < 4; i++) {
    for (int j = 3; j > 0; j--) {
      if (values[i][j] == 0) {
        for (int k = j-1; k >= 0; k--) {
          if (values[i][k] != 0) {
            values[i][j] = values[i][k];
            values[i][k] = 0;
            break;
          }
        }
      }
    }
  }

  // compare copy
  return !compareCopy(oldValues, values);
}

bool Board::isPossibleNextMove() {
  int oldValues[4][4];
  makeCopy(values, oldValues);

  bool possible = swipeUp() || swipeDown() || swipeLeft() || swipeRight();

  // restore values
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      values[i][j] = oldValues[i][j];
    }
  }

  return possible;
}