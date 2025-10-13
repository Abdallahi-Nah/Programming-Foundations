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

bool isDate1AfterDate2(sDate date1, sDate date2) {
    return (date1.year > date2.year ? true : (date1.month > date2.month ? true : (date1.day > date2.day ? true : false)));
}

bool isDate1EqualDate2(sDate date1, sDate date2) {
    return (date1.year == date2.year && date1.month == date2.month && date1.day == date2.day);
}

bool isDate1BeforeDate2(sDate date1, sDate date2) {
    return (!isDate1AfterDate2(date1, date2) && !isDate1EqualDate2(date1, date2));
}

short compareDates(sDate date1, sDate date2) {
    if(isDate1BeforeDate2(date1, date2))
        return -1;
    else if(isDate1EqualDate2(date1, date2))
        return 0;
    else
        return 1;
}

bool isOverlapDates(sPeriod period1, sPeriod period2) {
    if((compareDates(period2.date2, period1.date1) == -1) 
        || (compareDates(period1.date2, period2.date1) == -1)) {
        return false;
    } else {
        return true;
    }
}

int countOverlapDays(sPeriod period1, sPeriod period2) {
    int counter = 0;
    if(isOverlapDates(period1, period2)) {
        for(int i = period2.date1.year; i <= period1.date2.year; i++) {
            for(int j = period2.date1.month; j <= period1.date2.month; j++) {
                for(int k = period2.date1.day+1; k <= period1.date2.day; k++) {
                    counter++;
                }
            }
        }
    }
    return counter;
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

bool isDateInPeriod(sDate Date, sPeriod Period) { 
    return !(compareDates(Date, Period.date1) == -1 || compareDates(Date, Period.date2) == 1); 
} 

int CountOverlapDaysOptimized(sPeriod Period1, sPeriod Period2) {
    int OverlapDays = 0;
    if(isOverlapDates(Period1, Period2)) 
        return 0;  

    while(isDate1BeforeDate2(Period1.date1, Period1.date2)) {
        if(isDateInPeriod(Period1.date1, Period2)) 
            OverlapDays++; 
        
        Period1.date1 = dateAfterAddingOneDay(Period1.date1); 
    }
    return OverlapDays;
}

int main() {
    sPeriod period1, period2;

    cout << "\n\nEnter Period 1:\n";
    cout << "\nEnter Start Date\n\n";
    period1.date1 = readDate();
    cout << "\nEnter End Date\n\n";
    period1.date2 = readDate();

    cout << "\n\nEnter Period 2:\n";
    cout << "\nEnter Start Date\n\n";
    period2.date1 = readDate();
    cout << "\nEnter End Date\n\n";
    period2.date2 = readDate();

    cout << "\n\nOverlap Days Count is: " << countOverlapDays(period1, period2) << endl;

    return 0;
}