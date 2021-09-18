#include <iostream>

int fibonacci(int); // объявление функции

int main()
{
	int n;
	std::cout << "Enter the number of the number in the Fibbonacci sequence: " << std::endl;
	std::cin >> n;
	std::cout << "The number in the Fibonacci sequence at the " << n << "th place is: " << fibonacci(n) << std::endl;

	system("pause");
}

int fibonacci(int n) // определение функции
{
	return (n > 2) ? fibonacci(n - 1) + fibonacci(n - 2) : 1;
}