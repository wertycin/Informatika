#include<iostream>
template <bool _Test, class _Ty = void>
struct enable_if {};

template <class _Ty>
struct enable_if<true, _Ty>
{ using type = _Ty; };

template <bool _Test, class _Ty = void>
using enable_if_t = typename enable_if<_Test, _Ty>::type;

int main()
{
	std::cout << typeid(enable_if<true, int>::type).name() << std::endl;
	return 0;
}
