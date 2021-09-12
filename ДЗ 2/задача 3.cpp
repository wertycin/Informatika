#include <iostream>
#include <vector>
#include <iomanip>
int main()
{
	int n, k, key;
	std::vector <int> v;
	bool answer = 0;
	std::cout << "enter key: ";
	std::cin >> key;
	std::cout << '\n' << "enter the number of numbers in SORTED array: ";
	std::cin >> n;
	std::cout << "enter numbers, each on a new line" << '\n';
	for (auto i = 0U; i < n; ++i)
	{
		std::cin >> k;
		v.push_back(k);
	}
	
	int left = 0, right = n - 1, mid;

	while ((left <= right) && (answer != true)) {
		mid = (left + right) / 2;

		if (v[mid] == key)
		{
			answer = true;
		}
		if (v[mid] > key)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	std::cout << std::boolalpha << answer;
}