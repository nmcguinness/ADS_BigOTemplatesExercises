/*****************************************************************//**
 * \file   ADS_BigOTemplatesExercises.cpp
 * \brief  Selected solutions to the BigO and Templates exercises in Moodle
 *
 * \author NMCG
 * \date   November 2021
 *********************************************************************/
#include <iostream>
#include <list>
#include "BigO.h"

#include "templates_exercises.h"
#include "ADS_Array.h"
#include "GenericPair.h"
#include "GenericArray.h"
#include <functional>

using namespace std;

//BigO
void exercisesBigO();

//templates
void exercisesTemplates();
void templates_exercise1();
void templates_exercise2();
void templates_exercise3();
void templates_exercise4();
void templates_exercise5();

//functors
bool isOdd(int value);
bool isGreaterThan(int value);
bool isInRangeAndMultipleOf(int value /*, int lo, int hi, int multiple*/);
int searchGreaterThan(list<int> list, int floor);

template<typename E>
int search(list<E> list, bool (*pPredicate)(E));
template<typename Iter, typename E>
int search(Iter start, Iter end, bool (*pPredicate)(E));
template<typename E>
int search(list<E> list, function<bool(E)> predicate);
template<typename Iter, typename E>
int search(Iter start, Iter end, function<bool(E)> predicate);

void demoSearchFunction();
void demoSearchFunctionUsingPointer();
void demoSearchFunctionUsingFunction();
void demoSearchFunctor();
void demoSearchLambda();

int main()
{
	cout << "BigO Exercises..." << endl;
	exercisesBigO();

	cout << "Templates Exercises..." << endl;
	exercisesTemplates();

	cout << "Functor Demos..." << endl;
	demoSearchFunction();
	demoSearchFunctionUsingPointer();
	demoSearchFunctionUsingFunction();
	demoSearchFunctor();
	demoSearchLambda();
}

/*************************** BigO Exercises ***************************/
void exercisesBigO()
{
	//add solutions and code to call solutions to BigO exercises here...
}

/*************************** Templates Exercises ***************************/

void exercisesTemplates()
{
	cout << endl << "templates_exercise1..." << endl;
	templates_exercise1();

	cout << endl << "templates_exercise2..." << endl;
	templates_exercise2();

	cout << endl << "templates_exercise3..." << endl;
	templates_exercise3();

	//why dont you try solving exercise 4?
	cout << endl << "templates_exercise4..." << endl;
	templates_exercise4();

	cout << endl << "templates_exercise5..." << endl;
	templates_exercise5();
}

/// @brief A simple class to demonstrate that max, min, and print functions are generic
class Fruit {
public:
	string name;
	double weight;

	Fruit(string name, double weight) : name(name), weight(weight) {};

	int operator<(const Fruit& other) const {
		return (abs(this->weight - other.weight) < 0) ? true : false;
	}

	int operator>(const Fruit& other) const {
		//notice how we call < operator from this operator but invert (!) the result
		return !(*this < other);
	}

	friend ostream& operator<<(ostream& os, const Fruit& fruit) {
		os << fruit.name << "," << fruit.weight;
		return os;
	}
};

/// @brief Write a template function that finds the larger of two template parameters of the same type
void templates_exercise1()
{
	Fruit f1("apple", 0.8);
	Fruit f2("pineapple", 1.4);

	cout << "Max(int):" << ads_max(3, 15) << endl;
	cout << "Max(string):" << ads_max("adam", "zachary") << endl;
	cout << "Max(Fruit):" << ads_max(f1, f2) << endl;
}

/// @brief Write a template function that finds the smaller of two template parameters of the same type
void templates_exercise2()
{
	Fruit f1("apple", 0.8);
	Fruit f2("pineapple", 1.4);

	cout << "Min(int):" << ads_min(3, 15) << endl;
	cout << "Min(string):" << ads_min("adam", "zachary") << endl;
	cout << "Min(Fruit):" << ads_min(f1, f2) << endl;
}

/// @brief Write a template function that will print a list of elements of any type
void templates_exercise3()
{
	Fruit f1("apple", 0.8);
	Fruit f2("pineapple", 1.4);

	list<Fruit> fruitList = { f1, f2 };

	ads_print(fruitList);
}

///@brief demo defining an unscoped enum (i.e. an enum where enumerators (e.g. Daily) are globally visible)
///@see https://www.walletfox.com/course/darkercornerscpp_scopedenum.php
enum EPaymentType {
	Yearly, Monthly, Weekly, Daily
};

///@brief demo defining a scoped enum (i.e. an enum where enumerators (e.g. Gold) are not globally visible)
///@see https://www.walletfox.com/course/darkercornerscpp_scopedenum.php
enum class ESubscriptionType {
	Platinum, Gold, Silver
};

/// @brief Demo showing the use of an unscoped enum
void doSomething() {
	int x = static_cast<int>(Yearly);
	EPaymentType pT1 = Daily;
};

/// @brief Demo using a struct in our GenericPair
struct Account {
	string name;
	double subscription;
	ESubscriptionType subType; //warning on unintialized enum

	//TODO - implement << and < and >= operators
	friend ostream& operator<<(ostream& os, const Account& rhs) {
		os << rhs.name << ","
			<< rhs.subscription << ","
			<< static_cast<int>(rhs.subType);
		//<< (int)rhs.subType;  //does NOT throw a catchable exception
		return os;
	}

	bool operator >=(const Account& rhs) {
		return this->subscription >= rhs.subscription
			&& this->subType >= rhs.subType;
	}

	bool operator <(const Account& rhs) {
		return !(*this >= rhs);
	}
};

/// @brief Write a template
void templates_exercise4()
{
	//simple demo
	GenericPair<string, double> gp1("apple", 0.65);
	cout << gp1 << endl;

	//demo with struct and enum
	Account acc1;
	acc1.name = "Jane Bloggs";
	acc1.subscription = 14.99;
	acc1.subType = ESubscriptionType::Silver;
	GenericPair<int, Account> gp2(12345, acc1);
	cout << gp2 << endl;
}

void templates_exercise5()
{
	//an array of ints
	GenericArray<int> intArray(5, -1);

	//try print
	intArray.print();

	//try get and SUCCEED
	try {
		cout << intArray.get(0);
	}
	catch (invalid_argument e) {
		cerr << e.what() << endl;
	}

	//try get and FAIL
	try {
		cout << intArray.get(-10000);
	}
	catch (invalid_argument e) {
		cerr << e.what() << endl;
	}
}

/*************************** Functors ***************************/

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

class IsInRangeAndMultipleOf {
private:
	int lo, hi, multiple;

public:
	IsInRangeAndMultipleOf(int lo, int hi, int multiple) : lo(lo), hi(hi), multiple(multiple) {};

	bool operator()(int value) {
		return (value > lo) && (value < hi) && (value % multiple == 0);
	}
};

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
	for (int i : list) {
		if (pPredicate(i))
			return index;
		index++;
	}
	return -1;
}

template<typename Iter, typename E>
int search(Iter start, Iter end, bool (*pPredicate)(E)) {
	int index = 0;
	for (int i : list) {
		if (pPredicate(i))
			return index;
		index++;
	}
	return -1;
}

template<typename E>
int search(list<E> list, function<bool(E)> predicate) {
	int index = 0;
	for (int i : list) {
		if (predicate(i))
			return index;
		index++;
	}
	return -1;
}

template<typename Iter, typename E>
int search(Iter start, Iter end, function<bool(E)> predicate) {
	int index = 0;
	for (int i : list) {
		if (predicate(i))
			return index;
		index++;
	}
	return -1;
}

void demoSearchFunction() {
	list<int> populationList = { 234, 456, 1200, 1607, 210 };

	int index = searchGreaterThan(populationList, 1000);
	cout << "demoSearchFunction: " << index << endl;
}

void demoSearchFunctionUsingPointer() {
	list<int> populationList = { 234, 456, 1200, 1607, 210 };

	//make a pointer to a function - the syntax is difficult to read!
	bool (*pFuncA)(int) = &isGreaterThan;
	int index = search<int>(populationList, pFuncA);
	cout << "demoSearchFunctionUsingPointer: " << index << endl;
}

void demoSearchFunctionUsingFunction() {
	list<int> populationList = { 234, 456, 1200, 1607, 210 };

	//replace the pointer to a function syntax with easier to read using function<>
	function<bool(int)> pFuncB = isOdd;
	int index = search<int>(populationList, pFuncB);
	cout << "demoSearchFunctionUsingFunction: " << index << endl;
}

void demoSearchFunctor() {
	list<int> populationList = { 234, 456, 1200, 1607, 210 };

	//replace the pointer or function flavours above with a functor (i.e. an object that can store a predicate AND additional fields/values used by the predicate)
	IsInRangeAndMultipleOf pred(400, 1000, 2);
	int index = search<int>(populationList, pred);
	cout << "demoSearchFunctor: " << index << endl;
}

void demoSearchLambda() {
}