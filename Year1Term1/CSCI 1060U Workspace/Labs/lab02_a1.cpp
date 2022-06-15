#include <iostream>
#include <string>
#include <ctime>
//#include <stdclib>

using namespace std;

int main() {
    //The Initialization
    int round_count = 0;
    string play_again;
    bool win = false;
    srand(time(NULL));
    int loc_index_CPU = rand()%10;
    int guess;
    int loc_board[] = {0,0,0,0,0,0,0,0,0,0};
    string display_board[] = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};

    cout << "----------------------------------\nWelcome to Battleship Lite!\n----------------------------------" << endl;

    while(true){
        round_count +=1;

        cout << "Round " << round_count << endl;
//---------------------------------- Reset Variables ----------------------------------

        win = false;
        loc_index_CPU = rand()%10;
        int loc_board[] = {0,0,0,0,0,0,0,0,0,0};
        string display_board[] = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};

//---------------------------------- Round Start ----------------------------------

        for(int i = 0; i < 5; i++){
            cout << "Board:" << endl;
            cout << "0 1 2 3 4 5 6 7 8 9 " << endl;
            for(int ii = 0; ii <= 9; ii++){
                cout << display_board[ii] << " ";
            }
            cout << endl;
            cout << "Guess a location of the battleship: " << endl;
            cin >> guess;
            
//---------------------------------- Hit or Miss ----------------------------------

            if (loc_index_CPU != guess){
                cout << "Miss!" << endl;
                display_board[guess] = "X";
            }

            else{
                win = true;
                cout << "Hit!" << endl;
                display_board[guess] = "H";
                break;
            }

        }

//---------------------------------- Round End ----------------------------------
        if (win){
            cout << "Board:" << endl;
            cout << "0 1 2 3 4 5 6 7 8 9 " << endl;
            for(int ii = 0; ii <= 9; ii++){
                cout << display_board[ii] << " ";
            }
            cout << "PLAY AGAIN! (Y/N)" << endl;
            cin >> play_again;
            
            if (play_again == "N" || play_again == "n"){
                break;
            }

            else{

            }
        }
        
        else{
            cout << "GAME OVER!" << endl;
            cout << "Board:" << endl;
            cout << "0 1 2 3 4 5 6 7 8 9 " << endl;
            display_board[loc_index_CPU] = "O";
            for(int ii = 0; ii <= 9; ii++){
                cout << display_board[ii] << " ";
            }
            cout << endl;
            break;
        }

    }
    
    
    
    return 0;
}


