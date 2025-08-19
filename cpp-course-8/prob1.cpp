#include <iostream>
#include <string>
using namespace std;

string convertNumberToString(long int number) {
    string s = to_string(number);
    string words[] = {"zero", "one", "two", "three", "four", "five", 
                       "six", "seven", "eight", "nine", "ten"
                      };
    string words2[] = {"", "", "", "hundreds", "thousands", "", "", "millions", "", "", "billions"};
    string result = "";
    int len = s.length();

    for(char c : s) {
        long int digit = c - '0';
        result += words[digit];
        result = result + " " + words2[len] + " ";
        len = len - 1;
    }

    return result;
}

int main() {
    cout << convertNumberToString(8476362741) << endl;
    return 0;
}