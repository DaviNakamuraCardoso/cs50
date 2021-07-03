#include <stdlib.h>

void f(void)
{
    int *x = malloc(10 * sizeof(int));
/*    x[10] = 0; buffer overflow */
    free(x);
    x[9] = 90;
}

int main(void)
{
    f();
    return 0;
}
