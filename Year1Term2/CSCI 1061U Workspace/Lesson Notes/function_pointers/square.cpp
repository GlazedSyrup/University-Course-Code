#include <iostream>

using namespace std;

double square(double x)
{
    return x*x;
}

double neg(double x)
{
    return -x;
}

double sum(double x, double y)
{
    return x + y;
}

int main()
{
    double (*funptr)(double);  // How to define a function pointer variable.
    funptr = &square;

    cout << funptr(4.3) << endl;

    return 0;
}