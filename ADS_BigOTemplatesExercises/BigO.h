/*****************************************************************//**
 * \file   BigO.h
 * \brief  Provides timing function used to measure performance of a function.
 * This file also contains some common algorithm (search, sort, factorial)
 * implementations which you can use the measureTime function with.
 *
 * \author DF
 * \date   October 2020
 *********************************************************************/
#include <iostream>
#include <list>
#include <chrono>
using namespace std;

template <typename FuncType>
double measureTime(FuncType func);

int binarySearch(int* list, int size, int target);
int linearSearch(int* list, int size, int value);
void printFirstItem(int arrayOfItems[]);
void bubbleSort(int arr[], int size);
void factorial(int i);

/// @brief A template function to measure the time, in nanoseconds, that a function takes to execute
/// @tparam FuncType A struct or class which implements the function call operator (i.e. is a functor)
/// @param func A functor which calls the target method in the operator()(){} code
/// @return Time in nanoseconds for the function called by the functor to execute
template <typename FuncType>
double measureTime(FuncType func)
{
	std::chrono::time_point<std::chrono::high_resolution_clock> st = std::chrono::high_resolution_clock::now();
	func();
	std::chrono::time_point<std::chrono::high_resolution_clock> end = std::chrono::high_resolution_clock::now();
	return (end - st) / std::chrono::nanoseconds(1);
}

int binarySearch(int* list, int size, int target)
{
	int min = 0, max = size - 1, mid = 0;
	bool found = false;
	while (!found && min <= max)
	{
		mid = (min + max) / 2; // (integer div!)
		if (list[mid] == target)
			found = true;
		else if (target < list[mid])
			max = mid - 1;
		else min = mid + 1;
	}
	if (found) return mid;
	else return -1;
}

int linearSearch(int* list, int size, int target)
{
	for (int x = 0; x < size; x++)
		if (list[x] == target) return x;

	return -1;
}

void printFirstItem(int arrayOfItems[])
{
	cout << arrayOfItems[0] << endl;
}

void bubbleSort(int arr[], int size)
{
	int n = size;
	int tmp = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < (n - i - 1); j++) {
			if (arr[j] > arr[j + 1]) {
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

void factorial(int i)
{
	int sum = 0;
	for (int x = i; x > 0; x--)
	{
		sum += x;
	}
	cout << sum << endl;

	if (i > 0)
		factorial(i - 1);
	else
		return;
}
