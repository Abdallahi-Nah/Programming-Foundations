#include <iostream>
#include <string>

using namespace std;

class  clsCalculator {
    private:
        float number = 0;
        string operatorName = "";

    public:

        float getnumber() {
            return number;
        }

        void setnumber(float number) {
            this->number = number;
        }

        void Clear() {
            this->number = 0;
            this->operatorName = "Clearing ";
        }

        void Add(float number) {
            this->number = this->number + number;
            this->operatorName = "Adding " + to_string(number);
        }

        void Substruct(float number) {
            this->number = this->number - number;
            this->operatorName = "Substructing " + to_string(number);
        }

        void Multiply(float number) {
            this->number = this->number * number;
            this->operatorName = "Multipling By " + to_string(number);
        }

        void Divide(float number) {
            if(number != 0) {
                this->number = (this->number / number);
                this->operatorName = "Dividing By " + to_string(number);
            }
        }

        void PrintResult() {
            cout << "The result after " << this->operatorName << " Is : " << this->number << endl;
        }
};

int main() {
    clsCalculator calculator1;

    calculator1.Clear();
    calculator1.Add(10);
    calculator1.PrintResult();

    calculator1.Add(100);
    calculator1.PrintResult();

    calculator1.Substruct(20);
    calculator1.PrintResult();

    calculator1.Divide(0);
    calculator1.PrintResult();

    calculator1.Divide(2);
    calculator1.PrintResult();

    calculator1.Multiply(3);
    calculator1.PrintResult();

    calculator1.Clear();
    calculator1.PrintResult();

    system("pause>0");

    return 0;
}