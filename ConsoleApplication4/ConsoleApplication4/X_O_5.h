#pragma once
#include<iostream>
#include<random>
#include<iomanip>
#include<algorithm>
using namespace std;

class Board2 {
protected:
    int n_rows, n_cols;
    char** board;
    int  n_moves = 0;

public:
    // Return true  if move is valid and put it on board
    // within board boundaries in empty cell
    // Return false otherwise
    virtual bool update_board(int x, int y, char symbol) = 0;
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

class X_O_5_board : public Board2
{
public:
    static int cnt_X;
    static int cnt_O;
    X_O_5_board();
    bool update_board(int x, int y, char mark);
    void display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over();
};

class X_O_5_player {
protected:
    string name;
    char symbol;
public:
    // Two constructors to initiate player
    // Give player a symbol to use in playing
    // It can be X or O or others
    // Optionally, you can give him ID or order
    // Like Player 1 and Player 2
    X_O_5_player(char symbol); // Needed for computer players
    X_O_5_player(int order, char symbol);
    // Get desired move: x y (each between 0 and 2)
    // Virtual (can change for other player types)
    virtual void get_move(int& x, int& y);
    // Give player info as a string
    string to_string();
    // Get symbol used by player
    char get_symbol();
};

class X_O_5_random : public X_O_5_player {
protected:
    int dimension;
public:
    // Take a symbol and pass it to parent
    X_O_5_random(char symbol, int dimension);
    // Generate a random move
    void get_move(int& x, int& y);
};

class X_O_5_manager
{
private:
    Board2* boardPtr;
    X_O_5_player* players[2];
public:
    X_O_5_manager(Board2*, X_O_5_player* playerPtr[2]);

    void run();
};
