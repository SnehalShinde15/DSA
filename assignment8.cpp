/*Assignment No:8
name-snehal uday shinde
PRN-123B1B264
Assignment Title:Write a program to convert infix expression to postfix, infix expression to prefix and evaluation of postfix and prefix expression.
*/

#include <iostream>
#include <stack>
using namespace std;

// Function to return precedence of an operator
int precedence(char op) {
    if (op == '^')
        return 3; // Highest precedence for the power operator
    if (op == '*' || op == '/')
        return 2; // Higher precedence for multiplication and division
    if (op == '+' || op == '-')
        return 1; // Lowest precedence for addition and subtraction
    return 0;    // Return 0 if it's not an operator
}

// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to convert an infix expression to a postfix expression
void infixToPostfix(char infix[], char postfix[]) {
    stack<char> s; // Stack to hold operators
    int j = 0;     // Index for postfix array

    // Loop through each character in the infix expression
    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        // If the character is an operand (alphanumeric), add it to the postfix expression
        if (isalnum(c)) {
            postfix[j++] = c;
        }
        // If the character is '(', push it onto the stack
        else if (c == '(') {
            s.push(c);
        }
        // If the character is ')', pop from the stack until '(' is encountered
        else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix[j++] = s.top(); // Add the operator to the postfix expression
                s.pop();
            }
            s.pop(); // Remove '(' from the stack
        }
        // If the character is an operator
        else if (isOperator(c)) {
            // Pop from the stack to the postfix expression while the top of the stack has higher or equal precedence
            while (!s.empty() && precedence(s.top()) >= precedence(c)) {
                postfix[j++] = s.top();
                s.pop();
            }
            // Push the current operator onto the stack
            s.push(c);
        }
    }

    // Pop any remaining operators from the stack to the postfix expression
    while (!s.empty()) {
        postfix[j++] = s.top();
        s.pop();
    }
    postfix[j] = '\0'; // Null-terminate the postfix expression
}

int main() {
    char infix[100], postfix[100];

    // Input the infix expression from the user
    cout << "Enter an infix expression: ";
    cin >> infix;

    // Convert the infix expression to postfix
    infixToPostfix(infix, postfix);

    // Output the resulting postfix expression
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
