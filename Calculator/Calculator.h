#pragma once
#include "All In.h"

class Calculator
{
public:
    void run();
 
private:
    double calculate(double num1, double num2, char operation, bool& validOperation);
    void printHistory();
 
    std::vector<std::string> history;
};