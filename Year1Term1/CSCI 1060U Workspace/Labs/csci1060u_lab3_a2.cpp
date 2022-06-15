#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//This function swaps the location of 2 variables
void swapper (int &a, int &b){
    int c = a;
    a = b;
    b = c;
}



//this function sorts a list from smallest to largest
//This function can sort any number of values
void sortNums(int nums[], int size){
    //this loop ensures the far right number can moved to the far left
    for(int i = 0; i < size-1; i++){
        //this loop compares each number with one beside it, typically carrying a number to its correct location
        for(int ii = 0; ii < size-1; ii++){
            if(nums[ii] > nums[ii+1]){
                swapper(nums[ii], nums[ii+1]);
            }
        }
    }

}


int main() {
    //The Initialization
    //    int nums[] = {1, 23, 4, 54, 3}; // Template
    const int size = 1000;
    int nums[size];
        //seed the pseudo-random number generator
    srand(time(NULL));

    //generate random numbers
    for (int i = 0; i < size; i++){
        nums[i] = rand()%100;
    }

    //The Main Program
    sortNums(nums, size);
    
    //The Output
    cout << "The array of " << size << " integers sorted in ascending order is:" << endl;
    for(int i = 0; i < size; i++){
        cout << nums[i] << " ";
    }
    cout << "" << endl;

    return 0;
} 



//Result of the timed sorting

//  1000 items to sort
//  real    0m0.024s
//  user    0m0.016s
//  user    0m0.016s
//

//  10,000 items to sort
//  real    0m0.670s
//  user    0m0.547s
//  sys     0m0.016s