#include <stdio.h>

// Factorial - Non-tail recursive
int factorial_non_tail(int n) {
    if (n == 0) return 1;
    return n * factorial_non_tail(n - 1);
}

// Factorial - Tail recursive
int factorial_tail_helper(int n, int acc) {
    if (n == 0) return acc;
    return factorial_tail_helper(n - 1, n * acc);
}
int factorial_tail(int n) {
    return factorial_tail_helper(n, 1);
}

// Sum of natural numbers - Non-tail recursive
int sum_non_tail(int n) {
    if (n == 0) return 0;
    return n + sum_non_tail(n - 1);
}

// Sum of natural numbers - Tail recursive
int sum_tail_helper(int n, int acc) {
    if (n == 0) return acc;
    return sum_tail_helper(n - 1, acc + n);
}
int sum_tail(int n) {
    return sum_tail_helper(n, 0);
}

// Fibonacci - Non-tail recursive
int fib_non_tail(int n) {
    if (n <= 1) return n;
    return fib_non_tail(n - 1) + fib_non_tail(n - 2);
}

// Fibonacci - Tail recursive
int fib_tail_helper(int n, int a, int b) {
    if (n == 0) return a;
    if (n == 1) return b;
    return fib_tail_helper(n - 1, b, a + b);
}
int fib_tail(int n) {
    return fib_tail_helper(n, 0, 1);
}

// Tower of Hanoi - Non-tail recursive
void hanoi_non_tail(int n, char from, char to, char aux) {
    if (n == 0) return;
    hanoi_non_tail(n - 1, from, aux, to);
    printf("Move disk %d from %c to %c\n", n, from, to);
    hanoi_non_tail(n - 1, aux, to, from);
}

// Tower of Hanoi - Tail recursive (not truly possible, but can simulate tail call for one branch)
void hanoi_tail(int n, char from, char to, char aux) {
    while (n > 0) {
        hanoi_tail(n - 1, from, aux, to);
        printf("Move disk %d from %c to %c\n", n, from, to);
        // Only the second recursive call is in tail position
        n--;
        char temp = from; from = aux; aux = temp;
    }
}

int main() {
    int n;

    // Factorial
    n = 5;
    printf("Factorial of %d (non-tail): %d\n", n, factorial_non_tail(n));
    printf("Factorial of %d (tail): %d\n", n, factorial_tail(n));

    // Sum of natural numbers
    n = 10;
    printf("Sum of first %d natural numbers (non-tail): %d\n", n, sum_non_tail(n));
    printf("Sum of first %d natural numbers (tail): %d\n", n, sum_tail(n));

    // Fibonacci
    n = 7;
    printf("Fibonacci number %d (non-tail): %d\n", n, fib_non_tail(n));
    printf("Fibonacci number %d (tail): %d\n", n, fib_tail(n));

    // Tower of Hanoi
    n = 3;
    printf("Tower of Hanoi (non-tail) for %d disks:\n", n);
    hanoi_non_tail(n, 'A', 'C', 'B');

    printf("Tower of Hanoi (tail) for %d disks:\n", n);
    hanoi_tail(n, 'A', 'C', 'B');

    return 0;
}