#include <iostream>
#include <cmath>

using namespace std;

int main() {
    //using predefined function in math
    float result = sqrt(5);
    float result2 = sqrt(5.0);

    cout << "sqrt(5) = " << result << endl;
    cout << "sqrt(5.0) = " << result << endl;

    float base;
    float exp;
    cout << "base = ";
    cin >> base;
    cout << "exponent = ";
    cin >> exp;

    float power = 1;

    for (int i=0; i < exp; i++){
        power *= base;
    }
    
    cout << base << "^" << exp << " = " << power << endl;
    cout << base << "^" << exp << " = " << pow(base, exp) << endl;


    cout << "2^3 = " << pow(2.0, 3.0) << endl;

    return 0;
}