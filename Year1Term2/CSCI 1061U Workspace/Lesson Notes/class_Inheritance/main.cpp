#include <iostream>
#include <string>
#include <vector>
#include "circle.h"
#include "square.h"
#include "shapemanager.h"

using namespace std;

int main()
{
    ShapeManager manager;
    manager.add_shape( new Circle("Circle 1", 3.2) );
    manager.add_shape( new Circle("Circle 2", 0.2) );
    manager.add_shape( new Square("Square 1", 10.3) );
    
    manager.print_list();
}
