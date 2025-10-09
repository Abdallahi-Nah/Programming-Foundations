#include <iostream>
#include <string>
using namespace std;

int readYear() {
    int year;
    cout << "Please enter a year : " << endl;
    cin >> year;

    return year;
}

int readMonth() {
   int month;
   do {
    cout << "Please enter a month between 1 and 12 : " << endl;
    cin >> month;
   }while(month < 1 || month > 12);

   return month; 
}

int readDay() {
   int day;
   do {
    cout << "Please enter a day between 1 and 31 : " << endl;
    cin >> day;
   }while(day < 1 || day > 31);

   return day;  
}

void displayDate(int year, int month, int day) {
    cout << "The date : " << day << "/" << month << "/" << year << endl;
}

int getDayIndex(int year, int month, int day) {
    int a = ((14-month)/12);
    int y = year - a;
    int m = month + 12*a - 2;

    int dayIndex = (day + y + (y/4) - (y/100) + (y/400) + ((31*m)/12)) % 7;
    
    return dayIndex;
}

void printDayIndexAndDayName(int dayIndex) {
    string daysName[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    cout << "The index of day : " << dayIndex << endl;
    cout << "The name of day : " << daysName[dayIndex] << endl;
}

int main() {
    int year = readYear();
    int month = readMonth();
    int day = readDay();

    displayDate(year, month, day);

    int dayIndex = getDayIndex(year, month, day);

    printDayIndexAndDayName(dayIndex);

    return 0;
}