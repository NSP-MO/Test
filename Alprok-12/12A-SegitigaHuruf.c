#include <stdio.h>

int main() {
    int N, i, j;
    char ch1, ch2, ch3;
    
    scanf("%d %c%c%c", &N, &ch1, &ch2, &ch3);

    for (i = 0; i < N - 1; i++) {
        printf("%c", ch1);

        for (j = 0; j < i-1; j++) {
            printf(" ");
        }

        if (i > 0) {
            printf("%c", ch3);
        }
        
        printf("\n");
    }

    for (i = 0; i < N-1; i++) {
        printf("%c", ch2);
    }
    if (i != 0) {
        printf("%c", ch3);
    }
    printf("\n");

    return 0;
}
