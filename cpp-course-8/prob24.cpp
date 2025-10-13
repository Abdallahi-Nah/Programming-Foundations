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

bool isDateWithinPeriod(sDate dateCheck, sPeriod period) {
    if((compareDates(dateCheck, period.date1) == 0 || compareDates(dateCheck, period.date2) == 0 || (compareDates(dateCheck, period.date1) == 1 && compareDates(dateCheck, period.date2) == -1))) {
        return true;
    } else {
        return false;
    }
}

int main() {
    sPeriod period1;
    sDate dateCheck;

    cout << "\n\nEnter Period 1:\n";
    cout << "\nEnter Start Date\n\n";
    period1.date1 = readDate();
    cout << "\nEnter End Date\n\n";
    period1.date2 = readDate();

    cout << "\n\nEnter Date to Check:\n";
    dateCheck = readDate();

    if(isDateWithinPeriod(dateCheck, period1)) {
        cout << "\n\nYes, Date is within period" << endl;
    } else {
        cout << "\n\nNo, Date is NOT within period" << endl;
    }

    return 0;
}