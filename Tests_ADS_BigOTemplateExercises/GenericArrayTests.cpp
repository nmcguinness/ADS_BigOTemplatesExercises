#include "pch.h"
#include "CppUnitTest.h"
#include "../ADS_BigOTemplatesExercises/GenericArray.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace TestsADSBigOTemplateExercises
{
	TEST_CLASS(GenericArrayTests)
	{
	public:
		string userName = "jane"; //["","","","",""]

		TEST_METHOD(TestConstructor)
		{
			GenericArray<string> strArray(5, "default");
			Assert::IsNotNull(&strArray); //get the address of object in RAM (because thats what a pointer is)

			//or we could do same as line 17 but slightly more clumsily
			//GenericArray<string>* pArray = &strArray;
			//Assert::IsNotNull(pArray);
		}

		TEST_METHOD(TestSize)
		{
			//ask the user for input?
			Assert::Fail(L"Not yet implemented");
		}

		TEST_METHOD(TestGetPass)  //0 <= index < length
		{
			//get(index
			Assert::Fail(L"Not yet implemented");
		}

		TEST_METHOD(TestGetOutOfLimits)
		{
			//get(-1)
			//get(length+1)
			Assert::Fail(L"Not yet implemented");
		}
	};
}

/*
#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestsADSBigOTemplateExercises
{
	TEST_CLASS(TestsADSBigOTemplateExercises)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
		}
	};
}

*/