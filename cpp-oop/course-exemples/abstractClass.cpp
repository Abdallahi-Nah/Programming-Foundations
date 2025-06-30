#include <iostream>
#include <string>
#include "lib/clsDeveloper.h"
using namespace std;

int main() {
    clsDeveloper Developer1;

    Developer1.printFullName("Abdallahi", "Nah");
    
    Developer1.printSalary(Developer1.calculateSalary(150000, 50000, 40000));

    return 0;
}