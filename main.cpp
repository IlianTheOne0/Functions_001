#include <iostream>
#include <conio.h>
#include <random>

using std::cout;
using std::endl;
using std::cin;
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;

unsigned long long* get_size()
{
	unsigned long long* size = new unsigned long long;

	cout << "Enter the size of array: ";
	cin >> *size;

	return size;
}

int* allocate_arr(unsigned long long size)
{
	return new int[size];
}

void init_arr(int* arr, unsigned long long size)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(0, 50);

	for (int* ptr = arr; ptr < arr + size; ptr++)
	{
		*ptr = dist(gen);
	}
}

void print_arr(int* arr, unsigned long long size)
{
	for (int* ptr = arr; ptr < arr + size; ptr++)
	{
		cout << *ptr << " ";
	}
	cout << endl;
}

void delete_arr(int* arr)
{
	delete[] arr;
	arr = nullptr;
}

int main()
{
	unsigned long long* size = get_size();
	int* arr = allocate_arr(*size);
	init_arr(arr, *size);
	print_arr(arr, *size);
	delete_arr(arr);

	char ch = _getch();
	return 0;
}