#ifndef _shapemanager_h_
#define _shapemanager_h_

#include <vector>
using namespace std;

class Shape;

class ShapeManager // <-- Camelcase notation
{
    protected:
    vector<Shape*> _shapes;

    public:
    ShapeManager();
    ~ShapeManager();

    void add_shape(Shape* s); // <-- Snakecase notation
    void print_list();
};

#endif 