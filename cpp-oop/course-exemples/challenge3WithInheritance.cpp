#include <iostream>
#include <string>
#include "lib/clsEmployee.h"

using namespace std;

int main() {

    clsEmployee Employee1(12, "Ali", "Omar", "ali.omar@gmail.com", "+222 46231455", "Frontend Developer", 12000, "Web Development");

    Employee1.print();

    Employee1.sendEmail("Question", "The UI for the e-commerce project finish ?");

    Employee1.SendSMS("Watch your email please");

    return 0;
}