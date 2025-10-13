#include <iostream>
#include <string>
using namespace std;

struct sDate {
    int day;
    int month;
    int year;
};

struct sPeriod {
    sDate date1, date2;
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

int getTotalDays(int day, int month, int year) {
    int totalDays = day;

    for (int i = 1; i < month; i++) {
        totalDays += numberOfDaysInMonth(year, i);
    }

    for (int y = 1; y < year; y++) {
        totalDays += (isLeapYearOptimized(y) ? 366 : 365);
    }

    return totalDays;
}

int getTotalDays(sDate date) {
    return getTotalDays(date.day, date.month, date.year);
}

int main() {
    return 0;
}