#include "XO_Classes.hpp"


ComputerPlayer::ComputerPlayer(char symbol, Board &board) : Player(symbol) {
    vector<vector<char>> tmpBoard = board.get_board();
    minimax(true, 8, tmpBoard, board);
}

int ComputerPlayer::minimax(bool isMaximizing, int depth, vector<vector<char>> CurBoard, Board &tmpBoard, bool firstTime) {
    if (isDraw(CurBoard))
        return 0;
    if (isWinnerX(CurBoard))
        return 1;
    if (isWinnerO(CurBoard))
        return -1;
    if (isMaximizing) {
        int score, finalScore = INT_MIN;
        int finalI, finalJ;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (CurBoard[i][j] == ' ') {
                    CurBoard[i][j] = 'X';
                    score = minimax(!isMaximizing, depth - 1, CurBoard, tmpBoard, false);
                    CurBoard[i][j] = ' ';
                    if (score > finalScore) {
                        finalScore = score;
                        finalI = i;
                        finalJ = j;
                    }
                }
            }
        }
        if (firstTime) {
            tmpBoard.update_board(finalI, finalJ, 'X');
        }
        return finalScore;
    } else {
        int finalScore = INT_MAX, score, finalI, finalJ;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (CurBoard[i][j] == ' ') {
                    CurBoard[i][j] = 'O';
                    score = minimax(!isMaximizing, depth - 1, CurBoard, tmpBoard, false);
                    CurBoard[i][j] = ' ';
                    if (score < finalScore) {
                        finalScore = score;
                        finalI = i;
                        finalJ = j;
                    }
                }
            }
        }
        if (firstTime) {
            tmpBoard.update_board(finalI, finalJ, 'O');
        }
        return finalScore;
    }
}

bool ComputerPlayer::isDraw(vector<vector<char>> board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ')
                return false;
        }
    }
    if (!isWinnerO(board) && !isWinnerX(board))
        return true;
    return false;
}

bool ComputerPlayer::isWinnerX(vector<vector<char>> board) {
    //Checking Rows
    for (auto & i : board) {
        if (i[0] == i[1] && i[1] == i[2] && i[0] == 'X') {
            return true;
        }
    }

    //Checking Columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] == 'X') {
            return true;
        }
    }

    //Checking Diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] == 'X')
        ||(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] == 'X')) {
        return true;
    }

    return false;
}

bool ComputerPlayer::isWinnerO(vector<vector<char>> board) {
    //Checking Rows
    for (auto & i : board) {
        if (i[0] == i[1] && i[1] == i[2] && i[0] == 'O') {
            return true;
        }
    }

    //Checking Columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] == 'O') {
            return true;
        }
    }

    //Checking Diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] == 'O')
        ||(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] == 'O')) {
        return true;
    }

    return false;
}

