#include <iostream>

using namespace std;

typedef int* IntPtr;

int main(){

    int myInt = 23;
    IntPtr myPointer = &myInt;

    cout << "Value of myInt: \t" << myInt << "\nAddress of myInt: \t" << &myInt << endl;
    cout << "Value of myPointer: \t" << *myPointer << "\nAddress of myPointer: \t" << myPointer << endl;
    
    return 0;

}