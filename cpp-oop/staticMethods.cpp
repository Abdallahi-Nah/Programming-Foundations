#include <iostream>
using namespace std;

class clsA {
  public:

    static int function1() {
        return 10;
    }

    int function2() {
        return 20;
    } 
};

int main() {
    clsA A1, A2, A3;

    cout << clsA::function1() << endl;
    
    cout << A1.function1() << endl;

    cout << A1.function2() << endl;

    return 0;
}