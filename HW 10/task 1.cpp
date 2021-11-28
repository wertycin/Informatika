#include<iostream>
#include<vector>
#include<any>


template <typename...Types>
	int Size1(Types...args)
	{
		return (sizeof(args) + ...);
	}



int Size2()
{
	return 0;
}
template <typename Type, typename ... Types>
	int Size2(Type arg, Types ... args)
	{
		return sizeof(arg) + Size2(args...);
	}


int main()
{

	std::cout << Size1('a', 1, 1.f) << std::endl;
	std::cout << Size2('a', 1, 1.f);
	return 0;
}
