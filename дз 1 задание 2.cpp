#include <iostream>
#include <iomanip>
#include <string>

int main() {
    double value, coefficient;
    std::string name_1, name_2;
    std::cin >> value >> name_1;
    if (name_1 == "m") {
        coefficient = 100.0;
        name_2 = "cm";
    }
    if (name_1 == "kg") {
        coefficient = 1000.0;
        name_2 = "g";
    }
    if (name_1 == "s") {
        coefficient = 1.0;
        name_2 = "s";
    }
    if (name_1 == "C") {
        coefficient = 3e9;
        name_2 = "Fr";
    }
    std::cout << std::setprecision(3) << std::fixed << coefficient * value << " " << name_2 << '\n';
    return 0;
}