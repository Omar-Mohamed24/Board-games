#pragma once
#include<iostream>
#include<random>
#include<iomanip>
#include<algorithm>
using namespace std;

class Board1 {
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

class Pyramid_XO_Board :public Board1 {
public:
    Pyramid_XO_Board();
    bool update_board(int x, int y, char mark);
    void display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over();
};

class Pyramid_XO_Player {
protected:
    string name;
    char symbol;
public:
    // Two constructors to initiate player
    // Give player a symbol to use in playing
    // It can be X or O or others
    // Optionally, you can give him ID or order
    // Like Player 1 and Player 2
    Pyramid_XO_Player(char symbol); // Needed for computer players
    Pyramid_XO_Player(int order, char symbol);
    // Get desired move: x y (each between 0 and 2)
    // Virtual (can change for other player types)
    virtual void get_move(int& x, int& y);
    // Give player info as a string
    string to_string();
    // Get symbol used by player
    char get_symbol();
};

class Pyramid_XO_RandomPlayer : public Pyramid_XO_Player {
protected:
    int dimension;
public:
    // Take a symbol and pass it to parent
    Pyramid_XO_RandomPlayer(char symbol, int dimension);
    // Generate a random move
    void get_move(int& x, int& y);
};

class Pyramid_XO_GameManager {
private:
    Board1* boardPtr;
    Pyramid_XO_Player* players[2];
public:
    Pyramid_XO_GameManager(Board1*, Pyramid_XO_Player* playerPtr[2]);
    virtual void run();
    // This method creates board and players
    // It displays board
    // While True
    //   For each player
    //      It takes a valid move as x, y pair (between 0 - 2)
    //      It updates board and displays otit
    //      If winner, declare so and end
    //      If draw, declare so and end

};
