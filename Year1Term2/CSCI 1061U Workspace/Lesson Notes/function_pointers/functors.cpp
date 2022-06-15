#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class Square
{
    protected:
    int _max;

    public:
    Square() : _max(1000) {}
    Square(int max) : _max(max) {}
    void set_max(int v) { _max = v; }

    int operator()(int x, int y) { 
        return x + y;
    }  

    int operator()(int x) { 
        if (x*x < _max) return x*x;
        return 2*x; 
    }  
};

// Option 2: function pointer
class Cube {
    public:
    int operator()(int x) { return x*x*x; }
};


template<typename T>
int do_some_process(T process, int x)
{
    return process(x);
}

int timestwo(int x)
{
    return 2*x;
}

// Option 1: function pointer
int cube(int x) 
{
    return x*x*x;
}

int main()
{
    int x = 4;
    
    cout << do_some_process(timestwo, x) << endl;
    
    Square square; // square is an instance of Square class.
    cout << do_some_process(square, x) << endl;

    square.set_max(4);
    cout << do_some_process(square, x) << endl;

    square.set_max(17);
    cout << do_some_process(square, x) << endl;

    // Option 3: Use lambda functions
    cout << do_some_process([](int x)->int{ return x*x*x; }, x) << endl;

    return 0;
}