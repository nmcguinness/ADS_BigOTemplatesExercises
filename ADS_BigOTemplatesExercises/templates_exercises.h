#pragma once

//templates - exercise 1
template <typename T>
T ads_max(T x, T y) {
	return x > y ? x : y;
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