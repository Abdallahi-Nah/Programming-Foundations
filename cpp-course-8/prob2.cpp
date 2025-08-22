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

int main() {
    int year = readYear();
    if (isLeapYearOptimized(year)) {
        cout << "\nYes, Year [" << year << "] is a leap year" << endl;
    }else {
        cout << "\nNo, Year [" << year << "] is not a leap year" << endl;
    }

    return 0;
}