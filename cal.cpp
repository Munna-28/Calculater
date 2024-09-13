#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

// Helper functions to perform operations and precedence check
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

float applyOperation(float a, float b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': 
            if (b == 0) {
                throw invalid_argument("Error: Division by zero");
            }
            return a / b;
        default: return 0;
    }
}

// Function to evaluate the expression
float evaluate(const string& expression) {
    stack<float> values;   // Stack to store values
    stack<char> ops;       // Stack to store operators
    int i = 0;

    while (i < expression.length()) {
        // Skip whitespace
        if (isspace(expression[i])) {
            i++;
            continue;
        }

        // If the current token is a number, push it to the value stack
        if (isdigit(expression[i])) {
            float val = 0;
            while (i < expression.length() && (isdigit(expression[i]) || expression[i] == '.')) {
                if (expression[i] == '.') {
                    i++;
                    float decimalPart = 0;
                    float place = 0.1;
                    while (i < expression.length() && isdigit(expression[i])) {
                        decimalPart += (expression[i] - '0') * place;
                        place /= 10;
                        i++;
                    }
                    val += decimalPart;
                    break;
                }
                val = (val * 10) + (expression[i] - '0');
                i++;
            }
            values.push(val);
        }
        // If the current token is an operator
        else if (expression[i] == '+' || expression[i] == '-' ||
                 expression[i] == '*' || expression[i] == '/') {
            while (!ops.empty() && precedence(ops.top()) >= precedence(expression[i])) {
                float val2 = values.top(); values.pop();
                float val1 = values.top(); values.pop();
                char op = ops.top(); ops.pop();

                values.push(applyOperation(val1, val2, op));
            }
            // Push current operator to ops stack
            ops.push(expression[i]);
            i++;
        }
    }

    // Apply remaining operations in stacks
    while (!ops.empty()) {
        float val2 = values.top(); values.pop();
        float val1 = values.top(); values.pop();
        char op = ops.top(); ops.pop();

        values.push(applyOperation(val1, val2, op));
    }

    // The final result is in the values stack
    return values.top();
}

int main() {
    string expression;
    cout << "Enter an expression : ";
    getline(cin, expression);

    try {
        float result = evaluate(expression);
        cout << "Result: " << result << endl;
    } catch (const exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}
