#pragma once
#include<iostream>
#include<stdexcept>

namespace Fraction
{
	unsigned int gcd(unsigned int x, unsigned int y);
	int lcm(int x, int y);

	class fraction
	{
	public:
		fraction() : n(0), m(1) {};
		
		fraction(int a, int b = 1) : n(a), m(b)
		{
			try
			{
				if (b == 0) throw std::domain_error("Error: division by zero!\n");
			}
			catch (const std::domain_error& exception)
			{
				std::cerr << exception.what() << std::endl;
			}
		};

		fraction operator+=(const fraction& b);
		fraction operator-=(const fraction& b);
		fraction operator*=(const fraction& b);
		fraction operator/=(const fraction& b);
		friend std::ostream& operator<<(std::ostream& out, const fraction& x);
		friend std::istream& operator>>(std::istream& x, fraction& a);

		private:
		int n, m;
	};

	fraction operator+(const fraction& a, const fraction& b);
	fraction operator-(const fraction& a, const fraction& b);
	fraction operator*(const fraction& a, const fraction& b);
	fraction operator/ (const fraction& a, const fraction& b);
};
