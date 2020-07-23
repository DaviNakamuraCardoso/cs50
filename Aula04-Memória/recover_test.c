#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *card = fopen("./recover/card.raw", "r");
    char c;
    while (() c = fgetc(card)) != EOF)
    {
        printf("%c", c);
    }
}
