#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int a1, a2, b1, b2;
    scanf("%d %d", &a1, &a2);
    int *A = (int *)malloc(a1 * a2 * sizeof(int));
    for (int i = 0; i < a1 * a2; i++) {
        scanf("%d", &A[i]);
    }
    
    scanf("%d %d", &b1, &b2);
    int *B = (int *)malloc(b1 * b2 * sizeof(int));
    for (int i = 0; i < b1 * b2; i++) {
        scanf("%d", &B[i]);
    }
    
    char operation[4];
    scanf("%s", operation);

    if ((strchr("AB", operation[0]) == NULL) || (strchr("AB", operation[2]) == NULL) ||
        (strchr("+-*", operation[1]) == NULL)) {
        printf("ERROR\n");
        free(A);
        free(B);
        return 1;
    }

    if (operation[1] == '*' && operation[0] == operation[2]) {
        if ((operation[0] == 'A' && a1 != a2) || (operation[0] == 'B' && b1 != b2)) {
            printf("ERROR\n");
            free(A);
            free(B);
            return 1;
        }
    }

    if (operation[1] == '-' && operation[0] == operation[2]) {
        int rows = (operation[0] == 'A') ? a1 : b1;
        int cols = (operation[0] == 'A') ? a2 : b2;
        printf("%d %d\n", rows, cols);
        for (int i = 0; i < rows * cols; i++) {
            printf("0%c", (i % cols == cols - 1) ? '\n' : ' ');
        }
        free(A);
        free(B);
        return 0;
    }

    int *C = NULL;
    if (operation[1] == '+' || operation[1] == '-') {
        if (a1 != b1 || a2 != b2) {
            printf("ERROR\n");
        } else {
            C = (int *)malloc(a1 * a2 * sizeof(int));
            for (int i = 0; i < a1 * a2; i++) {
                C[i] = (operation[1] == '+') ? A[i] + B[i] : A[i] - B[i];
            }
        }
    } else if (operation[1] == '*') {
        int rows = (operation[0] == 'A') ? a1 : b1;
        int cols = (operation[0] == 'A') ? b2 : a2;
        int common = (operation[0] == 'A') ? a2 : b2;
        C = (int *)calloc(rows * cols, sizeof(int));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                for (int k = 0; k < common; k++) {
                    C[i * cols + j] += (operation[0] == 'A') ? A[i * a2 + k] * B[k * b2 + j] : B[i * b2 + k] * A[k * a2 + j];
                }
            }
        }
    }

    if (C) {
        int rows = (operation[1] == '+' || operation[1] == '-') ? a1 : ((operation[0] == 'A') ? a1 : b1);
        int cols = (operation[1] == '+' || operation[1] == '-') ? a2 : ((operation[0] == 'A') ? b2 : a2);
        printf("%d %d\n", rows, cols);
        for (int i = 0; i < rows * cols; i++) {
            printf("%d%c", C[i], (i % cols == cols - 1) ? '\n' : ' ');
        }
        free(C);
    }
    
    free(A);
    free(B);
    return 0;
}

