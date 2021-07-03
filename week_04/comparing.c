#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

int len(char *c);
int main(void)
{
    char *s = get_string("s: ");
    char *t = malloc(len(s)+1);
    for (int i = 0, n = len(s)+1; i < n; i++)
    {
        t[i] = s[i];
    }
    t[0] -= 32;
    printf("%s\n", s);
    printf("%s\n", t);
    free(t);
}
int len(char *c)
{
    int lenght = 0;
    for (int i = 0; c[i] != 0; i++)
    {
        lenght++;
    }
    return lenght;
}
