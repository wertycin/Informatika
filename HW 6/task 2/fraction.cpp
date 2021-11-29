#pragma once
#include"header.hpp"

namespace Fraction
{

	void easy(int& n, int& m)
	{
		int g = std::gcd(n, m);
		n = n / g; m = m / g;
		if (m < 0) { n = -n; m = -m; };
	};
	

	std::ostream& operator<<(std::ostream& out, const fraction& x)
	{
		if (x.n % x.m != 0)
		{
			out << x.n << '/' << x.m;
			return out;
		}
		else
		{
			out << x.n / x.m;
			return out;
		}
	}
	std::istream& operator>>(std::istream& x, fraction& a)
	{
		char s;
		x >> a.n >> s >> a.m;
		if (a.m == 0) throw std::invalid_argument("Error: division by zero!\n");
		if (s != '/') throw std::domain_error("Error: This is not a fraction!\n");
		easy(a.n, a.m);
		return x;
	}

	fraction fraction::operator+=(const fraction& b)
	{
		n = n * b.m + m * b.n;
		m = m * b.m;
		easy(n, m);
		return *this;
	}

	fraction fraction::operator-=(const fraction& b)
	{
		n = n * b.m - m * b.n;
		m = m * b.m;
		easy(n, m);
		return *this;
	}

	fraction fraction::operator*=(const fraction& b)
	{
		n *= b.n;
		m *= b.m;
		easy(n, m);
		return *this;
	}

	fraction fraction::operator/=(const fraction& b)
	{
		n *= b.m;
		m *= b.n;
		easy(n, m);
		if (m == 0) throw std::invalid_argument("Error: division by zero!\n");
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
