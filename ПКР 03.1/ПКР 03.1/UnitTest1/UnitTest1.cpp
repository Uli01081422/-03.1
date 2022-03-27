#include "pch.h"
#include "CppUnitTest.h"
#include "../ПКР 03.1/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int N = 1;
			Student* s = new Student[N];
			s[0].prizv = "join";
			s[0].kurs = 1;
			s[0].specialty = ІТ;
			s[0].physics = 5;
			s[0].math = 5;
			s[0].informatics = 5;

			double lf = lessfour(s, N);
			Assert::AreEqual(lf, 0.0);

		}
	};
}
