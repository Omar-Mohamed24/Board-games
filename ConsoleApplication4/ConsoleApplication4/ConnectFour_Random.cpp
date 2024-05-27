#include<iostream>
#include<random>
#include<iomanip>
#include<algorithm>
#include"ConnectFour_classes.h"
using namespace std;

// Set player symbol and name as Random Computer Player
ConnectFour_Random::ConnectFour_Random(char symbol, int dimension) :ConnectFour_Player(symbol)
{
    this->dimension = dimension;
    this->name = "Random Computer Player";
    cout << "My names is " << name << endl;
}

// Generate a random move
void ConnectFour_Random::get_move(int& x)
{
    x = (int)(rand() / (RAND_MAX + 1.0) * dimension);
}
