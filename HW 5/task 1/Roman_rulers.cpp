#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Header.h"

class Roman_rulers
{
	public:
	Roman_rulers() : name("Name"), birth(0), death(0)

	{}

	~Roman_rulers()
	{}

	Roman_rulers(const std::string& n, const int b, const int d) :
		name(n), birth(b), death(d)
	{}

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

	int birth, death;
	std::string name;

};
