#include<iostream>

// With virtual:
class Base
{
	public:
	virtual void print()
	{
		std::cout << "printed by Base";
	};
};

class Derivative : public Base
{
	public:
	void print() {
		std::cout << "printed by Derivative";
	}
};

// Without virtual:

template <typename T>
class Base_
{
	public:
	void print()
	{
		static_cast<T*>(this)->print();
	};
};

class Derivative_ : public Base_< Derivative_>
{
	public:
	void print() {
		std::cout << "printed by Derivative_";
	}
};


int main()
{
	// With virtual:
	Derivative* d = new Derivative;
	Base* b = d;
	b->print();

	std::cout << std::endl;
	// Without virtual:
	Derivative_* d_ = new Derivative_;
	Base_<Derivative_>* b_ = d_;
	b_->print();

	return 0;
}
