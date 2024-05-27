#pragma once
#include<iostream>
#include<random>
#include<iomanip>
#include<algorithm>
using namespace std;

class Board {
protected:
    int n_rows, n_cols;
    char** board;
    int  n_moves = 0;

public:
    // Return true  if move is valid and put it on board
    // within board boundaries in empty cell
    // Return false otherwise
    virtual bool update_board(int x,char symbol) = 0;
    // Returns true if there is any winner
    // either X or O
    // Written in a complex way. DO NOT DO LIKE THIS.
    virtual bool is_winner() = 0;
    // Return true if all moves are done and no winner
    virtual bool is_draw() = 0;
    // Display the board and the pieces on it
    virtual void display_board() = 0;
    // Return true if game is over
    virtual bool game_is_over() = 0;
};

class ConnectFour_Player {
protected:
    string name;
    char symbol;
public:
    ConnectFour_Player(char symbol);
    ConnectFour_Player(int order, char symbol);
    virtual void get_move(int& x);
    string to_string();
    char get_symbol();
};

class ConnectFour_Manager {
private:
    Board* boardPtr;
    ConnectFour_Player* players[2];
public:
    ConnectFour_Manager(Board*, ConnectFour_Player* playerPtr[2]);
    virtual void run();
};

class ConnectFour_Random : public ConnectFour_Player {
protected:
    int dimension;
public:

    ConnectFour_Random(char symbol, int dimension);
    void get_move(int& x);
};

class ConnectFourBoard :public Board {
public:
    ConnectFourBoard();
    bool update_board(int x, char mark);
    void display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over();
};

class ConnectFour_AI : public ConnectFour_Player {
private:
    Board* boardPtr;
    int n_rows = 6;
    int n_cols = 7;
public:
    ConnectFour_AI(Board*, char symbol);
    void get_move(int& x);
};

