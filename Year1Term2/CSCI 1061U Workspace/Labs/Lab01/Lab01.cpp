// main.cpp
// by Thomas Chiarello

#include <iostream>
#include <ctime>

const int N = 120;

char generate_random_char(){
    int i = 26.0 * rand() / RAND_MAX;

    if (static_cast<double>(rand())/RAND_MAX < 0.5){
        return static_cast<char>(65+i);
    }
    
    return static_cast<char>(97+i);
}
// counts the frequency of each letter
int letter_count(char l, char *p){
    int count = 0;
    for(int i = 0; i < N; i++){
        if(l == toupper(p[i])){
            count++;
        }
    }

    return count;
}

int main(){
    srand(time(0));

    // Set up an array of characters
    char arr[N];
    char alpha[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    for (int i=0; i < N; ++i){
        arr[i] = generate_random_char();
    }

    // Printing the contents of the input array
    std::cout << "Input array:" << std::endl;
    for (int i=0; i < N; ++i){
        std::cout << arr[i];
    }
    std::cout << std::endl;

    // Printing the frequency of each letter 
    for(int i = 0; i<26; i++){
        std::cout << alpha[i] << ": " << letter_count(alpha[i], arr) << std::endl;
    }

    std::cout << "Total number of characters: " << N << std::endl;

    return 0;
}