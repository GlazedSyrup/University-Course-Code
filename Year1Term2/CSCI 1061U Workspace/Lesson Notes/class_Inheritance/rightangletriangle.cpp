#include "rightangletriangle.h"

 RightAngleTriangle:: RightAngleTriangle()
        : Shape() 
{}

 RightAngleTriangle::RightAngleTriangle(const string& name, float base, float height)
    : Shape(name), _base(base), _height(height)
{}

 RightAngleTriangle::~RightAngleTriangle()
 {}

float RightAngleTriangle::compute_area()
{
    return 0.5 * _base * _height;
}

void RightAngleTriangle::grow()
{
    _base *= 1.1;
    _height *= 1.1;
}

void RightAngleTriangle::render()
{
    
}