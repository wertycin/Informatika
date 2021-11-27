#include <iostream>
#include <vector>

class Numbers
{
private:
	int * m_data;
	std::size_t m_length;
	std::vector <int> m_vector;

public:
	Numbers();
	Numbers(int i);
	Numbers(const std::vector <int>& v);
	Numbers(const int* array, int array_size);
	~Numbers();
	int number(int i) { return m_data[i]; }
	size_t size() { return m_length; };
	Numbers& operator=(const Numbers& other);
	Numbers& operator=(Numbers&& other);
	Numbers(const Numbers& other);
	Numbers(Numbers&& other);
};

Numbers::Numbers() : m_length(0), m_data(nullptr), m_vector({}) {}

Numbers::Numbers(int i) : m_length(1), m_vector({i})
{
	m_data = new int[m_length];
	m_data[0] = i;
}

Numbers::Numbers(const std::vector <int>& v) : m_length(v.size()), m_vector(v)
{
	m_data = new int[m_length];
	for (auto i = 0U; i < m_length; ++i)
	{
		m_data[i] = m_vector[i];
	}
}

Numbers::Numbers(const int* array, int array_size) : m_length(array_size)
{
	m_data = new int[m_length];
	m_vector.resize(m_length);
	for (auto i = 0U; i < m_length; ++i)
	{
		m_data[i] = array[i];
		m_vector[i] = array[i];
	}
};

Numbers:: ~Numbers()
{
	delete [] m_data;
}

Numbers& Numbers::operator=(const Numbers& other)
{
	if (&other == this)
		return *this;
	m_vector = other.m_vector;
	m_length = other.m_length;
	delete[] m_data;
	m_data = new int[m_length];
	for (auto i = 0U; i < m_length; i++)
	{
		m_data[i] = other.m_data[i];
	}
	return *this;
}
Numbers& Numbers::operator=(Numbers&& other)
{
	m_vector = std::move(other.m_vector);
	m_length = other.m_length;
	m_data = other.m_data;
	other.m_data = nullptr;
	other.m_length = 0;
	return *this;
}

Numbers::Numbers(Numbers&& other) : m_length(other.m_length), m_data(other.m_data), m_vector(std::move(other.m_vector))
{
	other.m_data = nullptr;
	other.m_length = 0;
}

Numbers::Numbers(const Numbers& other) : m_length(other.m_length), m_vector(other.m_vector)
{
	m_data = new int[m_length];
	for (auto i = 0U; i < m_length; i++)
	{
		m_data[i] = other.m_data[i];
	}
}


int main()
{
	std::vector <int> vector = { 0, 2, 4, 6 };
	Numbers n_1(vector);

	int* array = new int[3];
	array[0] = 1;
	array[1] = 3;
	array[2] = 5;
	Numbers n_2(array, 3);
	std::cout << "First element n_1 is " << n_1.number(0) << std::endl;
	std::cout << "Length n_1 is " << n_1.size() << std::endl;

	Numbers n_3(n_1);
	std::cout << "Length n_1 after copying " << n_1.size() << std::endl;
	std::cout << "Length n_3 after copying " << n_3.size() << std::endl;
	Numbers n_4(std::move(n_1));
	std::cout << "Length n_1 after moving " << n_1.size() << std::endl;
	std::cout << "Length n_4 after moving " << n_4.size() << std::endl;
	return 0;
}
