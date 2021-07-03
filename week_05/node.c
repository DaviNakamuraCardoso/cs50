#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
    int number;
    struct node *next;
}
node;

int main(void)
{
    node *list = NULL;
    node *n = malloc(sizeof(node));
    if (n != NULL)
    {
        (*n).number = 2; // Or: n->number = 2;
        (*n).next = NULL; // Or: n->next = NULL;
    }
    list = n;
    n = malloc(sizeof(node));
    n->number = 3;
    n->next = NULL;
    list->next = n;
    printf("%i\n%i\n%p\n%p", list->number, n->number, n, list->next);
    node *tmp = list;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    printf("%i\n", tmp->number);

}
