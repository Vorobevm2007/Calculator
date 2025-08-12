#include <iostream>
#include <cstdlib>
#include <string>

class Calculator
{
public:
    char EnterSign(char arrSigns[], const size_t SIGNS_COUNT)
    {
        char sign;
        bool flag = 1;
        while (flag)
        {
            std::cout << "Введите метод операции (+|-|*|/):";
            std::cin >> sign;
            for (int i=0;i < SIGNS_COUNT;i++)
            {
                if (sign == arrSigns[i]) { flag = 0; }
            }
            if (flag) { CheckForExceptions(); }
        }
        return sign;
    }
    double EnterNumber()
    {
        float number;
        while (std::cout << "Введи число:" && !(std::cin >> number)) {
            CheckForExceptions();
        }
        return number;
    }
    void CheckForExceptions()
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "error\n";
    }
    double SolveExpressione(double x, char sign, double y)
    {
        switch (sign)
        {
            case '/':
                if (y != 0) {
                    return x / y;
                }
                else {
                    std::cout << "Деление на 0!!!" << std::endl;
                    return 0;
                }
                break;
            case '*':
                return x * y;
                break;
            case '-':
                return x - y;
                break;
            case '+':
                return x + y;
                break;
        }
    }
    void PrintAndSolveExpression(double x,char sign, double y)
    {
        std::cout << x << sign << y << '=' << SolveExpressione(x, sign, y) << std::endl;
    }
};


int main()
{
    system("chcp 1251>nul");

    const size_t SIGNS_COUNT = 4;
    char arrSigns[SIGNS_COUNT]{ '/', '*', '-', '+' };
    Calculator calculator;

    double x = 0,y = 0;
    char sign = 0;

    while (true)
    {
        x = calculator.EnterNumber();
        sign = calculator.EnterSign(arrSigns,SIGNS_COUNT);
        y = calculator.EnterNumber();
        calculator.PrintAndSolveExpression(x, sign, y);
    }

    return 0;
}

