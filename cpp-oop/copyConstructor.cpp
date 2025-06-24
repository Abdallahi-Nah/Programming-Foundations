#include <iostream>
#include <string>
using namespace std;

class clsAddress {
    private:
        string _addressLine1 = "";
        string _addressLine2 = "";
        string _poBox = "";
        string _zipCode = "";

    public:

        clsAddress(string addressLine1, string addressLine2, string poBox, string zipCode) {
            _addressLine1 = addressLine1;
            _addressLine2 = addressLine2;
            _poBox = poBox;
            _zipCode = zipCode;     
        }

        // Copy Constructor
        clsAddress(clsAddress & old_obj) {
            _addressLine1 = old_obj.getAddressLine1();
            _addressLine2 = old_obj.getAddressLine2();
            _poBox = old_obj.getPOBox();
            _zipCode = old_obj.getZipCode();     
        }

        void setAddressLine1(string addressLine1) {
            _addressLine1 = addressLine1;
        }

        string getAddressLine1() {
            return _addressLine1;
        }

        void setAddressLine2(string addressLine2) {
            _addressLine2 = addressLine2;
        }

        string getAddressLine2() {
            return _addressLine2;
        }

        void setPOBox(string poBox) {
            _poBox = poBox;
        }

        string getPOBox() {
            return _poBox;
        }

        void setZipCode(string zipCode) {
            _zipCode = zipCode;
        }

        string getZipCode() {
            return _zipCode;
        }

        void Print()     {         
            cout << "\nAddress Details:\n";         
            cout << "------------------------";         
            cout << "\nAddressLine1: " << _addressLine1 << endl;         
            cout << "AddressLine2: " << _addressLine2 << endl;         
            cout << "POBox       : " << _poBox << endl;         
            cout << "ZipCode     : " << _zipCode << endl;     
        } 
};

int main() {

    clsAddress Address1("Al-Jedide", "Street Camel", "12", "1234");

    Address1.Print();

    clsAddress Address2 = Address1;
    Address2.Print();

    return 0;
}