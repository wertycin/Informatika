#include <iostream>

enum class Month
{
	January,
	February,
	March,
	April,
	May,
	June,
	July,
	August,
	September,
	October,
	November,
	December
};

int main()
{
	bool flag;
	int m;
	std::cout << "Is the year a leap year? (true/false): ";
	std::cin >> std::boolalpha >> std::fixed >> flag;
	std::cout << std::endl << "Enter the month number: ";
	std::cin >> m;
	std::cout << "The number of days in month number " << m << " is ";
	m--;
	Month m_1;
	m_1 = static_cast<Month>(m);
	switch (m_1)
	{
	case Month::January:
	case Month::March:
	case Month::May:
	case Month::July:
	case Month::August:
	case Month::October:
	case Month::December:
		std::cout << 31 << std::endl;
		break;
	case Month::April:
	case Month::June:
	case Month::September:
	case Month::November:
		std::cout << 30 << std::endl;
		break;
	case Month::February:
		if (flag)
		{
			std::cout << 29 << std::endl;
		}
		else
		{
			std::cout << 28 << std::endl;
		}
		break;
	default:
		break;
	}
}