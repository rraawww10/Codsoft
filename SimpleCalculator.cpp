#include <iostream>
using namespace std;

int main() {
    float num1, num2;
    char op;

    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter second number: ";
    cin >> num2;

    cout << "Enter operation (+, -, *, /): ";
    cin >> op;

    switch (op) {
        case '+':
            cout << num1 << " + " << num2 << " = " << (num1 + num2);
            break;
        case '-':
            cout << num1 << " - " << num2 << " = " << (num1 - num2);
            break;
        case '*':
            cout << num1 << " * " << num2 << " = " << (num1 * num2);
            break;
        case '/':
            if (num2 == 0) {
                cout << "Error! Division by zero is not allowed.";
            } else {
                cout << num1 << " / " << num2 << " = " << (num1 / num2);
            }
            break;
        default:
            cout << "Invalid operation!";
            break;
    }

    return 0;
}
