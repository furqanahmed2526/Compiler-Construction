#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main() {
    // Array of numbers
    string numbers[] = { "8e4", "5e-2", "6e9" };

    // Regular expression pattern
    regex pattern("\\d+e[-+]?\\d+");

    // Iterate through numbers
    for (const auto &num : numbers) {
        // Check if the number matches the pattern
        if (regex_match(num, pattern)) {
            cout << num << " is a valid number." << endl;
        } else {
            cout << num << " is not a valid number." << endl;
        }
    }

    return 0;
}

