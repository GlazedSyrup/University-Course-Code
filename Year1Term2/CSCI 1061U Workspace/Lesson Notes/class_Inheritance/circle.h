#ifndef _circle_h_
#define _circle_h_

#include <string>
using namespace std;

#include "shape.h"

class Circle : public Shape
{
    protected:
    float _radius;

    public:
    Circle() 
        : Shape(""), _radius(0.0) 
    {}
    
    Circle(const string& name, float radius) 
        : Shape(name), _radius(radius) 
    {}
    
    ~Circle() {}

    float radius() { return _radius; }

    // Overriding 
    float compute_area() { return _radius*_radius*3.14159; }

    // Added functionality
    void grow() {
        _radius += 0.2;
    }
};

#endif