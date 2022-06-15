#include <iostream>
#include <cmath>
using namespace std;

//              //\\                                        //\\                                        //\\
//              |  |        Coded by Thomas Chiarello       |  |         CSCI 1060U - CRN 43914         |  |
//              |  |                                         \/                                         |  |
//              |  |        The program calculates and determines how many thousand products have       |  |
//              |  |       been produced by each factory through inputs from the user. The program      |  |
//              |  |                then displays the information in a chart-like format.               |  |
//              \\//\______________________________________/\\//\______________________________________/\\//

const int factoryNum = 3;

void productionData(int a[], int num);
void numberOfStars(int a[], int num);
void displayFactorySums(const int sums[], int num);
void unitSum(int& sum);

int main(){

    int production[factoryNum];
    cout << "This program displays a graph showing\n" << "production for each factory in the company.\n";
    productionData(production, factoryNum);
    numberOfStars(production, factoryNum);
    displayFactorySums(production, factoryNum);
    
    return 0;

}

// this function starts to loop through the production count of each factory
void productionData(int a[], int num){

    for (int i = 0; i <= num-1; i++){
        cout << endl << "Enter production data for plant number " << i+1 << endl;
        unitSum(a[i]);
    }

}


// this function calculates the sum of the number of products that each department produces in a single
void unitSum(int& sum){

    cout << "Enter number of units produced by each department.\n" << "Append a negative number to the end of the list.\n";
    sum = 0;
    int next;
    cin >> next;

    while (next >= 0){
        sum = sum + next;
        cin >> next;
    }

    cout << "Total = " << sum << endl;

}

//This function determines the number of units produced in thousands of units
void numberOfStars(int a[], int num){

    for (int i = 0; i < num; i++){
        a[i] = static_cast<int>(floor((a[i]/1000.0) + 0.5));
    }

}

// displays each factories # of units as stars
void displayFactorySums(const int a[], int num){
    
    cout << "\nUnits produced in thousands of units:\n";
    for (int i = 1; i <= num; i++){
        cout << "Factory #" << i << " ";
        for (int ii = 1; ii <= a[i-1]; ii++){
            cout << "*";
        }        
        cout << endl;
    }

}


