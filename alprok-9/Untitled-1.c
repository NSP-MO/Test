#include <stdio.h>
#include <stdlib.h>
int main()
{
char s1[] = "University\n";
char s2[] = {'U', 'n', 'i', 'v', 'e', 'r', 's', 'i', 't', 'y'};
int n1 = sizeof(s1)/sizeof(s1[0]);
int n2 = sizeof(s2)/sizeof(s2[0]);
printf("%d\n", n1);
printf("%d\n", n2);
printf("%d\n", n1+n2);
return 0;
}
