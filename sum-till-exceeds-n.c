#include <stdio.h>

int main() {
    int num, sum = 0, n = 1;

    printf("Input : ");
    scanf("%d", &num);

    while (sum <= num) {
        sum += n;
        n++;
    }

    printf("Output: %d\n", n - 1);

    return 0;
}
