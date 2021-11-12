#include "pch.h"
#include "CppUnitTest.h"
#include "../ADS_BigOTemplatesExercises/templates_exercises.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestsADSBigOTemplateExercises
{
	TEST_CLASS(SearchFunctionsTests)
	{
	public:

		TEST_METHOD(AddTestPass)
		{
			int result = add<int>(3, 2);
		}

		TEST_METHOD(GenericLinearSearchForIntPass)
		{
			//create an array of ints
			int myData[] = { 2,5,6,1,8,9,21 };
			//int* pData = myData; //a pointer to array
			int size = sizeof(myData) / sizeof(myData[0]);

			//call the search
			int result = linearSearch<int>(myData, size, 1);

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

		TEST_METHOD(GenericLinearSearchForStructPass)
		{
		}

		TEST_METHOD(GenericLinearSearchForStructFail)
		{
		}
	};
}