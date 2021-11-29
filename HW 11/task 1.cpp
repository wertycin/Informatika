#include<iostream>

template<typename>
struct is_function : std::false_type { };

// specialization for regular functions
template<typename Ret, typename... Args>
struct is_function<Ret(Args...)> : std::true_type {};

// specialization for function types that have cv-qualifiers
template<typename Ret, typename... Args>
struct is_function<Ret(Args...) const> : std::true_type {};
template<typename Ret, typename... Args>
struct is_function<Ret(Args...) volatile> : std::true_type {};
template<typename Ret, typename... Args>
struct is_function<Ret(Args...) const volatile> : std::true_type {};


// specialization for function types that have ref-qualifiers
template<typename Ret, typename... Args>
struct is_function<Ret(Args...)&> : std::true_type {};
template<typename Ret, typename... Args>
struct is_function<Ret(Args...) const&> : std::true_type {};
template<typename Ret, typename... Args>
struct is_function<Ret(Args...) volatile&> : std::true_type {};
template<typename Ret, typename... Args>
struct is_function<Ret(Args...) const volatile&> : std::true_type {};
template<typename Ret, typename... Args>
struct is_function<Ret(Args...)&&> : std::true_type {};
template<typename Ret, typename... Args>
struct is_function<Ret(Args...) const&&> : std::true_type {};
template<typename Ret, typename... Args>
struct is_function<Ret(Args...) volatile&&> : std::true_type {};
template<typename Ret, typename... Args>
struct is_function<Ret(Args...) const volatile&&> : std::true_type {};


template <typename... Types>
bool is_function_v = is_function<Types...>::value;

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
	std::cout << is_function_v<decltype(a)> << std::endl;
	std::cout << is_function_v<decltype(f)> << std::endl;
	return 0;
}
