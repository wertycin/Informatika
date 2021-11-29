#include<iostream>

template<class>
struct is_function : std::false_type { };

// specialization for regular functions
template<class Ret, class... Args>
struct is_function<Ret(Args...)> : std::true_type {};

// specialization for function types that have cv-qualifiers
template<class Ret, class... Args>
struct is_function<Ret(Args...) const> : std::true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) volatile> : std::true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) const volatile> : std::true_type {};


// specialization for function types that have ref-qualifiers
template<class Ret, class... Args>
struct is_function<Ret(Args...)&> : std::true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) const&> : std::true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) volatile&> : std::true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) const volatile&> : std::true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...)&&> : std::true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) const&&> : std::true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) volatile&&> : std::true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) const volatile&&> : std::true_type {};


class A
{
	public:
	A(int a) {};
};

void f(A a) {};

int main()
{
	std::cout << std::boolalpha;

	A a(1);
	std::cout << is_function<decltype(a)>::value << std::endl;
	std::cout << is_function<decltype(f)>::value << std::endl;
	return 0;
}
