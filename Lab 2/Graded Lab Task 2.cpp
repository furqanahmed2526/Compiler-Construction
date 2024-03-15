#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main() {
    // Input string containing relational operators
    string input = "x < y && y >= z || a == b";

    // Regular expression pattern to match relational operators
    regex pattern("(==|!=|<=|>=|<|>)");

    // Iterator for searching the input string
    sregex_iterator it(input.begin(), input.end(), pattern);
    sregex_iterator end;

    // Output the matches found
    cout << "Relational operators found:" << endl;
    while (it != end) {
        cout << it->str() << endl;
        ++it;
    }

    return 0;
}

