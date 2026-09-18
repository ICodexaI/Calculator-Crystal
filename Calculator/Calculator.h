#pragma once
#include "All In.h"

class Calculator
{
public:
    void run();
    double calculate(double num1, double num2, char operation, bool& validOperation);
    std::string formatNumber(double number);

private:
    void printHistory();
    void clearHistory();
    void saveHistoryToFile();
    void loadHistoryFromFile();


    std::vector<std::string> history;
    double memory = 0;
};