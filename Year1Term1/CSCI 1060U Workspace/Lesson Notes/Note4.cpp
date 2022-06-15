#include <iostream>

using namespace std;

int main () {
    long sum = 0;
    int range = 50;

    for (int i = 0; i <= range; i++){
        //if (i%2 == 0) {
            cout << "i = " << i << endl;
            sum += i;

        //}

    }

    cout << "sum of even numbers [0,100] = " << sum << endl;

    return 0;
}