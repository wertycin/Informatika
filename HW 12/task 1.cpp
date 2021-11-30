#include<iostream>

template <int N>
struct F
{
	static inline const int value = N * F <N - 1>::value;
};

template <>
struct F <0>
{
	static inline const int value = 1;
};

template < int n >
int F_v = F<n>::value;

template <int n, int k>
struct C
{
	static inline const int value = F_v < n > / ( F_v < k > * F_v < n - k > );
};

template < int n, int k >
int C_v = C<n, k>::value;


int main()
{
	const int x = C_v<5, 3>;
	std::cout << x;
	return 0;
}
