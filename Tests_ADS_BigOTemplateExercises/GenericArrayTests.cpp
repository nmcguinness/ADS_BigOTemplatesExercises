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

		TEST_METHOD(TestSizePass)
		{
			GenericArray<string> strArray(5, "default");

			Assert::AreEqual(strArray.size(), 5);
		}

		TEST_METHOD(TestSizeFail)
		{
			try
			{
				GenericArray<string> strArray(-1, "default");
				Assert::Fail(L"Length was negative but no exception has been thrown!");
			}
			catch (invalid_argument e) {
				cout << e.what() << endl;
			}
		}

		TEST_METHOD(TestSizeLarge)
		{
			GenericArray<string> strArray(1E6, "default");
			Assert::AreEqual(strArray.size(), 1000000);
		}

		TEST_METHOD(TestGetPass)  //0 <= index < length
		{
			GenericArray<string> strArray(5, "default");
			strArray.add("alan", 0);
			strArray.add("bob", 1);
			strArray.add("ciara", 2);
			strArray.add("david", 3);
			//strArray.add("erica", 4);

			string target = "alan";
			Assert::AreEqual(strArray.get(0), target);  //(const char*, const char_t*)

			target = "default";
			Assert::AreEqual(strArray.get(4), target);  //(const char*, const char_t*)
		}

		TEST_METHOD(TestGetOutOfLimitsLow)
		{
			GenericArray<string> strArray(5, "default");
			strArray.add("alan", 0);
			strArray.add("bob", 1);
			strArray.add("ciara", 2);
			strArray.add("david", 3);
			strArray.add("erica", 4);

			try {
				string s = strArray.get(-1);
				Assert::Fail(L"Index was negative but no exception has been thrown!");
			}
			catch (invalid_argument e) {
				cout << e.what() << endl;
			}
		}

		TEST_METHOD(TestGetOutOfLimitsHigh)
		{
			GenericArray<string> strArray(5, "default");
			strArray.add("alan", 0);
			strArray.add("bob", 1);
			strArray.add("ciara", 2);
			strArray.add("david", 3);
			strArray.add("erica", 4);

			try {
				string s = strArray.get(5);
				Assert::Fail(L"Index was too large but no exception has been thrown!");
			}
			catch (invalid_argument e) {
				cout << e.what() << endl;
			}
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