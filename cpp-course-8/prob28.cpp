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

string readDateAsString() {
    string dateAsString = "";
    cout << "Enter date dd/mm/yy : ";
    cin >> dateAsString;
    return dateAsString;
}

sDate stringToDate(string dateAsString) {
    string items = "";
    int counter = 0;
    sDate date;
    for(int i=0; i < dateAsString.length(); i++) {
        if(dateAsString[i] == '/') {
            counter++;
            if(counter == 1) {
                date.day = stoi(items);
            } 
            if(counter == 2) {
                date.month = stoi(items);
            }
            items = "";
        } else {
            items += dateAsString[i];
        }
    }

    date.year = stoi(items);

    return date;
}

string dateToString(sDate date, string formateDate = "") {
    if(formateDate == "dd/mm/yy") {
        return to_string(date.day) + "/" + to_string(date.month) + "/" + to_string(date.year);
    } else if(formateDate == "yy/dd/mm") {
        return to_string(date.year) + "/" + to_string(date.day) + "/" + to_string(date.month);
    } else if(formateDate == "mm/dd/yy") {
        return to_string(date.month) + "/" + to_string(date.day) + "/" + to_string(date.year);
    } else if(formateDate == "mm-dd-yy") {
        return to_string(date.month) + "-" + to_string(date.day) + "-" + to_string(date.year);
    } else if(formateDate == "dd-mm-yy") {
        return to_string(date.day) + "-" + to_string(date.month) + "-" + to_string(date.year); 
    } else {
        return "Day:"+to_string(date.day)+", Month:"+to_string(date.month)+", Year:"+to_string(date.year);
    }
}

int main() {
    sDate date;

    string dateAsString = readDateAsString();
    date = stringToDate(dateAsString);
    
    cout << dateToString(date, "dd/mm/yy") << endl;
    cout << dateToString(date, "yy/dd/mm") << endl;
    cout << dateToString(date, "mm/dd/yy") << endl;
    cout << dateToString(date, "mm-dd-yy") << endl;
    cout << dateToString(date, "dd-mm-yy") << endl;
    cout << dateToString(date) << endl;

    return 0;
}
