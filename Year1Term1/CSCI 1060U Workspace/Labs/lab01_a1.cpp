#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    //The Initialization
    string firstname, lastname;
    int birth_year;
    float hourly_wage;
    int applicants_age;
    int current_year = 2020;

    //The Main Program
    cout << "What is your first and last name? ";
    cin >> firstname >> lastname;
    cout << "When were you born? ";
    cin >> birth_year;
    cout << "How much is your requested hourly wage? ";
    cin >> hourly_wage;

    applicants_age = current_year - birth_year;

/*
    cout << "Name: " << firstname << " " << lastname << endl;
    cout << "Birth year: " << birth_year << endl;
    cout << "Hourly wage ($): " << hourly_wage << endl;
*/
    //The Output
    cout << firstname << " " << lastname << " is " << applicants_age << " years old and requests and hourly wage of $" << std::fixed <<std::setprecision(2) << hourly_wage << "." << endl;

    return 0;
}