#include <iostream>
#include <vector>
#include "grid.h"

using namespace std;

Grid::Grid() {
    // create an empty 3x3 grid
    vector_grid = {
      {' ', ' ', ' '},
      {' ', ' ', ' '},
      {' ', ' ', ' '}
    };
}

void Grid::PrintGrid() {
    for (int i = 0; i < vector_grid.size(); i++) {
        for (int j = 0; j < vector_grid[i].size(); j++) {
            // print the square and a pipe unless it's the end of the row
            cout << vector_grid[i][j];
            if (j != vector_grid[i].size() - 1) {
                cout << "|";
            }
        }

        // after every row, print a line unless it's the last row
        if (i != vector_grid.size() - 1) {
            cout << "\n";
            cout << "-----";
        }

        cout << "\n";
    }

    // an extra space for good measure
    cout << "\n";
}

bool Grid::PlaceMark(int square_position, bool isPlayer1Turn) {
    // since we accept 1 through 9 as input, we need to subtract 3 for every row down
    int row_pos = 0;
    while (square_position > 3) {
        square_position -= 3;
        row_pos++;
    }

    // subtract one to start the count at 0
    square_position--;

    // check if the square selected is free and place the X or O if it is
    if (vector_grid[row_pos][square_position] == ' ') {
        if (isPlayer1Turn) {
            vector_grid[row_pos][square_position] = 'X';
        }
        else {
            vector_grid[row_pos][square_position] = 'O';
        }
        return true;
    }
    else {
        return false;
    }
}

bool Grid::CheckForWinState() {
    // check for winning rows and columns
    for (int i = 0; i < vector_grid.size(); i++) {
        if (vector_grid[i][0] == vector_grid[i][1] && vector_grid[i][1] == vector_grid[i][2] && vector_grid[i][0] != ' ') {
            return true;
        }
        else if (vector_grid[0][i] == vector_grid[1][i] && vector_grid[1][i] == vector_grid[2][i] && vector_grid[0][i] != ' ') {
            return true;
        }
    }

    // check for winning diagonals
    if (vector_grid[0][0] == vector_grid[1][1] && vector_grid[1][1] == vector_grid[2][2] && vector_grid[0][0] != ' ') {
        return true;
    }
    else if (vector_grid[0][2] == vector_grid[1][1] && vector_grid[1][1] == vector_grid[2][0] && vector_grid[0][2] != ' ') {
        return true;
    }

    return false;
}