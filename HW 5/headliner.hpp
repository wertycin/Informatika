#pragma once
#include <iostream>
#include <string>
#include <vector>
class Roman_rulers
{
	friend void lived_at_the_same_time(const Roman_rulers&, const Roman_rulers&);
public:
	Roman_rulers(const std::string& n, const int b, const int d) :
		name(n), birth(b), death(d)
	{}
	void print_years_of_life();
private:
	int birth, death;
	std::string name;
};

