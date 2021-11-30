#include<iostream>

template <int N>
struct F
{
	static inline const int value = F <N - 1>::value + F<N-2>::value;
};

template <>
struct F <1>
{
	static inline const int value = 1;
};

template<>
struct F <2>
{
	static inline const int value = 1;
};

template < int n >
int F_v = F<n>::value;



int main()
{
	const int x = F_v<10>;
	std::cout << x;
	return 0;
}
