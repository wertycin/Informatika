#include"header.hpp"

using namespace Fraction;
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
	std::cout << "x after x += y: " << (x += y);
	return 0;
}
