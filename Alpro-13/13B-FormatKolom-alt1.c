#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 999

int main() {
    int n;
    scanf("%d", &n);
    
    int *numbers = (int *)malloc(n * sizeof(int));
    char strings[n][SIZE];
    int sum = 0;
    getchar();

    for(int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
        fgets(strings[i], SIZE, stdin);
        strings[i][strlen(strings[i])-1] = '\0';
        
        sum += numbers[i];
        printf("%s\n", strings[i]);
    }
    
    double avg = (double)sum / n;
    printf("%.2f\n", avg);
    free(numbers);
    return 0;
}

