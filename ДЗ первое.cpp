// ДЗ первое.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
#include <limits>
#include <iomanip>

bool is_equal(double number_1, double number_2) {
    const double epsilon = std::numeric_limits < double > ::epsilon();
    if (abs(number_1 - number_2) < epsilon) {
        return true;
    }
    else {
        return false;
    }
}
int main()
{
    double a, b, c, x_1, x_2;
    
    std::cout << "Write a:\n";
    std::cin >> a;
    std::cout << "Write b:\n";
    std::cin >> b;
    std::cout << "Write c:\n";
    std::cin >> c;
    if (a == 0) {
        if (b != 0) {
            std::cout << - c / b;
        }
        else if (c!=0) {
            std::cout << "Solution doesn't exist" << '\n';
        }
        else if (c == 0) {
            std::cout << "Any x is solution" << '\n';
        }
    }
    else if (b * b - 4 * a * c >= 0) {
        x_1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
        x_2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
        if (is_equal(x_1, x_2)) {
            std::cout << std::setprecision(3) << std::fixed << "x is " << x_1 << '\n';
        }
        else {
            std::cout << std::setprecision(3) << std::fixed << "x1 is " << x_1 << '\n' << "x2 is " << x_2 << '\n';
        }
    }
    else if (b * b - 4 * a * c < 0) {
        std::cout << "Solution doesn't exist" << '\n';
    }
    system("pause");
    return 0;
}