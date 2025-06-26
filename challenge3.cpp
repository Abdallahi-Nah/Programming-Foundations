#include <iostream>
#include <string>

using namespace std;

class clsEmployee {
    private:
        int _ID;
        string _FirstName;
        string _LastName;
        string _Title;
        string _Email;
        string _Phone;
        double _Salary;
        string _Department;

        string FullName() {
            return _FirstName + " " + _LastName;
        }

    public:

        clsEmployee(int ID, string FirstName, string LastName, string Title, string Email, string Phone, double Salary, string Department) {
            _ID = ID;
            _FirstName = FirstName;
            _LastName = LastName;
            _Title = Title;
            _Email = Email;
            _Phone = Phone;
            _Salary = Salary;
            _Department = Department;
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

        void setTitle(string Title) {
            _Title = Title;
        }

        string getTitle() {
            return _Title;
        }

        void setEmail(string Email) {
            _Email = Email;
        }

        string getEmail() {
            return _Email;
        }

         void setPhone(string Phone) {
            _Phone = Phone;
        }

        string getPhone() {
            return _Phone;
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

        void sendEmail(string Subject, string Body) {
            cout << "The following message sent successfully to email : " << _Email << endl;
            cout << "Subject : " << Subject << endl;
            cout << "Body : " << Body << endl;
        }

        void SendSMS(string Subject) {
            cout << "\nThe following SMS sent successfully to phone : " << _Phone << endl;
            cout << Subject << endl;
        }

        void print() {
            cout << "Info: \n";
            cout << "=====================" << endl;
            cout << "ID : \t" << _ID << endl;
            cout << "FirstName : \t" << _FirstName << endl;
            cout << "LastName : \t" << _LastName << endl;
            cout << "FullName : \t" << FullName() << endl;
            cout << "Title : \t" << _Title << endl;
            cout << "Email : \t" << _Email << endl;
            cout << "Phone : \t" << _Phone << endl;
            cout << "Salary : \t" << _Salary << endl;
            cout << "Department : \t" << _Department << endl;
            cout << "=====================" << endl;
        }

};

int main() {

    clsEmployee Employee1(12, "Ali", "Omar", "Frontend Developer", "ali.omar@gmail.com", "+222 46231455", 12000, "Web Development");

    Employee1.print();

    Employee1.sendEmail("Question", "The UI for the e-commerce project finish ?");

    Employee1.SendSMS("Watch your email please");

    return 0;
}