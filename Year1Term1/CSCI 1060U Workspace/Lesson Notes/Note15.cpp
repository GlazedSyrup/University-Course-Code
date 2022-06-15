#include <iostream>

using namespace std;

typedef int* IntPtr; // defining our own type called IntPtr


void myFuction(IntPtr &p2);

int main(){
        
    int t = 20;
    IntPtr p1;

    p1 = &t;

    myFuction(p1);

    cout << "value: t = " << t << "\t" << "address: &t = " << &t << endl;
    cout << "value: *p1 = " << *p1 << "\t" << "address: p1 = " << p1 << endl;

    return 0;
}

void myFuction(IntPtr &p2){
    *p2 = 10;

    int x = 5;
    p2 = &x;
    
    cout << "value: x = " << x << "\t" << "address: &x = " << &x << endl;
    cout << "value: *p2 = " << *p2 << "\t" << "address: p2 = " << p2 << endl;
}