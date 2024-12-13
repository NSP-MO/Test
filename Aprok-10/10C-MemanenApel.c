#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main() {
    int N, M;

    scanf("%d %d", &N, &M);

    int *V = (int *)malloc(N * M * sizeof(int));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &V[i * M + j]);
        }
    }

    int xA1, yA1, xA2, yA2;
    int xB1, yB1, xB2, yB2;
    scanf("%d %d %d %d", &xA1, &yA1, &xA2, &yA2);
    scanf("%d %d %d %d", &xB1, &yB1, &xB2, &yB2);

    int SumA = 0;
    int SumB = 0;

    for (int i = xA1-1; i < xA2; i++) {
        for (int j = yA1-1; j < yA2; j++) {
            SumA += V[i * M + j];
        }
    }

    for (int i = xB1-1; i < xB2; i++) {
        for (int j = yB1-1; j < yB2; j++) {
            SumB += V[i * M + j];
        }
    }

    int overlapX1 = fmax(xA1, xB1);
    int overlapY1 = fmax(yA1, yB1);
    int overlapX2 = fmin(xA2, xB2);
    int overlapY2 = fmin(yA2, yB2);

    int overlap=0;

    if (overlapX1 <= overlapX2 && overlapY1 <= overlapY2) {
        for (int i = overlapX1 - 1; i < overlapX2; i++) {
            for (int j = overlapY1 - 1; j < overlapY2; j++) {
                overlap += V[i * M + j];
            }
        }
    }
    int sum = SumA + SumB - overlap;
    printf("%d\n", sum);

    free(V);
    return 0;
}