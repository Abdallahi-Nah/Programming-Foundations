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

void compareResult(short result) {
    cout << "\n\nCompare Result = " << result << endl;
}

int main() {
    sDate date1, date2;
    cout << "\nEnter Date 1 :\n";
    date1 = readDate();
    cout << "\n\nEnter Date 2 :\n";
    date2 = readDate();

    // if(isDate1AfterDate2(date1, date2))
    //     cout << "\n\nYes, Date1 is After Date2\n";
    // else
    //     cout << "\n\nNo, Date1 is NOT After Date2\n";

    compareResult(compareDates(date1, date2));

    return 0;
}