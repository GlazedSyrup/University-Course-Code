#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef int* IntPtr;

//int[] createRandomArray(int size); // not allowed!
//Array can't be returned by a function

IntPtr createRandomArray(int size);


int main(){
    int size;

    cout << "Enter array size: ";
    cin >> size;

    IntPtr p1 = createRandomArray(size);

    for(int i = 0; i < size; i++){
        cout << "p1[" << i << "] = " << p1[i] << endl;
    }

    delete [] p1;
    return 0;
}

IntPtr createRandomArray(int size){
    IntPtr temp = new int[size];

    //seed random number generator
    srand(time(NULL));

    //generate random numbers 0-100
    for(int i = 0; i < size; i++){
        temp[i] = rand()%101;
    }
}

