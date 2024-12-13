#include <stdio.h>
#define size 100000
#define offset 100000

int main() {
    int n, num;
    int counter[2*size+1]={0};
    scanf("%d", &n);
    for (int i = 0; i < n && scanf("%d", &num) == 1; i++) {
        counter[num + offset]++;
        }

    for(int i = -100000; i <= 100000; i++) {
        if (counter[i + offset] > 0) {
            printf("%d ada %d\n", i, counter[i+offset]);
        }
    }
}