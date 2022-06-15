#include <iostream>
#include <string>

// Pulling only these things from the std namespace
using std::cout;
using std::cin;
using std::endl;
using std::string;

// Meta programming
template <typename T>
void my_swap(T& i, T& j)
{
    T temp = i;
    i = j;
    j = temp;
}

class Person
{
    public:
    string _name;
};


int main()
{
    // Swapping floats.

    int x, y;
    cout << "Enter x: ";
    cin >> x;
    cout << "Enter y: ";
    cin >> y;

    cout << "Before swap:" << endl;
    cout << "x = " << x << ", y = " << y << endl;

    my_swap(x, y);

    cout << "After swap:" << endl;
    cout << "x = " << x << ", y = " << y << endl;

    // Swapping Persons

    Person adam;
    Person eve;
    adam._name = "Adam";
    eve._name = "Eve";

    cout << "Adam's name: " << adam._name << endl;
    cout << "Eve's name: " << eve._name << endl;

    my_swap(adam, eve);

    cout << "Adam's name: " << adam._name << endl;
    cout << "Eve's name: " << eve._name << endl;

    return 0;
}