#include<iostream>
#include<random>
#include<iomanip>
#include<algorithm>
#include"ConnectFour_classes.h"
using namespace std;

ConnectFour_Player::ConnectFour_Player(char symbol) {
    this->symbol = symbol;
}

ConnectFour_Player::ConnectFour_Player(int order, char symbol) {
    cout << "Welcome player " << order << endl;
    cout << "Please enter your name: ";
    cin >> name;
    this->symbol = symbol;
}

// Get desired move: x y (each between 0 and 2)
// Virtual (can change for other player types)
void ConnectFour_Player::get_move(int& x) {
    cout << "\nPlease enter your move ";
    cin >> x;
}

// Give player info as a string
string ConnectFour_Player::to_string() {
    return "Player: " + name;
}

// Get symbol used by player
char ConnectFour_Player::get_symbol() {
    return symbol;
}

