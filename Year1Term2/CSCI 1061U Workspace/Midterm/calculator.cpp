#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int add(int intA, int intB){
    return intA+intB;
}

int sub(int intA, int intB){
    return intA-intB;
}

int mul(int intA, int intB){
    return intA*intB;
}

int main(int argc, char** argv){
    int intA = atoi(argv[2]);
    int intB = atoi(argv[3]);
    std::string flag = argv[1];

    if(flag == "add"){
        int (*func)(int,int);
        func = &add;
    }
    if(flag == "sub"){
        int (*func)(int,int);
        func = &sub;
    }
    if(flag == "mul"){
        int (*func)(int,int);
        func = &mul;
    }


 
    std::cout << func(intA,intB) << std::endl;
    return 0;
}
