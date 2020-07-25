#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _try
{
    bool exist;
    struct _try * next[26];
}
_try;

// String len
int len(char* s);

// Lower

// Insertion 
void insertion(_try *ptr, char* key);

// Searching
bool search(_try *ptr, char* key);

int main(void)
{
    _try *pointer = malloc(sizeof(_try));
    insertion(pointer, "edavi");
    insertion(pointer, "caue");
    if (search(pointer, "edavi"))
    {
        printf("It just works!\n");
    }
    if (search(pointer, "edavii"))
    {
        printf("NOOOO!\n");
    }
    else
    {
        printf("YUUUUUUP!\n");
    }
}
int len(char* s)
{
    int l = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        l++;
    }
    return l;
}
void insertion(_try *ptr, char* key)
{
    _try *tmp = ptr;
    for (int i = 0; i < len(key); i++)
    {
        int a = key[i]-97;
        if (tmp->next[a] == NULL)
        {
            _try *n = malloc(sizeof(_try));
            tmp->next[a] = n;
            tmp = n;
        }
        else
        {
            tmp = tmp->next[a];
        }
    }
    tmp->exist = true;
}
/*void lower(char* s)
{
    int l = len(s);
    for (int i = 0; i < l; i++)
    {
        int a = (int) s[i];
        if (a < 92)
        {
            s[i] += 32;
        }
    }
}*/
bool search(_try *ptr, char* key)
{
    int l = len(key);
    _try *tmp = ptr;
    for (int i = 0; i < l; i++)
    {
        int a = key[i]-97;
        if (tmp->next[a] != NULL)
        {
            tmp = tmp->next[a];
        }
        else if (i < len(key)-1 || tmp->next[len(key)-1] == NULL)
        {
            return false;
        }
    }
    return tmp->exist;
}
