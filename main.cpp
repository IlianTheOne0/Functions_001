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

void init_arr(int* arr, int size)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dist(-49, 49);

	for (int i = 0; i < size; i++)
	{
		arr[i] = dist(gen);
	}
}

void print_arr(int* arr, const int* size)
{
	cout << "Array: ";
	for (int i = 0; i < *size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

template<typename value>
void print_size(value size)
{
	cout << "Size: " << size << endl;
}

void definder(int* arr, const int* size, int min, int max, int*& new_size, int*& new_arr)
{
	cout << endl;

	for (int i = 0; i < *size; i++)
	{
		if (arr[i] >= min && arr[i] <= max)
		{
			(*new_size)++;
		}
	}

	new_arr = new int[*new_size];
	int index{};

	for (int i = 0; i < *size; i++)
	{
		if (arr[i] >= min && arr[i] <= max)
		{
			new_arr[index] = arr[i];
			index++;
		}
	}
}

void delete_value(int*& value, char indicator)
{
	delete value;
	value = nullptr;
}
void delete_value(int*& arr, bool indicator)
{
	delete[] arr;
	arr = nullptr;
}

int main()
{
	const int size = 10;
	int arr[size]{};
	init_arr(arr, size);

	print_size<const int>(size);
	print_arr(arr, &size);



	int* positive_arr_size = new int{};
	int* negative_arr_size = new int{};
	int* zero_arr_size = new int{};

	int* positive_arr = nullptr;
	int* negative_arr = nullptr;
	int* zero_arr = nullptr;



	definder(arr, &size, 1, 49, positive_arr_size, positive_arr);
	cout << "Positive:" << endl;
	print_size<int>(*positive_arr_size);
	print_arr(positive_arr, positive_arr_size);

	definder(arr, &size, -49, -1, negative_arr_size, negative_arr);
	cout << "Negative:" << endl;
	print_size<int>(*negative_arr_size);
	print_arr(negative_arr, negative_arr_size);

	definder(arr, &size, 0, 0, zero_arr_size, zero_arr);
	cout << "Zero:" << endl;
	print_size<int>(*zero_arr_size);
	print_arr(zero_arr, zero_arr_size);



	delete_value(positive_arr, true);
	delete_value(negative_arr, true);
	delete_value(zero_arr, true);
	delete_value(positive_arr_size, ' ');
	delete_value(negative_arr_size, ' ');
	delete_value(zero_arr_size, ' ');



	char ch = _getch();
	return 0;
}