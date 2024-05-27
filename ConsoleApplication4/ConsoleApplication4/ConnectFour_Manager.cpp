#include<iostream>
#include<random>
#include<iomanip>
#include<algorithm>
#include"ConnectFour_classes.h"
using namespace std;

ConnectFour_Manager::ConnectFour_Manager(Board* bPtr, ConnectFour_Player* playerPtr[2]) {
    boardPtr = bPtr;
    players[0] = playerPtr[0];
    players[1] = playerPtr[1];
}

void ConnectFour_Manager::run() {
    int x;

    boardPtr->display_board();

    while (!boardPtr->game_is_over()) {
        for (int i : {0, 1}) {
            players[i]->get_move(x);
            while (!boardPtr->update_board(x, players[i]->get_symbol())) {
                players[i]->get_move(x);
            }
            boardPtr->display_board();
            if (boardPtr->is_winner()) {
                cout << players[i]->to_string() << " wins\n";
                return;
            }
            if (boardPtr->is_draw()) {
                cout << "Draw!\n";
                return;
            }
        }
    }
}