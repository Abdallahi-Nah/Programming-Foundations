#pragma once
#include <iostream>
#include <string>
#include "clsEmployee2.h"
using namespace std;

class clsDeveloper : public clsEmployee {
    public:

        void printFullName(string FirstName, string LastName) {
            cout << "Full Name : " << FirstName << " " << LastName << endl;
        }

        double calculateSalary(double Salary, double Bonus, double Discount) {
            return (Salary + Bonus - Discount);
        }

        void printSalary(double salaryAfterBonusAndDiscount) {
            cout << "salary After Bonus AndDiscount : " << salaryAfterBonusAndDiscount << endl;
        }
};