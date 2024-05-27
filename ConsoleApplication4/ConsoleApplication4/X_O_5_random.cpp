#include<iostream>
#include<random>
#include<iomanip>
#include<algorithm>
#include "X_O_5.h"
using namespace std;

// Set player symbol and name as Random Computer Player
X_O_5_random::X_O_5_random(char symbol, int dimension) :X_O_5_player(symbol)
{
    this->dimension = dimension;
    this->name = "Random Computer Player";
    cout << "My names is " << name << endl;
}

// Generate a random move
void X_O_5_random::get_move(int& x, int& y)
{
    x = (int)(rand() / (RAND_MAX + 1.0) * dimension);
    y = (int)(rand() / (RAND_MAX + 1.0) * dimension);
}