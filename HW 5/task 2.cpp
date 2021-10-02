#include <iostream>
#include <cmath>
class Energy
{
public:
	Energy() : joule(0.0)
	{}

	Energy(double e) : joule(e)
	{}

	void print_joule()
	{
		std::cout << joule << " joules" << std::endl;
	}

	void print_erg()
	{
		std::cout << joule * joule_to_erg << " ergs" << std::endl;
	}

	void print_electronvolt()
	{
		std::cout << joule * joule_to_electronvolt << " electronvolts" << std::endl;
	}

	void set_joule(double e)
	{
		joule = e;
	}

	void set_erg(double e)
	{
		joule = e / joule_to_erg;
	}

	void set_electronvolt(double e)
	{
		joule = e / joule_to_electronvolt;
	}

private:
	double joule;
	static inline const double joule_to_erg = 10000000.0;
	static inline const double joule_to_electronvolt = 6.241506 * pow(10, 18);

};

int main()
{
	Energy e_m;
	std::cout << "Enter 1 (joule) or 2 (erg) or 3 (electronvolt): ";
	int n;
	std::cin >> n;
	double e;
	std::cout << "Enter value: ";
	std::cin >> e;
	(n == 1) ? e_m.set_joule(e) : (n == 2) ? e_m.set_erg(e) : e_m.set_electronvolt(e);

	e_m.print_joule();
	e_m.print_erg();
	e_m.print_electronvolt();

	return(0);
}