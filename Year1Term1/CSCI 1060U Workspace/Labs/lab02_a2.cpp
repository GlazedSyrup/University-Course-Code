#include <iostream>
#include <string>
#include <ctime>
//#include <stdclib>

using namespace std;

int main() {

//The Initialization
    string play_again;
    srand(time(NULL));
//PLAYER
    bool player_win = false;
    int loc_player_index;
    int loc_player_board[] = {0,0,0,0,0,0,0,0,0,0};
    string display_player_board[] = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
    int player_guess;
//CPU
    bool CPU_win = false;
    int loc_CPU_index = rand()%10;
    int loc_CPU_board[] = {0,0,0,0,0,0,0,0,0,0};
    string display_CPU_board[] = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
    int CPU_guess;


    cout << "----------------------------------\nWelcome to Battleship Lite!\n----------------------------------" << endl;

    while(player_win == false){

//---------------------------------- Reset Variables ----------------------------------

//PLAYER
    bool player_win = false;
    int loc_player_index;
    int loc_player_board[] = {0,0,0,0,0,0,0,0,0,0};
    string display_player_board[] = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
    int player_guess;
//CPU
    bool CPU_win = false;
    int loc_CPU_index = rand()%10;
    int loc_CPU_board[] = {0,0,0,0,0,0,0,0,0,0};
    string display_CPU_board[] = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
    int CPU_guess;

//----------------------------------  Chose location ----------------------------------

        cout << "0 1 2 3 4 5 6 7 8 9 " << endl;
        cout << "- - - - - - - - - - " << endl;
        cout << "Choose a location for your battleship: ";
        cin >> loc_player_index;
        cout << endl;


        display_player_board[loc_player_index] = "B";
        
        
        cout << "\nYour Board:" << endl;
        cout << "0 1 2 3 4 5 6 7 8 9 " << endl;
        for(int i = 0; i <= 9; i++){
            cout << display_player_board[i] << " ";
        }
        cout << endl;

//---------------------------------- Game Start ----------------------------------
        cout << "\n\nGAME START\n\n" << endl;

//---------------------------------- Player Attacks ----------------------------------

        while (true){
            cout << "CPUs Board:" << endl;
            cout << "0 1 2 3 4 5 6 7 8 9 " << endl;
            for(int i = 0; i <= 9; i++){
                cout << display_CPU_board[i] << " ";
            }
            cout << endl;

            cout << "\nYour Board:" << endl;
            cout << "0 1 2 3 4 5 6 7 8 9 " << endl;
            for(int i = 0; i <= 9; i++){
                cout << display_player_board[i] << " ";
            }
            cout << endl;
            
            
            cout << "\nGuess the location of the battleship: ";
            cin >> player_guess;
            cout << endl;

//---------------------------------- Player Hit or Miss ----------------------------------

            if (loc_CPU_index != player_guess){
                cout << "Miss!\n" << endl;
                display_CPU_board[player_guess] = "X";
            }

            else{
                player_win = true;
                cout << "Hit!\n" << endl;
                display_CPU_board[player_guess] = "H";
                break;
            }
        
//---------------------------------- CPU Attacks ----------------------------------
        
            CPU_guess = rand()%10;
            cout << "\nCPUs guess: " << CPU_guess << "\n" << endl;

//---------------------------------- CPU Hit or Miss ----------------------------------

            if (loc_player_index != CPU_guess){
                cout << "Miss!" << endl;
                display_player_board[CPU_guess] = "X";
            }

            else{
                CPU_win = true;
                cout << "Hit!" << endl;
                display_player_board[CPU_guess] = "H";
                break;
            }




        }
//---------------------------------- Round End ----------------------------------
        
        
        if (player_win || CPU_win){
            if (player_win){
                cout << "YOU WIN!\n" << endl;
            }
            else{
                cout << "YOU LOSE!\n" << endl;
            }


        //CPU
            cout << "Enemy Board:" << endl;
            cout << "0 1 2 3 4 5 6 7 8 9 " << endl;
            for(int i = 0; i <= 9; i++){
                cout << display_CPU_board[i] << " ";
            }
            cout << "\n" << endl;

        //PLAYER
            cout << "Your Board:" << endl;
            cout << "0 1 2 3 4 5 6 7 8 9 " << endl;
            for(int i = 0; i <= 9; i++){
                cout << display_player_board[i] << " ";
            }
            cout << "\n" << endl;
            
            
            cout << "PLAY AGAIN? (Y/N)" << endl;
            cin >> play_again;
            

            if (play_again == "N" || play_again == "n"){
                goto end;
            }

            else{
//---------------------------------- Reset Variables ----------------------------------
            //PLAYER
                bool player_win = false;
                int loc_player_index;
                int loc_player_board[] = {0,0,0,0,0,0,0,0,0,0};
                string display_player_board[] = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
                int player_guess;
            //CPU
                bool CPU_win = false;
                int loc_CPU_index = rand()%10;
                int loc_CPU_board[] = {0,0,0,0,0,0,0,0,0,0};
                string display_CPU_board[] = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
                int CPU_guess;

                goto restart;
            }
        }
    
    restart: ;

    }

    end: ;

}