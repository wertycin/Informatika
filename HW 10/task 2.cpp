#include<iostream>
template <typename T, typename...Args>
	T* ptr(Args...args)
	{
		return  new T(args...);
	}

	class A
	{
	public:
		int i;
		std::string s;
		A(int i, std::string s) : i(i), s(s) {};
	};
int main()
{
	auto* m_ptr = ptr<A> (1, "hello");
	std::cout << typeid(*m_ptr).name() << std::endl;
	std::cout << (*m_ptr).i << '\n' << (*m_ptr).s;
	delete m_ptr;
	return 0;
}
