#include <iostream>
#include <string>
using namespace std;

class clsPerson {
    private:
        string _firstName;

    public:
        clsPerson() {
            cout << "Hi, I'm constructor" << endl;
        }

        ~clsPerson() {
            cout << "Hi, I'm destructor" << endl;
        }
};

int main() {
    clsPerson Person1;

    clsPerson * Person2 = new clsPerson;

    delete Person2;

    return 0;
}