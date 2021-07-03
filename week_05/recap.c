#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int* x;
    x = malloc(sizeof(int));
    *x = 41;
    printf("x é %i\n", *x);
}
