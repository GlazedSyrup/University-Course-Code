//Create a Connect 4 Game
#include <iostream>
#include <string>

using namespace std;

// Code provided by Professor

//Global constants for the game pieces
const char EMP = '-';
const char P1 = 'X';
const char P2 = 'O';

//global variables/constants for the game board
const int COLS = 7;
const int ROWS = 6;
char board[COLS][ROWS]; //2D array of 7x6 connect 4 board

//Initialize the board to be empty
void initializeBoard();

//Display the board
void displayBoard();

//Get column for current move
int getColumn(bool isPlayer1);

//Add one piece to the Board
bool addPiece(int c, bool isPlayer1);

//Check if a given player has won
bool isWinner(bool isPlayer1, int lastCol);

int main() {
    //Initialize game
    //TO DO: Add code to randomize first player
    int totalMoves = 0; //number of moves by both players
    const int MAX_MOVES = COLS * ROWS; //total cells on the board
    bool playerOne = true; //boolean to keep track of current player
    bool gameWon = false; //boolean to keep track if game won
    int column = -1;

    initializeBoard();
    displayBoard();

    //Game play loop
    //loop until game is won or the board is full
    while ((!gameWon) && (totalMoves < MAX_MOVES)) {
        bool validMove = false;
        while (!validMove) {
            column = getColumn(playerOne);
            validMove = addPiece(column, playerOne);
            if (!validMove) {
                cout << "Invalid move. Try again." << endl;
            }
        }

        totalMoves++;
        displayBoard();

        //Check if game is won
        gameWon = isWinner(playerOne, column);
        if (gameWon) {
            cout << "CONGRATULATIONS Player " << (playerOne ? "1" : "2") << ". You've won Connect 4!!!!" << endl;
        }
        else if (totalMoves == MAX_MOVES) {
            cout << "Game over! No moves remaining." << endl;
        }
        else {
            playerOne = !playerOne; //switch player
        }
    }



    return 0;
}

void initializeBoard() {
    //Loops through each column
    for (int c = 0; c < COLS; c++) {
        //Loop through each row in a given column
        for (int r = 0; r < ROWS; r++){
            board[c][r] = EMP; //initialize all cells to empty
        }
    }
}

void displayBoard() {
    cout << endl << "Connect 4 Board:" << endl;
    //Display the board one row at a time
    for (int r = 0; r < ROWS; r++) {
        //For each row display all of the columns
        for (int c = 0; c < COLS; c++) {
            cout << board[c][r] << " ";
        }
        cout << endl; //After each row output a newline character
    }
    //Now display the column numbers below the board
    for (int c = 0; c < COLS; c++) {
        cout << c << " ";
    }
    cout << endl << endl;
}

int getColumn(bool isPlayer1) {
    int col = 0;

    /*cout << "Player ";
    if (isPlayer1) {
    cout << "1";
    } else {
    cout << "2";
    }
    cout << " - Select a column [0," << (COLS-1) <<  "] to play: ";*/
    //The below is a short form of above output
    cout << "Player " << (isPlayer1 ? "1" : "2") << " - Select a column [0," << (COLS-1) <<  "] to play: ";
    cin >> col;
    return col;
}

bool addPiece(int c, bool isPlayer1) {
    if ((c < 0) || (c >= COLS)) { //check if column is valid for board
        return false;
    }
    //check if column c has space
    if (board[c][0] == EMP) {
        //add a piece to the lowest unoccupied row in column c
        for (int r = (ROWS-1); r >= 0; r--) {
            if (board[c][r] == EMP) {
                //add piece
                if (isPlayer1) {
                    board[c][r] = P1;
                }
                else {
                    board[c][r] = P2;
                }
                return true;
            }
        }
    }
  //if column is full return false
  return false;
}


//                                            I have programmed the code below 
//      //\\                                                //\\                                            //\\
//      |  |            Coded by Thomas Chiarello           |  |         CSCI 1060U - CRN 43914             |  |
//      |  |                                                 \/                                             |  |
//      |  |      The following function checks 4 possible win conditions through the use of for loops.     |  |
//      |  |       The function checks the diagonals, the horizontal, and below the most recent tile.       |  |
//      |  |     This can be otherwise explained as in all branching directions of the most recent tile.    |  |
//      \\//\______________________________________________/\\//\__________________________________________/\\//
//   

bool isWinner(bool isPlayer1, int lastCol) {
//Initialization
//tempRow and tempCol have been relocated, because if there is a win situation 
//before checking diagonals, then there is no need to initialize those variables
    int counter = 0;
    int row;
    char currTile;
    char enemyTile;

//Identifies which tile(O or X) is used by current player
    if (isPlayer1) {
        currTile = P1;
        enemyTile = P2;
    }
    else {
        currTile = P2;
        enemyTile = P1;
    }
    
    //Determines which row of the board is the row of the tile
    for(int i = 0; i < 6; i++){
        if(board[lastCol][i] == currTile){
            row = i;
            break;
        }
    }
    
    //Checking Up is unnecesary as the most recent piece is the top most piece
    //First Check; DOWN
    cout << "First Check; DOWN" << endl;
    for(int i = row; i < row+4; i++){
        if(board[lastCol][i] == EMP){
            cout << "First If; (" << lastCol << ", " << i << ")" << endl;
            break;
        }
        else if(board[lastCol][i] == enemyTile){
            cout << "Second If; (" << lastCol << ", " << i << ")" << endl;
            break;
        }
        else if(board[lastCol][i] == currTile){
            cout << "Third If; (" << lastCol << ", " << i << ")" << endl;
            counter +=1;
        }
    }
    if(counter == 4){
        return true;
    }
    else{
        counter = 0;
    }

    //Each of the following checks determine if there are 3 tiles to the left and right of the initial tile

    //Second Check; First Half; LEFT
    cout << "Second Check; First Half; LEFT" << endl;
    for(int i = lastCol; i > lastCol-4; i--){
        //include an out of bounds check: i > 5, 1<0
        if(board[i][row] == EMP){
            cout << "First If; (" << i << ", " << row << ")" << endl;
            break;
        }
        else if(board[i][row] == enemyTile){
            cout << "Second If; (" << i << ", " << row << ")" << endl;
            break;
        }
        else if(board[i][row] == currTile){
            cout << "Third If; (" << i << ", " << row << ")" << endl;
            counter +=1;
        }
    }
    if(counter == 4){
        return true;
    }
    else{
        counter -= 1;
    }
    
    //Second Check; Second Half; RIGHT
    cout << "Second Check; Second Half; RIGHT" << endl;
    for(int i = lastCol; i < lastCol+4; i++){
        //include an out of bounds check: i > 5, 1<0
        if(board[i][row] == EMP){
            cout << "First If; (" << i << ", " << row << ")" << endl;
            break;
        }
        else if(board[i][row] == enemyTile){
            cout << "Second If; (" << i << ", " << row << ")" << endl;
            break;
        }
        else if(board[i][row] == currTile){
            cout << "Third If; (" << i << ", " << row << ")" << endl;
            counter +=1;
        }
    }
    if(counter >= 4){
        return true;
    }
    else{
        counter = 0;
    }


    //Third Check; First Quarter; DIAGONAL - POSITIVE SLOPE - RIGHT(aka last piece to top right)
    cout << "Third Check; First Quarter; DIAGONAL - POSITIVE SLOPE - RIGHT" << endl;
    int tempRow = row;
    //Reason for reuse of the variable name tempCol, is because outside of this loop I will still
    //need a variable tempCol that is not limited to this loop. This applies for tempRow
    for(int tempCol = lastCol; tempCol < lastCol+4; tempCol++){
        //include an out of bounds check: i > 5, 1<0
        if(board[tempCol][tempRow] == EMP){
            cout << "First If; (" << tempCol << ", " << tempRow << ")" << endl;
            break;
        }
        else if(board[tempCol][tempRow] == enemyTile){
            cout << "Second If; (" << tempCol << ", " << tempRow << ")" << endl;
            break;
        }
        else if(board[tempCol][tempRow] == currTile){
            cout << "Third If; (" << tempCol << ", " << tempRow << ")" << endl;
            counter +=1;
        }

        tempRow -= 1;
    }
    if(counter >= 4){
        return true;
    }
    else{
        counter -= 1;
    } 

    //Third Check; Second Quarter; DIAGONAL - POSITIVE SLOPE - LEFT
    cout << "Third Check; Second Quarter; DIAGONAL - POSITIVE SLOPE - LEFT" << endl;
    int tempCol = lastCol;
    for(int tempRow = row; tempRow < row+4; tempRow++){
        //include an out of bounds check: i > 5, 1<0
        if(board[tempCol][tempRow] == EMP){
            cout << "First If; (" << tempCol << ", " << tempRow << ")" << endl;
            break;
        }
        else if(board[tempCol][tempRow] == enemyTile){
            cout << "Second If; (" << tempCol << ", " << tempRow << ")" << endl;
            break;
        }
        else if(board[tempCol][tempRow] == currTile){
            cout << "Third If; (" << tempCol << ", " << tempRow << ")" << endl;
            counter +=1;
        }

        tempCol -= 1;
    }
    if(counter >= 4){
        return true;
    }
    else{
        counter = 0;
    } 
    
    //Third Check; Third Quarter; DIAGONAL - NEGATIVE SLOPE - RIGHT
    cout << "Third Check; Fourth Quarter; DIAGONAL - NEGATIVE SLOPE - RIGHT" << endl;
    tempCol = lastCol;
    for(int tempRow = row; tempRow < row+4; tempRow++){
        //include an out of bounds check: i > 5, 1<0
        if(board[tempCol][tempRow] == EMP){
            cout << "First If; (" << tempCol << ", " << tempRow << ")" << endl;
            break;
        }
        else if(board[tempCol][tempRow] == enemyTile){
            cout << "Second If; (" << tempCol << ", " << tempRow << ")" << endl;
            break;
        }
        else if(board[tempCol][tempRow] == currTile){
            cout << "Third If; (" << tempCol << ", " << tempRow << ")" << endl;
            counter +=1;
        }

        tempCol += 1;
    }
    if(counter >= 4){
        return true;
    }
    else{
        counter -= 1;
    } 

    //Third Check; Fourth Quarter; DIAGONAL - NEGATIVE SLOPE - LEFT
    cout << "Third Check; Fourth Quarter; DIAGONAL - NEGATIVE SLOPE - LEFT" << endl;
    tempCol = lastCol;
    for(int tempRow = row; tempRow > row-4; tempRow--){
        //include an out of bounds check: i > 5, 1<0
        if(board[tempCol][tempRow] == EMP){
            cout << "First If; (" << tempCol << ", " << tempRow << ")" << endl;
            break;
        }
        else if(board[tempCol][tempRow] == enemyTile){
            cout << "Second If; (" << tempCol << ", " << tempRow << ")" << endl;
            break;
        }
        else if(board[tempCol][tempRow] == currTile){
            cout << "Third If; (" << tempCol << ", " << tempRow << ")" << endl;
            counter +=1;
        }

        tempCol -= 1;
    }
    if(counter >= 4){
        return true;
    }
    else{
        counter = 0;
    } 

    return false;
}