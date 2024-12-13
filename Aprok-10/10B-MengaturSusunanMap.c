#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, count = 0, s = 0;
    int *A = (int *)malloc(10001 * sizeof(int));
    int *C = (int *)malloc(10001 * sizeof(int));

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    for (int i = 0; i < N; i++) {
        C[i] = 1;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if(A[i] > A[j] && C[i] < C[j]+1) {
                C[i] = C[j] + 1;
            }
        }
        if (C[i] > s) {
            s = C[i];
        }
    }
    count = N - s;
    printf("%d\n", count);
    free(A);
    free(C);
    return 0;
}