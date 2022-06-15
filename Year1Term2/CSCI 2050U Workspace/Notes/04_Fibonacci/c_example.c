#include <stdio.h>

int main(){
    int n = 8;
    int count = 1;
    int previousFib = 0;
    int lastFib = 1;
    int newFib;

    while(count < n){
        //calculuate the next fibonacci number
        int newFib = previousFib +lastFib;

        //remember the last two values
        previousFib = lastFib;
        lastFib = newFib;

        count++;
    }

    printf("The %d fibonnacci number is %d.\n", n, lastFib);

}