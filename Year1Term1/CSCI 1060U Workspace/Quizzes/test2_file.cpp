#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

int main() {
    string filename;
    const int SIZE = 5;
    string data[SIZE];

    cout << "Enter output filename: ";
    cin >> filename;
        
    ofstream myOutput(filename);
    

    cout << "Enter " << SIZE
        << " words to store in a file in reverse order: ";
    for (int i=0; i < SIZE; i++) {
        cin >> data[i];
    }

    for (int i = SIZE-1; i >= 0; i--) {
        myOutput << data[i] << endl;
    }

    myOutput.close();

    //The code never outputs an error when run. Code is bug free as far as i can tell

    return 0;
}