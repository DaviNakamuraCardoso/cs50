#include <stdio.h>
#include <cs50.h>

bool binary_search(int n, int sorted_array[], int start, int end);
void selection(int a[], int start, int end);
int main(void)
{
    int array[18] = {23, 231, 322, 22, 23, 22, 233, 88, 4, 1, 6, 32, 9393, 938, 393, 433, 44, 44};
    int n = 1;
    selection(array, 0, 18);
    for (int i = 0; i < 18; i++)
    {
        printf("The %iº element is %i\n", i, array[i]);
    }
    binary_search(n, array, 0, 18);
}
void selection(int a[], int start, int end)
{
    if (start == end)
    {
        return;
    }
    else
    {
        for (int i = start; i < end; i++)
        {
            int min = a[start];
            int max = a[end-1]; // The last element index is lenght - 1;
            if (a[i] < min)
            {
                int temp = a[start];
                a[start] = a[i];
                a[i] = temp;
            }
            else if (a[i] > max)
            {
                int temp = a[end-1];
                a[end-1] = a[i];
                a[i] = temp;
            }
        }
        selection(a, start+1, end-1);
    }
}
bool binary_search(int n, int sorted_array[], int start, int end)
{
    int middle = (start + end) / 2;
    if (sorted_array[middle] == n)
    {
        printf("found at position %i\n", middle);
        return true;
    }
    else if (sorted_array[middle] > n && start != middle)
    {
        return binary_search(n, sorted_array, start, middle-1);
    }
    else if (sorted_array[middle] < n && start != middle)
    {
        return binary_search(n, sorted_array, middle+1, end);
    }
    else
    {
        printf("%i isn't in this array.\n", n);
        return false;
    }
}
