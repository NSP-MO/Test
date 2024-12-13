#include <stdio.h>
#define SIZE 10000

int main () {
    int i = 0, j = 0, k = 0;
    int n[SIZE], m[SIZE], o[2 * SIZE];

    while(i < SIZE && scanf("%d", &n[i]) == 1 && n[i] != -9) {
        i++;
    }

    while(j < SIZE && scanf("%d", &m[j]) == 1 && m[j] != -9) {
        j++;
    }

    int a = 0, b = 0;

    while (a < i && b < j) {
        if (n[a] <= m[b]) {
            o[k++] = n[a++];
        } else {
            o[k++] = m[b++];
        }
    }

    while (a < i) {
        o[k++] = n[a++];
    }

    while (b < j) {
        o[k++] = m[b++];
    }

    for (int x = 0; x < k; x++) {
        printf("%d ", o[x]);
    }
    printf("\n");

    return 0;
}
