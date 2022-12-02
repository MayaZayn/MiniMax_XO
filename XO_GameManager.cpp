// Class definition for XO_GameManager class
// Author:  Mohammad El-Ramly
// Date:    10/10/2022
// Version: 1

// Author2: Maya Ayman -> Added conditions to support the smart computer player
// ID: 20210508
// Last Modification: 8/11/2022

#include <iostream>
#include"XO_Classes.hpp"
using namespace std;

void GameManager::run() {
    Board x_o;
    int x, y, choice;
    Player* players[2];

    cout << "Press 1 if you want to play with computer (if not press any other value):\n";
    cin >> choice;
    players[0] = new Player(1, 'O');

    if (choice == 1) {
        //players[1] = new ComputerPlayer('X', x_o); This is if I wanna the computer to go first;
        x_o.display_board();

        for (int i = 0; i < 9; ++i) {
            if (i % 2 == 0) {
                players[0]->get_move(x, y);
                while (!x_o.update_board(x, y, players[0]->get_symbol())) {
                    players[0]->get_move(x, y);
                }
            } else {
                players[1] = new ComputerPlayer('X', x_o);
                cout << "\nComputer's Move:\n";
            }

            x_o.display_board();

            if (x_o.is_winner()){
                if (i % 2 == 0)
                    cout  << "Congratulations! You won, " << players[0]->to_string() << ".\n";
                else
                    cout << "You lost, " << players[0]->to_string() << ".\n";
                return;
            }

            if (x_o.is_draw()){
                cout << "Draw!\n";
                return;
            }
        }
    } else {
        players[1] = new Player(2, 'X');
        x_o.display_board();
        while (true) {
            for (int i:{0,1}) {
                players[i]->get_move(x, y);
                while (!x_o.update_board (x, y, players[i]->get_symbol())){
                    players[i]->get_move(x, y);
                }
                x_o.display_board();
                if (x_o.is_winner()){
                    cout  << players[i]->to_string() << " wins!\n";
                    return;
                }
                if (x_o.is_draw()){
                    cout << "Draw!\n";
                    return;
                }
            }
        }
    }
}
