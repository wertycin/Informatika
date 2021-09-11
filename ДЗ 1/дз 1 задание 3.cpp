// ДЗ первое.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
#include <limits>
#include <iomanip>

bool is_equal(double number_1, double number_2) {
    const double epsilon = std::numeric_limits < double > ::epsilon();
    return (abs(number_1 - number_2) < epsilon);
}
int main()
{
    double a, b, c, x_1, x_2, D;
    
    std::cout << "Write a:\n";
    std::cin >> a;
    std::cout << "Write b:\n";
    std::cin >> b;
    std::cout << "Write c:\n";
    std::cin >> c;
    D = b * b - 4.0 * a * c;
    if (is_equal(a, 0.0)) {
        if (not is_equal(b, 0.0)) {
            std::cout << - c / b;
        }
        else if (not is_equal(c, 0.0)) {
            std::cout << "Solution doesn't exist" << '\n';
        }
        else {
            std::cout << "Any x is solution" << '\n';
        }
    }
    x_1 = (-b + sqrt(D)) / (2.0 * a);
    x_2 = (-b - sqrt(D)) / (2.0 * a);
    if (is_equal(D, 0)) {
        std::cout << std::setprecision(3) << std::fixed << "x is " << x_1 << '\n';
    }
    else if (D > 0) {
        std::cout << std::setprecision(3) << std::fixed << "x1 is " << x_1 << '\n' << "x2 is " << x_2 << '\n';
        
    }
    else {
        std::cout << "Solution doesn't exist" << '\n';
    }
    system("pause");
    return 0;
}
