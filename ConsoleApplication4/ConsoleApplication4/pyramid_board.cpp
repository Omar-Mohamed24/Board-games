#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include"pyramid.h"
using namespace std;

Pyramid_XO_Board::Pyramid_XO_Board()
{
    n_rows = 3;
    n_cols = 5;
    board = new char* [n_rows];
    for (int i = 0; i < n_rows; i++) {
        board[i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}

// Return true  if move is valid and put it on board
// within board boundaries in empty cell
// Return false otherwise
bool Pyramid_XO_Board::update_board(int x, int y, char mark) {
    // Only update if move is valid
    if (!((x == 0 && (y < 2 || y > 2)) || (x == 1 && (y < 1 || y > 3))) && (board[x][y] == 0)) {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else
        return false;
}

// Display the board and the pieces on it
void Pyramid_XO_Board::display_board() {
    for (int i : {0, 1, 2})
    {
        if (i == 0)
        {
            cout << "\n                  ----------";
            cout << "\n                  | ";
            cout << "(" << i << "," << "2" << ")";
            cout << setw(2) << board[i][2] << " | ";

            cout << "\n         ----------------------------";
        }
        else if (i == 1)
        {
            cout << "\n         | ";
            for (int j : {1, 2, 3}) {
                cout << "(" << i << "," << j << ")";
                cout << setw(2) << board[i][j] << " | ";
            }
            cout << "\n----------------------------------------------";
        }
        else if (i == 2)
        {
            cout << "\n| ";
            for (int j : {0, 1, 2, 3, 4}) {
                cout << "(" << i << "," << j << ")";
                cout << setw(2) << board[i][j] << " | ";
            }
            cout << "\n----------------------------------------------";
        }
    }
    cout << endl;
}

// Returns true if there is any winner
// either X or O
bool Pyramid_XO_Board::is_winner() {
    //Checking Virtcal Lines:
    if (board[0][2] != 0 && board[0][2] == board[1][2] && board[0][2] == board[2][2]) return true;

    //Checking Horizontal Lines:
    if (board[1][1] != 0 && board[1][1] == board[1][2] && board[1][1] == board[1][3]) return true;
    if (board[2][0] != 0 && board[2][0] == board[2][1] && board[2][0] == board[2][2]) return true;
    if (board[2][1] != 0 && board[2][1] == board[2][2] && board[2][1] == board[2][3]) return true;
    if (board[2][2] != 0 && board[2][2] == board[2][3] && board[2][2] == board[2][4]) return true;

    //Cheecking Diagonal Lines:
    if (board[0][2] != 0 && board[0][2] == board[1][1] && board[0][2] == board[2][0]) return true;
    if (board[0][2] != 0 && board[0][2] == board[1][3] && board[0][2] == board[2][4]) return true;

    return false;
}


// Return true if 9 moves are done and no winner
bool Pyramid_XO_Board::is_draw() {
    return (n_moves == 9 && !is_winner());
}

bool Pyramid_XO_Board::game_is_over() {
    return n_moves >= 9;
}