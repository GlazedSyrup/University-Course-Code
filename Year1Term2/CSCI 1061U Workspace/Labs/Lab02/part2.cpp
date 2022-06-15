// part2++-.cpp
// by Thomas Chiarello
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

//The following function takes in a string and a shift value then encrypts 
//the string using the cipher encryption method, which is then returned.
std::string encrypt(std::string text, int shift){
    //Initialize variables
    char alpha[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    char character;
    int index;

    //Main method //loops each character in the string and encrypts each character
    for(int i = 0; i < text.length(); i++){
        character = text[i];
        //toupper() to ensure the character cannot be a lowercase character
        character = toupper(character);
        index = 0;
        //this loop is used to determine the index of the current character within the alpha list, which is useful later
        for(int i = 0; i < 26; i++){
            if(character == ' ' || character == '1' || character == '2' || character == '3' || character == '4' || character == '5' || character == '6' || character == '7' || character == '8' || character == '9'){
                index = 10101;
                break;
            }
            else if(alpha[i] == character){
                break;
            }

            index +=1;
        }

        //this index value could have been any number, 10101 is just chosen randomlyto use as a key or code.
        //if the index is not 10101 then the code will encrypt the character
        if(index != 10101){
            index = index + shift;
            if(index>25){
                index = index-26;
            }
            if(index<0){
                index = index+26;
            }

            character = alpha[index];
            text[i] = character;
        }
    }

    return text;
}

int main(int argc, char** argv){
    //Initialize variables
    std::string line;
    std::string encryptedText;
    std::vector<std::string> text;
    std::ifstream f(argv[3]);

//This reads the mentioned file and stores it all in the text variable
    if (f.is_open()) {
        while (getline(f, line)){
            text.push_back(line);
        }
        f.close();
    }
        
    std::string flag(argv[1], 2);
    std::ofstream of(argv[4]);

//The following encrypts/decrypts the string and outputs the string to a file
    if (of.is_open()) {
        if(flag == "-e"){
            for(int i = 0; i < text.size(); i++){
                //*argv[2]is a character of a number (char *argv[2] = 3) thus to convert
                //the character to an integer i subtract the character 0
                encryptedText = encrypt(text[i], (*argv[2] - '0'));
                of << encryptedText << "\n";
            }
        }
        if(flag == "-d"){
            for(int i = 0; i < text.size(); i++){
                encryptedText = encrypt(text[i], -(*argv[2] - '0'));
                of << encryptedText << "\n";
            }
        }

        of.close();
    }

    return 0;
}
