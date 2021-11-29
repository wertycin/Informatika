#pragma once
#include<iostream>
#include<stdexcept>
#include<numeric>

namespace Fraction
{
	int lcm(int x, int y);

	class fraction
	{
	public:
		fraction() : n(0), m(1) {};
		
		fraction(int a, int b = 1) : n(a), m(b)
		{
				if (b == 0) throw std::domain_error("Error: division by zero!\n");
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
