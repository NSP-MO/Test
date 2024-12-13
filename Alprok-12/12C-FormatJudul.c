#include <stdio.h>

void formatTitle(char text[], int length) {
    int i;
    int newWord = 1;
    
    for (i = 0; i < length; i++) {
        if (newWord && text[i] >= 'a' && text[i] <= 'z') {
            text[i] = text[i] - 32; 
        }
        
        if (text[i] == ' ' || text[i] == '\t' || text[i] == '\n') {
            newWord = 1;
        } else {
            newWord = 0;
        }
    }
}

int main() {
    char text[10001];
    int length = 0; 
    char c;           
    
    while ((c = getchar()) != EOF) {
        text[length++] = c;
    }
    text[length] = '\0';
    
    formatTitle(text, length);
    
    printf("%s", text);
    
    return 0;
}