#include "pch.h"
#include "CppUnitTest.h"
#include <bitset>
#include "../lab2/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        bool booleanFunction(int p, int q, int r) {
            return (p || q) && (p || r);
        }

        TEST_METHOD(TestBooleanFunction)
        {
            Assert::AreEqual(booleanFunction(0, 0, 0), false);
            Assert::AreEqual(booleanFunction(0, 0, 1), false);
            Assert::AreEqual(booleanFunction(0, 1, 0), false);
            Assert::AreEqual(booleanFunction(0, 1, 1), true);
            Assert::AreEqual(booleanFunction(1, 0, 0), true);
            Assert::AreEqual(booleanFunction(1, 0, 1), true);
            Assert::AreEqual(booleanFunction(1, 1, 0), true);
            Assert::AreEqual(booleanFunction(1, 1, 1), true);
        }

        TEST_METHOD(TestLogicalOperations)
        {
            bool p, q;

            p = true;
            q = false;

            bool expectedAnd = p && q;
            bool expectedOr = p || q;
            bool expectedXor = p ^ q;
            bool expectedImplication = !p || q;
            bool expectedEquivalence = (p && q) || (!p && !q);

            Assert::AreEqual(expectedAnd, false);
            Assert::AreEqual(expectedOr, true);
            Assert::AreEqual(expectedXor, true);
            Assert::AreEqual(expectedImplication, false);
            Assert::AreEqual(expectedEquivalence, false);
        }

        TEST_METHOD(TestBitwiseOperations)
        {
            std::bitset<8> b1("11111000");
            std::bitset<8> b2("10100110");

            std::bitset<8> expectedOr = b1 | b2;
            std::bitset<8> expectedAnd = b1 & b2;
            std::bitset<8> expectedXor = b1 ^ b2;

            Assert::AreEqual(expectedOr.to_ulong(), std::bitset<8>("11111110").to_ulong());
            Assert::AreEqual(expectedAnd.to_ulong(), std::bitset<8>("10100000").to_ulong());
            Assert::AreEqual(expectedXor.to_ulong(), std::bitset<8>("01011110").to_ulong());
        }
    };
}