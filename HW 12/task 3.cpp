#include<iostream>

constexpr double e_n(double d)
{
	double e = 1;
	double f = 1;
	int k = 1;
	while (1/f > d)
	{
		e = e + (1 / f);
		k = k + 1;
		f = f * k;
	}
	return e;
}

int main()
{
	constexpr double epsilon = 0.0000001;
	constexpr double x = e_n(epsilon);
	std::cout << x << std::endl;
	return 0;
}
