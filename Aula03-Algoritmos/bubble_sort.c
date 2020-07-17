#include <stdio.h>
#include <cs50.h>

int len(int a[]);
void bubble(int a[]);
int main(void)
{
    int array[12] = {4, 2, 5, 9, 23, 98, 122, 3, 6, 8, 7, 23};
    bubble(array);
    for (int i = 0; i < 12; i++) {
        printf("O %iº termo é %i\n", i+1, array[i]);
    }
    string s = get_string(" ");
    printf("%s", s);
}
void bubble(int a[])
{
    int l = len(a);
    int counter = 1;
    while (counter != 0)
    {
        counter = 0;
        for (int i = 0; i < l-1; i++)
        {
            if (a[i] > a[i+1])
            {
                int temp = a[i];
                a[i] = a[i+1];
                a[i+1] = temp;
                counter++;
            }
        }
    }
}
int len(int a[])
{
    int l = 0;
    for (int i = 0; a[i] != 0; i++) {
        l++;
    }
    return l;
}
