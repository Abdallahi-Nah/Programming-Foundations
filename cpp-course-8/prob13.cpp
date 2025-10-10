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

int differenceBetweenTwoDays(sDate date1, sDate date2, bool isEndDayIncluded = false) {
    int totalDaysForDate1 = getTotalDays(date1.day, date1.month, date1.year);
    int totalDaysForDate2 = getTotalDays(date2.day, date2.month, date2.year);

    return (((isEndDayIncluded) ? (totalDaysForDate2 - totalDaysForDate1 + 1) : (totalDaysForDate2 - totalDaysForDate1)));  
}

int main() {
    sDate date1, date2;
    date1 = readDate();
    date2 = readDate();
    
    cout << "\n\nDifference is: " << differenceBetweenTwoDays(date1, date2) << " Day(s)";
    cout << "\n\nDifference (Including End Day) is: " << differenceBetweenTwoDays(date1, date2, true) << " Day(s)";

    return 0;
}