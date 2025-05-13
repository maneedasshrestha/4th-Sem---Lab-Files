#include <stdio.h>

// Iterative function to find factorial
unsigned long factorial_iterative(int n) {
    unsigned long result = 1;
    for(int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Recursive function to find factorial
unsigned long factorial_recursive(int n) {
    if(n == 0 || n == 1)
        return 1;
    else
        return n * factorial_recursive(n - 1);
}

int main() {
    int num;
    printf("Enter a non-negative integer: ");
    scanf("%d", &num);

    if(num < 0) {
        printf("Factorial is not defined for negative numbers.\n");
        return 1;
    }

    // Note: Using %lu for unsigned long instead of %llu
    printf("Factorial of %d (Iterative): %lu\n", num, factorial_iterative(num));
    printf("Factorial of %d (Recursive): %lu\n", num, factorial_recursive(num));

    return 0;
}