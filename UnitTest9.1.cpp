#include "pch.h"
#include "CppUnitTest.h"
#include <math.h>

// підключаємо модулі з основного проєкту 
#include "../ап 9.1/var.cpp"
#include "../ап 9.1/dod.cpp"
#include "../ап 9.1/sum.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace nsVar;

const double PI = 3.14159265358979323846;

namespace UnitTest1
{
    TEST_CLASS(TestArcctg)
    {
    public:

        // перевірка рекурентного співвідношення: a1 = x^3 / 3 при x = 0.5
        TEST_METHOD(TestDod)
        {
            x = 0.5;
            n = 1;
            a = -x;                       // a0 = -x
            nsDod::dod();                 // a1
            Assert::AreEqual(0.125 / 3.0, a, 1e-12);
        }

        // x = 0: arcctg(0) = pi/2
        TEST_METHOD(TestSumZero)
        {
            x = 0;
            e = 0.0001;
            nsSum::sum();
            Assert::AreEqual(PI / 2, s, 1e-9);
        }

        // x = 0.5: arcctg(0.5) = pi/2 - atan(0.5)
        TEST_METHOD(TestSumHalf)
        {
            x = 0.5;
            e = 1e-6;
            nsSum::sum();
            Assert::AreEqual(PI / 2 - atan(0.5), s, 1e-5);
        }

        // x = -0.7: від'ємний аргумент
        TEST_METHOD(TestSumNegative)
        {
            x = -0.7;
            e = 1e-6;
            nsSum::sum();
            Assert::AreEqual(PI / 2 - atan(-0.7), s, 1e-5);
        }

        // x = 1: край області збіжності, arcctg(1) = pi/4
        TEST_METHOD(TestSumOne)
        {
            x = 1;
            e = 0.001;
            nsSum::sum();
            Assert::AreEqual(PI / 4, s, 0.002);
        }

        // кількість доданків n має бути більшою за 0
        TEST_METHOD(TestCountN)
        {
            x = 0.5;
            e = 1e-6;
            nsSum::sum();
            Assert::IsTrue(n > 0);
        }
    };
}