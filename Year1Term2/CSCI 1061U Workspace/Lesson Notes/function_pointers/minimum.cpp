#include <iostream>

using namespace std;

int minimum(int a, int b)
{
    if (a < b) return 1;
    else if (a == b) return 0;
    return -1;
}

int main()
{
    cout << minimum(10, 12) << endl;
    cout << minimum(6, 6) << endl;
    cout << minimum(12, 1) << endl;

    return 0;
}