#include"header.hpp"

using namespace Fraction;

int main()
{
	try
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
	}
	catch (const std::domain_error& exception)
	{
		std::cerr << exception.what() << std::endl;
	}
	catch (const std::invalid_argument& exception)
	{
		std::cerr << exception.what() << std::endl;
	}
	return 0;
}
