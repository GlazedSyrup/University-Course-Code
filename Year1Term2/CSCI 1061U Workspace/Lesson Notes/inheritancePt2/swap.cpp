#include <iostream>
#include <string>

// Pulling only these things from the std namespace
using std::cout;
using std::cin;
using std::endl;
using std::string;

class Person
{
    public:
    string _name;
};

// This is a problem.  Because the compiler is unable to
// figure out which swap is called using the return 
// value only.
// int swap(int& i, int& j)
// {
// }

// Overloading

void swap(int& i, int& j)
{
    int temp = i;
    i = j;
    j = temp;
}

void swap(double& i, double& j)
{
    double temp = i;
    i = j;
    j = temp;
}

void swap(Person& i, Person& j)
{
    Person temp = i;
    i = j;
    j = temp;
}

int main()
{
    double x, y;
    cout << "Enter x: ";
    cin >> x;
    cout << "Enter y: ";
    cin >> y;

    cout << "Before swap:" << endl;
    cout << "x = " << x << ", y = " << y << endl;

    swap(x, y);

    cout << "After swap:" << endl;
    cout << "x = " << x << ", y = " << y << endl;

    Person adam;
    Person eve;
    adam._name = "Adam";
    eve._name = "Eve";

    cout << "Adam's name: " << adam._name << endl;
    cout << "Eve's name: " << eve._name << endl;

    swap(adam, eve);

    cout << "Adam's name: " << adam._name << endl;
    cout << "Eve's name: " << eve._name << endl;

    return 0;
}