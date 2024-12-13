#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_AKUN 5000
#define SIZE 100

typedef struct {
    char akun[SIZE + 1];
    int count;
} Daftar;

int cek(const void *a, const void *b) {
    return strcmp(((Daftar *)a)->akun, ((Daftar *)b)->akun);
}

int main() {
    int n;
    scanf("%d", &n);
    getchar();

    Daftar daftar[MAX_AKUN];
    int beda = 0;

    for (int i = 0; i < n; i++) {
        char buffer[SIZE + 1];
        fgets(buffer, sizeof(buffer), stdin);

        size_t len = strlen(buffer);
        if (buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }

        int berulang = 0;
        for (int j = 0; j < beda; j++) {
            if (strcmp(daftar[j].akun, buffer) == 0) {
                daftar[j].count++;
                berulang = 1;
                break;
            }
        }

        if (!berulang) {
            strcpy(daftar[beda].akun, buffer);
            daftar[beda].count = 1;
            beda++;
        }
    }

    qsort(daftar, beda, sizeof(Daftar), cek);

    for (int i = 0; i < beda; i++) {
        printf("%s %d\n", daftar[i].akun, daftar[i].count);
    }

    return 0;
}
