#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

typedef struct { char data[MAX]; int top; } Stack;

void push(Stack *s, char c) { if (s->top < MAX - 1) s->data[++s->top] = c; }
char pop(Stack *s) { return s->top >= 0 ? s->data[s->top--] : '\0'; }
char peek(Stack *s) { return s->top >= 0 ? s->data[s->top] : '\0'; }
int isOperator(char c) { return strchr("+-*/^", c) != NULL; }
int precedence(char op) { return (op == '^') ? 3 : (op == '*' || op == '/') ? 2 : (op == '+' || op == '-') ? 1 : 0; }

void infixToPostfix(const char *infix, char *postfix) {
    Stack s = {.top = -1};
    int i = 0, k = 0;
    for (; infix[i]; i++) {
        char c = infix[i];
        if (isspace(c)) continue;
        if (isalnum(c)) postfix[k++] = c;
        else if (c == '(') push(&s, c);
        else if (c == ')') {
            while (peek(&s) != '(') postfix[k++] = pop(&s);
            pop(&s);
        }
        else if (isOperator(c)) {
            while (precedence(peek(&s)) >= precedence(c)) postfix[k++] = pop(&s);
            push(&s, c);
        }
    }
    while (s.top != -1) postfix[k++] = pop(&s);
    postfix[k] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter infix expression: ");
    fgets(infix, MAX, stdin);
    infix[strcspn(infix, "\n")] = '\0';
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}
