#pragma once
#include "headliner.hpp"

void Roman_rulers::print_years_of_life()
	{
		std::cout << name << " was born in ";
		(birth >= 0) ? std::cout << birth << " AC" : std::cout << abs(birth) << " BC";

		std::cout << " and died in ";

		(death >= 0)? std::cout << death << " AC" : std::cout << abs(death) << " BC";
	
		std::cout << std::endl << std::endl;
	}

void lived_at_the_same_time(const Roman_rulers& ruler_1, const Roman_rulers& ruler_2)
{
	(ruler_1.birth < ruler_2.death&& ruler_2.birth < ruler_1.death) ?
		std::cout << ruler_1.name << " and " << ruler_2.name << " lived at the same time" << std::endl << std::endl
		: std::cout << ruler_1.name << " and " << ruler_2.name << " did't live at the same time" << std::endl << std::endl;
}


