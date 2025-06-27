#include <iostream>
#include <string>
using namespace std;

class clsA {
    private:

        int _Var1 = 10;
        int _Func1() {
            return _Var1;
        }

    protected:

        int Var2 = 20;
        int Func2() {
            return Var2;
        }

    public:

        int Var3 = 30;
        int Func3() {
            return Var3; 
        }
};

class clsB : public clsA {
    public:

        void Func1() {
            cout << clsA::Var2 << endl;
        }
};

int main() {

    clsB B1;
    B1.Func1();

    return 0;
}