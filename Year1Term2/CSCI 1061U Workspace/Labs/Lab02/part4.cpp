// part4.cpp
// by Thomas Chiarello
#include <iostream>
#include <fstream>
#include <string> 
#include <vector>

//The following function takes in a string and a shift value then encrypts 
//the string using the cipher encryption method, which is then returned.
std::string encrypt(std::string text, int charShift, int intShift){
    //Initialize variables
    char alphaU[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    char alphaL[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char numb[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char character;
    int index;
    bool isNumber = false;
    bool isLower = false;

    //Main method //loops each character in the string and encrypts each character
    for(int i = 0; i < text.length(); i++){
        character = text[i];
        index = 0;
        isNumber = false;
        isLower = false;
        //this loop is used to determine the index of the current character within the alpha list, which is useful later
        for(int i = 0; i < 26; i++){
            if(character == ' '){
                index = 10101;
                break;
            }
            else if(alphaU[i] == character){
                break;
            }
            else if(alphaL[i] == character){
                isLower = true;
                break;
            }
            else if(numb[i] == character && i < 10){
                isNumber = true;
                break;
            }
            index +=1;
        }

        //this index value could have been any number, 10101 is just chosen randomlyto use as a key or code.
        //if the index is not 10101 then the code will encrypt the character
        if(index != 10101){
            if(!isNumber){
                index = index + charShift;
                if(index>25){
                    index = index-26;
                }
                if(index<0){
                    index = index+26;
                }

                if(isLower){
                    character = alphaL[index];
                }
                else{
                    character = alphaU[index];
                }

                text[i] = character;
            }
            else{
                index = index + intShift;
                if(index>=10){
                    index = index-10;
                }
                if(index<0){
                    index = index+10;
                }

                character = numb[index];
                text[i] = character;

            }
        }
    }

    return text;
}


//argv[0] = ./main
//argv[1] = -e or -d
//argv[2] = charShift variable
//argv[3] = intShift variable
//argv[4] = input file
//argv[5] = output code


int main(int argc, char** argv){
    //Initialize variables
    std::string line;
    std::string encryptedText;
    std::vector<std::string> text;
    

    //This reads the mentioned file and stores it all in the text variable
    std::ifstream f(argv[4]);
    if (f.is_open()) {
        while (getline(f, line)){
            text.push_back(line);
        }
        f.close();
    }
    std::string flag(argv[1], 2);
    std::ofstream of(argv[5]);

    //The following encrypts/decrypts the string and outputs the string to a file
    if (of.is_open()) {
        if(flag == "-e"){
            for(int i = 0; i < text.size(); i++){
                //*argv[2 or 3] is a character of a number (char *argv[2] = 3) thus to convert
                //the character to an integer i subtract the character 0
                encryptedText = encrypt(text[i], *argv[2] - '0', *argv[3] - '0');
                of << encryptedText << "\n";
            }
        }
        if(flag == "-d"){
            for(int i = 0; i < text.size(); i++){
                encryptedText = encrypt(text[i], -(*argv[2] - '0'), -(*argv[3] - '0'));
                of << encryptedText << "\n";
            }
        }

        of.close();
    }


    return 0;
}
