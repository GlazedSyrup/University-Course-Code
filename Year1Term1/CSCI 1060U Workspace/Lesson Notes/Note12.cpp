#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <math.h>

using namespace std;

int main() {
    int days[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31};
    string months[] = {"january", "febuary", "march", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int month_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string testy = "0123";
    int year = 2018;
//    string te = to_string(testy[0]) + to_string(testy[1]);
    string te = testy.substr(0,2);
    cout << to_string(testy[0]) << endl;
    cout << to_string(testy[1]) << endl;
    cout << stoi(te) << endl;
    cout << te << endl;


int y = stoi((to_string(year)).substr(1,3))-1;
cout << stoi((to_string(year)).substr(0,2)) << endl;
cout << stoi((to_string(year)).substr(1,3)) << endl;
cout << abs(((int)(1 + floor(2.6*1 - 0.2) - 2*(20) + 8 + floor(8/4) + floor(20/4)))%7) << endl;
cout << (abs((int)(1 + floor(2.6*1 - 0.2) - 2*(20) + 8 + floor(8/4) + floor(20/4))))%7 << endl;

}