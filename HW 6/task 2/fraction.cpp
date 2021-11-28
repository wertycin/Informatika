#pragma once
#include"header.hpp"

namespace Fraction
{
	unsigned int gcd(unsigned int x, unsigned int y)
	{
		if (x == y)
			return x;
		if (x > y)
			return gcd(x - y, y);
		return gcd(x, y - x);
	}

	int lcm(int x, int y)
	{
		return x / gcd(x, y) * y;
	}

	std::ostream& operator<<(std::ostream& out, const fraction& x)
	{
		if (x.n != 0)
		{
			int g = 1;
			if (x.n > 0) g = gcd(x.n, x.m);
			if (x.n < 0) g = gcd(-1 * x.n, x.m);
			if (x.m != 1 && x.n % x.m != 0)
			{
				out << x.n / g << '/' << x.m / g;
				return out;
			}
			else
			{
				out << x.n / x.m;
				return out;
			}
		}
		out << 0;
		return out;
	}
	std::istream& operator>>(std::istream& x, fraction& a)
	{
		char s;
		x >> a.n >> s >> a.m;
		if (s != '/')
		{
			std::cout << "Error! This is not a fraction!\n";
		}
		try
		{
			if (a.m == 0) throw std::invalid_argument("Error: division by zero!\n");
			if (s != '/') throw std::domain_error("Error: This is not a fraction!\n");
		}
		catch (const std::domain_error& exception)
		{
			std::cerr << exception.what() << std::endl;
		}
		catch (const std::invalid_argument& exception)
		{
			std::cerr << exception.what() << std::endl;
		}
		return x;
	}

	fraction fraction::operator+=(const fraction& b)
	{
		n = n * b.m + m * b.n;
		m = m * b.m;
		return *this;
	}

	fraction fraction::operator-=(const fraction& b)
	{
		n = n * b.m - m * b.n;
		m = m * b.m;
		return *this;
	}

	fraction fraction::operator*=(const fraction& b)
	{
		n *= b.n;
		m *= b.m;
		return *this;
	}

	fraction fraction::operator/=(const fraction& b)
	{
		n *= b.m;
		m *= b.m;
		return *this;
	}

	fraction operator+ (const fraction& a, const fraction& b)
	{
		fraction c = a;
		return c += b;
	}

	fraction operator- (const fraction& a, const fraction& b)
	{
		fraction c = a;
		return c -= b;
	}

	fraction operator* (const fraction& a, const fraction& b)
	{
		fraction c = a;
		return c *= b;
	}

	fraction operator/ (const fraction& a, const fraction& b)
	{
		fraction c = a;
		return c /= b;
	}
};
