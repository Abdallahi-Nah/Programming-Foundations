#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"

using namespace std;

class clsEmployee : public clsPerson {
    private:
        string _Title;
        double _Salary;
        string _Department;

    public:

        clsEmployee(int ID, string FirstName, string LastName, string Email, string Phone, string Title, double Salary, string Department) : clsPerson(ID, FirstName, LastName, Email, Phone) {
            _Title = Title;
            _Salary = Salary;
            _Department = Department;
        }

        void setTitle(string Title) {
            _Title = Title;
        }

        string getTitle() {
            return _Title;
        }

        void setSalary(double Salary) {
            _Salary = Salary;
        }

        double getSalary() {
            return _Salary;
        }

        void setDapartment(string Department) {
            _Department = Department;
        }

        string getDepartment() {
            return _Department;
        }

        void print() {
            cout << "Info: \n";
            cout << "===========================\n";
            cout << "ID         : \t" << getID() << endl;
            cout << "FirstName  : \t" << getFirstName() << endl;
            cout << "LastName   : \t" << getLastName() << endl;
            cout << "FullName   : \t" << FullName() << endl;
            cout << "Email      : \t" << getEmail() << endl;
            cout << "Phone      : \t" << getPhoneNumber() << endl;
            cout << "Title      : \t" << _Title << endl;
            cout << "Salary     : \t" << _Salary << endl;
            cout << "Department : \t" << _Department << endl;
            cout << "===========================\n";
        }

};