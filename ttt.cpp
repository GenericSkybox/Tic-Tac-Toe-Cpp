#include <iostream>
#include <vector>
#include "grid.h"

using namespace std;

// ask the player where they want to mark the grid
void PlayerTurn(bool isPlayer1Turn) {
    if (isPlayer1Turn) {
        std::cout << "Where do you want to place your X?\n";
    }
    else {
        std::cout << "Where do you want to place your Circle?\n";
    }
}

int main() {
    Grid grid;
    bool playerWon = false;
    bool isPlayer1Turn = true;
    bool inputInvalid = true;
    int turnCount = 0;
    int playerChoice;

    // introduction to the game and rules
    cout << "Welcome to Tic-Tac-Toe!\n";
    cout << "Choose your placement by treating the grid like a keypad.\n";
    cout << "(I.e. 1 is top-left, 2 is top-middle, 3 is top-right, 4 is middle-left, etc.)\n\n";

    // main game loop
    while (!playerWon && turnCount < 9) {
        // show the player the current grid and ask them for input
        grid.PrintGrid();
        PlayerTurn(isPlayer1Turn);

        // validate input inside of a loop
        inputInvalid = true;
        while (inputInvalid) {
            // if the grid choice is out of bounds or already filled, keep asking for a valid number
            if (cin >> playerChoice) {
                if (playerChoice <= 0 || playerChoice > 9) {
                    cout << "Sorry, that's not a valid grid number. Please enter a number between 1 and 9.\n";
                }
                else if (!grid.PlaceMark(playerChoice, isPlayer1Turn)) {
                    cout << "Sorry, that square is already filled. Please pick an empty grid slot.\n";
                }
                // if PlaceMark was successful, then we break the loopo
                else {
                    inputInvalid = false;
                }
            }
            // if user inputs something other than an int, we clear and ignore the command line input
            else {
                cout << "Sorry, that input was invalid. Please enter a number between 1 and 9.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        // update the turn counter on successful turns and check for a win state on the board
        turnCount++;
        playerWon = grid.CheckForWinState();

        // if the game isn't over, cycle the turns
        if (!playerWon) {
            isPlayer1Turn = !isPlayer1Turn;
        }
    }

    // print the final grid
    grid.PrintGrid();

    // if either player won, display a congratulatory message
    if (playerWon) {
        cout << "Congratulations! Player ";
        if (isPlayer1Turn) {
            cout << '1';
        }
        else {
            cout << '2';
        }
        cout << " wins!\n";
    }
    // otherwise, print a tie
    else {
        cout << "It's a draw!\n";
    }
}