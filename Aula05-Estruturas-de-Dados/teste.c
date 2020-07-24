#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char name;
    struct node* next;
}
node;

void printnode(node *start);

int main(void)
{
    // Setting the node
    node *n = malloc(sizeof(node));
    node *list_start = n;
    // Declaring the first element
    for (int i = 0; i < 26; i++)
    {
        node *tmp = n;
        n = malloc(sizeof(node));
        n->name = (char) i+65;
        tmp->next = n;
    }
    printnode(list_start);

    for (int j = 0; j < 26; j++)
    {
        node *tmpr = n;
        n = malloc(sizeof(node));
        n->name = (char) 97+j;
        tmpr->next = n;
    }
    printnode(list_start);

}
void printnode(node *start)
{
    node *temp = start;
    for (node *d = start->next; temp->next != NULL; d = d->next)
    {
        printf("%c\n", d->name);
        temp = d;
    }
}
