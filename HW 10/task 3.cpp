#include <iostream>

template <typename F, typename ... A>
void call(F function, A  ... args)
{
	function(args...);
}

void sum(int x, double y)
{
	std::cout << "Summary of x and y from called function is: " << x + y;
}


int main()
{
	double x, y;
	std::cin >> x;
	std::cin >> y;

	call(sum, x, y);

	return 0;
}
