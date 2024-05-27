#include<iostream>
#include<random>
#include<iomanip>
#include<algorithm>
#include "X_O_5.h"
using namespace std;

// Give player a symbol to use in playing
// It can be X or O or others
// This is needed for computer players
// as it does not ask for a name
X_O_5_player::X_O_5_player(char symbol) {
    this->symbol = symbol;
}

// Optionally, you can give him ID or order
// Like Player 1 and Player 2
X_O_5_player::X_O_5_player(int order, char symbol) {
    cout << "Welcome player " << order << endl;
    cout << "Please enter your name: ";
    cin >> name;
    this->symbol = symbol;
}

// Get desired move: x y (each between 0 and 2)
// Virtual (can change for other player types)
void X_O_5_player::get_move(int& x, int& y) {
    cout << "\nPlease enter your move x and y (as showen above) separated by spaces: ";
    cin >> x >> y;
}

// Give player info as a string
string X_O_5_player::to_string() {
    return "Player: " + name;
}

// Get symbol used by player
char X_O_5_player::get_symbol() {
    return symbol;
}
