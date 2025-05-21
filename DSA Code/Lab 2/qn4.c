#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack for integers
int stack[MAX];
int top = -1;

// Push to stack
void push(int val) {
    if (top >= MAX - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    stack[++top] = val;
}

// Pop from stack
int pop() {
    if (top < 0) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack[top--];
}

// Check if a string is an operator
int isOperator(char* token) {
    return strlen(token) == 1 && strchr("+-*/", token[0]);
}

// Evaluate a single operation
int evaluate(char op, int a, int b) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': 
            if (b == 0) {
                printf("Division by zero error\n");
                exit(1);
            }
            return a / b;
        default:
            printf("Invalid operator: %c\n", op);
            exit(1);
    }
}

int main() {
    char input[256];
    printf("Enter a prefix expression (space-separated):\n");
    fgets(input, sizeof(input), stdin);

    // Remove newline if present
    input[strcspn(input, "\n")] = '\0';

    // Tokenize input
    char* tokens[MAX];
    int count = 0;
    char* token = strtok(input, " ");
    while (token != NULL) {
        tokens[count++] = token;
        token = strtok(NULL, " ");
    }

    // Traverse from right to left
    for (int i = count - 1; i >= 0; i--) {
        if (isOperator(tokens[i])) {
            // Pop two operands
            int op1 = pop();
            int op2 = pop();
            int result = evaluate(tokens[i][0], op1, op2);
            push(result);
        } else {
            // Push operand
            push(atoi(tokens[i]));
        }
    }

    printf("Evaluated Result: %d\n", pop());
    return 0;
}
