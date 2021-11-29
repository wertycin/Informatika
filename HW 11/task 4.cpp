#include<iostream>
template <bool b, typename T = void>
struct enable_if {};

template <typename T>
struct enable_if<true, T>
{
	using type = T;
};

template <bool b, typename T = void>
using enable_if_t = typename enable_if<b, T>::type;

int main()
{
	std::cout << typeid(enable_if_t<true, int>).name() << std::endl;
	return 0;
}
