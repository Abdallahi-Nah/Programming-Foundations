#include <iostream>
#include <string>
#include <ctime>
using namespace std;

int readYear() {
    int year;
    cout << "Please enter a year: ";
    cin >> year;
    return year;
}

int readMonth() {
    int month;
    do {
        cout << "Please enter a month between 1 and 12: ";
        cin >> month;
    } while (month < 1 || month > 12);
    return month;
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

void printMonthName(int monthNumber) {
    string monthsNames[12] = {"January", "February", "March", "April", "May", "June",
                              "July", "August", "September", "October", "November", "December"};
    cout << "\n_____________________" << monthsNames[monthNumber - 1] << "_____________________\n\n";
}

void printDaysNames() {
    string daysNames[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    for (int i = 0; i < 7; i++) {
        cout << daysNames[i] << "\t";
    }
    cout << endl;
}

int getStartDay(int year, int month) {
    // Use <ctime> to get weekday of the 1st of the month
    tm time_in = {0, 0, 0, 1, month - 1, year - 1900}; // day=1, month 0-based, year since 1900
    mktime(&time_in);
    return time_in.tm_wday; // 0 = Sunday, 6 = Saturday
}

void printMonthCalendar(int year, int month) {
    printMonthName(month);
    printDaysNames();

    int startDay = getStartDay(year, month);
    int daysInMonth = numberOfDaysInMonth(year, month);

    // Print initial spaces
    for (int i = 0; i < startDay; i++) {
        cout << "\t";
    }

    // Print days
    for (int day = 1; day <= daysInMonth; day++) {
        cout << day << "\t";
        if ((day + startDay) % 7 == 0) // new line every week
            cout << endl;
    }
    cout << "\n___________________________________________________\n";
}

void printYearCalendar(int year) {
    for(int i=1; i <= 12; i++) {
        printMonthCalendar(year, i);
    }
}
int main() {
    int year = readYear();
    // int month = readMonth();
    cout << "\n_______________________________________________\n\n";
    cout << "\t\t Calendar - " << year << "\t\t";
    cout << "\n_______________________________________________\n";

    printYearCalendar(year);

    return 0;
}
