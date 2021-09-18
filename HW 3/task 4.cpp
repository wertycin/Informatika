#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <functional>


int run_function(std::function < double(double, double) > function, double x, double y) // функция получает функцию
{
	std::cout << function(x, y) << std::endl;
	return 0;
}

int main()
{
	double x, y;
	std::cout << "Enter x and y:" << std::endl;
	std::cin >> x;
	std::cin >> y;
	std::vector < std::function < double(double, double) > > v =
	{
		[](double x, double y) { return x + y; },
		[](double x, double y) { return x * y; }
	};

	std::cout << "Lambda function results:" << std::endl;

	for (auto i = 0U; i < v.size(); ++i)
	{
		run_function(v[i], x, y);
	}
}