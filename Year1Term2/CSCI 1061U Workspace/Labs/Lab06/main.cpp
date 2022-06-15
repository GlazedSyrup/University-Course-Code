#include <iostream>
using namespace std;

class Point {
  public:
  int x, y;

  Point() {}
  Point(int x, int y) { this->x = x; this->y = y; }
  
  friend ostream& operator<<(ostream& os, const Point& pt) {
    os << "(" << pt.x << ", " << pt.y << ")";
    return os;
  }
};

class Shape {

  protected:
  Point _location;

  public:
  Shape() {}
  Shape(const Point& location) : _location(location) {}
  ~Shape() {}
  
  void draw() {
    cout << "location: " << _location << endl;
  }
  
  void get_info_from_user() {
    cout << "Enter position: ";
    cin >> _location.x >> _location.y;
  }
};

class Tri : public Shape {
  protected:
  char* _type = "Triangle";
  int _width, _height;

  public:
    Tri() {}
    Tri(int _width, int _height) : _width(_width), _height(_height) {}
    ~Tri() {}

//Added an area function for future implementation
    int get_area(){
      return (_width*_height)/2;
    }
};

class Cir : public Shape {
  protected:
    char* type = "Circle";
  int _radius;

  public:
    Cir() {}
    Cir(int _radius) : _radius(_radius) {}
    ~Cir() {}

//Added an area function for future implementation
    int get_area(){
      return 2*3.14*_radius;
    }
};

/////////////////////////////////////////////////
//
// DO NOT CHANGE CODE BELOW THIS LINE
//
/////////////////////////////////////////////////
#define MAX_SHAPES 10

void print_shapes(Shape** shapes, int n)
{
  for (int i=0; i<n; ++i) {
    cout << "[" << i << "] "; shapes[i]->draw();
  }
}

int main()
{
  Shape* shapes[MAX_SHAPES];

  int n = 0;
  char shape_choice;
  do {
    cout << "Choose a shape to add" << endl;
    cout << "\t(a) for triangle" << endl;
    cout << "\t(b) for circle" << endl;
    cout << "\t(p) to print the shapes" << endl;
    cout << "\t(0-9) to modify a shape" << endl;
    cout << "\t(q) to exit" << endl;
    cout << ": ";
    cin >> shape_choice;

    if (shape_choice == 'q') break;
    
    switch(shape_choice)
    {
      case '0':
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':
        shapes[((int) shape_choice) - 48]->get_info_from_user();
      break;
      case 'a':
        if (n >=  MAX_SHAPES) {
          cout << "== Cannot add any more shapes ==" << endl;
          continue;
        }      
        cout << "== You selected a triangle. ==" << endl;
        shapes[n] = new Tri();
        shapes[n]->get_info_from_user();
        ++n;
      break;
      case 'b':
        if (n >=  MAX_SHAPES) {
          cout << "== Cannot add any more shapes ==" << endl;
          continue;
        }
        cout << "== You selected a circle. ==" << endl;
        shapes[n] = new Cir();
        shapes[n]->get_info_from_user();
        ++n;     
      break;
      case 'p':
        print_shapes(shapes, n);
      break;
      case 'q':
      break;
      default:
        cerr << "== Invalid choice ==" << endl;
      break;
    }
  } while (true);

  for (int i=0; i<n; ++i) delete shapes[i];
}