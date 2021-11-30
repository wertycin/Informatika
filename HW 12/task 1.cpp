#include<iostream>

template <int n, int k>
struct C
{
	static inline const int value = C <n - 1, k>::value + C<n - 1, k - 1>::value;
};

template <int n>
struct C <n, 0>
{
	static inline const int value = 1;
};

template <int n>
struct C <n, n>
{
	static inline const int value = 1;
};


template < int n, int k >
int C_v = C<n, k>::value;



int main()
{
	const int x = C_v<5, 3>;
	std::cout << x;
	return 0;
}
