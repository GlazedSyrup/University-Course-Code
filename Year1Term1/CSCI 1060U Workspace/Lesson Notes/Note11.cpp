#include <string>   //library for strings
#include <iostream>  //library for terminal input and output
#include <fstream>   //library for file input and output

using namespace std;

int main() {
    string filename;
    const int SIZE = 5;
    string data[SIZE];  //our first array
                        //an array of SIZE strings

    //FILE OUTPUt
    cout << "enter filename: ";
    cin >> filename;

    //open the file
    //ofstream myOutput; // similar to cout but for a file
    //myOutput.open(filename);
    //above two lines same as below
    ofstream myOutput(filename);

    //input words to store in file
    cout << "Enter " << SIZE << "words to store in a file in reverse order: ";
    for (int i = 0; i < SIZE; i++){
        cin >> data[i];
    }

    //store words in file in reverse
    for (int i = SIZE-1; i >=0; i--){
        myOutput << data[i] << endl;
    }

    //close the file
    myOutput.close();

    //FILE INPUT
    cout << "Reading in " << filename << "..." << endl;

    ifstream myInput(filename);

    while(!myInput.eof()){
        string line;
        myInput >> line;
        cout << line << endl;
    }

    myInput.close();

}