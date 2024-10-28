#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
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

int main()
{
    string str;
    cout << "Enter string:" << endl;
    getline(cin, str);

    string Str = Spaces(str);
    cout << "Processed string: \"" << Str << "\"" << endl;

    return 0;
}
