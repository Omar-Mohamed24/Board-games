#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include"ConnectFour_classes.h"
using namespace std;

ConnectFourBoard::ConnectFourBoard() {
    n_rows = 6;
    n_cols = 7;
    board = new char* [n_rows];
    for (int i = 0; i < n_rows; i++) {
        board[i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = ' ';
    }
}


bool ConnectFourBoard::update_board(int x, char mark) {
        for (int i = n_rows - 1; i >= 0; --i) {
            if (board[i][x] == ' ') {
                board[i][x] = mark;
                n_moves++;
                return true;
            }
            else {
                continue;
            }
        }
    return false;
}

void ConnectFourBoard::display_board() {
    cout << "-----------------------------\n";
    for (int i = 0; i < n_rows; ++i) {
        cout << "| ";
        for (int j = 0; j < n_cols; ++j) {
            cout << board[i][j] << " | ";
        }
        cout << "\n-----------------------------\n";
    }
    cout << "  0   1   2   3   4   5   6\n";
}

bool ConnectFourBoard::is_winner() {
    // Check horizontally
    for (int i = 0; i < n_rows; ++i) {
        for (int j = 0; j <= n_cols - 4; ++j) {
            if (board[i][j] != ' ' && board[i][j] == board[i][j + 1] &&
                board[i][j] == board[i][j + 2] && board[i][j] == board[i][j + 3]) {
                return true;
            }
        }
    }

    // Check vertically
    for (int i = 0; i <= n_rows - 4; ++i) {
        for (int j = 0; j < n_cols; ++j) {
            if (board[i][j] != ' ' && board[i][j] == board[i + 1][j] &&
                board[i][j] == board[i + 2][j] && board[i][j] == board[i + 3][j]) {
                return true;
            }
        }
    }

    // Check diagonally (from bottom-left to top-right)
    for (int i = 0; i <= n_rows - 4; ++i) {
        for (int j = 0; j <= n_cols - 4; ++j) {
            if (board[i][j] != ' ' && board[i][j] == board[i + 1][j + 1] &&
                board[i][j] == board[i + 2][j + 2] && board[i][j] == board[i + 3][j + 3]) {
                return true;
            }
        }
    }

    // Check diagonally (from top-left to bottom-right)
    for (int i = 3; i < n_rows; ++i) {
        for (int j = 0; j <= n_cols - 4; ++j) {
            if (board[i][j] != ' ' && board[i][j] == board[i - 1][j + 1] &&
                board[i][j] == board[i - 2][j + 2] && board[i][j] == board[i - 3][j + 3]) {
                return true;
            }
        }
    }

    return false;
}

bool ConnectFourBoard::is_draw()
{
    return (n_moves == 42 && !is_winner());
}

bool ConnectFourBoard::game_is_over()
{
    return (is_draw() || is_winner());
}
