#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>
int main() {
	double a, b;
	std::cout << "Write a" << '\n';
	std::cin >> a;
	std::cout << "Write b" << '\n';
	std::cin >> b;
	a = a + b;
	b = a - 2.0 * b;
	a = (a - b) / 2.0;
	b = a + b;
	std::cout << a << '\n' << b;
}