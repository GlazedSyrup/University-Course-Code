#include <iostream>
#include <string>
//#include <ctime>
//#include <cstdlib>
using namespace std;

void hello(string fname);

//we can overload a function by having different parameter types
//or number of parameters

void hello(string fname, char linit);

void hello(int studentid);

int main() {
    /*
    cout << "Hello A" << endl;
    cout << "Hello B" << endl;
    cout << "Hello C" << endl;
    cout << "Hello D" << endl;
    */
    hello("A", 'a');
    hello("B");
    hello("C");
    hello("D");
    hello(100786096);
    char finit = 'M';
    hello(string(1, finit));

    return 0;
}

//declaration of functions
void hello(string fname) {
    cout << "Hello " << fname << ", welcome to the class!" << endl;

}


void hello(string fname, char linit) {
    cout << "Hi " << fname << " " << linit << endl;
}

void hello(int studentid) {
    cout << "Hello student # " << studentid << endl;
}


