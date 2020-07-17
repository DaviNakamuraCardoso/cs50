#include <stdio.h>
#include <cs50.h>

int collatz(int a);
int main(void)
{
    int n = get_int("Integer: ");
    int c = collatz(n);
    printf("%i\n", c);
}
int collatz(int a)
{
    if (a == 1)
    {
        return 0;
    }
    else if (a % 2 == 0)
    {
        return 1 + collatz(a/2);
    }
    else
    {
        return 1 + collatz(3*a+1);
    }
}
