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

sDate dateAfterAddingXDays(sDate& date, int numberOfDays) {
    for(int i=1; i <= numberOfDays; i++) {
        dateAfterAddingOneDay(date);
    }
    return date;
}

sDate dateAfterAddingOneWeek(sDate& date) {
    for(int i=1; i <= 7; i++) {
        dateAfterAddingOneDay(date);
    }
    return date;    
}

sDate dateAfterAddingXWeeks(sDate& date, int numberOfWeeks) {
    for(int i=1; i <= numberOfWeeks; i++) {
        dateAfterAddingOneWeek(date);
    }
    return date;
}

sDate dateAfterAddingOneMonth(sDate& date) {
    date.month++;
    if (date.month > 12) {
        date.month = 1;
        date.year++;
    }

    int daysInNewMonth = numberOfDaysInMonth(date.year, date.month);
    if (date.day > daysInNewMonth) {
        date.day = daysInNewMonth;
    }

    return date;
}

sDate dateAfterAddingXMonths(sDate& date, int numberOfMonths) {
    for(int i=1; i <= numberOfMonths; i++) {
        dateAfterAddingOneMonth(date);
    }
    return date;
}

sDate dateAfterAddingOneYear(sDate& date) {
    for(int i=1; i <= 12; i++) {
        dateAfterAddingOneMonth(date);
    }
    return date;
}

sDate dateAfterAddingXYears(sDate& date, int numberOfYears) {
    for(int i=1; i <= numberOfYears; i++) {
        dateAfterAddingOneYear(date);
    }
    return date;
}

sDate dateAfterAddingOneDecade(sDate& date) {
   dateAfterAddingXYears(date, 10);
   return date; 
}

sDate dateAfterAddingXDecades(sDate& date, int numberOfDeacades) {
    for(int i=1; i <= numberOfDeacades; i++) {
        dateAfterAddingOneDecade(date);
    }
    return date;
} 

sDate dateAfterAddingOneCentury(sDate& date) {
    dateAfterAddingXDecades(date, 10);
    return date;
}

sDate dateAfterAddingOneMillennium(sDate& date) {
    for(int i=1; i <= 10; i++) {
        dateAfterAddingOneCentury(date);
    }
    return date;
}

void displayResults(sDate& date) {
    date = dateAfterAddingOneDay(date);
    cout << "\n\nDate After Adding : " << endl;
    cout << "\n01- Adding One day is: " << 
             date.day << "/" << date.month << 
             "/" << date.year << endl;

    date = dateAfterAddingXDays(date, 10);

    cout << "\n02- Adding 10 days is: " << 
             date.day << "/" << date.month << 
             "/" << date.year << endl;

    date = dateAfterAddingOneWeek(date);

    cout << "\n03- Adding One week is: " << 
             date.day << "/" << date.month << 
             "/" << date.year << endl;

    date = dateAfterAddingXWeeks(date, 10);

    cout << "\n04- Adding 10 weeks is: " << 
             date.day << "/" << date.month << 
             "/" << date.year << endl;

    date = dateAfterAddingOneMonth(date);

    cout << "\n05- Adding One month is: " << 
             date.day << "/" << date.month << 
             "/" << date.year << endl;

    date = dateAfterAddingXMonths(date, 5);

    cout << "\n06- Adding 5 months is: " << 
             date.day << "/" << date.month << 
             "/" << date.year << endl;

    date = dateAfterAddingOneYear(date);

    cout << "\n07- Adding One year is: " << 
             date.day << "/" << date.month << 
             "/" << date.year << endl;

    date = dateAfterAddingXYears(date, 10);

    cout << "\n08- Adding 10 Years is: " << 
             date.day << "/" << date.month << 
             "/" << date.year << endl;

    date = dateAfterAddingOneDecade(date);

    cout << "\n09- Adding One Decade is: " << 
             date.day << "/" << date.month << 
             "/" << date.year << endl;

    date = dateAfterAddingXDecades(date, 10);

    cout << "\n10- Adding 10 Decades is: " << 
             date.day << "/" << date.month << 
             "/" << date.year << endl;

    date = dateAfterAddingOneCentury(date);

    cout << "\n11- Adding One Century is: " << 
             date.day << "/" << date.month << 
             "/" << date.year << endl;

    date = dateAfterAddingOneMillennium(date);

    cout << "\n12- Adding One Millennium is: " << 
             date.day << "/" << date.month << 
             "/" << date.year << endl;
}

int main() {    
    sDate date = readDate();
    displayResults(date);   

    return 0;
}