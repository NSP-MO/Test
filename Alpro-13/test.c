#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n+1; i++) {
        char s[100];
        scanf("%s", s);
        char *len= strtok(s,";");
        printf("%s\n", len);
    }
    return 0;
}