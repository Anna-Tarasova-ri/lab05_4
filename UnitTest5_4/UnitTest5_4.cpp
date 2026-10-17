#include "pch.h"
#include "CppUnitTest.h"
#include "../PR5_4/pr5_4.cpp"   // підключаємо файл з функціями S0..S4

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest54
{
    TEST_CLASS(UnitTest54)
    {
    public:
        const double eps = 1e-9;

        // k = 0, N = 6: (0*0+1*1+...+6*6) / 36 = 91/36
        TEST_METHOD(TestIterative)
        {
            Assert::AreEqual(91.0 / 36.0, S0(0, 6), eps);
        }

        TEST_METHOD(TestRecDownIncreasing_S1)
        {
            Assert::AreEqual(91.0 / 36.0, S1(0, 6, 0), eps);
        }

        TEST_METHOD(TestRecDownDecreasing_S2)
        {
            Assert::AreEqual(91.0 / 36.0, S2(0, 6, 6), eps);
        }

        TEST_METHOD(TestRecUpIncreasing_S3)
        {
            Assert::AreEqual(91.0 / 36.0, S3(0, 6, 0, 0), eps);
        }

        TEST_METHOD(TestRecUpDecreasing_S4)
        {
            Assert::AreEqual(91.0 / 36.0, S4(0, 6, 6, 0), eps);
        }

        // k = 1, N = 3: (1+4+9) / (1+9) = 1.4
        TEST_METHOD(TestAllMethods_k1_N3)
        {
            Assert::AreEqual(1.4, S0(1, 3), eps);
            Assert::AreEqual(1.4, S1(1, 3, 1), eps);
            Assert::AreEqual(1.4, S2(1, 3, 3), eps);
            Assert::AreEqual(1.4, S3(1, 3, 1, 0), eps);
            Assert::AreEqual(1.4, S4(1, 3, 3, 0), eps);
        }

        // k = N = 2: один доданок 4 / (4+4) = 0.5
        TEST_METHOD(TestSingleTerm)
        {
            Assert::AreEqual(0.5, S0(2, 2), eps);
            Assert::AreEqual(0.5, S1(2, 2, 2), eps);
            Assert::AreEqual(0.5, S2(2, 2, 2), eps);
            Assert::AreEqual(0.5, S3(2, 2, 2, 0), eps);
            Assert::AreEqual(0.5, S4(2, 2, 2, 0), eps);
        }

        // Усі рекурсивні варіанти мають збігатися з ітераційним
        TEST_METHOD(TestRecursiveEqualsIterative)
        {
            int k = 2, N = 9;
            double expected = S0(k, N);
            Assert::AreEqual(expected, S1(k, N, k), eps);
            Assert::AreEqual(expected, S2(k, N, N), eps);
            Assert::AreEqual(expected, S3(k, N, k, 0), eps);
            Assert::AreEqual(expected, S4(k, N, N, 0), eps);
        }
    };
}