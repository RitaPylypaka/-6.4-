#include "pch.h"
#include "CppUnitTest.h"
#include "../пр6.4рек/пр6.4рек.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest64рек
{
	TEST_CLASS(UnitTest64рек)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{

			const int size = 6;
			int a[size] = { 5,6,7,1,6,3 };
			int k = 3;
			int d = Sum(a, 3, 0, k);
			Assert::AreEqual(d, 18);
		}
	};
}
