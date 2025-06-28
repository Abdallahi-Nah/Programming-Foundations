#include <iostream>
#include <string>
using namespace std;

class clsPerson {
    private:
        string _FullName;

    public:

        class clsAddress {
            private:
                string _AddressLine1;
                string _AddressLine2;
                string _City;
                string _Country;

            public:

                clsAddress(string AddressLine1, string AddressLine2, string City, string Country) {
                    _AddressLine1 = AddressLine1;
                    _AddressLine2 = AddressLine2;
                    _City = City;
                    _Country = Country;
                } 
                
                void setAddressLine1(string AddressLine1) {
                    _AddressLine1 = AddressLine1;
                }

                string getAddressLine1() {
                    return _AddressLine1;
                }

                void setAddressLine2(string AddressLine2) {
                    _AddressLine2 = AddressLine2;
                }

                string getAddressLine2() {
                    return _AddressLine2;
                }

                void setCity(string City) {
                    _City = City;
                }

                string getCity() {
                    return _City;
                }

                void setCountry(string Country) {
                    _Country = Country;
                }

                string getCountry() {
                    return _Country;
                }

                void Print() {
                    cout << "Info : \n";
                    cout  << "=================================\n";
                    cout << "Address Line 1 : " << _AddressLine1 << endl;
                    cout << "Address Line 2 : " << _AddressLine2 << endl;
                    cout << "City : " << _City << endl;
                    cout << "Country : " << _Country << endl;
                    cout  << "=================================\n";
                }
        };

    public:
        clsAddress Address =  clsAddress("", "","",""); 

        clsPerson(string FullName, string AddressLine1, string AddressLine2, string City, string Country) {
            _FullName = FullName;
           Address = clsAddress( AddressLine1, AddressLine2, City, Country);
        }

        void setFullName(string FullName) {
            _FullName = FullName;
        }

        string getFullName() {
            return _FullName;
        }
};

int main() {
    clsPerson Person1("Abdallahi Nah", "Al-Jedide", "Street II", "Boutilimitt", "Mauritania");

    Person1.Address.Print();



    return 0;
}