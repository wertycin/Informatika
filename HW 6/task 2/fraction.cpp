#pragma once
#include"header.hpp"

namespace Fraction
{

	int lcm(int x, int y)
	{
		return x / std::gcd(x, y) * y;
	}

	std::ostream& operator<<(std::ostream& out, const fraction& x)
	{
		if (x.n != 0)
		{
			int g = 1;
			if (x.n > 0) g = std::gcd(x.n, x.m);
			if (x.n < 0) g = std::gcd(-1 * x.n, x.m);
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
		if (a.m == 0) throw std::invalid_argument("Error: division by zero!\n");
		if (s != '/') throw std::domain_error("Error: This is not a fraction!\n");
		int g = std::gcd(a.n, a.m);
		if (g != 1) { a.n = a.n / g; a.m = a.m / g; };
		return x;
	}

	fraction fraction::operator+=(const fraction& b)
	{
		n = n * b.m + m * b.n;
		m = m * b.m;
		int g = std::gcd(n, m);
		if (g != 1) { n = n / g; m = m / g; };
		return *this;
	}

	fraction fraction::operator-=(const fraction& b)
	{
		n = n * b.m - m * b.n;
		m = m * b.m;
		int g = std::gcd(n, m);
		if (g != 1) { n = n / g; m = m / g; };
		return *this;
	}

	fraction fraction::operator*=(const fraction& b)
	{
		n *= b.n;
		m *= b.m;
		int g = std::gcd(n, m);
		if (g != 1) { n = n / g; m = m / g; };
		return *this;
	}

	fraction fraction::operator/=(const fraction& b)
	{
		n *= b.m;
		m *= b.n;
		int g = std::gcd(n, m);
		if (g != 1) { n = n / g; m = m / g; };
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
