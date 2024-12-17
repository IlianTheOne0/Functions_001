#include <iostream>
#include <conio.h>
#include <random>
#include <Windows.h>

using std::cout;
using std::endl;
using std::cin;
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;

void _delete(int*& arr, unsigned long long& size, int* indexes);

unsigned long long* get_size()
{
	unsigned long long* size = new unsigned long long;

	cout << "Enter the size of array: ";
	cin >> *size;

	if (*size != 0)
	{
		return size;
	}

	delete size;
	return nullptr;
}

int* allocate_arr(unsigned long long size)
{
	return new int[size];
}

void init_arr(int* arr, unsigned long long size)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(0, 99);

	cout << "Array: ";
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

void delete_arr(int*& arr, unsigned long long*& size)
{
	delete[] arr;
	delete size;
	arr = nullptr, size = nullptr;
}

void definer(int*& arr, unsigned long long& size)
{
	int* indexes = new int[size]{};

	for (int i = 0; i < size; i++)
	{
		if (arr[i] >= 2) {
			bool prime = true;

			for (int j = 2; j <= sqrt(arr[i]); j++)
			{
				if (arr[i] % j == 0)
				{
					prime = false;
					break;
				}
			}

			if (prime)
			{
				indexes[i] = 1;
			}
		}
	}

	_delete(arr, size, indexes);
	delete[] indexes;
	indexes = nullptr;
}

void _delete(int*& arr, unsigned long long& size, int* indexes)
{
	unsigned long long* amount = new unsigned long long{};
	cout << "Primary numbers: ";
	for (unsigned long long i = 0; i < size; i++)
	{
		if (indexes[i] == 1)
		{
			(*amount)++;
			cout << arr[i] << " ";
		}
	}
	int* new_arr = new int[size - *amount] {};
	cout << endl;

	unsigned long long* number = new unsigned long long{0};
	for (unsigned long long i = 0; i < size; i++)
	{
		if (indexes[i] == 1)
		{
			(*number)++;
		}
		else
		{
			new_arr[i - *number] = arr[i];
		}
	}

	delete[] arr;
	arr = new_arr;

	size -= *amount;

	delete amount;
	delete number;
	amount = nullptr, number = nullptr;
}

int main()
{
	unsigned long long* size = get_size();
	if (size == nullptr)
	{
		return 0;
	}
	int* arr = allocate_arr(*size);
	init_arr(arr, *size);
	print_arr(arr, *size);

	cout << endl;
	definer(arr, *size);
	cout << "Result: ";
	print_arr(arr, *size);
	
	delete_arr(arr, size);
	char ch = _getch();
	return 0;
}