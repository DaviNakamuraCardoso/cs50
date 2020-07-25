#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

// Struct try
typedef struct _try
{
    bool exist;
    struct _try* next[10];
}
_try;

// Try insertion
void insertion(_try* ptr, int key);

// Try search
bool searchtry(_try *ptr, int num);

// Destroy try
void destroy(_try *ptr);

// Essential for splitting numbers
int* split(int a);
int len(int a);

int main(void)
{
    _try *pt = malloc(sizeof(_try));
    insertion(pt, 1914);
    insertion(pt, 1870);
    insertion(pt, 1935);
    insertion(pt, 1919);
    insertion(pt, 2020);
    insertion(pt, 33);
    insertion(pt, 70);
    insertion(pt, 100);
    insertion(pt, 144000);
    for (int i = 0; i < 200000; i++)
    {
        if (searchtry(pt, i))
        {
            printf("Found! The year is %i\n", i);
        }
    }
    printf("%d\n", pt->next[1]->next[9]->next[1]->next[4]->exist);
    if (searchtry(pt, 1914))
    {
        printf("Nice!\n");
    }
    else
    {
        printf("Failed!\n");
    }
    destroy(pt);
    printf("The len of 1914 is %i\n", len(1914));
    printf("It just works!\n");
}
void insertion(_try* ptr, int key)
{
    int l = len(key);
    int* numbers = split(key);
    _try *tmp = ptr;
    for (int j = 0; j < l; j++)
    {
        if (tmp->next[numbers[j]] == NULL)
        {
            _try *n = malloc(sizeof(_try));
            tmp->next[numbers[j]] = n;
            tmp = n;
        }
        else
        {
            tmp = tmp->next[numbers[j]];
        }
    }
    (*tmp).exist = true;
    printf("%p\n%i\n\n", tmp, tmp->exist);
    free(numbers);
}
bool searchtry(_try *ptr, int num)
{
    int l = len(num);
    int* numbers = split(num);
    _try *tmp = ptr;
    for (int i = 0; i < l; i++)
    {
        if (tmp->next[numbers[i]] != NULL)
        {
            tmp = tmp->next[numbers[i]];
        }
        else if (i != l-1 || tmp->next[numbers[l-1]] == NULL)
        {
            return false;
            break;
        }
    }
    return tmp->exist;
}
int* split(int a)
{
    int l = len(a);
    int *numbers = malloc(l * sizeof(int));
    for (int i = 0; i < l; i++)
    {
        numbers[l-i-1] = a % 10;
        a = a / 10;
    }
    return numbers;
}
void destroy(_try *ptr)
{
    for (int i = 0; i < 10; i++)
    {
        if (ptr == NULL)
        {
            return;
        }
        else if (ptr->next[i] == NULL)
        {
            continue;
        }
        else
        {
            printf("Searching in %i %p...\n",i, ptr->next[i]);
            destroy(ptr->next[i]);
        }
    }
    printf("Deleting %p...\n", ptr);
    free(ptr);
}
int len(int a)
{
    int l = 0;
    for (int i = a; i >= 1; i = i/10)
    {
        l++;
    }
    return l;
}
