#include <iostream>
#include <unordered_map>
#include <sstream>
#include <cctype>

using namespace std;

// Token types
enum TokenType {
    INT, IDENTIFIER, PLUS, MINUS, MULTIPLY, DIVIDE, SEMICOLON, LPAREN, RPAREN, END
};

// Token structure
struct Token {
    TokenType type;
    string value;
};

// Lexer class
class Lexer {
private:
    string input;
    size_t position;
public:
    Lexer(const string& input) : input(input), position(0) {}

    // Get the next token
    Token getNextToken() {
        while (position < input.size()) {
            char currentChar = input[position];
            if (isspace(currentChar)) {
                position++;
                continue;
            }
            if (isdigit(currentChar)) {
                return {INT, parseInteger()};
            }
            if (isalpha(currentChar)) {
                return {IDENTIFIER, parseIdentifier()};
            }
            switch (currentChar) {
                case '+':
                    position++;
                    return {PLUS, "+"};
                case '-':
                    position++;
                    return {MINUS, "-"};
                case '*':
                    position++;
                    return {MULTIPLY, "*"};
                case '/':
                    position++;
                    return {DIVIDE, "/"};
                case ';':
                    position++;
                    return {SEMICOLON, ";"};
                case '(':
                    position++;
                    return {LPAREN, "("};
                case ')':
                    position++;
                    return {RPAREN, ")"};
                default:
                    cerr << "Invalid character: " << currentChar << endl;
                    exit(EXIT_FAILURE);
            }
        }
        return {END, ""};
    }

private:
    // Parse an integer
    string parseInteger() {
        string result;
        while (position < input.size() && isdigit(input[position])) {
            result += input[position++];
        }
        return result;
    }

    // Parse an identifier
    string parseIdentifier() {
        string result;
        while (position < input.size() && (isalnum(input[position]) || input[position] == '_')) {
            result += input[position++];
        }
        return result;
    }
};

// Parser class
class Parser {
private:
    Lexer lexer;
    Token currentToken;

public:
    Parser(Lexer& lexer) : lexer(lexer), currentToken(lexer.getNextToken()) {}

    // Parse the entire program
    void parseProgram() {
        while (currentToken.type != END) {
            parseStatement();
        }
    }

private:
    // Parse a statement
    void parseStatement() {
        switch (currentToken.type) {
            case INT:
                parseVariableDeclaration();
                break;
            case IDENTIFIER:
                parseAssignment();
                break;
            default:
                parseExpressionStatement();
                break;
        }
    }

    // Parse a variable declaration
    void parseVariableDeclaration() {
        match(INT);
        match(IDENTIFIER);
        match(SEMICOLON);
    }

    // Parse an assignment
    void parseAssignment() {
        match(IDENTIFIER);
        match("=");
        parseExpression();
        match(SEMICOLON);
    }

    // Parse an expression statement
    void parseExpressionStatement() {
        parseExpression();
        match(SEMICOLON);
    }

    // Parse an expression
    void parseExpression() {
        parseTerm();
        while (currentToken.type == PLUS || currentToken.type == MINUS) {
            getNextToken();
            parseTerm();
        }
    }

    // Parse a term
    void parseTerm() {
        parseFactor();
        while (currentToken.type == MULTIPLY || currentToken.type == DIVIDE) {
            getNextToken();
            parseFactor();
        }
    }

    // Parse a factor
    void parseFactor() {
        if (currentToken.type == INT) {
            match(INT);
        } else if (currentToken.type == IDENTIFIER) {
            match(IDENTIFIER);
        } else if (currentToken.type == LPAREN) {
            match(LPAREN);
            parseExpression();
            match(RPAREN);
        } else {
            cerr << "Unexpected token: " << currentToken.value << endl;
            exit(EXIT_FAILURE);
        }
    }

    // Match a token and advance to the next one
    void match(TokenType expectedType) {
        if (currentToken.type == expectedType) {
            currentToken = lexer.getNextToken();
        } else {
            cerr << "Expected token type: " << expectedType << ", got: " << currentToken.type << endl;
            exit(EXIT_FAILURE);
        }
    }

    // Match a token value and advance to the next one
    void match(const string& expectedValue) {
        if (currentToken.value == expectedValue) {
            currentToken = lexer.getNextToken();
        } else {
            cerr << "Expected token value: " << expectedValue << ", got: " << currentToken.value << endl;
            exit(EXIT_FAILURE);
        }
    }

    // Get the next token
    void getNextToken() {
        currentToken = lexer.getNextToken();
    }
};

int main() {
    string input = "int x; int y; x = 10; y = 5; int z; z = x + y * 2;";

    Lexer lexer(input);
    Parser parser(lexer);

    parser.parseProgram();

    cout << "Parsing successful!" << endl;

    return 0;
}

