#include <iostream>

using namespace std;

class clsA {
    private:
        int _value;
    
    public:

        static int _counter;

        clsA() {
            _counter++;
        }

        void setValue(int value) {
            this->_value = value;
        }

        int getValue() {
            return this->_value;
        }

        void print() {
            cout << "Value = " << this->_value << endl;
            cout << "Counter = " << this->_counter << endl;
            cout << "=====================================" << endl;
        }
};

int clsA::_counter = 0;

int main() {
    clsA A1, A2, A3;

    A1.setValue(10);

    A2.setValue(20);

    A3.setValue(30);

    A1.print();

    A2.print();

    A3.print();

    A2._counter = 500;

    cout << "Counter After updating" << endl;

    A1.print();
    A2.print();
    A3.print();

    return 0;
}