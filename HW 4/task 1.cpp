#include <iostream>
#include <string>
#include <cmath>
struct Roman_rulers // структура "Правители Древнего Рима"
{
	int birth, death;
	std::string name;

	Roman_rulers(): name("Name"), birth(0), death(0) 
	// имя, год рождения, год смерти, год начала правления, год окончания правления
	{}

	~Roman_rulers()
	{}

	Roman_rulers(const std::string& n, const int b, const int d) : // конструктор
		name(n), birth(b), death(d)
	{}

	void print_years_of_life() // функция, которая выводит годы жизни правителя
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
};

void lived_at_the_same_time(Roman_rulers ruler_1, Roman_rulers ruler_2) // функция, отвечающая на вопрос, жили ли два правителя в одно и то же время
{
	(ruler_1.birth < ruler_2.death && ruler_2.birth < ruler_1.death) ?
		std::cout << ruler_1.name << " and " << ruler_2.name << " lived at the same time" << std::endl << std::endl
	: std::cout << ruler_1.name << " and " << ruler_2.name << " did't live at the same time" << std::endl << std::endl;
}

int main()
{
	Roman_rulers
		Gaius_Julius_Caesar{ "Gaius Julius Caesar", -100, -44, },
		Gnaeus_Pompeius_Magnus{ "Gnaeus Pompeius Magnus", -106, -48 },
		Caesar_Augustus{ "Caesar Augustus", -63, 14 },
		Marcus_Antonius{ "Marcus Antonius", -83, -30 },
		Tiberius_Caesar_Augustus{ "Tiberius Caesar Augustus", -42, 37 },
		Caligula{ "Caligula", 12, 41 };


	lived_at_the_same_time(Gaius_Julius_Caesar, Gnaeus_Pompeius_Magnus);

	lived_at_the_same_time(Gaius_Julius_Caesar, Caligula);

	Tiberius_Caesar_Augustus.print_years_of_life();

	Marcus_Antonius.print_years_of_life();

}