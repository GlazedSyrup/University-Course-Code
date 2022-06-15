#ifndef _shape_h_
#define _shape_h_

#include <string>
using namespace std;

class Shape // now this is an abstract class
{
    protected:
    string _name;

    public:
    Shape() { _name = ""; }
    Shape(const string& name) : _name(name) {}
    virtual ~Shape() {}

    virtual float compute_area() = 0; // pure virtual function
    const string& name() { return _name; }

    virtual void grow() = 0;  // pure virtual function
};

#endif