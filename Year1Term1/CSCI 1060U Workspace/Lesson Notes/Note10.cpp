#include <iostream>

using namespace std;

//declarations of functions
int valueSquared(int a);   //call-by-value example
int refSquared(int &a);     //call-by-reference example

int main() {
    int num = 1;
    int numsquared = 1;

    cout << "Enter a number to be squared: ";
    cin >> num;

    cout << "Address of num =" << &num << endl;
    cout << "Address of numsquared =" << &numsquared << endl;
    

    cout << "Call-by-value example:" << endl;
    numsquared = valueSquared(num);
    cout << "The square of " << num << " is " << numsquared << "." << endl;

    cout << "Call-by-reference example:" << endl;
    numsquared = refSquared(num);
    cout << "The square of " << num << " is " << numsquared << "." << endl;

    return 0;
}

//definitions of functions
int valueSquared(int a) {
    cout << "Address of call-by-value a =" << &a << endl;
    a = a *a;
    return a;
}

int refSquared(const int &a) {
    cout << "Address of call-by-reference a =" << &a << endl; // creates a new variable that refers to the 
    int a_squared = a *a;
    return a_squared;
}

//how to modify and extend programs from class