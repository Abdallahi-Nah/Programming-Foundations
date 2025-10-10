#include <iostream>
#include<string>
using namespace std;

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

int readHowManyDaysYouWantToAdd() {
    int daysYouWantToAdd = 0;
    cout << "Please how many days you want to add ? " << endl;
    cin >> daysYouWantToAdd;
    return daysYouWantToAdd;
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
    for(int i=1; i < month; i++) {
        totalDays += numberOfDaysInMonth(year, i);
    }
    return totalDays;
}

struct sDate {
    int day;
    int month;
    int year;
};

sDate initialDate(int days, int year) {
    int remeinderDays = days;
    int currentNumberOfDays = days;
    sDate date;
    date.year = year;
    date.month = 1;
    int monthDays = 0;

    while(true) {
        monthDays = numberOfDaysInMonth(year, date.month);

        if(remeinderDays > monthDays) {
            remeinderDays -= monthDays;
            if(date.month == 12) {
                date.year++;
                date.month = 1;
            } else {
                date.month++;
            }
        } else {
            date.day = remeinderDays;
            break;
        }
    }
    return date;
}

int main() {
    int day = readDay();
    int month = readMonth();
    int year = readYear();
    int totalDays = getTotalDays(day, month, year);
    int daysYouWanToAdd = readHowManyDaysYouWantToAdd();
    int allDays = totalDays + daysYouWanToAdd;
    sDate date = initialDate(allDays, year);

    cout << "Date after adding [" << daysYouWanToAdd << "] is : " << 
             date.day << "/" << date.month << "/" << date.year;

    return 0;
}