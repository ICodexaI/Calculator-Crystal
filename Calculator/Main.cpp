#include "All In.h"



int main()

{

    double num1, num2;
    char Operation;
    bool running = true;
    bool useLastResult = false;
    double LastResult = 0;


    Russ();

    std::cout << "Для выхода введите 'q' вместо операции.\n";

    while (running)
   
    {
        if (useLastResult)
        {

            num1 = LastResult;
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
        std::cin >> Operation;

        if (std::cin.fail())
        
        {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Некорректный ввод операции.\n";
            continue;
        }

        if (Operation == 'q')
        
        {
            running = false;
            continue;
        }

        std::cout << "Введите второе число: ";
        std::cin >> num2;

        double result = 0;
        bool validOperation = true;

        switch (Operation) {
        
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
            if (num2 == 0) {
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
            std::cout << "Неизвестная операция: " << Operation << "\n";
            validOperation = false;
            break;
        }

        if (validOperation)
        {
            std::cout << "Результат: " << result << "\n";
            LastResult = result;

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
    return 0;
}