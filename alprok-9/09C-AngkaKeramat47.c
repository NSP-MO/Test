#include <stdio.h>
#define size 1000000

int main() {
    int n, count=0;
    int arr[size]={0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n && j < i + 47; j++)
        {
            sum += arr[j];
            if (sum == 47) count++;
        }
    }
    printf("%d\n", count);
}