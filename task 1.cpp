#include <iostream>

int fibonacci(int); // ���������� �������

int main()
{
	int n;
	std::cout << "Enter the number of the number in the Fibbonacci sequence: " << std::endl;
	std::cin >> n;
	std::cout << "The number in the Fibonacci sequence at the " << n << "th place is: " << fibonacci(n) << std::endl;

	system("pause");
}

int fibonacci(int n) // ����������� �������
{
	return (n > 2) ? fibonacci(n - 1) + fibonacci(n - 2) : 1;
}