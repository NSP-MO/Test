#include <stdio.h>

void kapitalisasi(char text[], char c1, char c2) {
    int i;
    char c1_upper, c1_lower, c2_upper, c2_lower;
    
    if (c1 >= 'a' && c1 <= 'z') {
        c1_lower = c1;
        c1_upper = c1 - 32;
    } else if (c1 >= 'A' && c1 <= 'Z') {
        c1_upper = c1;
        c1_lower = c1 + 32;
    } else {
        c1_upper = c1_lower = c1;
    }
    
    if (c2 >= 'a' && c2 <= 'z') {
        c2_lower = c2;
        c2_upper = c2 - 32;
    } else if (c2 >= 'A' && c2 <= 'Z') {
        c2_upper = c2;
        c2_lower = c2 + 32;
    } else {
        c2_upper = c2_lower = c2;
    }
    
    for (i = 0; text[i] != '\0'; i++) {
        if (text[i] == c1_upper) {
            text[i] = c2_upper;
        } else if (text[i] == c1_lower) {
            text[i] = c2_lower;
        }
    }
}

int main() {
    char text[10001];
    char c1, c2;
    
    scanf("%c %c", &c1, &c2);
    getchar();
    
    int i = 0;
    char c;
    while ((c = getchar()) != EOF) {
        text[i++] = c;
    }
    text[i] = '\0';
    
    kapitalisasi(text, c1, c2);
    
    printf("%s", text);
    
    return 0;
}