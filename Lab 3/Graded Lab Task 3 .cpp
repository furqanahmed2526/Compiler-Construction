#include <iostream>
#include <regex>
#include <string>
#include <vector>

using namespace std;

int main() {
    // Input document
    string document = "The quick brown fox jumps over the lazy dog. Tom and Mary went to the market.";

    // Regular expression pattern
    regex pattern("\\b[tm]\\w*\\b");

    // Vector to store matched words
    vector<string> matches;

    // Iterator for searching the document
    sregex_iterator it(document.begin(), document.end(), pattern);
    sregex_iterator end;

    // Iterate through matches and store them in the vector
    while (it != end) {
        matches.push_back(it->str());
        ++it;
    }

    // Output the matched words
    cout << "Words starting with 't' or 'm':" << endl;
    for (const auto &word : matches) {
        cout << word << endl;
    }

    return 0;
}

