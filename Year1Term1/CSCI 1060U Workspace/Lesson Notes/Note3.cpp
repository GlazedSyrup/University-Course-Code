//==    Equal to
//!=    Not equal to
//<     Less than
//<=    Less than or equal to
//>     Greater than
//>=    Greater than or equal to
//&&    And
//||    Or
//!     Not

//  (x == y)                if x is equal to y the expression is true    
//  x < y < z               Not proper syntax
//  (x < y) && (y < z)      Correct form of the previous example. if x is less than y and y is less than z the expression is true
//  (y < z) && (y != x)     If y is greater than z and y is not equal to x the expression is true 
//  !((x > 6) || (x <= 2))  


#include <iostream>

using namespace std;

int main() {
    //some var
    int x = 2;
    int y = 4;
    bool temp = true;

    if (x < y) {
        cout << "x is less than y" << endl;
        if (temp) {
            cout << "(temp is also true)";
        }
        cout << endl;
    
    } else if (x > y) {
        cout << "x is greater than y" << endl;
    } else {
        cout << "x is equal to y" << endl;
    }

    return 0;
}