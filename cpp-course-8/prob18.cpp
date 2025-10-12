#include <iostream>
#include <string>
#include <ctime>
using namespace std;

struct sDate {
    int day;
    int month;
    int year;
    int dayOfWeek;
};

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

    return totalDays;
}

string getDayName(int wday) {
    string days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    return days[wday];
}

sDate getSystemDate() {
    sDate date;
    time_t now = time(0);
    tm *ltm = localtime(&now);

    date.day = ltm->tm_mday;     
    date.month = 1 + ltm->tm_mon;
    date.year = 1900 + ltm->tm_year;
    date.dayOfWeek = ltm->tm_wday;

    return date;
}

bool isItLastDayInTheWeek(int dayNumber) {
    return dayNumber == 6;
}

bool isItWeekend(int dayNumber) {
    return (dayNumber == 0 || dayNumber == 6);   
}

bool isItBuisnessDay(int dayNumber) {
    return !isItWeekend(dayNumber);
}

int daysUntilTheEndOfWeek(int dayNumber) {
    return (7-(dayNumber + 1));
}

int daysUntilTheEndOfMonth(sDate& date) {
    return (numberOfDaysInMonth(date.year, date.month) - date.day);
}

int daysUntilTheEndOfYear(sDate& date) {
    return (isLeapYearOptimized(date.year) ? (366 - getTotalDays(date.day, date.month, date.year)) : 
            (365 - getTotalDays(date.day, date.month, date.year)));
}

void results(sDate& date) {
    string dayName = getDayName(date.dayOfWeek); 
    
    cout << "\n\nToday is " << dayName << " , " << 
            date.day << "/" << date.month << "/" << date.year;

    cout << "\n\nIs It End of Week ?\n";
    if(isItLastDayInTheWeek(date.dayOfWeek)) 
        cout << "Yes it is end of week" << endl;
    else
        cout << "No Not end of week" << endl;

    cout << "\n\nIs It Weekend ?\n";
    if(isItWeekend(date.dayOfWeek))
        cout << "Yes it is a week end" << endl;
    else
        cout << "No it is Not a week end" << endl;

    cout << "\n\nIs It Buisness Day ?\n";
    if(isItBuisnessDay(date.dayOfWeek))
        cout << "Yes it is a Buisness day" << endl;
    else
        cout << "No it is Not a Buisness day" << endl;

    cout << "\n\nDays until end of week : " << 
         daysUntilTheEndOfWeek(date.dayOfWeek) << " day(s)" << endl;
    cout << "Days until end of month : " << 
         daysUntilTheEndOfMonth(date) << " day(s)" << endl;
    cout << "Days until end of year : " << 
         daysUntilTheEndOfYear(date) << " day(s)" << endl;
}

int main() {
    sDate date;
    date = getSystemDate();
    results(date);   

    return 0;
}