#include <stdio.h>

int fibonacci(int n) {
    if (n <= 1) 
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int given_number;
    printf("Masukkan angka batas: ");
    scanf("%d", &given_number);

    int sum = 0, n = 0;

    while (sum <= given_number) {
        sum += fibonacci(n);
        n++;
    }

    printf("Jumlah angka Fibonacci melebihi %d pada n = %d\n", given_number, n);

    return 0;
}