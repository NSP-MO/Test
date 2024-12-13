#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int n, sum = 0;
    scanf("%d", &n);
    getchar();

    char s[n][38];
    int num;
    char nama[38];

    for (int i = 0; i < n; i++) {
        fgets(s[i], sizeof(s[i]), stdin);
        s[i][strcspn(s[i], "\n")] = '\0';
    }

    for (int i = 0; i < n; i++) {
        char snum[3] = {s[i][0], s[i][1], '\0'};
        num = atoi(snum);
        sum += num;
        strcpy(nama, s[i] + 2);
        printf("%s\n", nama);
    }

    
    double avg = (double)sum/n;
    printf("%.2f\n", avg);

    return 0;
}