#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
	int n, k;
	std::vector <int> v;
	std::cout << "Enter the number of numbers: ";
	std::cin >> n;
	std::cout << '\n' << "Enter numbers: " << std::endl;

	for (auto i = 0; i < n; ++i)
	{
		std::cin >> k;
		v.push_back(k);
	}
	std::sort(v.begin(), v.end(), [](int a, int b) {return a > b;});

	for (int i : v)
	{
		std::cout << i << ' ';
	}

	system("pause");
}