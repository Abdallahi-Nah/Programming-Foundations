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

int main() {
    sDate date1, date2;
    date1.day = readDay();
    date1.month = readMonth();
    date1.year = readYear();

    date2.day = readDay();
    date2.month = readMonth();
    date2.year = readYear();


    int totalDaysForDate1 = getTotalDays(date1.day, date1.month, date1.year);
    int totalDaysForDate2 = getTotalDays(date2.day, date2.month, date2.year);

    if(totalDaysForDate1 < totalDaysForDate2) {
        cout << "Yes, Date1 is less than Date2" << endl;
    } else {
        cout << "No, Date1 is NOT less than Date2" << endl;
    }
    

    return 0;
}