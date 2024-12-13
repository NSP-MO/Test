#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int *a = (int *)malloc(n * sizeof(int));
    if (a == NULL) {
        return -1;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int recall = -1, second = -1;

    for (int i = 0; i < n; i++) {
        if (a[i] > recall) {
            second = recall;
            recall = a[i];
        } else if (a[i] > second && a[i] != recall) {
            second = a[i];
        }
    }

    if (second == -1) {
        printf("-1\n");
    } else {
        printf("%d\n", second);
    }

    free(a);
    return 0;
}
