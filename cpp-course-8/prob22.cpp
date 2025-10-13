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

    // if((period1.date2.year < period2.date1.year) || (period2.date2.year < period1.date1.year)) {
    //     return false;
    // } else {
    //     if(((period1.date2.year == period2.date1.year) && (period1.date2.month < period2.date1.month)) || ((period2.date2.year == period1.date1.year) && (period2.date2.month < period1.date1.month))) {
    //         return false;
    //     } else {
    //         if(((period1.date2.year == period2.date1.year) && (period1.date2.month == period2.date1.month) && (period1.date2.day < period2.date1.day)) || ((period2.date2.year == period1.date1.year) && (period2.date2.month == period1.date1.month) && (period2.date2.day < period1.date1.day))) {
    //             return false;
    //         } else {
    //             return true;
    //         }
    //     }
    // }
}

int main() {
    sPeriod period1, period2;
    sDate date1, date2, date3, date4;

    cout << "\n\nEnter Period 1:\n";
    cout << "\nEnter Start Date\n\n";
    date1 = readDate();
    cout << "\nEnter End Date\n\n";
    date2 = readDate();
    period1.date1 = date1;
    period1.date2 = date2;

    cout << "\n\nEnter Period 2:\n";
    cout << "\nEnter Start Date\n\n";
    date3 = readDate();
    cout << "\nEnter End Date\n\n";
    date4 = readDate();
    period2.date1 = date3;
    period2.date2 = date4;

    if(isOverlapDates(period1, period2)) {
        cout << "\nYes, Periods Overlap" << endl;
    } else {
        cout << "\nNo, Periods NOT Overlap" << endl;
    }

    return 0;
}