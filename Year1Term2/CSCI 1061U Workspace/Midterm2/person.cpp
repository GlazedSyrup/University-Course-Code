#include <iostream>
#include <string>

using namespace std;


struct dob {
    int year;
    int month;
    int day;
};

class Person{
protected:
    string _name;
    dob *date;
public:
    Person(){ _name = "No Name"; };
    Person(string n, int y, int m, int d){
        _name = n;
        date->year = y;
        date->month = m;
        date->day = d;
    }
    ~Person(){ cout << "The person was destroyed" << endl; }
    void operator=( Person& person){
        _name = person._name;
        date->year = person.date->year;
        date->month = person.date->month;
        date->day = person.date->day;
    }
    friend ostream& operator<<(ostream& o, Person& person){
        o << person._name << " was born " << person.date->month << "/" << person.date->day << "/" << person.date->year << endl;           
        return o;
    }
    friend istream& operator>>(istream& i, Person& person){
        string name;
        int year;
        int month;
        int day;
        i >> name >> year >> month >> day;
        person._name = name;
        person.date->year = year;
        person.date->month = month;
        person.date->day = day;
        return i;
    }


};









int main() {
    Person a = Person("Rick", 1953, 01, 01);
    cout << a << endl;

    Person b;
    b = a;
    cout << b << endl;

    Person c;
    cout << "Enter name and dob details: ";
    cin >> c;
    cout << c << endl;

    return 0;
}