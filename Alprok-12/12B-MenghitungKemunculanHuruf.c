#include <stdio.h>
#include <ctype.h>

int main() {
    char N;
    int count[26] = {0};

    while ((N = getchar()) != EOF) {
        if (isalpha(N)) {
            count[tolower(N) - 'a'] += 1;
        }
    }
    for (int i = 0; i < 26; i++) {
        if (count[i] > 0) {
            printf("%c %d\n", i + 'a', count[i]);
        }
    }

    return 0;

}