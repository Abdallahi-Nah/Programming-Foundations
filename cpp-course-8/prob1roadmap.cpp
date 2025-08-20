#include <iostream>
#include <string>
using namespace std;

string numberToString(long int number) {
    if (number == 0) {
        return "";
    }

    if (number >= 1 && number <= 19) {
        string words[] = {
            "", "One", "Two", "Three", "Four", "Five",
            "Six", "Seven", "Eight", "Nine", "Ten",
            "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen",
            "Sixteen", "Seventeen", "Eighteen", "Nineteen"
        };
        return (words[number] + " ");
    } else if(number >= 20 && number <= 99) {
        string words[] = {
            "", "", "Twenty", "Thirty", "Forty", "Fifty", 
            "Sixty", "Seventy", "Eighty", "Ninety" 
        };
        return (words[number / 10] + " " + numberToString(number % 10));
    } else if(number >= 100 && number <= 199) {
        return ("One hundred " + numberToString(number % 100));
    } else if(number >= 200 && number <= 999) {
        return (numberToString(number / 100) + "Hundreds " + numberToString(number % 100));
    } else if(number >= 1000 && number <= 1999) {
        return ("One thousand " + numberToString(number % 1000));
    } else if(number >= 2000 && number <= 999999) {
        return (numberToString(number / 1000) + "Thousands " + numberToString(number % 1000));
    } else {
        return ("One million " + numberToString(number % 1000000));
    }
}

long int readNumber() {
    long int number;
    cout << "Enter a number : " << endl;
    cin >> number;
    return number;
}

int main() {
    long int number = readNumber();
    cout << numberToString(number) << endl;
    return 0;
}