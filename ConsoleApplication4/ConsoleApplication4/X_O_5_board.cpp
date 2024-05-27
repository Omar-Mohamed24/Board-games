#include<iostream>
#include<random>
#include<iomanip>
#include<algorithm>
#include "X_O_5.h"
using namespace std;

int X_O_5_board::cnt_X = 0;
int X_O_5_board::cnt_O = 0;


X_O_5_board::X_O_5_board() {
    n_rows = n_cols = 5;
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
bool X_O_5_board::update_board(int m, int n, char mark) {
    // Only update if move is valid
    if (!(m < 0 || m > 4 || n < 0 || n > 4) && (board[m][n] == 0)) {
        board[m][n] = tolower(mark);
        n_moves++;
        return true;
    }
    else
        return false;
}

// Display the board and the pieces on it
void X_O_5_board::display_board()
{
    for (int i : {0, 1, 2, 3, 4}) {
        cout << "\n| ";
        for (int j : {0, 1, 2, 3, 4}) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board[i][j] << " |";
        }
        cout << "\n-----------------------------------------------";
    }
    cout << endl;
}

// Returns true if there is any winner
// either X or O
bool X_O_5_board::is_winner() {

    if (game_is_over()) {
        for (int i : {0, 1, 2, 3, 4}) {
            for (int j : {0, 1, 2}) {
                if (board[i][0 + j] == board[i][1 + j] && board[i][1 + j] == board[i][2 + j] &&
                    board[i][1 + j] == 'x') {
                    cnt_X++;
                }
                if (board[i][0 + j] == board[i][1 + j] && board[i][1 + j] == board[i][2 + j] &&
                    board[i][1 + j] == 'x') {
                    cnt_O++;
                }
                if (board[0 + j][i] == board[1 + j][i] && board[1 + j][i] == board[2 + j][i] &&
                    board[1 + j][i] == 'x') {
                    cnt_X++;
                }
                if (board[0 + j][i] == board[1 + j][i] && board[1 + j][i] == board[2 + j][i] &&
                    board[1 + j][i] == 'o') {
                    cnt_O++;
                }
            }
        }
        for (int i : {0, 1, 2}) {
            for (int j : {0, 1, 2}) {
                if (board[i][j] == board[i + 1][j + 1] && board[i + 1][j + 1] == board[i + 2][j + 2] &&
                    board[i + 1][j + 1] == 'x') {
                    cnt_X++;
                }
                if (board[i][j] == board[i + 1][j + 1] && board[i + 1][j + 1] == board[i + 2][j + 2] &&
                    board[i + 1][j + 1] == 'o') {
                    cnt_O++;
                }
                if (board[i][(j + 2)] == board[i + 1][(j + 2) - 1] &&
                    board[i + 1][(j + 2) - 1] == board[i + 2][(j + 2) - 2] &&
                    board[i + 1][(j + 2) - 1] == 'x') {
                    cnt_X++;
                }
                if (board[i][(j + 2)] == board[i + 1][(j + 2) - 1] &&
                    board[i + 1][(j + 2) - 1] == board[i + 2][(j + 2) - 2] &&
                    board[i + 1][(j + 2) - 1] == 'o') {
                    cnt_O++;
                }
            }
        }
        return true;
    }
    else {
        return false;
    }

}

// Return true if 9 moves are done and no winner
bool X_O_5_board::is_draw() {
    return (n_moves == 24);
}

bool X_O_5_board::game_is_over() {
    return (n_moves >= 24);
}