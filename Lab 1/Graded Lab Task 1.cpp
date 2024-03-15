
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    char operation;
    double num;

    cout << "Welcome to Scientific Calculator!" << endl;
    cout << "Enter operation: (sin, cos, tan, log): ";
    cin >> operation;

    cout << "Enter number: ";
    cin >> num;

    switch (operation) {
        case 's':
        case 'S':
            cout << "Sine of " << num << " is: " << sin(num) << endl;
            break;
        case 'c':
        case 'C':
            cout << "Cosine of " << num << " is: " << cos(num) << endl;
            break;
        case 't':
        case 'T':
            cout << "Tangent of " << num << " is: " << tan(num) << endl;
            break;
        case 'l':
        case 'L':
            cout << "Natural logarithm of " << num << " is: " << log(num) << endl;
            break;
        default:
            cout << "Invalid operation! Please choose from sin, cos, tan, log." << endl;
    }

    return 0;
}

