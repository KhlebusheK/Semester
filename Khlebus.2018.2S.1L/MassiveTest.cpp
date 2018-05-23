#include "stdafx.h"
#include "CppUnitTest.h"
#include "Laba.h"
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LabaTest
{		
	TEST_CLASS(MassiveTest)
	{
	public:
		
		TEST_METHOD(Inverse_1)
		{
			int x = 110110;
			int expected = 1001;

			int actual = Massive::Inverse(x);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Inverse_2)
		{
			int x = 10001;
			int expected = 1110;

			int actual = Massive::Inverse(x);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(BinaryTranslation_1)
		{
			int x = -50;
			int expected = 1110;

			int actual = Massive::BinaryTranslation(x);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(BinaryTranslation_2)
		{
			int x = -16;
			int expected = 10000;

			int actual = Massive::BinaryTranslation(x);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Counter_1)
		{
			int x = 1110011000;
			int expected = 0;

			int actual = Massive::Counter(x);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Counter_2)
		{
			int x = 11100110001;
			int expected = 1;

			int actual = Massive::Counter(x);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(CounterDigit_1)
		{
			int x = 123;
			int expected = 3;

			int actual = Massive::CounterDigit(x);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(CounterDigit_2)
		{
			int x = 1000000;
			int expected = 7;

			int actual = Massive::CounterDigit(x);

			Assert::AreEqual(expected, actual);
		}
	};
}