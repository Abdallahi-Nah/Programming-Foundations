#include <iostream>
#include <string>
using namespace std;

struct sDate {
    int day;
    int month;
    int year;
};

int readDay() {
    int day;
    do {
        cout << "Please enter a day between 1 and 31 : " << endl;
        cin >> day;
    }while(day < 1 || day > 31);
    return day;
}

int readMonth() {
    int month;
    do {
        cout << "Please enter a month between 1 and 12: ";
        cin >> month;
    } while (month < 1 || month > 12);
    return month;
}

int readYear() {
    int year;
    cout << "Please enter a year: ";
    cin >> year;
    return year;
}

sDate readDate() {
    sDate date;
    date.day = readDay();
    date.month = readMonth();
    date.year = readYear();
    return date;
}

bool isLeapYearOptimized(int year) {
    return ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)));
}

int numberOfDaysInMonth(int year, int month) {
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return isLeapYearOptimized(year) ? 29 : 28;
        default:
            return 0;
    }
}

bool isLastDayInAMonth(sDate date) {
    return (date.day == numberOfDaysInMonth(date.year, date.month));
}

bool isLastMonthInAYear(int month) {
    return (month == 12);
}

int main() {    
    sDate date = readDate();

    if(isLastDayInAMonth(date)) {
        cout << "Yes, Day is Last Day in Month." << endl;
    } else {
       cout << "No, Day is NOT Last Day in Month." << endl; 
    }

    if(isLastMonthInAYear(date.month)) {
        cout << "Yes, Month is Last Month in Year." << endl;
    } else {
        cout << "No, Month is NOT Last Month in Year." << endl;
    }  

    return 0;
}