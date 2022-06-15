#include <iostream>
using std::cout; 
using std::endl;

int main() 
{
    auto func = [](int x)->int{ return x*x; };
    
    int x = 11;
    cout << func(x) << endl;
    
    return 0; 
}