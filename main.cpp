//
//  main.cpp
//
//  Created by Austin Tsang on 9/27/18.
//  Copyright © 2018 Austin Tsang. All rights reserved.
//
#include <iostream>
using namespace std;

bool isWon(char player, char board[][3]);
bool isDraw(char board[][3]);
void displayBoard(char board[][3]);
void makeAMove(char board[][3], char);

int main() {
    char board[3][3] = { { ' ', ' ', ' ' },{ ' ', ' ', ' ' },{ ' ', ' ', ' ' } };
    displayBoard(board);
    
    while (true) {
        // The first player makes a move
        makeAMove(board, 'X');
        displayBoard(board);
        if (isWon('X', board)) {
            cout << "X player won" << endl;
            exit(0);
        }
        else if (isDraw(board)) {
            cout << "No winner" << endl;
            exit(0);
        }

        // The second player makes a move
        makeAMove(board, 'O');
        displayBoard(board);

        if (isWon('O', board)) {
            cout << "O player won" << endl;
            exit(0);
        }
        else if (isDraw(board)) {
            cout << "No winner" << endl;
            exit(0);
        }
    }

    return 0;
}

// Make move
void makeAMove(char board[][3], char player) {
    int inputRow, inputColumn;
    cout << "Enter a row (0, 1, 2) for player " << player << ": ";
    cin >> inputRow;
    cout << "Enter a column (0, 1, 2) for player " << player << " ";
    cin >> inputColumn;
    
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(i == inputRow && j == inputColumn) {
                board[i][j] = player;
            }
        }
    }
}

// an array with 3 rows and 3 columns.
// output each array element's value
void displayBoard(char board[][3]) {
    for (int i = 0; i < 3; i++) {
        cout << "-------------" << endl;
        for (int j = 0; j < 3; j++) {
            switch(j) {
                case 0 : cout << "| " << board[i][j];
                    break;
                case 2 : cout << board[i][j] << " |" << endl;
                    break;
                default : cout << " | " << board[i][j] << " | " ;
                    break;
            }
        }
        if(i == 2) {
            cout << "-------------" << endl;
        }
    }
};

// If Won
bool isWon(char player, char board[][3]) {
    for(int i=0; i<3 ; i++) {
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
    }
    
    for(int j=0; j<3 ; j++) {
        if(board[0][j] == player && board[1][j] == player && board[2][j] == player)
            return true;
    }
        
    if((board[0][0] == player && board[1][1] == player && board[2][2] == player)||( board[0][2] == player && board[2][2] == player && board[2][0] == player))
        return true;
    else return false;
};

// If draw
bool isDraw(char board[][3]) {
    for(int i = 0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(board[i][j] == ' ') return false;
        }
    }
    return true;
};


