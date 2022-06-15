#include "arr.h"
#include <string>

using std::string;

class Person
{
    public:
    string _name;

    friend ostream& operator<<(ostream& o, const Person& p) {
        o << p._name;
        return o;
    }
};

int main()
{
    MyArr<int> a;
    for (int i=0; i<17; ++i) {
        a.push_back(i);
    }
    cout << a << endl;

    MyArr<string> s;
    s.push_back("Adam");
    s.push_back("Eve");
    cout << s << endl;

    // OOPS --- This does not work .......
    MyArr<Person> p;
    Person p1;
    p1._name = "Joni Mitchell";
    p.push_back(p1);
    cout << p << endl;

    return 0;
}