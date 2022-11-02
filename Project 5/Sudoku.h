#ifndef SUDOKU_H
#define SUDOKU_H

#include "Searchable.h"
#include "set"
#include "vector"

using namespace std;

// TODO: Your Sudoku class goes here:

class Sudoku {
public:
  vector<vector<set<int>>> board;
  set<int> sudokuNumbers = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  Sudoku(int boardSize) {
      for (int i = 0; i < boardSize; ++i) {
        vector<set<int>> row;
        for (int j = 0; j < boardSize; ++j) {
          row.push_back(sudokuNumbers);
        }
        board.push_back(row);
      }
  }

  int getSquare(int row, int col) {
    auto value = board[row][col];
    if (value.size() == 1) {
      auto square = value.begin();
      return *square;
    } else {
      return -1;
    }
  }


};


#endif
