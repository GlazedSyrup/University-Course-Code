#include <iostream>

using namespace std;

typedef int* IntPtr;

int main(){

/*
    int x = 45;



    IntPtr p1;
    p1 = new int;

    *p1 = 50;

    cout << "*p1 value = " << *p1 << "\t" << "*p1 address = " << p1 << endl;

    delete p1;

    IntPtr p2 = new int;
    IntPtr p3 = new int;

    *p2 = 30;
    *p3 = 30;

    cout << "*p2 value = " << *p2 << "\t" << "*p2 address = " << p2 << endl;
    cout << "*p3 value = " << *p3 << "\t" << "*p3 address = " << p3 << endl;

    delete p2;
    delete p3;


    cout << "After delete! << endl;" << endl;
    cout << "*p1 value = " << *p1 << "\t" << "*p1 address = " << p1 << endl;
*/
    
/*
    IntPtr p1;
    p1 = new int[30];

    for(int i = 0; i < 30; i++){

        *(p1+i) = i; //same thing as p1[i] = i

        cout << "p[" << i << "] value = " << (p1+i) << " " << "p[" << i << "] value = " << (p1+i) << endl;
        (p1+i) = i == p1[i] = i
    }

    delete [] p1;
*/

    IntPtr p1;
    int length;
    const int MIN = 1;
    const int MAX = 5;

    cout << "Enter the size:" << endl;
    cin >> length;
    p1 = new int[length];

    cout << "Enter the integers:" << endl;
    for(int i = 0; i < length; i++){
        cin >> p1[i];
    }


    for(int i = MIN; i <= MAX; i++){
        int value_count = 0;
        for(int ii = 0; ii < length; ii++){
            if(p1[ii] == i){
                value_count ++;
            }
        }
        if(value_count > 0){
            cout << i <<  " -> " << value_count;
            if(value_count == 1){
                cout << " time" << endl;
            }
            else{
                cout << " times" << endl;
            }
        }
    }



    delete [] p1;








    return 0;

}