#include <stdio.h>

int main() {

    int x, y , z;

    printf("input : ");
    scanf("%d, %d, %d", &x, &y, &z);
    printf("Output: ");

    if (x >= y && x > z) {
        printf("1\n");
        } else if (y >= x && y > z) {
            printf("2\n");
        } else if (z >= x && z > y) {
            printf("3\n");
        }

    if (x == y && x == z) {
        printf("sama\n");
    }

    return 0;
}
