#include <stdio.h>

int main(void)
{
    char *s = "É DAVI!";
    printf("%p\n", s);
    for (int i = 0; s[i] != 0; i++)
    {
        printf("%p\n", &s[i]);
    }
    for (int j = 0; j <= 6; j++)
    {
        printf("%c", *(s+j));
    }
    printf("\n");
}
