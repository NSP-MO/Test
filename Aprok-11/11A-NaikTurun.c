#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int *a = (int *)malloc(2*n * sizeof(int));
    for (int i = 0; i < n; i++) {
        a[2*i] = 2*i + 1;
        a[2*i+1] = 2*n - 2*i;
    }
    for (int i = 0; i < 2*n; i++) {
        printf("%d ", a[i]);
    }
    free(a);
    return 0;
}
