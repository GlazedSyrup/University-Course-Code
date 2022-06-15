//TIC-TAC-TOE [game]
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int SIZE = 3;

//Code provided by proffesor

void displayBoard(string b[][SIZE]);
bool userFirst();
bool currentPlayerWon(string b[][SIZE], string symbol);
void generateComputerMove(string b[][SIZE], int &row, int &col);

int main(){
    //construct board
    string board[SIZE][SIZE];
    
    int position_id = 1;
    for (int i=0; i< SIZE; i++){
        for (int j=0; j < SIZE; j++){
            board[i][j] = to_string(position_id);
            position_id++;
        }
    }

    //Initial game output
    cout << "Welcome to Tic-Tac-Toe" << endl;

    bool userTurn = userFirst();
    if (userTurn == true){
        cout << "Player goes first!" << endl;
    }
    else{
        cout << "Computer goes first!" << endl;
    }

    //Loop for turn taking in game
    int positionsRemaining = SIZE * SIZE;
    bool userWon = false;
    bool computerWon = false;
    while ((positionsRemaining > 0) && (!userWon) && (!computerWon)){
        displayBoard(board);

        //User's turn
        if (userTurn){
            bool validMove = false;
            while (!validMove){
                int position_id;
                cout << "Enter a position: ";
                cin >> position_id;
                if ((position_id <= (SIZE*SIZE)) && (position_id > 0)){
                    int row = (position_id-1)/SIZE;
                    int col = (position_id-1)%SIZE;
                    //cout << "row = " << row << " col = " << col << endl;
                    if ((board[row][col] != "X") && (board[row][col] != "O")){
                        board[row][col] = "X";
                        validMove = true;
                    }
                    else{
                        cout << "Position already used. Try again." << endl;
                    }

                }
                else{
                    cout << "Position invalid. Try again." << endl;
                }
            }
            positionsRemaining--;
            userWon = currentPlayerWon(board, "X");
            userTurn = false;
        }

        //Computer's turn
        else{
            //The row and col are both passed as call-by-reference
            int row, col;
            generateComputerMove(board, row, col);
            board[row][col] = "O";

            positionsRemaining--;
            computerWon = currentPlayerWon(board, "O");
            userTurn = true;
        }
    }

    //Display game result
    displayBoard(board);
    if (userWon){
        cout << "Congratulations! You have won!" << endl;
        }
    else if (computerWon){
        cout << "The computer has won. Try again." << endl;
    }
    else{
        cout << "Out of moves. Try again." << endl;
    }
    return 0;
}

void displayBoard(string b[][SIZE]){
    cout << "Tic-tac-toe board:" << endl << endl;
    for (int i=0; i< SIZE; i++){
        for (int j=0; j < SIZE; j++){
            cout << b[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

bool userFirst(){
    //set seed for random number generation
    srand(time(NULL));
    //generate a random number
    //0 for computer
    //1 for user
    int num = rand()%2;
    if (num == 0){
        return false;
    }
    return true;
}

//Return true if player/computer with symbol (X or O) has won
bool currentPlayerWon(string b[][SIZE], string symbol){
//Horizontal case
//Loop through each row
    for (int i=0; i < SIZE; i++){
        bool rowWinDetected = true;
        //Check all positions in row and see if they are the same symbol
        for (int j = 0; j < SIZE; j++){
            if (b[i][j] != symbol){
                rowWinDetected = false;
            }
        }
        if (rowWinDetected){
            return true;
        }
    }

    //Vertical case
    //Loop through each column
    for (int i=0; i < SIZE; i++){
        bool colWinDetected = true;
        //Check all positions in column and see if they are the same symbol
        for (int j = 0; j < SIZE; j++){
            if (b[j][i] != symbol){
                colWinDetected = false;
            }
        }
        if (colWinDetected){
            return true;
        }
    }

    //Diagonal case #1
    bool diagonal1WinDetected = true;
    for (int i=0; i < SIZE; i++){
        if (b[i][i] != symbol){
            diagonal1WinDetected = false;
        }
    }
    if (diagonal1WinDetected){
        return true;
    }

    //Diagonal case #2
    bool diagonal2WinDetected = true;
    for (int i=0; i < SIZE; i++){
        if (b[(SIZE-1)-i][i] != symbol){
            diagonal2WinDetected = false;
        }
    }
    if (diagonal2WinDetected){
        return true;
    }
    //otherwise win not diagonal2WinDetected
    return false;
}

//Code I have programmed
//              //\\                                        //\\                                        //\\
//              |  |        Coded by Thomas Chiarello       |  |         CSCI 1060U - CRN 43914         |  |
//              |  |                                         \/                                         |  |
//              |  |         The following code gives the AI, or CPU player, a set of conditions        |  |
//              |  |        that it must follow. By following the conditions set the AI determines      |  |
//              |  |                     what choice to make in different situations                    |  |
//              \\//\______________________________________/\\//\______________________________________/\\//
//   


void generateComputerMove(string b[][SIZE], int &row, int &col){
    int turn = 0;
    for (int i = 0; i < SIZE; i++){
        for (int ii = 0; ii < SIZE; ii++){
            if(b[i][ii] == "X"){
                turn++;
                cout << "turn" << turn << endl;
            }
        }
    }

    if(turn == 0){
        //this runs if the computer is player 1 //aka first round
        row = 0;
        col = 0;
    }

    else if(turn == 1){
        //this runs if the computer is player 2
        if(b[0][0] == "1"){
            if(b[0][2] == "3"){
                if(b[2][0] == "7"){
                    if(b[2][2] == "9"){
                        //If all are true, all corners are available
                        row = 0;
                        col = 0;
                    }
                    else{
                        //A corner is taken
                        row = 1;
                        col = 1;
                    }
                }
                else{
                    //A corner is taken
                    row = 1;
                    col = 1;
                }
            }
            else{
                //A corner is taken
                row = 1;
                col = 1;
            }
        }
        else{
            //A corner is taken
            row = 1;
            col = 1;
        }
    }

    else{
        //This runs every other round
        //Initialize most of the variables
        int Xcount = 0;
        int Ocount = 0;
        int emptyCellRow;
        int emptyCellCol;

    //Check for 8 win case
    //This checks to see if the ai can make a winning move,
    //if so the ai will make that move
        //Check rows
        for (int i=0; i < SIZE; i++){
            Xcount = 0;
            Ocount = 0;
            for (int ii = 0; ii < SIZE; ii++){
                if(b[i][ii] == "X"){
                    Xcount++;
                }
                else if(b[i][ii] == "O"){
                    Ocount++;
                }
                else{
                    emptyCellRow = i;
                    emptyCellCol = ii; 
                }
            }
            if((Xcount == 0) && (Ocount == 2)){
                row = emptyCellRow;
                col = emptyCellCol;
            }
        }
        //Check columns
        for (int i=0; i < SIZE; i++){
            Xcount = 0;
            Ocount = 0;
            for (int ii = 0; ii < SIZE; ii++){
                if(b[ii][i] == "X"){
                    Xcount++;
                }
                else if(b[ii][i] == "O"){
                    Ocount++;
                }
                else{
                    emptyCellRow = ii;
                    emptyCellCol = i; 
                }
            }
            if((Xcount == 0) && (Ocount == 2)){
                row = emptyCellRow;
                col = emptyCellCol;
            }
        }
        //Check left to right diagonal
            Xcount = 0;
            Ocount = 0;
        for (int i=0; i < SIZE; i++){
            if(b[i][i] == "X"){
                Xcount++;
            }
            else if(b[i][i] == "O"){
                Ocount++;
            }
            else{
                emptyCellRow = i;
                emptyCellCol = i; 
            }
            if((Xcount == 0) && (Ocount == 2)){
                row = emptyCellRow;
                col = emptyCellCol;
            }
        }
        //Check right to left diagonal
            Xcount = 0;
            Ocount = 0;
            int ii = 3;
        for (int i=0; i < SIZE; i++){
            ii--;
            
            if(b[i][ii] == "X"){
                Xcount++;
            }
            else if(b[i][ii] == "O"){
                Ocount++;
            }
            else{
                emptyCellRow = i;
                emptyCellCol = ii; 
            }
            if((Xcount == 0) && (Ocount == 2)){
                row = emptyCellRow;
                col = emptyCellCol;
            }
        }


    //Check for 8 enemy win cases
    //This checks to see if the player/enemy can make
    //a winning move, if so the ai blocks that spot
        //Check rows
        for (int i=0; i < SIZE; i++){
            Xcount = 0;
            Ocount = 0;
            for (int ii = 0; ii < SIZE; ii++){
                if(b[i][ii] == "X"){
                    Xcount++;
                }
                else if(b[i][ii] == "O"){
                    Ocount++;
                }
                else{
                    emptyCellRow = i;
                    emptyCellCol = ii; 
                }
            }
            if((Xcount == 2) && (Ocount == 0)){
                row = emptyCellRow;
                col = emptyCellCol;
            }
        }
        //Check columns
        for (int i=0; i < SIZE; i++){
            Xcount = 0;
            Ocount = 0;
            for (int ii = 0; ii < SIZE; ii++){
                if(b[ii][i] == "X"){
                    Xcount++;
                }
                else if(b[ii][i] == "O"){
                    Ocount++;
                }
                else{
                    emptyCellRow = ii;
                    emptyCellCol = i; 
                }
            }
            if((Xcount == 2) && (Ocount == 0)){
                row = emptyCellRow;
                col = emptyCellCol;
            }
        }
        //Check left to right diagonal
            Xcount = 0;
            Ocount = 0;
        for (int i=0; i < SIZE; i++){
            if(b[i][i] == "X"){
                Xcount++;
            }
            else if(b[i][i] == "O"){
                Ocount++;
            }
            else{
                emptyCellRow = i;
                emptyCellCol = i; 
            }
            if((Xcount == 2) && (Ocount == 0)){
                row = emptyCellRow;
                col = emptyCellCol;
            }
        }
        //Check right to left diagonal
            Xcount = 0;
            Ocount = 0;
            ii = 3;
        for (int i=0; i < SIZE; i++){
            ii--;
            
            if(b[i][ii] == "X"){
                Xcount++;
            }
            else if(b[i][ii] == "O"){
                Ocount++;
            }
            else{
                emptyCellRow = i;
                emptyCellCol = ii; 
            }
            if((Xcount == 2) && (Ocount == 0)){
                row = emptyCellRow;
                col = emptyCellCol;
            }
        }

    }

}


