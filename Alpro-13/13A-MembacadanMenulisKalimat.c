#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    char **s;

    scanf("%d", &n);
    getchar();

    s = (char **) malloc(n * sizeof(char *));
    for(int i=0; i<n; i++){
        s[i] = (char *) malloc(1001 * sizeof(char));
        fgets(s[i], 1001, stdin);
        size_t len = strlen(s[i]);
        if(len > 0 && s[i][len - 1] == '\n'){
            s[i][len-1] = '\0';
        }
    }

    while (1) {
        int k;
        scanf("%d", &k);
        if (k == -9) break;
        if (k > 0 && k <= n) {
            printf("%s\n", s[k-1]);
        } else {
            return 1;
       }
    }

    for(int i=0; i<n; i++){
        free(s[i]);
    }
    free(s);

    return 0;
}

