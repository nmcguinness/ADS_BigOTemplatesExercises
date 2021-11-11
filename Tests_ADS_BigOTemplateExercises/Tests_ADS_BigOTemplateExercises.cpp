#include "pch.h"
#include "CppUnitTest.h"
#include "../ADS_BigOTemplatesExercises/GenericArray.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace TestsADSBigOTemplateExercises
{
	TEST_CLASS(TestsGenericArray)
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
		}

		TEST_METHOD(TestGetPass)  //0 <= index < length
		{
			//get(index)
		}

		TEST_METHOD(TestGetOutOfLimits)
		{
			//get(-1)
			//get(length+1)
		}

		//TEST_METHOD(TestConstructor)
		//{
		//	bool result = false;
		//	Assert::AreEqual(result, false);

		//	std::string x = "xyz";
		//	std::string y = "xyz";
		//	//tests for unique and distinct memory addresses
		//	Assert::AreNotSame(x, y);
		//	Assert::AreEqual(x, y);
		//}
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