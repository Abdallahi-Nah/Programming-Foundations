#include <iostream>
#include <string>
using namespace std;

class clsA {
    private:
        int _Var1;
    
    protected:
        int Var2;

    public:
        int Var3;

        clsA() {
            _Var1 = 10;
            Var2 = 20;
            Var3 = 30;
        }

        friend class clsB;
        friend int Sum(clsA A);
};

// Friend Function
int Sum(clsA A) {
    return A._Var1 + A.Var2 + A.Var3;
}

// Non Friend Function
int Result(clsA A) {
    // We can access only Var3
    return A.Var3;
}

class clsB : public clsA{
    public:
        void Display(clsA A) {
            cout << "Var 1 : " << A._Var1 << endl;
            cout << "Var 2 : " << A.Var2 << endl;
            cout << "Var 3 : " << A.Var3 << endl;
        }
};

int main() {
    clsB B1;
    clsA A1;

    B1.Display(A1);

    cout << Sum(A1) << endl;

    return 0;
}