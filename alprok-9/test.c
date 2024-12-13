#include <stdio.h>
#define N 100
int main()
{
    int dt[N]={0};
    int n, nilai;
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        scanf("%d", &nilai);
        if (!nilai) dt[nilai]++;
        else dt[1]++;
    }
    for (int i=0; i<5; i++)
        printf("%d ", dt[i]);
    printf("\n");
    
    return 0;
}