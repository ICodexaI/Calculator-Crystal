#include "Calculator.h"

double Calculator::calculate(double num1, double num2, char operation, bool& validOperation)
{
    double result = 0;
    validOperation = true;

    switch (operation)
    {
    case '+':
        result = num1 + num2;
        break;

    case '-':
        result = num1 - num2;
        break;

    case '*':
        result = num1 * num2;
        break;

    case '/':
        if (num2 == 0)
        {
            std::cout << "Ошибка: деление на ноль!\n";
            validOperation = false;
        }
        else
        {
            result = num1 / num2;
        }
        break;

    case '^':
        result = std::pow(num1, num2);
        break;

    case '%':
        if (num2 == 0)
        {
            std::cout << "Ошибка: остаток от деления на ноль!\n";
            validOperation = false;
        }
        else
        {
            result = std::fmod(num1, num2);
        }
        break;

    default:
        std::cout << "Неизвестная операция: " << operation << "\n";
        validOperation = false;
        break;
    }

    return result;
}

void Calculator::run()
{
    double num1, num2;
    char operation;
    bool running = true;
    bool useLastResult = false;
    double lastResult = 0;

    std::cout << "Для выхода введите 'q' вместо операции.\n";

    while (running)
    {
        if (useLastResult)
        {
            num1 = lastResult;
            std::cout << "\nПервое число (результат предыдущего расчёта): " << num1 << "\n";
        }
        else
        {
            std::cout << "\nВведите первое число (или 'q' для выхода): ";
            std::cin >> num1;

            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                running = false;
                continue;
            }
        }

        std::cout << "Введите операцию (+, -, *, /, ^, %) или 'q' для выхода: ";
        std::cin >> operation;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Некорректный ввод операции.\n";
            continue;
        }

        if (operation == 'q')
        {
            running = false;
            continue;
        }

        std::cout << "Введите второе число: ";
        std::cin >> num2;

        bool validOperation = true;
        double result = calculate(num1, num2, operation, validOperation);

        if (validOperation)
        {
            std::cout << "Результат: " << result << "\n";
            lastResult = result;

            std::cout << "Использовать результат как первое число для следующего расчёта? (y/n): ";
            char chainChoice;
            std::cin >> chainChoice;
            useLastResult = (chainChoice == 'y');
        }
        else
        {
            useLastResult = false;
        }
    }

    std::cout << "Выход из программы.\n";
}