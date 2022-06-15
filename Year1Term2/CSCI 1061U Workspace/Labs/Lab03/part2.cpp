// part1.cpp
// by Thomas Chiarello

#include <iostream>
#include <fstream>
#include <string> 
#include <vector>

int wordCounter(std::string txt){
    std::ifstream f(txt);
    std::string line;
    int wordCount = 0;
    char lastChar = ' ';
    bool lastLine = true;

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
        }
        wordCount += 1;
        f.close();
    }
    return wordCount;
}

int lineCounter(std::string txt){
    std::ifstream f(txt);
    std::string line;
    int lineCount = 0;

    if (f.is_open()) {
        while (getline(f, line)){
            lineCount += 1;
        }
        f.close();
    }
    return lineCount;
}

int byteCounter(std::string txt){

    std::ifstream in_file(txt, std::ios::binary | std::ios::ate);
    int byteCount = in_file.tellg();

    return byteCount;
}

int main(int argc, char** argv){
    std::vector<int> lines;
    std::vector<int> words;
    std::vector<int> bytes;
    int lineCount = 0;
    int wordCount = 0;
    int byteCount = 0;
    
    for(int i = 1; i < argc; ++i){
        lines.push_back(lineCounter(argv[i]));
        words.push_back(wordCounter(argv[i]));
        bytes.push_back(byteCounter(argv[i]));
    }
    
    //output
    for(int i = 0; i < argc-1; ++i){
        std::cout << "\t" << lines[i] << "\t" << words[i] << "\t" << bytes[i] << "\t" << argv[i+1] << std::endl;
        wordCount += words[i];
        lineCount += lines[i];
        byteCount += bytes[i];
    }

    std::cout << "\t" << lineCount << "\t" << wordCount << "\t" << byteCount << "\t" << "Total" << std::endl;

    return 0;
}