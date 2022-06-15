#include <iostream>

using namespace std;

int main(){
    int sum = 0;
    int num = 0;

    do {
        sum += num;

        cout << "Enter a positive number: ";
        cin >> num;
    } while (num > 0);

    cout << "sum = " << sum << endl;
    return 0;
}