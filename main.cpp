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

void _add(int*& arr, unsigned long long& size);
void _insert(int*& arr, unsigned long long& size);
void _delete(int*& arr, unsigned long long& size);

unsigned long long* get_size()
{
	unsigned long long* size = new unsigned long long;

	cout << endl
		<< "(Enter zero if you want to exit)" << endl
		<< "Enter the size of array: ";
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

int _selection(int*& arr, unsigned long long& size)
{
	int* selection = new int;
	
	do
	{
		cout << endl
			<< "0. Exit" << endl
			<< "1. Add element in the end of array" << endl
			<< "2. Insert an element at the specified index" << endl
			<< "3. Delete an item at a specified index" << endl
			<< "Enter your choice: ";
		cin >> *selection;
	} while (*selection > 3 || *selection < 0);
	
	switch (*selection)
	{
		case 0: { delete selection; return 4; }; break;
		case 1: { _add(arr, size); }; break;
		case 2: { _insert(arr, size); }; break;
		case 3: { _delete(arr, size); }; break;
	}

	delete selection;
	return 0;
}

void _add(int*& arr, unsigned long long& size)
{
	int* newArr = new int[size + 1];

	for (unsigned long long i = 0; i < size; i++)
	{
		newArr[i] = arr[i];
	}

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(0, 50);

	newArr[size] = dist(gen);
	delete[] arr;
	arr = newArr;
	size++;
}

/*
void _insert(int*& arr, unsigned long long& size)
{
	int* index = new int{};
	
	do
	{
		cout << "Enter the index you want to replace (from 0 to " << size - 1 << "): ";
		cin >> *index;
	} while (*index >= size);
	
	int* newArr = new int[size];
	unsigned long long i = 0;

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(0, 50);
	for (; i < *index; i++)
	{
		newArr[i] = arr[i];
	}
	newArr[*index] = dist(gen);
	for (; i < size; i++)
	{
		newArr[i + 1] = arr[i];
	}

	delete[] arr;
	arr = newArr;

	delete index;
}
*/

void _insert(int*& arr, unsigned long long& size)
{
	int* index = new int{};

	do
	{
		cout << "Enter the index you want to replace (from 0 to " << size - 1 << "): ";
		cin >> *index;
	} while (*index >= size);

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(0, 50);

	arr[*index] = dist(gen);

	delete index;
}

void _delete(int*& arr, unsigned long long& size)
{

}

int main()
{
	do
	{
		unsigned long long* size = get_size();
		if (size == nullptr)
		{
			break;
		}
		int* arr = allocate_arr(*size);
		init_arr(arr, *size);
		print_arr(arr, *size);

		do
		{
			int selection_ = _selection(arr, *size);
			
			if (selection_ == 4)
			{
				system("cls");
				break;
			}

			cout << endl << "Result: ";
			print_arr(arr, *size);
			cout << endl << endl;
		} while (true);
		
		delete_arr(arr);
		delete size;
	} while (true);

	/*char ch = _getch();*/
	return 0;
}