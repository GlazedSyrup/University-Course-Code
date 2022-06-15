#include <iostream>

using namespace std;

int main(){
    int x = 45;
    int y = 63;

    int count = x;
    while (count%y != 0) {
        cout << count << " is not divisible by " << y << endl;
        count--;
    }

    if (count == 0) {
        cout << "No positive numbers less than " << x << " divisible by " << y << endl;
    }
    else{
        cout << count << "is DIVISIBLE by " << y << endl;
    }
    
    return 0;
}