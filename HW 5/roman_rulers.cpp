#pragma once
#include "headliner.hpp"
class Roman_rulers
{
	friend void lived_at_the_same_time(Roman_rulers, Roman_rulers);
public:
	void print_years_of_life()
	{
		std::cout << name << " was born in ";
		if (birth >= 0)
		{
			std::cout << birth << " AC";
		}
		else
		{
			std::cout << abs(birth) << " BC";
		}
		std::cout << " and died in ";
		if (death >= 0)
		{
			std::cout << death << " AC";
		}
		else
		{
			std::cout << abs(death) << " BC";
		}
		std::cout << std::endl << std::endl;
	}
private:
	int birth, death;
	std::string name;
};

void lived_at_the_same_time(Roman_rulers ruler_1, Roman_rulers ruler_2)
{
	(ruler_1.birth < ruler_2.death&& ruler_2.birth < ruler_1.death) ?
		std::cout << ruler_1.name << " and " << ruler_2.name << " lived at the same time" << std::endl << std::endl
		: std::cout << ruler_1.name << " and " << ruler_2.name << " did't live at the same time" << std::endl << std::endl;
}


