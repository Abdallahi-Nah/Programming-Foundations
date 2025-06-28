#include <iostream>
#include <string>

using namespace std;

class clsA {
    private:
        int _Var1;
        int Func1() {
            return 1;
        }

    protected:
        int Var2;
        int Func2() {
            return 2;
        }

    public:
        int Var3;
        int Fun3() {
            return 3;
        }
};

class clsB : protected clsA {
    public:
        int Var4 = 4;
        void Func4() {
            cout << clsA::Fun3() << endl;

            cout << Var4 << endl;
        }
};

class clsC : public clsB, clsA {
    public:
        int Var5;
        int Func5() {
            // clsB::Var3;
            return 5;
        }
};

int main() {
    clsB B1;
    clsA A1;

    B1.Func4();

    B1.Func4();

  

    clsC C1;

    C1.Func5();
    

    return 0;
}