// part1.cpp
// by Thomas Chiarello

#include <iostream>
#include <fstream>
#include <string> 
#include <vector>




int main(int argc, char** argv){
    //Initialize variables
    std::string line;
    std::string encryptedText;
    std::ifstream f(argv[1]);
    char lastChar = ' ';
    int lineCount = 0;
    int wordCount = 0;
    int byteCount = 0;


    if (f.is_open()) {
        while (getline(f, line)){
            for(int i = 0; i < line.length(); ++i){
                if(line[i] == ' '){
                    if(lastChar != ' '){
                        wordCount += 1;
                    }
                }
                else if(line[i] == '\r'){
                    if(lastChar != '\r'){
                        wordCount += 1;
                    }
                }
                lastChar = line[i];
            }

            lineCount += 1;
        }
        
        wordCount += 1;

        std::ifstream in_file(argv[1], std::ios::binary | std::ios::ate);
        byteCount = in_file.tellg();
 

        std::cout << "\t" << lineCount << "\t" << wordCount << "\t" << byteCount << std::endl;
        
        f.close();
    }

    return 0;
}