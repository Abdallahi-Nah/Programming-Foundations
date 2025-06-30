#include <iostream>
#include <string>
using namespace std;

class clsEmployee {
    private:
        int ID;
        string FullName;
        float Salary;

    public:

        clsEmployee(int ID, string FullName, float Salary) {
            this->ID = ID;
            this->FullName = FullName;
            this->Salary = Salary;
        }

        static void Func1(clsEmployee Employee) {
            Employee.Print();
        }

        void Func2() {
            Func1(*this);
        }

        void Print() {
            cout << "=============================\n";
            cout << "ID : " << ID << endl;
            cout << "FullName : " << FullName << endl;
            cout << "Salary : " << Salary << endl;
            cout << "=============================\n";
        }
};

int main() {
    clsEmployee Employee1(100, "Abdallahi Nah", 300000);

    // Employee1.Print();
    Employee1.Func2();

    return 0;
}