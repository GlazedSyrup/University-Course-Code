//ASCII Value of CSCI 1060U is  67 83 67 73 32 49 48 54 48 85
#include <iostream>
#include <string>

using namespace std;


string ASCII_Converter(string sentence){
    string converted;
    for(int i=0; i < sentence.length(); i++){
        converted = converted + " " + to_string(int(sentence[i]));
}
    return converted;
}

int main() {
    //The Initialization
    string sentence = "CSCI 1060U";

    //The Output
    cout << "ASCII Value of " << sentence << " is " << ASCII_Converter(sentence) << endl;
    return 0;
}