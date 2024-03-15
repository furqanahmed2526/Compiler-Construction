#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

// Symbol structure to store symbol information
struct Symbol {
    string name;
    int value; // For simplicity, assuming integer values here
    // Add any other attributes as needed
};

// Hash table implementation for the symbol table
class SymbolTable {
private:
    static const int TABLE_SIZE = 10; // Size of the hash table
    vector<list<Symbol>> table; // Hash table implemented using a vector of linked lists

    // Hash function to map symbol names to indices in the hash table
    int hashFunction(const string& name) {
        int sum = 0;
        for (char ch : name) {
            sum += ch;
        }
        return sum % TABLE_SIZE;
    }

public:
    SymbolTable() : table(TABLE_SIZE) {}

    // Insert a symbol into the symbol table
    void insert(const string& name, int value) {
        int index = hashFunction(name);
        table[index].push_back({name, value});
    }

    // Lookup a symbol in the symbol table
    bool lookup(const string& name, int& value) {
        int index = hashFunction(name);
        for (const Symbol& sym : table[index]) {
            if (sym.name == name) {
                value = sym.value;
                return true;
            }
        }
        return false;
    }
};

int main() {
    SymbolTable symbolTable;

    // Insert symbols into the symbol table
    symbolTable.insert("x", 10);
    symbolTable.insert("y", 20);
    symbolTable.insert("z", 30);

    // Lookup symbols in the symbol table
    int value;
    if (symbolTable.lookup("x", value)) {
        cout << "Value of x: " << value << endl;
    } else {
        cout << "Symbol x not found" << endl;
    }

    if (symbolTable.lookup("a", value)) {
        cout << "Value of a: " << value << endl;
    } else {
        cout << "Symbol a not found" << endl;
    }

    return 0;
}

