#include <iostream>

using namespace std;

typedef int* IntPtr; // defining our own type called IntPtr

int main(){
        
/*
Remember
            value   address
int t;       t       &t
int *p1;    *p1     p1
*/
        
/*
    int *p2;
    int x = 0;

    p2 = &x; //p2 stores an address 
    *p2 = 12; //p2 points to adress that will store 12, aka x
    cout << *p2 << " " << x << endl;
    
*/
/*
        
    int i = 12;
    int *p1;

    p1 = &i;
    *p1 = 24;
    cout << *p1 << " " << i << endl;

*/
/**/
    

    int t = 20;     //an automatic variable of type int
                    //(also called an ordinary variable)
    int *p1;        //pointer to an integer
                    //(called a pointer variable)
    
    //replace int *p2 with
    IntPtr p2;


    //point p1 to t's address
    p1 = &t;
    p2 = p1;
    //Display the value and address of the ordinary variable
    cout << "value: t = " << t << "\t" << "address: &t = " << &t << endl;

    //display the value and address of the pointer variable
    cout << "value: *p1 = " << *p1 << "\t" << "address: p1 = " << p1 << endl;

    cout << "value: *p2 = " << *p2 << "\t" << "address: p2 = " << p2 << endl;





    return 0;

}