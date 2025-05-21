#include<stdio.h>

#define SIZE 20

int stack[SIZE];
int top = -1;

void push(int value) {
    if (top < SIZE - 1) {
        top++;
        stack[top] = value;
    } else {
        printf("Stack is full\n");
    }
}

void pop() {
    if (top >= 0) {
        printf("Popped: %d\n", stack[top]);
        top--;
    } else {
        printf("Stack is empty\n");
    }
}

void display() {
    if (top >= 0) {
        printf("Stack: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    } else {
        printf("Stack is empty\n");
    }
}

// New functionalities

void peek() {
    if (top >= 0) {
        printf("Top element: %d\n", stack[top]);
    } else {
        printf("Stack is empty\n");
    }
}

int isFull() {
    return top == SIZE - 1;
}

int isEmpty() {
    return top == -1;
}

int count() {
    return top + 1;
}

void clear() {
    top = -1;
    printf("Stack cleared\n");
}

int main() {
    push(10);
    push(20);
    push(30);
    display(); // Stack: 10 20 30
    pop();     // Popped: 30
    display(); // Stack: 10 20

    peek();    // Top element: 20

    printf("Is stack full? %s\n", isFull() ? "Yes" : "No");
    printf("Is stack empty? %s\n", isEmpty() ? "Yes" : "No");
    printf("Number of items in stack: %d\n", count());

    clear();
    display(); // Stack is empty

    return 0;
}