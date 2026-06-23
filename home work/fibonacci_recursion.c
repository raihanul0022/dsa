#include <stdio.h>

void fib(int n, int a, int b) {
    if (n == 0) {
        return;
    }

    printf("%d ", a);
    fib(n - 1, b, a + b);
}

int main() {
    int n;
    int a = 0, b = 1;

    scanf("%d", &n);

    fib(n, a, b);

    return 0;
}