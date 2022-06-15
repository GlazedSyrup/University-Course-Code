//Create a connect 4 Game
#include <iostream>
#include <string>

using namespace std;

//Global constants for the game pieces
const char EMP = '-';
const char P1 = 'X';
const char P2 = 'O';

//global variables/constants for the game board
const int COLS = 7;
const int ROWS = 6;
char board[COLS][ROWS]; // 2D array of 7x6 conect 4 board

//Initialize the board to be empty
void InitializeBoard();

//Display the board
void displayBoard();

//Add one piece to the Board
bool addPiece(int c, bool isPlayer1);

int main(){
    InitializeBoard();
    displayBoard();
    addPiece(0, true);
    addPiece(0, false);
    displayBoard();
    return 0;
}

void InitializeBoard(){
    //loops through each column 
    for (int c = 0; c < COLS; c++){
        //loop through each row in a given column
        for (int r = 0; r < ROWS; r++){
            board[c][r] = EMP; // initialize all cells to be empty
        }
    }
}

void displayBoard(){
    cout << endl << "Connect 4 Board" << endl;
    //Display the board one row at a time
    for (int r = 0; r < ROWS; r++){
        //for each row display all of the columns
        for (int c = 0; c < COLS; c++){
            cout << board[c][r] << " ";
        }
        cout << endl; //After each row output a newline character
    }
    for (int c = 0; c < COLS; c++){
        cout << c << " ";
    }
    cout << endl << endl;
}

bool addPiece(int c, bool isPlayer1){
    //check if column c is full
    if (board[c][0] != EMP){
        return false;
    }
    else {
        //add a piece to the lowest unoccupied row in column c
        for (int r = (ROWS-1); r >= 0; r--){
            if (board[c][r] == EMP){
                //add piece
                if (isPlayer1){
                    board[c][r];
                }
            }
        }
    }

}