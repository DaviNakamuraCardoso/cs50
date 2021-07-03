#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int *list = malloc(3 * sizeof(int));
    if (list == NULL)
    {
        return 1;
    }

    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    int* tmp = malloc(4 * sizeof(int));
    for (int i = 0; i < 3; i++)
    {
        tmp[i] = list[i];
    }
    free(list);
    list = tmp;
    list[3] = 4;
    for (int j = 0; j < 4; j++)
    {
        printf("%i\n", list[j]);
    }
    free(tmp);
}
