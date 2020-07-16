#include <stdio.h>
#include <cs50.h>

void drawn(int height);
int main(void)
{
    int h = get_int("Heiht: ");
    drawn(h);
}

void drawn(int height)
{   if (height == 0)
    {
        return;
    }
    drawn(height-1);
    for (int i = 0; i < height; i++)
    {
        printf("#");
    }
    printf("\n");
}
