#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#include <ctype.h>

char *input(char *str) {
    char *hasil = (char *)(malloc(sizeof(char)));
    int i = 0;

    while (*str != '\0') {
        if (isalpha(*str) || isdigit(*str)) {
            hasil[i++] = tolower(*str);
            hasil = (char *)(realloc(hasil, (i + 1) * sizeof(char)));
        }
        ++str;
    }

    hasil[i] = '\0';
    return hasil;
}

struct kata {
    char kata[250];
    int count;
};

typedef struct kata KATA;

int main() {
    char baris[1000];
    int maks = 0;
    KATA list[500];
    char *delim = "[ \n\t,;-.]";
    
    while (fgets(baris, 500, stdin) != NULL) {
        char *token = strtok(baris, delim);

        while (token != NULL) {
            char *hasil = input(token);
            if (strlen(hasil) < 3) {
                token = strtok(NULL, delim);
                continue;
            }

            int berulang = 0;
            for (int i = 0; i < maks; i++) {
                if (strcmp(list[i].kata, hasil) == 0) {
                    list[i].count++;
                    berulang = 1;
                }
            }

            if (!berulang) {
                strcpy(list[maks].kata, hasil);
                list[maks].count = 1;
                maks++;
            }
            
            token = strtok(NULL, delim);
        }
    }

    for (int i = 0; i < maks; i++) {
        printf("%s %d\n", list[i].kata, list[i].count);
    }

    return 0;
}