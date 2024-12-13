#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 500
#define MAX_LENGTH 201

void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

void clean_word(char *str) {
    int i = 0, j = 0;
    while (str[i]) {
        if (isalnum(str[i])) { // Hanya huruf dan angka yang disalin
            str[j++] = str[i];
        }
        i++;
    }
    str[j] = '\0'; // Akhiri string bersih
}

int main() {
    char input[MAX_LENGTH * MAX_WORDS];
    char *unique_words[MAX_WORDS];
    int word_counts[MAX_WORDS] = {0};
    int unique_count = 0;

    // Membaca seluruh input
    if (fgets(input, sizeof(input), stdin) == NULL) {
        return 1;
    }

    // Tokenisasi input menggunakan delimiters
    char *token = strtok(input, " ,;.-\n\t\"");
    
    while (token != NULL) {
        // Ubah ke huruf kecil
        to_lowercase(token);
        
        clean_word(token);

        if (strlen(token) == 0) {
            token = strtok(NULL, " ,;.-\n\t\"");
            continue;
        }

        int found = 0;
        for (int i = 0; i < unique_count; i++) {
            if (strcmp(unique_words[i], token) == 0) {
                word_counts[i]++;
                found = 1;
                break;
            }
        }

        if (!found) {
            if (unique_count >= MAX_WORDS) {
                break; 
            }
            
            unique_words[unique_count] = strdup(token);
            word_counts[unique_count] = 1;
            unique_count++;
        }

        token = strtok(NULL, " ,;.-\n\t\"");
    }


    for (int i = 0; i < unique_count; i++) {
        printf("%s %d\n", unique_words[i], word_counts[i]);
        free(unique_words[i]);
    }

    return 0;
}
