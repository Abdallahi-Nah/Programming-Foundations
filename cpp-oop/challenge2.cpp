#include <iostream>
#include <string>

using namespace std;

class clsPerson {
    private:
        int _ID;
        string _FirstName;
        string _LastName;
        string _FullName;
        string _Email;
        string _PhoneNumber;

    public:

        clsPerson(int ID, string FirstName, string LastName, string Email, string PhoneNumber)  {
            _ID = ID;
            _FirstName = FirstName;
            _LastName = LastName;
            _FullName = FirstName + " " + LastName;
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

        void setFullName(string FullName) {
            _FullName = FullName;
        }

        string getFullName() {
            return _FullName;
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
            cout << "FullName : \t" << _FullName << endl;
            cout << "Email : \t" << _Email << endl;
            cout << "Phone : \t" << _PhoneNumber << endl;
            cout << "=====================" << endl;
        }
};

int main() {
    clsPerson Person1(10, "Abdallahi", "Nah", "abdou@gmail.com", "+222 33124566");

    Person1.print();

    Person1.sendEmail("Hi", "How are you !");

    Person1.SendSMS("How are you ?");

    return 0;
} 