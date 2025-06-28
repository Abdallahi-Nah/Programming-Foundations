#include <iostream>
#include <string>
using namespace std;

class clsPerson {
    public:

        virtual void Print() {
            cout << "Hi, I'm a person" << endl;
        }
};

class clsEmployee : public clsPerson {
    public:

        void Print() {
            cout << "Hi, I'm an employee" << endl;
        }
};

class clsStudent : public clsPerson {
    public:

        void Print() {
            cout << "Hi, I'm a student" << endl;
        }
};

int main() {
    clsEmployee Employee1;
    clsStudent Student1;

    Employee1.Print();
    Student1.Print();

    clsPerson * Person1 = &Employee1;
    clsPerson * Person2 = &Student1; 

    Person1->Print();
    Person2->Print();

    return 0;
}