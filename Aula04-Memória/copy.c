#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

int main(void)
{
    char *s = get_string("s: ");
    char *t = s;
    t[0] -= 32;
    printf("%s\n", s);
    printf("%s\n", t);
}
