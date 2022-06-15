#include <iostream>
#include <ctime>

using namespace std;

char chart[6][6];

int main() {

    for (int i = 0; i < 6; i++) {
        for (int ii = 0; ii < 6; ii++){
            if(i%2 == 0){
                chart[i][ii] = 'X'; 
            }
            else{
                chart[i][ii] = 'Y'; 
            }
        }
    }

    for (int i = 0; i < 6; i++) {
        for (int ii = 0; ii < 6; ii++){
            cout << chart[i][ii] << " "; 
            
        }
        cout << endl;
    }


    return 0;
}