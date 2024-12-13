#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int arr[1001][1001]={0};
    int pre[1001][1001]={0};

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    while(1) {
        scanf("%d %d", &n, &m);
        if(n==-9) break;
        pre[n][m] = arr[n][m] - arr[n-1][m] - arr[n][m-1] + arr[n-1][m-1];
        printf("%d\n", pre[n][m]);
    }
}