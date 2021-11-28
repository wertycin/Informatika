#include <iostream>

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
	return x/gcd(x, y)*y;
}

class fraction
{
private:
	int n, m;
public:
	fraction()
	{
		n = 0;
		m = 1;
	}
	fraction(int a, int b) : n(a), m(b) {};

	fraction(int a) : n(a), m(1) {};

	friend std::ostream& operator<<(std::ostream& out, const fraction& x)
	{
		if (x.n != 0)
		{
			int g = 1;
			if (x.n > 0) g = gcd(x.n, x.m);
			if (x.n < 0) g = gcd(-1 * x.n, x.m);
			if (x.m != 1 && x.n % x.m != 0) {
				out << x.n / g << '/' << x.m / g;
				return out;
			}
			else {
				out << x.n / x.m;
				return out;
			}
		}
		out << 0;
		return out;
	}
	friend std::istream& operator>>(std::istream& x, fraction& a)
	{
		char s;
		x >> a.n >> s >> a.m;
		if (s != '/')
		{
			std::cout << "Error!\n";
		}
		return x;
	}
	friend const fraction operator+(const fraction& a, const fraction& b)
	{
		fraction c;
		c.m = lcm(a.m, b.m);
		c.n = a.n * (c.m / a.m) + b.n * (c.m / b.m);
		return c;
	}
	friend const fraction operator-(const fraction& a, const fraction& b)
	{
		fraction c;
		c.m = lcm(a.m, b.m);
		c.n = a.n * (c.m / a.m) - b.n * (c.m / b.m);
		return c;
	}
	friend const fraction operator*(const fraction& a, const fraction& b)
	{
		fraction c(a.n * b.n, a.m * b.m);
		return c;
	}
	friend const fraction operator/ (const fraction& a, const fraction& b)
	{
		fraction c(a.n * b.m, b.n * a.m);
		return c;
	}

	void operator-()
	{
		n = -n;
	}
	void operator=(fraction b)
	{
		n = b.n;
		m = b.m;
	}
	void operator=(int a)
	{
		n = a;
		m = 1;
	}
	void operator+=(int b)
	{
		n = b * m + n;
	}
	void operator+=(fraction b)
	{
		fraction c;
		c.m = lcm(this->m, b.m);
		c.n = n * (c.m / m) + b.n * (c.m / b.m);
		n = c.n;
		m = c.m;
	}
	void operator-=(int b)
	{
		n = -b * m + n;
	}
	void operator-=(fraction b)
	{
		fraction c;
		c.m = lcm(m, b.m);
		c.n = n * (c.m / m) - b.n * (c.m / b.m);
		n = c.n;
		m = c.m;
	}
	void operator*=(int b)
	{
		n = b * n;
	}
	void operator*=(fraction b)
	{
		n = n * b.n;
		m = m * b.m;
	}
	void operator/=(int b)
	{
		m = b * m;
	}
	void operator/=(fraction b)
	{
		n = n * b.m;
		m = m * b.n;
	}

	friend const fraction operator+(const fraction& a, const int b)
	{
		fraction c(a.n + b * a.m, a.m);
		return c;
	}
	friend fraction operator-(fraction& a, int b)
	{
		fraction c(a.n - b * a.m, a.m);
		return c;
	}
	friend fraction operator*(fraction& a, int b)
	{
		a.n *= b;
		return a;
	}
	friend fraction operator/(fraction& a, int b)
	{
		a.m *= b;
		return a;
	}
};

int main()
{
	fraction x;
	fraction y;
	std::cin >> x;
	std::cin >> y;

	std::cout << x << '+' << y << '=' << x + y << std::endl;
	std::cout << x << '-' << y << '=' << x - y << std::endl;
	std::cout << x << '*' << y << '=' << x * y << std::endl;
	std::cout << x << '/' << y << '=' << x / y << std::endl;
	return 0;
}
