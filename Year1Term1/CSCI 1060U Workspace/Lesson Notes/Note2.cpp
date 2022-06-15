#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    double x = 2.3;
    string firstname, lastname;

    double y = double(4)/3;
    //The above line does the same thing as below
    double four = 4;
    double y2 = four/3;


    cout <<"enter name: ";
    cin >> firstname >> lastname;

    cout << "Welcome " << firstname << " " << lastname << endl;

    return 0;



}