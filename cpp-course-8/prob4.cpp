#include <iostream>
#include <string>
using namespace std;

int readYear() {
    int year;
    cout << "Please enter a year : " << endl;
    cin >> year;

    return year;
}

bool isLeapYearOptimized(int year) {
    return ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)));
}

int readMonth() {
   int month;
   do {
    cout << "Please enter a month between 1 and 12 : " << endl;
    cin >> month;
   }while(month < 1 || month > 12);

   return month; 
}

int numberOfDaysInMonth(int year, int month) {
    return (month == 2) ? (isLeapYearOptimized(year) ? 29 : 28) : ((month % 2 != 0 && month != 9 && month != 11) || month == 8 || month == 10 || month == 12) ? 31 : 30;
}

void printMonthName(int monthNumber) {
    string monthsNames[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    cout << "-------" << monthsNames[monthNumber-1] << "-------\n";
}

void printDaysNames() {
    string daysNames[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

    for(int i=0; i < 7; i++) {
        cout << daysNames[i] << "\t";
    }
    cout << endl;
}

int main() {
    int year = readYear();
    int month = readMonth();

    printMonthName(month);
    printDaysNames();
    return 0;
}