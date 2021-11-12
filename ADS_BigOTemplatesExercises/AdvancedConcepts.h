#pragma once
#include <functional>
#include <regex>

/// @brief A file containing methods to demonstrate predicates, functors, and lambda functions

/************************************ Predicates ************************************/
bool isOdd(int value) {
	return value % 2 == 1;
}
bool isGreaterThan(int value) {
	return value > 1000;
}

//this predicate is really bad because it contains hard-coded values used in the predicate condition
//is there a solution? yes - make a functor (or lambda function) instead - see class below
bool isInRangeAndMultipleOf(int value /*, int lo, int hi, int multiple*/) {
	return value > 50 && value < 200 && value % 7 == 0;
}

/************************************ Predicates ************************************/

/// @brief A function to test if an int is in range [lo,hi] and a multiple of a value
class IsInRangeAndMultipleOf {
private:
	int lo, hi, multiple;

public:
	IsInRangeAndMultipleOf(int lo, int hi, int multiple) : lo(lo), hi(hi), multiple(multiple) {};

	bool operator()(int value) {
		return (value > lo) && (value < hi) && (value % multiple == 0);
	}
};

/// @brief A functor to test if a string satisfies a set of constraints (regex, length)
/// @see //See https://www.softwaretestinghelp.com/regex-in-cpp/
class StringConstraints {
private:

	string strRegex;
	int minLength, maxLength;

public:
	StringConstraints(string strRegex, int minLength, int maxLength) : strRegex(strRegex), minLength(minLength), maxLength(maxLength) {};

	bool operator()(string target) {
		int length = target.length();
		if (length < this->minLength || length > this->maxLength)
			return false;

		return regex_match(target, regex(strRegex));
	}
};

/************************************ Functions that use Predicates, Functors, Lambdas ************************************/
//Write one search function to rule them all!
	//Remove the specific search predicate (i.e. a search function that returns true based on a condition)
	//Pass a function as an argument
	//Make a template version for not just ints!
	//Remove the specific data structure and replace with iterators
int searchGreaterThan(list<int> list, int floor) {
	int index = 0;
	for (int i : list) {
		if (i > floor)
			return index;
		index++;
	}
	return -1;
}

template<typename E>
int search(list<E> list, bool (*pPredicate)(E)) {
	int index = 0;
	for (E i : list) {
		if (pPredicate(i))
			return index;
		index++;
	}
	return -1;
}

template<typename Iter, typename E>
int search(Iter start, Iter end, bool (*pPredicate)(E)) {
	int index = 0;
	for (E i : list) {
		if (pPredicate(i))
			return index;
		index++;
	}
	return -1;
}

template<typename E>
int search(list<E> list, function<bool(E)> predicate) {
	int index = 0;
	for (E i : list) {
		if (predicate(i))
			return index;
		index++;
	}
	return -1;
}

template<typename Iter, typename E>
int search(Iter start, Iter end, function<bool(E)> predicate) {
	int index = 0;
	for (E i : list) {
		if (predicate(i))
			return index;
		index++;
	}
	return -1;
}
