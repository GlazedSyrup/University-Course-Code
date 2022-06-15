#include <string>   //library for strings
#include <iostream>  //library for terminal input and output
#include <fstream>   //library for file input and output

using namespace std;


void writeString(string var){
    
    ofstream myOutput("user.txt");
    myOutput << var << endl;
    myOutput.close();

    cout << "String " << var << "written to file user.txt" << endl;

}


int main() {

    string content;
    cout << "Enter a string:" << endl;
    cin >> content;
    writeString(content);

}