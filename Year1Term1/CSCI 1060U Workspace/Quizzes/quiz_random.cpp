#include <iostream>
#include <random>

using namespace std;

int main() {
    //The Initialization
    int lower_bound;
    int upper_bound;
    int random_num;
    string num_string;

    cout << "Enter a lower bound (positive integer): ";
    cin >> lower_bound;
    cout << "Enter an upper bound (positive integer greater than " << lower_bound << "): ";
    cin >> upper_bound;

    //the program
    random_num = rand();
    //num_string =  random_num.toString();
    //The Output
    cout <<  random_num << endl;
    return 0;
}