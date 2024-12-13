#include <stdio.h>

int main() {
    int n, q, a, b, sum = 0;
    scanf("%d", &n);
    int num[n-1];
    int presum[n];
    presum[0] = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
        presum[i+1] = presum[i] + num[i];
    }
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &a, &b);
        if (a > b) {
            int temp = a;
            a = b;
            b = temp;
        }
        sum = presum[b+1] - presum[a];
        printf("%d\n", sum);
    }
    return 0;
}