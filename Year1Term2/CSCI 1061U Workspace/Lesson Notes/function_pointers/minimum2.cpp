#include <iostream>
#include <string>

using namespace std;

class Person {
    public:
    string _firstname;
    string _lastname; 
    int _age;

    Person() {}
    Person(string firstname, string lastname, int age)
        : _firstname(firstname), _lastname(lastname), _age(age)
        {}

    bool operator==(const Person& o) { return _age == o._age; }
    bool operator<(const Person& o) { return _age < o._age; }
};

template<typename T>
int minimum(T a, T b)
{
    if (a < b) return 1;
    else if (a == b) return 0;
    return -1;
}

int main(){
    // cout << minimum<double>(10.01, 10.03) << endl;
    // cout << minimum<double>(6.2, 6.2) << endl;
    // cout << minimum<double>(12.054, 12.034) << endl;

    Person superman("Clark", "Kent", 33);
    Person captain_marvel("Carol", "Denver", 24);

    cout << minimum<Person>(superman, captain_marvel) << endl; // Help us figure out who is younger (0)

    // We need to figure out which of the two will appear in a dictionary that is ordered
    // based upon first names. (1)
    // We need to figure out which of the two will appear in a dictionary that is ordered
    // based upon last names. (2)

    // PROBLEM: in the current setup, we have no choice but to re-write the two operators
    // to solve either 1 or 2.

    // SOLUTION: how about we are able to somehow pass "functionality" into another function
    // as needed.  Pass functions into other functions.  We MUST be able to have variables that somehow
    // refer to the functions.


    return 0;
}