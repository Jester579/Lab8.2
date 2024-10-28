#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include <algorithm>
#include <cctype>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

string Spaces(const string& s)
{
	size_t start = s.find_first_not_of(' ');
	if (start == string::npos)
		return "";

	size_t end = s.find_last_not_of(' ');

	string trimmed = s.substr(start, end - start + 1);

	auto new_end = unique(trimmed.begin(), trimmed.end(), [](char a, char b) {
		return isspace(a) && isspace(b);
		});
	trimmed.erase(new_end, trimmed.end());

	return trimmed;
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
