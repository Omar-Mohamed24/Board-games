#include<iostream>
#include<random>
#include<iomanip>
#include<algorithm>
#include"pyramid.h"
using namespace std;

// Give player a symbol to use in playing
// It can be X or O or others
// This is needed for computer players
// as it does not ask for a name
Pyramid_XO_Player::Pyramid_XO_Player(char symbol) {
    this->symbol = symbol;
}

// Optionally, you can give him ID or order
// Like Player 1 and Player 2
Pyramid_XO_Player::Pyramid_XO_Player(int order, char symbol) {
    cout << "Welcome player " << order << endl;
    cout << "Please enter your name: ";
    cin >> name;
    this->symbol = symbol;
}

// Get desired move: x y (each between 0 and 2)
// Virtual (can change for other player types)
void Pyramid_XO_Player::get_move(int& x, int& y) {
    cout << "\nPlease enter your move x and y (as showen above) separated by spaces: ";
    cin >> x >> y;
}

// Give player info as a string
string Pyramid_XO_Player::to_string() {
    return "Player: " + name;
}

// Get symbol used by player
char Pyramid_XO_Player::get_symbol() {
    return symbol;
}