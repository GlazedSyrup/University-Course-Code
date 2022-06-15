#include <iostream>
#include "vec.h"

using namespace std;

Vec2::Vec2(){ // constructors are methods that have the same name as the class
    cout << "did someone call a constructor" << endl;

    _x = 0.5;
    _y = 0.5;

}

Vec2::Vec2(const Vec2& v){
    cout << "copy constructor was called" << endl;

    _x = v._x;
    _y = v._y;
}


Vec2::~Vec2(){ // destructor
    cout << "destructor called" << endl;
}

void Vec2::print(){
    cout << "{" << _x << ", " << "_y" << "}" << endl;
}

void Vec2::set_coord(double x, double y){
    _x = x;
    _y = y;
}
