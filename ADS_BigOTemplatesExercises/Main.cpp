/*****************************************************************//**
 * \file   ADS_BigOTemplatesExercises.cpp
 * \brief  Selected solutions to the BigO and Templates exercises in Moodle
 *         also includes unit tests, secure delete, and functor, function pointer, and lambda demos
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
#include "AdvancedConcepts.h"

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
void demoSearchFunction();
void demoSearchFunctionUsingPointer();
void demoSearchFunctionUsingFunction();
void demoSearchFunctorInts();
void demoSearchFunctorStrings();
void demoSearchLambda();

int main()
{
	cout << endl << "BigO Exercises..." << endl;
	exercisesBigO();
	cout << endl;

	cout << endl << "Templates Exercises..." << endl;
	exercisesTemplates();
	cout << endl;

	cout << endl << "Functor Demos..." << endl;
	demoSearchFunction();
	cout << endl;

	demoSearchFunctionUsingPointer();
	cout << endl;

	demoSearchFunctionUsingFunction();
	cout << endl;

	demoSearchFunctorInts();
	cout << endl;

	demoSearchFunctorStrings();
	cout << endl;

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
	GenericArray<int> intArray(5, 2021); //default = 2021

	//try print
	intArray.print();

	//try get and SUCCEED
	try {
		cout << intArray.get(0) << endl;
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

/*************************** Function Pointers, Functors & Lambdas  ***************************/

//BAD
/// @brief Demos a search method that is sub-optimal in its implementation because it...
/// 1. A very specific search
/// 2. Only searches through a list
/// 3. Only searches through ints
/// Surely there must be a better way!? :(
void demoSearchFunction() {
	list<int> populationList = { 234, 456, 1200, 1607, 210 };

	int index = searchGreaterThan(populationList, 1000);
	cout << "demoSearchFunction: " << index << endl;
}

//BETTER
/// @brief Demos a search method that is sub-optimal in its implementation because it...
/// 1. Only searches through a list with a predicate (isGreaterThan) that has a built in value of 1000
/// Surely there must be a better way!? :(
void demoSearchFunctionUsingPointer() {
	list<int> populationList = { 234, 456, 1200, 1607, 210 };

	//make a pointer to a function - the syntax is difficult to read!
	bool (*pFuncA)(int) = &isGreaterThan;
	int index = search<int>(populationList, pFuncA);
	cout << "demoSearchFunctionUsingPointer: " << index << endl;
}

//EVEN BETTER
/// @brief Demos a search method that is sub-optimal in its implementation because it...
/// 1. Only searches through a list with a predicate (isOdd) that cannot have additional search criteria included (e.g. odd and multiples of 5)
/// Surely there must be a better way!? :(
void demoSearchFunctionUsingFunction() {
	list<int> populationList = { 234, 456, 1200, 1607, 210 };

	//replace the pointer to a function syntax with easier to read using function<>
	function<bool(int)> pFuncB = isOdd;
	int index = search<int>(populationList, pFuncB);
	cout << "demoSearchFunctionUsingFunction: " << index << endl;
}

//BEST
/// @brief Demos a search method that is the best solution thus far because it...
/// 1. Uses a predicate (see operator() in IsInRangeAndMultipleOf) and a class (IsInRangeAndMultipleOf) that allows me to add additional search criteria for use by the predicate
void demoSearchFunctorInts() {
	list<int> populationList = { 234, 456, 1200, 1607, 210 };

	//replace the pointer or function flavours above with a functor (i.e. an object that can store a predicate AND additional fields/values used by the predicate)
	//notice how we are now able to write a predicate with additional data (lo, hi, multiple) and package the predicate in a functor
	IsInRangeAndMultipleOf predicate(400, 1000, 2);
	int index = search<int>(populationList, predicate);
	cout << "demoSearchFunctorInts: " << index << endl;
}

void demoSearchFunctorStrings() {
	list<string> passwordList = { "1", "abcdef", "ASg33SD2fws", "nonumbers", "tooshort" };

	//find the first password string with correct length (10,32) and alphanumeric
	StringConstraints predicate("^[a-zA-Z0-9]+$", 10, 32);
	int index = search<string>(passwordList, predicate);
	cout << "demoSearchFunctorStrings: " << index << endl;
}

void demoSearchLambda() {
}