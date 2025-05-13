#include <stdio.h>

// Function to swap using call by value
void swapByValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    printf("Inside swapByValue: a = %d, b = %d\n", a, b);
}

// Function to swap using call by reference
void swapByReference(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x, y;

    printf("Enter two integers: ");
    scanf("%d %d", &x, &y);

    printf("\nBefore swap (main): x = %d, y = %d\n", x, y);

    // Call by value
    swapByValue(x, y);
    printf("After swapByValue (main): x = %d, y = %d\n", x, y);

    // Call by reference
    swapByReference(&x, &y);
    printf("After swapByReference (main): x = %d, y = %d\n", x, y);

    return 0;
}