#include <iostream>
#include <string>

using namespace std;

// Déclaration commune de la structure d'adresse
struct stPersonAddress {
    string AddressLine1;
    string AddressLine2;
    string City;
    string Country;
};

class clsPerson {
private:
    string _FullName;

public:
    class clsAddress {
    public:
        stPersonAddress Address;

        clsAddress(stPersonAddress AddressCons) : Address(AddressCons) {} // Initialisation correcte

        void Print() {
            cout << "Info : " << endl;
            cout << "======================================\n";
            cout << "Address Line 1 : " << Address.AddressLine1 << endl;
            cout << "Address Line 2 : " << Address.AddressLine2 << endl;
            cout << "City : " << Address.City << endl;
            cout << "Country : " << Address.Country << endl;
            cout << "======================================\n" << endl;
        }
    };

    stPersonAddress AddressStr;
    clsAddress AddressObj;

    clsPerson() : 
        _FullName("Abdallahi Nah"),
        AddressStr{ "Al-Jedide", "Street II", "Boutilimitt", "Mauritania" },
        AddressObj(AddressStr) // Initialisation correcte
    {}
};

int main() {
    clsPerson Person1;
    Person1.AddressObj.Print();
    return 0;
}