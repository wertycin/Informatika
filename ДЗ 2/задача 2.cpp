#include <iostream>
#include <vector>

int main()
{
	int n, k;
	std::vector <int> v;
	std::cout << "enter the number of numbers: ";
	std::cin >> n;
	for (auto i = 0U; i < n; ++i)
	{
		std::cin >> k;
		v.push_back(k);
	}
	for (auto i = 0U; i < n; ++i)
	{
		for (auto j = i; j > 0U && v[j - 1] > v[j]; --j)
		{
			std::swap(v[j - 1], v[j]);
		}
	}
	
	std::cout << "sorted array:" << '\n';

	for (auto i = 0U; i < n; ++i)
	{
		std::cout << v[i] << '\n';
	}
}
