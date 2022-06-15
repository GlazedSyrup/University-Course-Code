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
    int size = 5;
    int nums[] = {0, 0, 0, 0, 0};
    cout << "Enter " << size << " integers:\n" << endl;
    for(int i = 0; i < size; i++){
        cout << "Enter an integer" << endl;
        cin >> nums[i];
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