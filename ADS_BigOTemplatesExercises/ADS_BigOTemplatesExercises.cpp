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
#include "ADS_BigOTemplatesExercises.h"

using namespace std;

void exercisesBigO();
void exercisesTemplates();

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
	ADS_Array<string> arr1(5, "blank");
	arr1.print();

	ADS_Array<int> arr2(5, -1);
	arr2.print();
	arr2.add(2, 0);
	arr2.add(4, 1);
	arr2.add(8, 2);
	arr2.add(16, 3);
	arr2.add(32, 4);

	cout << arr2.get(3) << endl;
}