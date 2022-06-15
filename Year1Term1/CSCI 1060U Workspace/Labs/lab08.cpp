//TIC-TAC-TOE [game]
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <cstdlib>

using namespace std;


typedef string* ArrayPtr;

void displayBoard(ArrayPtr b[]);
bool userFirst();
bool currentPlayerWon(ArrayPtr b[], string symbol);
void generateComputerMove(ArrayPtr b[], int &row, int &col);

int main(){
    //construct board
    ArrayPtr *board = new ArrayPtr[3];
    for(int i = 0; i < 3; i++){
        board[i] = new string[3];
    }
    int position_id = 1;
        // initialize array values and display
    for(int i = 0; i < 3; i++){
        for(int ii = 0; ii < 3; ii++){
            board[i][ii] = to_string(position_id);
            cout << board[i][ii] << " ";
            position_id++;
        }
        cout << endl;
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
    int positionsRemaining = 9;
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
                if ((position_id <= (9)) && (position_id > 0)){
                    int row = (position_id-1)/3;
                    int col = (position_id-1)%3;
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

//Delete the array
    for(int i = 0; i < 3; i++){
        delete [] board[i];
    }
    delete [] board;
    return 0;
}

void displayBoard(ArrayPtr b[]){
    cout << "Tic-tac-toe board:" << endl << endl;
    for (int i=0; i< 3; i++){
        for (int j=0; j < 3; j++){
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
bool currentPlayerWon(ArrayPtr b[], string symbol){
//Horizontal case
//Loop through each row
    for (int i=0; i < 3; i++){
        bool rowWinDetected = true;
        //Check all positions in row and see if they are the same symbol
        for (int j = 0; j < 3; j++){
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
    for (int i=0; i < 3; i++){
        bool colWinDetected = true;
        //Check all positions in column and see if they are the same symbol
        for (int j = 0; j < 3; j++){
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
    for (int i=0; i < 3; i++){
        if (b[i][i] != symbol){
            diagonal1WinDetected = false;
        }
    }
    if (diagonal1WinDetected){
        return true;
    }

    //Diagonal case #2
    bool diagonal2WinDetected = true;
    for (int i=0; i < 3; i++){
        if (b[2-i][i] != symbol){
            diagonal2WinDetected = false;
        }
    }
    if (diagonal2WinDetected){
        return true;
    }
    //otherwise win not diagonal2WinDetected
    return false;
}

void generateComputerMove(ArrayPtr b[], int &row, int &col){
    int turn = 0;
    for (int i = 0; i < 3; i++){
        for (int ii = 0; ii < 3; ii++){
            if(b[i][ii] == "X"){
                turn++;
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
        for (int i=0; i < 3; i++){
            Xcount = 0;
            Ocount = 0;
            for (int ii = 0; ii < 3; ii++){
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
        for (int i=0; i < 3; i++){
            Xcount = 0;
            Ocount = 0;
            for (int ii = 0; ii < 3; ii++){
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
        for (int i=0; i < 3; i++){
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
        for (int i=0; i < 3; i++){
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
        for (int i=0; i < 3; i++){
            Xcount = 0;
            Ocount = 0;
            for (int ii = 0; ii < 3; ii++){
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
        for (int i=0; i < 3; i++){
            Xcount = 0;
            Ocount = 0;
            for (int ii = 0; ii < 3; ii++){
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
        for (int i=0; i < 3; i++){
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
        for (int i=0; i < 3; i++){
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


