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

sDate dateAfterSubstractingOneDay(sDate& date) {
    if(date.day == 1) {
        if(date.month == 1) {
            date.month = 12;
            date.year--;
            date.day = 31;
        } else {
            date.month--;
            date.day = numberOfDaysInMonth(date.year, date.month);
        }
    } else {
        date.day--;
    }
    return date;
}

sDate dateAfterSubstractingXDays(sDate& date, int numberOfDays) {
    for(int i=1; i <= numberOfDays; i++) {
        dateAfterSubstractingOneDay(date);
    }
    return date;
}

sDate dateAfterSubstractingOneWeek(sDate& date) {
    for(int i=1; i <= 7; i++) {
        dateAfterSubstractingOneDay(date);
    }
    return date;    
}

sDate dateAfterSubstractingXWeeks(sDate& date, int numberOfWeeks) {
    for(int i=1; i <= numberOfWeeks; i++) {
        dateAfterSubstractingOneWeek(date);
    }
    return date;
}

sDate dateAfterSubstractingOneMonth(sDate& date) {
    date.month--;
    if (date.month == 1) {
        date.month = 12;
        date.year--;
    }

    int daysInNewMonth = numberOfDaysInMonth(date.year, date.month);
    if (date.day == 1) {
        date.day = daysInNewMonth;
    }
    return date;
}

sDate dateAfterSubstractingXMonths(sDate& date, int numberOfMonths) {
    for(int i=1; i <= numberOfMonths; i++) {
        dateAfterSubstractingOneMonth(date);
    }
    return date;
}

sDate dateAfterSubstractingOneYear(sDate& date) {
    date.year--;
    return date;
}

sDate dateAfterSubstractingXYears(sDate& date, int numberOfYears) {
    date.year -= numberOfYears;
    return date;
}

sDate dateAfterSubstractingOneDecade(sDate& date) {
    date.year -= 10;
    return date;
}

sDate dateAfterSubstractingXDecades(sDate& date, int numberOfDecades) {
    date.year -= numberOfDecades * 10;
    return date;
}

sDate dateAfterSubstractingOneCentury(sDate& date) {
    date.year -= 100;
    return date;
}

sDate dateAfterSubstractingOneMillenium(sDate& date) {
    date.year -= 1000;
    return date;
}

void displayResults(sDate& date) {
    date = dateAfterSubstractingOneDay(date);
    cout << "\n\nDate After : " << endl;
    cout << "\n01- Substracting One day is: " << 
             date.day << "/" << date.month << 
             "/" << date.year << endl;

    date = dateAfterSubstractingXDays(date, 10);

    cout << "\n02- Substracting 10 days is: " << 
             date.day << "/" << date.month << 
             "/" << date.year << endl;

    date = dateAfterSubstractingOneWeek(date);

    cout << "\n03- Substracting One week is: " << 
             date.day << "/" << date.month << 
             "/" << date.year << endl;

    date = dateAfterSubstractingXWeeks(date, 10);

    cout << "\n04- Substracting 10 weeks is: " << 
             date.day << "/" << date.month << 
             "/" << date.year << endl;

    date = dateAfterSubstractingOneMonth(date);

    cout << "\n05- Substracting One month is: " << 
             date.day << "/" << date.month << 
             "/" << date.year << endl;

    date = dateAfterSubstractingXMonths(date, 5);

    cout << "\n06- Substracting 5 months is: " << 
             date.day << "/" << date.month << 
             "/" << date.year << endl;

    date = dateAfterSubstractingOneYear(date);

    cout << "\n07- Substracting One year is: " << 
             date.day << "/" << date.month << 
             "/" << date.year << endl;

    date = dateAfterSubstractingXYears(date, 10);

    cout << "\n08- Substracting 10 Years is: " << 
             date.day << "/" << date.month << 
             "/" << date.year << endl;

    date = dateAfterSubstractingOneDecade(date);

    cout << "\n09- Substracting One Decade is: " << 
             date.day << "/" << date.month << 
             "/" << date.year << endl;

    date = dateAfterSubstractingXDecades(date, 10);

    cout << "\n10- Substracting 10 Decades is: " << 
             date.day << "/" << date.month << 
             "/" << date.year << endl;

    date = dateAfterSubstractingOneCentury(date);

    cout << "\n11- Substracting One Century is: " << 
             date.day << "/" << date.month << 
             "/" << date.year << endl;

    date = dateAfterSubstractingOneMillenium(date);

    cout << "\n12- Substracting One Millennium is: " << 
             date.day << "/" << date.month << 
             "/" << date.year << endl;
}

int main() {    
    sDate date = readDate();
    displayResults(date);   

    return 0;
}