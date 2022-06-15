#include "vec.h"

int main(){
    Vec2 a;
    a.set_coord(0.5, 1.0);
    a.print();

    Vec2* b = &a;
    b->print();

    Vec2 c(a);
    c.print();
    return 0;
};