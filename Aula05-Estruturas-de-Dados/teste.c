#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char name;
    struct node* next;
}
node;

void printnode(node *start);
int searchnode(node *nod, char val);
void destroy(node *list);

int main(void)
{
    // Setting the node
    node *list = NULL;
    node *n = malloc(sizeof(node));
    n->name = 'A';
    n->next = NULL;
    list = n;
    // Declaring the first element
    for (int i = 1; i < 26; i++)
    {
        node *tmp = n;
        n = malloc(sizeof(node));
        n->name = (char) i+65;
        tmp->next = n;
    }
    printnode(list);

    for (int j = 0; j < 26; j++)
    {
        node *tmpr = n;
        n = malloc(sizeof(node));
        n->name = (char) 97+j;
        tmpr->next = n;
    }
    printnode(list);
    if (searchnode(list, 'd') == 1)
    {
        printf("Found!\n");
    }
    destroy(list);
    if (list == NULL)
    {
        printf("Mission complete!\n");
    }
}


void printnode(node *start)
{
    node *temp = start;
    for (node *d = start; temp->next != NULL; d = d->next)
    {
        printf("%c\n", d->name);
        temp = d;
    }
}

int searchnode(node *nod, char val)
{
    node *tmp = nod;
    for (node *n = nod; tmp->next != NULL; n = n->next)
    {
        tmp = n;
        if (n->name == val)
        {
            return 1;
            break;
        }
        else
        {
            continue;
        }
    }
    return 0;
}
void destroy(node *list)
{
    if (list->next == NULL)
    {
        return;
    }
    else
    {
        destroy(list->next);
        free(list);
    }
}
