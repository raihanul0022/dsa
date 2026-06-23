#include <stdio.h>

void fib(int n, int a, int b) {
    if (n == 0)
        return;

    printf("%d ", a);
    fib(n - 1, b, a + b);
}

int main() {
    int n;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci Series: ");
    fib(n, 0, 1);

    return 0;
}