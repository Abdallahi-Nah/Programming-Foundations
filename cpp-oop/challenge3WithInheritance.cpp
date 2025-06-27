#include <iostream>
#include <string>

using namespace std;

class clsPerson {
    private:
        int _ID;
        string _FirstName;
        string _LastName;
        string _Email;
        string _PhoneNumber;

    public:

        clsPerson(int ID, string FirstName, string LastName, string Email, string PhoneNumber)  {
            _ID = ID;
            _FirstName = FirstName;
            _LastName = LastName;
            _Email = Email;
            _PhoneNumber = PhoneNumber;
        }

        int getID() {
            return _ID;
        }

        void setFirstName(string FirstName) {
            _FirstName = FirstName;
        }

        string getFirstName() {
            return _FirstName;
        }

        void setLastName(string LastName) {
            _LastName = LastName;
        }

        string getLastName() {
            return _LastName;
        }

        string FullName() {
            return _FirstName + " " + _LastName;
        }

        void setEmail(string Email) {
            _Email = Email;
        }

        string getEmail() {
            return _Email;
        }

        void setPhoneNumber(string PhoneNumber) {
            _PhoneNumber = PhoneNumber;
        }

        string getPhoneNumber() {
            return _PhoneNumber;
        }

        void sendEmail(string Subject, string Body) {
            cout << "The following message sent successfully to email : " << _Email << endl;
            cout << "Subject : " << Subject << endl;
            cout << "Body : " << Body << endl;
        }

        void SendSMS(string Subject) {
            cout << "\nThe following SMS sent successfully to phone : " << _PhoneNumber << endl;
            cout << Subject << endl;
        }

        void print() {
            cout << "Info: \n";
            cout << "=====================" << endl;
            cout << "ID : \t" << _ID << endl;
            cout << "FirstName : \t" << _FirstName << endl;
            cout << "LastName : \t" << _LastName << endl;
            cout << "FullName : \t" << FullName() << endl;
            cout << "Email : \t" << _Email << endl;
            cout << "Phone : \t" << _PhoneNumber << endl;
            cout << "=====================" << endl;
        }
};

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

int main() {

    clsEmployee Employee1(12, "Ali", "Omar", "ali.omar@gmail.com", "+222 46231455", "Frontend Developer", 12000, "Web Development");

    Employee1.print();

    Employee1.sendEmail("Question", "The UI for the e-commerce project finish ?");

    Employee1.SendSMS("Watch your email please");

    return 0;
}