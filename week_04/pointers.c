#include <stdio.h>

int main(void)
{
    int k = 49;
    int* pk = &k;
    printf("%p\n", pk);
    char* s = "Davi";
    printf("%p\n%s\n", s, s);
}
