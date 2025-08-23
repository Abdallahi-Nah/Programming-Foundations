#include <iostream>
#include <string>
using namespace std;

bool isLeapYear(int year) {
    if(year % 400 == 0) {
        return true;
    } else {
        if((year % 4 == 0) && (year % 100 != 0)) {
            return true;
        } else {
            return false;
        }
    }
}

bool isLeapYearOptimized(int year) {
    return ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)));
}

int readYear() {
    int year;
    cout << "Please enter a year : " << endl;
    cin >> year;

    return year;
}

int readMonth() {
   int month;
   do {
    cout << "Please enter a month between 1 and 12 : " << endl;
    cin >> month;
   }while(month < 1 || month > 12);

   return month; 
}

int numberOfDaysInYear(int year) {
    return ((isLeapYearOptimized(year)) ? 366 : 365);
}

int numberOfDaysInMonth(int year, int month) {
    return (month == 2) ? (isLeapYearOptimized(year) ? 29 : 28) : ((month % 2 != 0 && month != 9 && month != 11) || month == 8 || month == 10 || month == 12) ? 31 : 30;
}

int numberOfHoursInYear(int year) {
    return (numberOfDaysInYear(year) * 24);
}

int numberOfHoursInMonth(int year, int month) {
    return (numberOfDaysInMonth(year, month) * 24);
}

int numberOfMinutesInYear(int year) {
    return (numberOfHoursInYear(year) * 60);
}

int numberOfMinutesInMonth(int year, int month) {
    return (numberOfHoursInMonth(year, month) * 60);
}

int numberOfSecondsInYear(int year) {
    return (numberOfMinutesInYear(year) * 60);
}

int numberOfSecondsInMonth(int year, int month) {
    return (numberOfMinutesInMonth(year, month) * 60);
}

int main() {
    int year = readYear();
    int month = readMonth();

    cout << "\nNumber of Days in Month [" << month << "] is : " << numberOfDaysInMonth(year, month) << endl;
    cout << "\nNumber of Hours in Month [" << month << "] is : " << numberOfHoursInMonth(year, month) << endl;
    cout << "\nNumber of Minutes in Month [" << month << "] is : " << numberOfMinutesInMonth(year, month) << endl;
    cout << "\nNumber of Seconds in Month [" << month << "] is : " << numberOfSecondsInMonth(year, month) << endl;

    return 0;
}