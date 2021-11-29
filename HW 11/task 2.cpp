#include<iostream>
#include<type_traits>
template<typename T>
struct add_const { using type = T const; };

template<typename T>
struct remove_const { using type = T; };

template<typename T>
struct remove_const<T const> { using type = T; };



int main()
{
	std::cout << std::boolalpha;
	int x = 1;
	int* const y = &x;
	std::cout << std::is_const_v<decltype(y)> << std::endl;
	if (std::is_const_v<decltype(y)>)
	{
		std::cout << std::is_const_v<remove_const<decltype(y)>::type> << std::endl;
	}
	else
	{
		std::cout << std::is_const_v<add_const<decltype(y)>::type> << std::endl;
	}

	return 0;
}
