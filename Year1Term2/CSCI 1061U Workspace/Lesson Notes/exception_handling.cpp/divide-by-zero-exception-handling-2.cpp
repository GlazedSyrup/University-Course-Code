#include <iostream>
using namespace std;

class BadTime {};

class NegativeTime : public BadTime {  // NegativeTime is a subclass of BadTime
                                       // NegativeTime "is a" BadTime
    protected:
    double _value;  // data

    public:
    
    NegativeTime() : _value(-1.0) {}  // Default constructor
                                      // that I have changed to
                                      // set the value to -1.0.

    NegativeTime(double value) : _value(value) {} // Another constructor 

    friend
    ostream& operator<<(ostream& s, const NegativeTime& o) {
        s << "Negative time entered: " << o._value;
        return s;
    }
};

class ZeroTime : public BadTime {};  // ZeroTime is also a subclass of BadTime
                                     // ZeroTime "is a" BadTime

class NegativeDistance {};

int main()
{
    double distance, dt, interval=3.0;

    cout << "Enter distance travelled: ";
    cin >> distance;

    cout << "Enter time interval: ";
    cin >> dt;

    try {
        // if (dt < 0) throw NegativeTime(dt);  // You're throwing an instance of class NegativeTime.  NegativeTime() is the "default constructor."
        // if (dt == 0) throw ZeroTime();

        if (dt == 0) throw ZeroTime();
        if (dt < 0) throw NegativeTime(dt);
        if (distance < 0) throw NegativeDistance();

        double velocity = distance / dt;
        cout << "Distance covered in " << interval << " seconds = " << velocity * interval << endl;
    }
    catch (NegativeTime o) // Catches a specific exception of type NegativeTime
                           // This block must sit before BadTime catch block
                           // Simply bacause otherwise NegativeTime will be caught by 
                           // BadTime black.
    {
        cout << "Catch block 1 (NegativeTime)" << endl;
        cout << o << endl;
    }
    catch (NegativeDistance) 
    {
        cout << "Catch block 2 (NegativeDistance)." << endl;
    }
    catch (BadTime)
    {
        cout << "Catch block 4 (BadTime)" << endl;        
    }




    // catch (ZeroTime) 
    // {
    //     cout << "Catch block 3 (ZeroTime)" << endl;
    // }

    cout << "Exiting gracefully." << endl;
    return 0;
}