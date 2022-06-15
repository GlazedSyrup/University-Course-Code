#include <iostream>

using namespace std;

int main()
{
    double *data;

    try {
        data = new double[1000000000000000];
    }
    catch(...) {
        cout << "Too much memory." << endl;
    }

    cout << "Graceful exit." << endl;

    return 0;
}