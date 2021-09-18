#include <iostream>
void merge(int* first, int* middle, int* last)
{
    int n = last - first;
    int* deck = new int[n];
    int* left = first;
    int* right = middle;
    for (int* d = deck; d != deck + n; ++d) {
        if (left == middle) *d = *right++;
        else if (right == last) *d = *left++;
        else if (*left < *right) *d = *left++;
        else *d = *right++;
    }

    int* d = deck;
    while (first != middle) *first++ = *d++;
    while (middle != last) *middle++ = *d++;

    delete[] deck;
}


void mergesort(int* first, int* last)
{
    int n = last - first;
    if (n <= 1) return;
    int* middle = first + n / 2;
    mergesort(first, middle);
    mergesort(middle, last);
    merge(first, middle, last);
}

int main()
{
    int n;
    std::cout << "Enter the number of numbers: ";
    std::cin >> n;
    int* a = new int[n];
    for (auto i = 0U; i < n; ++i)
    {
        std::cin >> a[i];
    }
    int* first = a;
    int* last = a + n;
    mergesort(first, last);
    for (auto i = 0U; i < n; ++i)
    {
        std::cout << a[i] << ' ';
    }
    return 0;
}