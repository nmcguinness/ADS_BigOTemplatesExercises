/*****************************************************************//**
 * \file   ADS_BigOTemplatesExercises.cpp
 * \brief  Selected solutions to the BigO and Templates exercises in Moodle
 *
 * \author NMCG
 * \date   November 2020
 *********************************************************************/
#include <iostream>
#include "BigO.h"

#include "templates_exercises.h"
#include "ADS_Array.h"

using namespace std;

//BigO
void exercisesBigO();

//templates
void exercisesTemplates();
void templates_exercise1();
void templates_exercise2();
void templates_exercise3();
void templates_exercise5();

int main()
{
	cout << "BigO Exercises..." << endl;
	exercisesBigO();

	cout << "Templates Exercises..." << endl;
	exercisesTemplates();
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

	cout << endl << "templates_exercise5..." << endl;
	templates_exercise5();
}

/// @brief A simple class to demonstrate that max, min, and print functions are generic
class Fruit {
public:
	string name;
	double weight;

	Fruit(string name, double weight) : name(name), weight(weight) {};

	int operator<(const Fruit& other) {
		return (this->weight - other.weight < 0) ? true : false;
	}
	int operator>(const Fruit& other) {
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

/// @brief Create a template Array class, which implements a dynamic array
void templates_exercise5()
{
	//an array of strings
	ADS_Array<string> arr1(5, "default value");
	arr1.print();

	//an array of integers
	ADS_Array<int> arr2(5, -1);

	//adding some values
	arr2.add(2, 0);
	arr2.add(4, 1);
	arr2.add(8, 2);
	arr2.add(16, 3);
	//arr2.add(32, 4); //leave the last element free to see how print deals with an uninitialized value

	//calling the print
	arr2.print();

	//accessing a value
	cout << arr2.get(3) << endl;
}