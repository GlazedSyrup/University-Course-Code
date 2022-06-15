#include <iostream>
#include <string>

// Pulling only these things from the std namespace
using std::cout;
using std::cin;
using std::endl;
using std::string;

template <typename T>
void my_swap(T& i, T& j)
{
    T temp = i;
    i = j;
    j = temp;
}

// Specialization
template<>
void my_swap(char& i, char& j)
{
    i ^= j; // XOR operator - bitwise
    j ^= i;
    i ^= j;
//    cout << "A special swap, just for characters" << endl;
}

template<class T>
T addition(const T& a, const T& b)
{
    T c = a + b;

    return c;
}

class Person
{
    public:
    string _name;
    Person(string name) : _name(name) {}
};

int main()
{
    int x = 10, y = -9;
    cout << "Pre swap" << endl;
    cout << x << " " << y << endl;
    my_swap(x, y);
    cout << "Post swap" << endl;
    cout << x << " " << y << endl;

    Person p1("Adam"), p2("Eve");
    cout << "Pre swap" << endl;
    cout << p1._name << " " << p2._name << endl;
    my_swap(p1, p2);
    cout << "Post swap" << endl;
    cout << p1._name << " " << p2._name << endl;

    char a='A', b='b';
    cout << "Pre swap" << endl;
    cout << a << " " << b << endl;
    my_swap<char>(a, b);
    cout << "Post swap" << endl;
    cout << a << " " << b << endl;

    int n1 = 3, n2 = 5;
    cout << addition<int>(3, 5) << endl;

    return 0;
}