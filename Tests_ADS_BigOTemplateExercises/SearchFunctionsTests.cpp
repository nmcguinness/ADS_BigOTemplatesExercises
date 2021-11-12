#include "pch.h"
#include "CppUnitTest.h"
#include "../ADS_BigOTemplatesExercises/TemplateExercises.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestsADSBigOTemplateExercises
{
	struct Student {
		string name;
		int age;

		Student(string name, int age) : name(name), age(age) {};

		//if we want to use search then we must implement whatever operators the search function use (e.g. >, <, ==,  !=)
		bool operator==(const Student& rhs) {
			return this->age == rhs.age; //simple age comparison
		}
	};

	TEST_CLASS(SearchFunctionsTests)
	{
	public:

		TEST_METHOD(GenericLinearSearchForIntPass)
		{
			//create an array of ints
			int myData[] = { 2,5,6,1,8,9,21 };
			//int* pData = myData; //a pointer to array
			int size = sizeof(myData) / sizeof(myData[0]);

			//call the search
			int result = linearSearch<int>(myData, size, 1);  //TODO - why?

			//assert based on result
			Assert::AreEqual(result, 3);
		}

		TEST_METHOD(GenericLinearSearchForIntFail)
		{
			//create an array of ints
			int myData[] = { 2,5,6,1,8,9,21 };
			int size = sizeof(myData) / sizeof(myData[0]);

			//call the search for invalid value
			int result = linearSearch<int>(myData, size, -100000);

			//assert based on result
			Assert::AreEqual(result, -1);
		}

		TEST_METHOD(GenericBinarySearchForIntPass)
		{
			//create an array of ints
			int myData[] = { 2,5,6,1,8,9,21 };
			//int* pData = myData; //a pointer to array
			int size = sizeof(myData) / sizeof(myData[0]);

			//call the search
			int result = binarySearch<int>(myData, size, 1);  //TODO - why?

			//assert based on result
			Assert::AreEqual(result, 3);
		}

		TEST_METHOD(GenericBinarySearchForIntFail)
		{
			//create an array of ints
			int myData[] = { 2,5,6,1,8,9,21 };
			int size = sizeof(myData) / sizeof(myData[0]);

			//call the search for invalid value
			int result = binarySearch<int>(myData, size, -100000);

			//assert based on result
			Assert::AreEqual(result, -1);
		}

		TEST_METHOD(GenericLinearSearchForStructPass)
		{
			//create an array of Students
			Student myData[] = { Student("anna", 21), Student("bob", 34), Student("ciara", 26) };
			int size = sizeof(myData) / sizeof(myData[0]);

			//call the search for invalid value
			int result = linearSearch<Student>(myData, size, Student("ciara", 26));

			//assert based on result
			Assert::AreEqual(result, 2);
		}

		TEST_METHOD(GenericLinearSearchForStructFail)
		{
			//create an array of Students
			Student myData[] = { Student("anna", 21), Student("bob", 34), Student("ciara", 26) };
			int size = sizeof(myData) / sizeof(myData[0]);

			//call the search for invalid value
			int result = linearSearch<Student>(myData, size, Student("mark", 9999999));

			//assert based on result
			Assert::AreEqual(result, -1);
		}
	};
}