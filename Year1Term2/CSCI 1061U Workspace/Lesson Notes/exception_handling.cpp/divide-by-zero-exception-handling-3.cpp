#include <iostream>
using namespace std;

class DivideByZero {};

/* Functions, e.g. safeDivide above, that throw exceptions, but don’t catch them should warn users that it will throw an exception. Specifically, such functions should list all exceptions that it can throw. This is list is often called “exception list” or “throw list”.*/
double divides_a_with_b(double a, double b)
    throw (DivideByZero)
{
    if (b == 0) throw DivideByZero();

    return a / b;
}

int main(int argc, char** argv)
{
    if (argc != 3) { cout << "Usage error 1." << endl; }

    double x, y, z;
    x = atof(argv[1]);
    y = atof(argv[2]);

    try {
        try {
            z = divides_a_with_b(x, y);
        }
        catch(DivideByZero) {
            cout << "Bad thing happened." << endl;
            throw;
        }
    }
    catch(DivideByZero) {
        cout << "This is a rethrow." << endl;
    }

    cout << x << " / " << y << " = " << z << endl;

    cout << "Exiting gracefully." << endl;
    return 0;
}