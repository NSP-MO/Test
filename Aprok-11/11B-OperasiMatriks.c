#include <stdio.h>
#include <stdlib.h>

int main() {
    int a1, a2;
    scanf("%d %d", &a1, &a2);
    
    int *A = (int *)malloc(a1 * a2 * sizeof(int));
    
    for (int i = 0; i < a1; i++) {
        for (int j = 0; j < a2; j++) {
            scanf("%d", &A[i * a2 + j]);
        }
    }
    
    int b1, b2;
    scanf("%d %d", &b1, &b2);
    
    int *B = (int *)malloc(b1 * b2 * sizeof(int));
    
    for (int i = 0; i < b1; i++) {
        for (int j = 0; j < b2; j++) {
            scanf("%d", &B[i * b2 + j]);
        }
    }
    
    char operation[4];
    scanf("%s", operation);

    if ((operation[0] != 'A' && operation[0] != 'B') || (operation[2] != 'A' && operation[2] != 'B')) {
        printf("ERROR\n");
        return 1;
    }

    if (operation[0] == operation[2] && operation[1] == '*') {
        if (operation[0] == 'A') {
            if(a1 != a2) {
                printf("ERROR\n");
                return 1;
            };
        } else { 
            if(b1 != b2) {
                printf("ERROR\n");
                return 1;
            };
        }
    }

    if (operation[1] == '-' && operation[0] == operation[2]) {
        if (operation[0] == 'A') {
            printf("%d %d\n", a1, a2);
            for (int i = 0; i < a1; i++) {
                for (int j = 0; j < a2; j++) {
                    printf("0 ");
                }
                printf("\n");
            }
        }
        if (operation[0] == 'B') {
            printf("%d %d\n", b1, b2);
            for (int i = 0; i < b1; i++) {
                for (int j = 0; j < b2; j++) {
                    printf("0 ");
                }
                printf("\n");
            }
        }
    }

    if (operation[1] == '-' && operation[0] != operation[2]) {
        printf("%d %d\n", a1, a2);
        for (int i = 0; i < a1; i++) {
            for (int j = 0; j < a2; j++) {
                printf("0 ");
            }
            printf("\n");
        }
    }
    
    if (operation[1] == '+' || operation[1] == '-') {
        if (a1 != b1 || a2 != b2) {
            printf("ERROR\n");
        } else {
            int *C = (int *)malloc(a1 * a2 * sizeof(int));
            
            for (int i = 0; i < a1; i++) {
                for (int j = 0; j < a2; j++) {
                    if (operation[1] == '+') {
                        C[i * a2 + j] = A[i * a2 + j] + B[i * b2 + j];
                    } else {
                        if (operation[0] == 'A') {
                            C[i * a2 + j] = A[i * a2 + j] - B[i * b2 + j];
                        } else {
                            C[i * a2 + j] = B[i * b2 + j] - A[i * a2 + j];
                        }
                    }
                }
            }
            
            printf("%d %d\n", a1, a2);
            for (int i = 0; i < a1; i++) {
                for (int j = 0; j < a2; j++) {
                    printf("%d", C[i * a2 + j]);
                    if (j < a2 - 1) printf(" ");
                }
                printf("\n");
            }
            
            free(C);
        }
    } else if (operation[1] == '*') {
        if (operation[0] == 'A') {
            if (a2 != b1) {
                printf("ERROR\n");
            } else if (a1 == b1 || a2 == b2) {
                printf("ERROR\n");
            }
            else {
                int *C = (int *)malloc(a1 * b2 * sizeof(int));
                
                for (int i = 0; i < a1; i++) {
                    for (int j = 0; j < b2; j++) {
                        C[i * b2 + j] = 0;
                        for (int k = 0; k < a2; k++) {
                            C[i * b2 + j] += A[i * a2 + k] * B[k * b2 + j];
                        }
                    }
                }
                
                // Mencetak hasil
                printf("%d %d\n", a1, b2);
                for (int i = 0; i < a1; i++) {
                    for (int j = 0; j < b2; j++) {
                        printf("%d", C[i * b2 + j]);
                        if (j < b2 - 1) printf(" ");
                    }
                    printf("\n");
                }
                
                free(C);
            }
        } else {
            if (b2 != a1) {
                printf("ERROR\n");
            } else if (a1 == b1 || a2 == b2) {
                printf("ERROR\n");
            }
            else {
                int *C = (int *)malloc(b1 * a2 * sizeof(int));
                
                for (int i = 0; i < b1; i++) {
                    for (int j = 0; j < a2; j++) {
                        C[i * a2 + j] = 0;
                        for (int k = 0; k < b2; k++) {
                            C[i * a2 + j] += B[i * b2 + k] * A[k * a2 + j];
                        }
                    }
                }
                
                printf("%d %d\n", b1, a2);
                for (int i = 0; i < b1; i++) {
                    for (int j = 0; j < a2; j++) {
                        printf("%d", C[i * a2 + j]);
                        if (j < a2 - 1) printf(" ");
                    }
                    printf("\n");
                }
                
                free(C);
            }
        }
    }
    
    free(A);
    free(B);
    
    return 0;
}