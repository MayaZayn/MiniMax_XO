// Class definition for XO_Player class
// Author:  Mohammad El-Ramly
// Date:    10/10/2022
// Version: 1

// Author2: Maya Ayman -> Added virtual function minimax
// ID: 20210508
// Last Modification: 8/11/2022

#include<iostream>
#include<random>
#include<iomanip>
#include<algorithm>
#include"XO_Classes.hpp"
using namespace std;

// Give player a symbol to use in playing
// It can be X or O or others
// This is needed for computer players
// as it does not ask for a name
Player::Player(char symbol) {
    this->symbol = symbol;
}

// Optionally, you can give him ID or order
// Like Player 1 and Player 2
Player::Player (int order, char symbol) {
    cout << "Welcome player " << order << endl;
    cout << "Please enter your name:\n";
    cin >> name;
    this->symbol = symbol;
}

// Get desired move: x y (each between 0 and 2)
// Virtual (can change for other player types)
void Player::get_move (int& x, int& y) {
    cout << "\nPlease enter your move x and y (0 to 2) separated by spaces:\n";
    cin >> x >> y;
}

// Give player info as a string
string Player::to_string(){
    return name ;
}

// Get symbol used by player
char Player::get_symbol() {
    return symbol;
}

int Player::minimax(bool isMaximizing, vector<vector<char>> CurBoard, Board &tmpBoard, bool firstTime) {
    return 0;
}

Player::Player() {}
