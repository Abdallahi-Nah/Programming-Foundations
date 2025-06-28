#include <iostream>
#include <string>
using namespace std;

class clsEmployee {
    virtual void printFullName(string FirstName, string LastName) = 0;
    virtual double calculateSalary(double Salary, double Bonus, double Discount) = 0;
    virtual void printSalary(double salaryAfterBonusAndDiscount) = 0;
};

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

int main() {
    clsDeveloper Developer1;

    Developer1.printFullName("Abdallahi", "Nah");
    
    Developer1.printSalary(Developer1.calculateSalary(150000, 50000, 40000));

    return 0;
}