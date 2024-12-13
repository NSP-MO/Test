#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, sum=0;
    scanf("%d", &n);
    
    for(int i=0; i<n; i++){
        int a;
        char b[38];
        scanf("%d;%[^\n]", &a, b);
        sum+=a;
        printf("%s\n", b);
    }
    float mean=(float)sum/n;
    printf("%.2f\n", mean);
    return 0;
}