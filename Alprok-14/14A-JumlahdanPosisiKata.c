#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct input {
    char kata[101];
    int n[51];
    int jumlah;
};

int main() {
    struct input s[1001];
    int num = 0;

    char line[1000];
    while(fgets(line, sizeof(line), stdin)) {
        line[strcspn(line, "\n")] = '\0';
      
        char *token = strtok(line, " ,.\n;");
        if(token) {
            strcpy(s[num].kata, token);
            s[num].jumlah = 0;

            while((token = strtok(NULL, " ,.\n;")) != NULL) {
                s[num].n[s[num].jumlah++] = atoi(token);
            }
            num++;
        }
    }

    for(int i = 0; i < num; i++) {
        printf("%s(%d):", s[i].kata, s[i].jumlah);
        
        for(int j = 0; j < s[i].jumlah; j++) {
            if (j > 0) {
                printf("->");
            }
            
            printf("%d", s[i].n[j]);
        }
        
        printf("\n");
    }

    return 0;
}