#include <iostream>
#include <ctime>

using namespace std;

int main() {

    //seeding the random number generator with current time
    srand(time(NULL));

    //generating random numbers between 2 and 5 inclusively
    cout << "A random number in the range [2,5] is " << (rand()%4 + 2) << endl;

    return 0;
}