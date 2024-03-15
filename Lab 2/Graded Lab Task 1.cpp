#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main() {
    // Input string containing logical operators
    string input = "x || y && (z == 10) != (a <= b)";

    // Regular expression pattern to match logical operators
    regex pattern("(\\|\\||&&|==|!=|<=|>=)");

    // Counter for the number of matches
    int count = 0;

    // Iterator for searching the input string
    sregex_iterator it(input.begin(), input.end(), pattern);
    sregex_iterator end;

    // Loop through matches and count them
    while (it != end) {
        count++;
        ++it;
    }

    // Output the number of matches found
    cout << "Number of logical operators found: " << count << endl;

    return 0;
}

