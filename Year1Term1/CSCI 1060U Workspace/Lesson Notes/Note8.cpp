#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {

    int count = 0;

    cout << "how many random numbers do you need?" << endl;
    cin >> count;

    //seed the pseudo-random number generator
    srand(time(NULL));

    //generate random numbers
    for (int i = 0; i < count; i++){
        cout << "rand() = " << (100000000 + rand()%100000000) << endl;
    }
    return 0;
}