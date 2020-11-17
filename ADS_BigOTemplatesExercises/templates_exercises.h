#pragma once

//templates - exercise 1
template <typename T>
T max(T x, T y) {
	return x > y ? x : y;
}

//templates - exercise 2
template <typename T>
T min(T x, T y) {
	return x < y ? x : y;
}

//templates - exercise 3
template <typename E>
void print(list<E> list) {
	for (E value : list) {
		cout << value << endl;
	}
}