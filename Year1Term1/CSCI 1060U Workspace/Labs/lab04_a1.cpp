#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>

using namespace std;

//              //\\                                        //\\                                        //\\
//              |  |        Coded by Thomas Chiarello       |  |  Thoroughly tested with the year 2008  |  |
//              \\//\______________________________________/\\//\______________________________________/\\//


//  This function determines the months starting point based off of the previous months up to january, and january is calculated with the function below
int week_day(int month, int year, int days[], int month_days[]){
//  Initialization
    int day_count = 0;
    int indent_num = 0;
    int month_indent[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
//  Determining week day starting point for january
    int arith_cell = abs(((int)(1 + floor(2.6*11 - 0.2) - 2*(stoi((to_string(year)).substr(0,2))) + (stoi((to_string(year)).substr(1,3))-1) + floor((stoi((to_string(year)).substr(1,3))-1)/4) + floor(stoi((to_string(year)).substr(0,2))/4)))%7);
    month_indent[0] = arith_cell;


//  loop through the months until reaching the requested month.
    for(int i = 0; i < month+1; i++){
        for(int ii = 0; ii <= 6; ii++){
            for(int iii = 0; iii < 7; iii++){
                if(day_count == month_days[i]){
                    month_indent[i+1] = iii;
                    break;
                }

                if(indent_num < month_indent[i]){
                    indent_num += 1;
                }
                
                else{
                    day_count += 1;
                }
            }
    
            if(day_count == month_days[i]){
                break;
            }
        }
//  reset counter values
    indent_num = 0;
    day_count = 0;
    }
    return month_indent[month];
    
}





//  This function prints out the specified month in the specified year 
void printMonth(int month, int year){
    int days[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31};
    string months[] = {"January", "Febuary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int month_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int day_count = 0;
    bool leap = false;
    int indent_num = 0;

    indent_num = 0;

    // Determines if the year is a leap year.
    if(year%4 == 0){
        leap = true;
        month_days[1] = 29;
        if(year%100 == 0){
            leap = false;
            month_days[1] = 28;
            if(year%400 == 0){
                leap = true;
                month_days[1] = 29;
            }
        }
    }



//print the month
    cout << "\t\t" << months[month] << "\t" << year << endl;
    for(int i = 0; i < 6; i++){
        for(int ii = 0; ii < 7; ii++){
            if(day_count == month_days[month]){
                break;
            }
//  tabs through the blank days of the previous month
            if(indent_num < week_day(month, year, days, month_days)){
                cout << " " << "\t";
                indent_num += 1;
            }
//  prints each day
            else{
                cout << days[day_count] << "\t";
                day_count += 1;
            }             
        }

        cout << endl;
    }
}



//This function prints out the 12 months in the specified year
void printYear(int year){
    int month_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int month_count = 0;

//  loops each month
    for(int i = 0; i <= 11; i++){
        printMonth(i, year);
    }
}


// main program that takes an input from the user on if they want a year calender or a month and which month. Then the programs calls the respective function and the calender is printed.
int main(){
//  Initialization
    string choice = "";
    int year;
    int month;


//The main code
    cout << "do you want a year or month calender?" << endl;
        cin >> choice;

    if(choice == "year" || choice == "Year"){
        cout << "what year?" << endl;
        cin >> year;

    printYear(year);
    }

    else{
        cout << "what month (in number format 1-12)?" << endl;
        cin >> month;
        month = month - 1;
        cout << "what year?" << endl;
        cin >> year;
        printMonth(month, year);   
    
    }

    return 0;
}

//  Program finishes