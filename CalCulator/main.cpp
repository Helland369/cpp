#include <iostream>
#include <cmath>
#include <cstdlib>

double x, y, z;

void add1();
void sub();
void mult();
void div();
void SquareR();
void Power();
void Sinn();
void Coss();
void Tann();
void NatLog();
void LogR();

void ExitProgram() {
    exit(0);
}

int main() {
    int oper;

    do {

    std::cout << "---------------------------------------------------------------------\n";
    std::cout << "\t *** Calculator ***\n";
    std::cout << "---------------------------------------------------------------------\n";
    std::cout << "\tSelect an operation\n";
    std::cout << "---------------------------------------------------------------------\n";
    std::cout << "\t1 Addition" << "\t\t2 Subtraction\n"
              << "\t3 Multiplication" << "\t 4 Division\n"
        << "\t5 Square Root" << "\t\t6 Power\n"
        << "\t7 Sin" << "\t8 Cos" << "\t\t9 Tan\n"
        << "\t10 Natural Logarithm" << "\t11 Logarithm\n"
        << "\t0 Exit" << std::endl;

    std::cin >> oper;

    if (oper == 0) {
        ExitProgram();
    }

        switch (oper) {
            case 1:
                add1();
                break;
            case 2:
                sub();
                break;
            case 3:
                mult();
                break;
            case 4:
                div();
                break;
            case 5:
                SquareR();
                break;
            case 6:
                Power();
                break;
            case 7:
                Sinn();
                break;
            case 8:
                Coss();
                break;
            case 9:
                Tann();
                break;
            case 10:
                NatLog();
                break;
            case 11:
                LogR();
                break;
            default:
                std::cout << "Some thing went wrong!!!" << std::endl;

        }

    }while(oper != 0);

return 0;
}

void add1() {
    std::cout << "Enter the first number:\n";
    std::cin >> x;
    std::cout << "Enter second number:\n";
    std::cin >> y;
    z = x +y;
    std::cout << "Sum = " << z << std::endl;
}

void sub() {
    std::cout << "Enter first number:\n";
    std::cin >> x;
    std::cout << "Enter second number";
    std::cin >> y;
    z = x - y;
    std::cout << "Sum = " << z << std::endl;
}

void mult() {
    std::cout << "Enter first number:\n";
    std::cin >> x;
    std::cout << "Enter second number:\n";
    std::cin >> y;
    z = x * y;
    std::cout << "Sum = " << z << std::endl;
}

void div() {
    std::cout << "Enter first number:\n";
    std::cin >> x;
    std::cout << "Enter second number:\n";
    std::cin >> y;
    z = x / y;
    std::cout << "Sum = " << z << std::endl;
}

void SquareR() {
    std::cout << "Enter the number you want to find the square root off:\n";
    std::cin >> x;
    z = std::sqrt(x);
    std::cout << "The square root is = " << z << std::endl;
}

void Power() {
    std::cout << "Enter a number to find it's power:\n";
    std::cin >> x ;
    std::cout << "Enter Exponent:\n";
    std::cin >> y;
    z = std::pow(x, y);
    std::cout << "Power = " << z << std::endl;
}

void Sinn() {
    std::cout << "Enter the number you want to find sin off:\n";
    std::cin >> x;
    z = std::sin(x);
    std::cout << "Sin = " << z << std::endl;
}

void Coss() {
    std::cout << "Enter the number you want to find cos off:\n";
    std::cin >> x;
    z = std::cos(x);
    std::cout << "Cos = " << z << std::endl;
}

void Tann() {
    std::cout << "Enter the number you want to find tan off:\n";
    std::cin >> x;
    z = std::tan(x);
    std::cout << "Tan = " << z << std::endl;
}

void NatLog() {
    std::cout << "Enter the number you want to find natural logarithm oof:\n";
    std::cin >> x;
    z = std::log10(x);
    std::cout << "Natural logarithm = " << z << std::endl;
}

void LogR() {
    std::cout << "Enter the number you want to find logarithm off:\n";
    std::cin >> x;
    z = std::log(x);
    std::cout << "Logarithm = " << z << std::endl;
}
