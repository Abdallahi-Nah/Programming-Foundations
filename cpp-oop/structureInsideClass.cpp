#include <iostream>
#include  <string>

using namespace std;

class clsPerson {
    private:
        string _FullName;
        struct _stPersonAddress {
            string _AddressLine1;
            string _AddressLine2;
            string _City;
            string _Country;
        };

    public:
        _stPersonAddress Address;

        clsPerson() {
            _FullName = "Abdallahi Nah";
            Address._AddressLine1 = "Al-Jedide";
            Address._AddressLine2 = "Street II";
            Address._City = "Boutilimitt";
            Address._Country = "Mauritania";
        }

        void Print() {
            cout << "Info : " << endl;
            cout << "======================================\n" << endl;
            cout << "Full Name : " << _FullName << endl;
            cout << "Address Line 1 : " << Address._AddressLine1 << endl;
            cout << "Address Line 2 : " << Address._AddressLine2 << endl;
            cout << "City : " << Address._City << endl;
            cout << "Country : " << Address._Country << endl;
            cout << "======================================\n" << endl;
        }
};

int main() {
    clsPerson Person1;

    Person1.Print();

    return 0;
}