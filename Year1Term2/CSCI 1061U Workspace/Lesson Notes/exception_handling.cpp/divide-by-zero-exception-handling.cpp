#include <iostream>
using namespace std;

int main()
{
    double distance, dt, interval=3.0;

    cout << "Enter distance travelled: ";
    cin >> distance;

    cout << "Enter time interval: ";
    cin >> dt;

    try {
        if (dt < 0) throw -456.0;
        if (dt == 0) throw -523;
        if (distance < 0) throw 'a';

        double velocity = distance / dt;
        cout << "Distance covered in " << interval << " seconds = " << velocity * interval << endl;
    }
    catch (double e)  // This catch block catches exceptions thrown with double data payload
    {
        cout << "Catch block 1" << endl;
        cout << "Error code is " << e << endl;
    }
    catch (int n) // This catch block catches exceptions thrown with int data payload
    {
        cout << "Catch block 2." << endl;
        cout << "Error code is " << n << endl;
    }
    catch (...) // This catch block catches all unhandled exceptions
    {
        cout << "Catch block 3" << endl;
    }

    cout << "Exiting gracefully." << endl;
    return 0;
}