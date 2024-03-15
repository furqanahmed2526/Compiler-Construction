#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// Function to tokenize a string
vector<string> tokenize(const string& str, char delim) {
    vector<string> tokens;
    stringstream ss(str);
    string token;
    while (getline(ss, token, delim)) {
        tokens.push_back(token);
    }
    return tokens;
}

// Lexical analyzer class
class LexicalAnalyzer {
private:
    string buffer1;
    string buffer2;

public:
    LexicalAnalyzer(const string& input) : buffer1(input), buffer2() {}

    // Read characters from buffer1 and fill buffer2
    void readNextChunk() {
        // Read characters from input source into buffer2
        // For this example, we will simulate reading from input
        // by using a static string as the source
        static string inputSource = "int main() { return 0; }";
        buffer2 = inputSource;
    }

    // Tokenize the current buffer
    vector<string> tokenizeCurrentBuffer(char delim) {
        return tokenize(buffer1, delim);
    }

    // Tokenize the next buffer
    vector<string> tokenizeNextBuffer(char delim) {
        return tokenize(buffer2, delim);
    }
};

int main() {
    LexicalAnalyzer lexer("input_text");
    
    // Read and tokenize the first buffer
    lexer.readNextChunk();
    vector<string> tokens1 = lexer.tokenizeCurrentBuffer(' ');

    // Process and tokenize the second buffer
    vector<string> tokens2 = lexer.tokenizeNextBuffer(' ');

    // Output tokens from both buffers
    cout << "Tokens from first buffer:" << endl;
    for (const auto& token : tokens1) {
        cout << token << endl;
    }

    cout << "\nTokens from second buffer:" << endl;
    for (const auto& token : tokens2) {
        cout << token << endl;
    }

    return 0;
}

