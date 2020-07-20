#include <stdio.h>

int main(void)
{
    int n = 50;
    int *p = &n;
    printf("%i\n%p\n", *p, p);
}
