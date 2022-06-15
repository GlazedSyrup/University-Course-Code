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
};

template<typename T>
int minimum(T a, T b, int (*c)(T, T) )
{
    int result = c(a, b);

    if (result == 1) return 1;
    else if (result == 0) return 0;
    return -1;
}

int compare_age(Person x, Person y) {
    if (x._age == y._age) return 0;
    else if (x._age < y._age) return 1;
    return 2;
}

int compare_firstname(Person x, Person y) {
    if (x._firstname == y._firstname) return 0;
    else if (x._firstname < y._firstname) return 1;
    return 2;
}

int compare_lastname(Person x, Person y) {
    if (x._lastname == y._lastname) return 0;
    else if (x._lastname < y._lastname) return 1;
    return 2;
}

int main()
{
    Person superman("Clark", "Kent", 33);
    Person captain_marvel("Carol", "Denver", 24);

    int (*c)(Person, Person); // How to define a function pointer variable.
    c = compare_lastname;

    // Help us figure out who is younger (0)
    cout << minimum<Person>(superman, captain_marvel, &compare_age) << endl; 

    // We need to figure out which of the two will appear in a dictionary that is ordered
    // based upon first names. (1)
    cout << minimum<Person>(captain_marvel, superman, &compare_firstname) << endl; 

    // We need to figure out which of the two will appear in a dictionary that is ordered
    // based upon last names. (2)
    cout << minimum<Person>(captain_marvel, superman, c) << endl; 

    return 0;
}