#pragma once
#include <iostream>
#include <string>

using namespace std;

class clsEmployee {
    virtual void printFullName(string FirstName, string LastName) = 0;
    virtual double calculateSalary(double Salary, double Bonus, double Discount) = 0;
    virtual void printSalary(double salaryAfterBonusAndDiscount) = 0;
};