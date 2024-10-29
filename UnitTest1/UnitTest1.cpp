#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include <algorithm>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

string Spaces(const string& s) {
    string result = s;

    result.erase(result.begin(), find_if(result.begin(), result.end(), [](char ch) {
        return ch != ' ';
        }));

    result.erase(find_if(result.rbegin(), result.rend(), [](char ch) {
        return ch != ' ';
        }).base(), result.end());

    auto new_end = unique(result.begin(), result.end(), [](char a, char b) {
        return a == ' ' && b == ' ';
        });
    result.erase(new_end, result.end());

    return result;
}

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{

			string str = "   1111 1 1   1 11   ";
			string expected = "1111 1 1 1 11";

			Assert::AreEqual(expected, Spaces(str));
		}
	};
}
