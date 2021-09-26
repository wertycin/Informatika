#include <iostream>

struct Date_and_Time // битовое поле
{
	Date_and_Time() : year(2000), month(1), day(1), hour(0), minute(0), millisecond(0)
	{}
	
	//~Time():
	//{}

	Date_and_Time(unsigned int y, unsigned int m, unsigned int d, unsigned int h, unsigned int min, unsigned int s, unsigned int ms) :
		year(y), month(m), day(d), hour(h), minute(min), second(s), millisecond(ms)
	{}

	void Print_Date()
	{
		std::cout << "Year: " << year << std::endl << "Month: " << month << std::endl << "Day: " << day << std::endl;
	}

	void Print_Time()
	{
		std::cout << "Hour: " << hour << std::endl << "Minute: " << minute << std::endl << "Second: " << second << std::endl << "Millisecond: " << millisecond << std::endl;
	}

	unsigned int year : 11;
	unsigned int month : 4;
	unsigned int day : 5;
	unsigned int hour : 5;
	unsigned int minute : 6;
	unsigned int second : 6;
	unsigned int millisecond : 10;
};

int main()
{
	unsigned int y, m, d, h, min, s, ms;
	bool flag_date, flag_time;

	std::cout << "Enter year: ";
	std::cin >> y;
	std::cout << "Enter month: ";
	std::cin >> m;
	std::cout << "Enter day: ";
	std::cin >> d;
	std::cout << "Enter hour: ";
	std::cin >> h;
	std::cout << "Enter minute: ";
	std::cin >> min;
	std::cout << "Enter second: ";
	std::cin >> s;
	std::cout << "Enter millisecond: ";
	std::cin >> ms;

	Date_and_Time t(y, m, d, h, min, s, ms);

	std::cout << std::endl << "Do you want to print the date? (true/false): ";
	std::cin >> std::boolalpha >> flag_date;
	
	if (flag_date)
	{
		t.Print_Date();
		std::cout << std::endl;
	}

	std::cout << std::endl << "Do you want to print the time? (true/false): ";
	std::cin >> std::boolalpha >> flag_time;

	if (flag_time)
	{
		t.Print_Time();
		std::cout << std::endl;
	}
	
	system("pause");
	return(0);
}