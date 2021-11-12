#pragma once

//templates - exercise 1
template <typename T>
T ads_max(T x, T y) {
	return x > y ? x : y; //ternary operator (3 operands)
}

//templates - exercise 2
template <typename T>
T ads_min(T x, T y) {
	return x < y ? x : y;
}

//templates - exercise 3
template <typename E>
void ads_print(list<E> list) {
	for (E value : list) {
		cout << value << endl;
	}
}

template <typename Iter>
void ads_print(Iter iter, Iter end) {
	while (iter != end) {
		cout << *iter << endl;
		iter++;
	}
}

template <typename T>
T add(T x, T y) {
	return x + y;
}

//templates - exercise 6
template <typename T>
int binarySearch(T* list, int size, T target)
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

//templates - exercise 6
template <typename T>
int linearSearch(T* list, int size, T target)
{
	for (int x = 0; x < size; x++)
		if (list[x] == target) return x;

	return -1;
}