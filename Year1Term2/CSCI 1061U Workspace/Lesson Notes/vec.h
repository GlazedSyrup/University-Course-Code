#ifndef __vec_h__
#define __vec_h__

class Vec2 {
public:     //access members
    double _x;     // members of this class, I use _infront of the name to denote a member
    double _y;
public:
    Vec2(){}
    Vec2(const Vec2& v);
    ~Vec2(){}
    void print(){}
    void set_coord(double x, double y){}
};

#endif