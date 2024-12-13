#include <stdio.h>

int main() {
    int n, num;
    scanf("%d", &n);
    int arr[n];
    int pre[n];
    pre[n] = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++) {
        pre[i] = arr[i] - arr[i-1];
    }
    while(1){
        scanf("%d", &num);
        if (num == -9) break;
        printf("%d\n", pre[num-1]);
    }
}