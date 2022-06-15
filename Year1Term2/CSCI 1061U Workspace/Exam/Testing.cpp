//LinkedList class in C++
#include <iostream>
#include <string>

using namespace std;

struct MyStruct {
    int age;
    string name;
};


void function_1(MyStruct& m, string n) {
    m.name = n;
}

void function_2(MyStruct m, string n) {
    m.name = n;
}

int main() {
    MyStruct myS;
    cout << myS.name;
    function_2(myS, "Thomas");
    cout << myS.name;

    return 0;
}