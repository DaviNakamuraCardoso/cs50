#include <stdio.h>
#include <cs50.h>

int len(int a[]);
void bubble(int a[]);
int main(void)
{
    int array[12] = {4, 2, 5, 9, 23, 98, 122, 3, 6, 8, 7, 23};
    bubble(array);
    for (int i = 0; i < 12; i++) {
        printf("O %i termo é %i\n", i, array[i]);
    }
}
void bubble(int a[])
{
    int l = len(a);
    int count = 0;
    while (count != l-1) {
        for (int i = 0; i < l; i++) {
            if (a[i-1] > a[i]) {
                int temp = a[i];
                a[i] = a[i-1];
                a[i-1] = temp;
                count = 0;
            }
            else {
                count++;
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
