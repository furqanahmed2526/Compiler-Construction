#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main() {
    // Input string containing floating-point numbers
    string input = "1.23456 123.4567 12345.67890 12.3456789";

    // Regular expression pattern to match floating-point numbers with length not greater than 6
    regex pattern("\\b\\d+\\.\\d{0,6}\\b");

    // Iterator for searching the input string
    sregex_iterator it(input.begin(), input.end(), pattern);
    sregex_iterator end;

    // Output the matches found
    cout << "Floating-point numbers with length not greater than 6:" << endl;
    while (it != end) {
        cout << it->str() << endl;
        ++it;
    }

    return 0;
}

