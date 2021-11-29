#include<iostream>


template <typename function, typename...args>
auto call(function f, args...a)
{
	return f(a...);
}

auto sum(double x, double y)
{
	 return x + y;
}

auto max(double x, double y)
{
	return (x > y) ? x : y;
}

int main()
{
	std::cout << call(sum, 1, 2.0) << std::endl;
	std::cout << call(max, 1.0, 2) << std::endl;

	return 0;
}
