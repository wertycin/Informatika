#include<iostream>

template< typename T >
void quick_sort(T* arr, int l, int r)
{
	if (r - l < 1) return;
	int k = l;
	for (auto i = l; i < r; i++)
	{
		if (arr[i] <= arr[r])
		{
			std::swap(arr[i], arr[k]);
			k++;
		}
	}
	std::swap(arr[k], arr[r]);
	quick_sort(arr, l, k - 1);
	quick_sort(arr, k + 1, r);
}


template< typename T >
void sort(T* arr, int N )
{
	quick_sort(arr, 0, N - 1);
}

template< typename T, int N >
void sort(T(&arr)[N])
{
	quick_sort(arr, 0, N - 1);
}


int main()
{
	int n = 6;
	const int m = 5;
	char* array_1 = new char[n] { 'q', 'f', 'y', 'z', 't', 'a' };
	int array_2[m] = { 4, 5, 6, 2, 0 };

	sort(array_1, n);
	sort(array_2);

	for (auto i = 0U; i < n; ++i)
	{
		std::cout << array_1[i] << " ";
	}
	std::cout << std::endl;

	for (auto i = 0U; i < 5; i++)
	{
		std::cout << array_2[i] << " ";
	}
	std::cout << std::endl;
	delete[] array_1;
	return 0;
}
