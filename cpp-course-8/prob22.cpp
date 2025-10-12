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

    

    return 0;
}