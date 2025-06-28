#include <iostream>
#include <string>
using namespace std;

class clsA {
    private:
        int _Var1 = 10;

    public:
        int Var2 = 20;

        friend class clsB;
};

class clsB {
    public:

        void Display(clsA A) {
            cout << "Var1 : " << A._Var1 << endl;
            cout << "Var2 : " << A.Var2 << endl;
        }
};

int main() {
    clsB B;
    clsA A1;

    B.Display(A1);

    return 0;
}