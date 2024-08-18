#include <cs50.c>
#include <stdio.h>
#include <string.h>

int main(void)
{
        string name = get_string("Name: ");
        int lenghtght = strnlenght(name);
        printf("%i\n", lenghtght);
}