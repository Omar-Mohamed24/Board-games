#include "ConnectFour_classes.h"

ConnectFour_AI::ConnectFour_AI(Board* bPtr, char symbol) :ConnectFour_Player(symbol)
{
    boardPtr = bPtr;
    this->name = "ConnectFour AI";
    cout << "My name is " << name << endl;
}

void ConnectFour_AI::get_move(int& x) {
    char opponentSymbol = (symbol == 'X') ? 'O' : 'X';

    // Make a copy of the current board state
    ConnectFourBoard tempBoard = *dynamic_cast<ConnectFourBoard*>(boardPtr);

    for (int col = 0; col < n_cols; ++col) {
        // Simulate the move for the AI
        if (tempBoard.update_board(col, symbol) && tempBoard.is_winner()) {
            x = col;
            return;
        }
        tempBoard = *dynamic_cast<ConnectFourBoard*>(boardPtr);

        // Simulate the move for the opponent
        if (tempBoard.update_board(col, opponentSymbol) && tempBoard.is_winner()) {
            x = col;
            return;
        }
        tempBoard = *dynamic_cast<ConnectFourBoard*>(boardPtr);
    }
    x = (int)(rand() / (RAND_MAX + 1.0) * n_cols);
}

