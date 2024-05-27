#include<iostream>
#include<random>
#include<iomanip>
#include<algorithm>
#include "X_O_5.h"
#include "ConnectFour_classes.h"
#include "pyramid.h"
using namespace std;

int main() {
    int game;
    cout << "Welcome to FCAI Games. :)\n";
    cout << "Press 1 to play Pyramic Tic-Tac-Toe Game\n";
    cout << "Press 2 to play Four-in-a-row Game\n";
    cout << "Press 3 to play 5 x 5 Tic-Tac-Toe Game\n";
    cout << "Enter your choice : ";
    cin >> game;

    if (game == 1)
    {
        int choice;
        Pyramid_XO_Player* players[2];
        players[0] = new Pyramid_XO_Player(1, 'x');

        cout << "Welcome to FCAI Pyramic Tic-Tac-Toe Game. :)\n";
        cout << "Press 1 if you want to play with computer: \n";
        cout << "Press 2 if you want to play with real player: \n";
        cout << "Press 3 if you want to play with Ai: \n";
        cin >> choice;

        if (choice == 2) {
            players[1] = new Pyramid_XO_Player(2, 'o');
        }

        else if (choice == 1) {
            players[1] = new Pyramid_XO_RandomPlayer('o', 3);
        }

        //else if (choice == 3) {

        //}

        Pyramid_XO_GameManager Pyramid_XO_Game(new Pyramid_XO_Board(), players);
        Pyramid_XO_Game.run();
        system("pause");
    }
    
    else if (game == 2)
    {
        int choice;
        ConnectFour_Player* players[2];
        players[0] = new ConnectFour_Player(1, 'x');

        cout << "Welcome to FCAI Four-in-a-row Game. :)\n";
        cout << "Press 1 if you want to play with computer: \n";
        cout << "Press 2 if you want to play with real player: \n";
        cout << "Press 3 if you want to play with Ai: \n";
        cin >> choice;
        if (choice == 2) {
            players[1] = new ConnectFour_Player(2, 'o');
        }
    
        else if (choice == 1) {
            players[1] = new ConnectFour_Random('o', 3);
        }

        else if (choice == 3) {
            players[1] = new ConnectFour_AI(new ConnectFourBoard(), 'o');
        }

        ConnectFour_Manager connectfour_game(new ConnectFourBoard(), players);
        connectfour_game.run();
        system("pause");
    }
    
     else if (game == 3)
    {
        int choice;
        X_O_5_player* players[2];
        players[0] = new X_O_5_player(1, 'x');

        cout << "Welcome to FCAI 5x5 Tic-Tac-Toe Game. :)\n";
        cout << "Press 1 if you want to play with computer: \n";
        cout << "Press 2 if you want to play with real player: \n";
        cout << "Press 3 if you want to play with Ai: \n";
        cin >> choice;
        if (choice == 2) {
            players[1] = new X_O_5_player(2, 'o');
        }

        else if (choice == 1) {
            players[1] = new X_O_5_random('o', 5);
        }

        //else if (choice == 3) {
        
        //}

        X_O_5_manager x_o_game(new X_O_5_board(), players);
        x_o_game.run();
        system("pause");
    }
}





/*0 0
1 0
0 1
1 1
0 2
1 2
0 3
1 3
0 4
1 4
2 0
3 0
2 1
3 1
2 2
3 2
2 3
3 3
2 4
3 4
4 0
4 1
4 2
4 3
4 4
draw


0 0
0 1
0 2
0 3
0 4
1 0
1 1
1 2
1 3
1 4
2 0
2 1
2 2
2 3
2 4
3 0
3 1
3 2
3 3
3 4
4 0
4 1
4 2
4 3
4 4
1


4 4
0 0
0 1
0 2
0 3
0 4
1 0
1 1
1 2
1 3
1 4
2 0
2 1
2 2
2 3
2 4
3 0
3 1
3 2
3 3
3 4
4 0
4 1
4 2
4 3
2*/