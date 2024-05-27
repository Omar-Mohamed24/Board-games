#include<iostream>
#include<random>
#include<iomanip>
#include<algorithm>
#include "X_O_5.h"
using namespace std;

X_O_5_manager::X_O_5_manager(Board2* bPtr, X_O_5_player* playerPtr[2]) {
    boardPtr = bPtr;
    players[0] = playerPtr[0];
    players[1] = playerPtr[1];
}

void X_O_5_manager::run() {
    int m, n;
    boardPtr->display_board();
    while (!boardPtr->game_is_over()) {
        for (int i : {0, 1}) {
            players[i]->get_move(m, n);
            while (!boardPtr->update_board(m, n, players[i]->get_symbol())) {
                players[i]->get_move(m, n);
            }
            boardPtr->display_board();
            if (boardPtr->is_winner() && X_O_5_board::cnt_X > X_O_5_board::cnt_O) {
                cout << players[0]->to_string() << " wins\n";
                return;
            }
            else if (boardPtr->is_winner() && X_O_5_board::cnt_X < X_O_5_board::cnt_O) {
                cout << players[1]->to_string() << " wins\n";
                return;
            }
            else if (boardPtr->is_draw() && X_O_5_board::cnt_X == X_O_5_board::cnt_O) {
                cout << "Draw!\n";
                return;
            }
        }
    }
}