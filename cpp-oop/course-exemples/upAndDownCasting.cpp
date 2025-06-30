#include <iostream>
#include <string>
using namespace std;

class clsPerson {
    public:
        string FullName = "Abdallahi Nah";
};

class clsEmployee : public clsPerson {
    public:
        string Title = "CEO";
}; 

int main() {
    clsEmployee Employee1;
    cout << Employee1.FullName << endl;
    cout << Employee1.Title << endl;

    // up-casting
    clsPerson * Person1 = &Employee1;
    cout << Person1->FullName << endl;

    // down-casting (impossible in C++)
    clsPerson Person2;
    // clsEmployee * Employee1 = &Person2;

    return 0;
}