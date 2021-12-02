#include<iostream>
#include<array>

template <int n>
constexpr int f()
{
	std::array <int, n> array{0};
	int i = 0;
	int m = 3;
	array[0] = 2;
	while (array[n - 1] == 0)
	{
		i = 0;
		bool flag = 1;
		for (; array[i] != 0; ++i)
		{
			if (m % array[i] == 0)
			{
				flag = 0;
				break;
			}
		}
		if (flag) { array[i] = m; }
		m+=2;
	}
	return array[n - 1];
}


int main()
{
	constexpr auto x = f<10>();
	std::cout << x;
	return 0;
}
