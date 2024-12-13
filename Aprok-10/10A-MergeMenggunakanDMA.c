#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, M, i=0, k=0;
    int *A = (int *)malloc(2001 * sizeof(int));
    int *B = (int *)malloc(2001 * sizeof(int));
    int *C = (int *)malloc(4001 * sizeof(int));

    while(1){
        scanf("%d", &A[i]);
        if(A[i] == -9) break;
        i++;
    } N = i;
    i=0;
    while(1){
        scanf("%d", &B[i]);
        if(B[i] == -9) break;
        i++;
    } M = i;
    int j=0;
    i=0;

    while (i < N && j < M) {
        if (A[i] < B[j]) {
            C[k++] = A[i++];
        } else C[k++] = B[j++];
    }

    while (i < N) {
        C[k++] = A[i++];
    }

    while (j < M) {
        C[k++] = B[j++];
    }

    for (int i = 0; i < k; i++) {
        printf("%d ", C[i]);
    }
    free(A);
    free(B);
    free(C);
    return 0;
}