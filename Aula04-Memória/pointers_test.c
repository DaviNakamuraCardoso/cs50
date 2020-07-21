#include <stdio.h>
#include <stdlib.h>

int len(char* str);
void double_mult(int* a);
int main(void)
{
    int p = 2;
    double_mult(&p);
    printf("%i", p);
    char* s = "Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";
    char* t = malloc(len(s)+1);
    for (int j = 0, n = len(s)+1; j < n; j++)
    {
        t[j] = s[j];
        int ascii = (int) t[j-1];
        int ascii2 = (int) t[j-2];k
        if (ascii == 32 && ascii2 != 21 && ascii2 != 46 && ascii2 != 63)
        {
            t[j] -= 32;
        }
    }
    printf("%s", t);
    free(t);
}
void double_mult(int* a)
{
    *a *= 2;
}

int len(char* str)
{
    int lenght = 0;
    for (int i = 0; str[i] != 0; i++)
    {
        lenght++;
    }
    return lenght;
}
