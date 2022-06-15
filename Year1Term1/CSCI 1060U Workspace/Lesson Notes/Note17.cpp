#include <iostream>

using namespace std;

typedef int* IntPtr;

int main(){

    IntPtr p1;
    int size = 5;
    const int INCREMENT = 10;
    int value = 0;
    int count = 0;
    const int MIN = 1;
    const int MAX = 5;
    p1 = new int[size];

    while (value != -1){
        cout << "Enter the integers [" << MIN << "," << MAX << "] (-1 to quit): " << endl;
        cin >> value;
        if(value != -1){
            if(count == size){
                IntPtr temp = new int[size+INCREMENT];
                for(int i = 0; i<size; i++){
                    temp[i] = p1[i];
                }
                delete [] p1;
                p1 = temp;
                size += INCREMENT;
            }
        p1[count] = value;
        count++;

        }
    }



    for(int i = MIN; i <= MAX; i++){
        int value_count = 0;
        for(int ii = 0; ii < size; ii++){
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