#include <iostream>
#include <string>
#include "../lib/clsString.h" // Update the path if the file is located in a different directory

using namespace std;

int main() {

    clsString String1;
    clsString String2("Mohammed");
    
    String1.SetValue("Ali Ahmed");
    
    cout << "String1 = " << String1.GetValue() << endl;
    
    cout << "String2 = " << String2.GetValue() << endl;
    
    cout << "Number of words: "<< String1.CountWords() <<endl;
    
    cout << "Number of words: "<< String1.CountWords("Fadi ahmed rateb omer") << endl;
    
    cout << "Number of words: "<< clsString::CountWords("Mohammed Saqer Abu-Hadhoud") << endl;

    cout << "EndsWith : " << clsString::EndsWith(String2.GetValue(), "d") << endl;

    return 0;
}