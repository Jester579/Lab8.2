#include <iostream>
#include <string>
#include <algorithm>

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

int main() {
    string str;
    cout << "Enter string:" << endl;
    getline(cin, str);

    string Str = Spaces(str);
    cout << "String: \"" << Str << "\"" << endl;

    return 0;
}
