#include<iostream>
#include<random>
#include<iomanip>
#include<algorithm>
#include"pyramid.h"
using namespace std;

// Set player symbol and name as Random Computer Player
Pyramid_XO_RandomPlayer::Pyramid_XO_RandomPlayer(char symbol, int dimension) :Pyramid_XO_Player(symbol)
{
    this->dimension = dimension;
    this->name = "Random Computer Player";
    cout << "My names is " << name << endl;
}

// Generate a random move
void Pyramid_XO_RandomPlayer::get_move(int& x, int& y)
{
    x = (int)(rand() / (RAND_MAX + 1.0) * dimension);
    y = (int)(rand() / (RAND_MAX + 1.0) * dimension);
}