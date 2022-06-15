#include <iostream>

using namespace std;

typedef int* ArrayPtr;

int main(){
    //Create a 2D array by first creating an array of int pointers
    //and then creating arrays of ints from each int pointers
    ArrayPtr *p1 = new ArrayPtr[5];
    //above would look like this without typedef => int **p1 = int*[5];
    for(int i = 0; i < 5; i++){
        p1[i] = new int[3];
    }

    // initialize array values and display
    for(int i = 0; i < 5; i++){
        for(int ii = 0; ii < 3; ii++){
            p1[i][ii] = i*ii;
            cout << p1[i][ii] << " ";
        }
        cout << endl;
    }


    //delete the 2d array - first delete the integer arrays
    for(int i = 0; i < 5; i++){
        delete [] p1[i];
    }
    delete [] p1;
    return 0;
}

/*
root@Beta:/mnt/d/Coding/School code/CSCI 1060U Workspace/lesson notes# g++ Note19.cpp
root@Beta:/mnt/d/Coding/School code/CSCI 1060U Workspace/lesson notes# ./a.out
0 0 0 
0 1 2
0 2 4
0 3 6
0 4 8
root@Beta:/mnt/d/Coding/School code/CSCI 1060U Workspace/lesson notes#
*/