#include <iostream>
#include <string>
#include <ctime>
using namespace std;

struct sDate {
    int day;
    int month;
    int year;
};

int dayOfWeekOrder(int day, int month, int year) {
    int a, y, m; 
    a = (14 - month) / 12; 
    y = year - a; 
    m = month + (12 * a) - 2;

    return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7; 
}

int dayOfWeekOrder(sDate date) {
    return dayOfWeekOrder(date.day, date.month, date.year);
}

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

bool isDate1BeforeDate2(sDate date1, sDate date2) {
    return (date1.year < date2.year) ? true : ((date1.year == date2.year) ? (date1.month < date2.month ? true : (date1.month == date2.month ? date1.day < date2.day : false)) : false); 
}

string getDayNameFromDate(sDate date) {
    tm timeStruct = {};
    timeStruct.tm_mday = date.day;
    timeStruct.tm_mon = date.month - 1;
    timeStruct.tm_year = date.year - 1900;

    mktime(&timeStruct);

    string days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    return days[timeStruct.tm_wday];
}

void printDate(string message, sDate date) {
    cout << "\n" << message << ": " << getDayNameFromDate(date) << " , " << 
            date.day << "/" << date.month << "/" << date.year << endl;
}

bool isItWeekend(sDate date) {
    return (dayOfWeekOrder(date) == 0 || dayOfWeekOrder(date) == 6);   
}

bool isItBuisnessDay(sDate date) {
    return !isItWeekend(date);
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

sDate dateAfterAddingOneDay(sDate& date) {
    if(isLastDayInAMonth(date)) {
        date.day = 1;
        if(isLastMonthInAYear(date.month)) {
            date.month = 1;
            date.year++;
        } else {
            date.month++;
        }
    } else {
        date.day++;
    }
    return date;
}

short calculateVaccationDays(sDate dateFrom, sDate dateTo) {
    short numberOfDays = 0;
    while(isDate1BeforeDate2(dateFrom, dateTo)) {
        if(isItBuisnessDay(dateFrom)) {
            numberOfDays++;
        }
        dateFrom = dateAfterAddingOneDay(dateFrom);
    }
    return numberOfDays;
}

int main() {
    sDate date1, date2;
    cout << "Vacation Starts : " << endl;
    date1 = readDate();
    cout << "\nVacation Ends : " << endl;
    date2 = readDate();

    printDate("Vaccation From", date1);
    printDate("Vaccation To", date2);
    cout << "\nActual Vacation days is: " << calculateVaccationDays(date1, date2) << endl;
    
    return 0;
}