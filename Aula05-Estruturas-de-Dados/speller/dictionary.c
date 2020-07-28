// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 10000;
void destroy(node *n);
char* lower(char* str);
int len(const char* s);
// Hash table
node *table[N];
// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int h = hash(word);
    node *tmp = malloc(sizeof(node));
    bool status = false;
    for (tmp = table[h]; tmp != NULL; tmp = tmp->next)
    {
        if (strcasecmp(word, tmp->word) == 0)
        {
            status = true;
            break;
        }
        else
        {
            continue;
        }
    }

    return status;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned int h;
    int num = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        num += word[i];
    }
    h = N % num;
    return h;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *d = fopen(dictionary, "r");
    bool statement = false;
    int c;
    char *w = malloc((LENGTH+1)*sizeof(char));
    int counter = 0;
    int i = 0;
    while ((c = fgetc(d)) != EOF)
    {
        if (c != '\n')
        {
            w[i] = c;
            i++;
        }
        else
        {
            int h = hash(w);
            if (table[h] == NULL)
            {
                for (int j = 0; j < i; j++)
                {
                    table[h] = malloc(sizeof(node));
                    table[h]->word[j] = w[j];
                    printf("%c", w[j]);
                }
            }
            else
            {
                node* tmp = malloc(sizeof(node));
                tmp->next = table[h]->next;
                for (int j = 0; j < i; j++)
                {
                    tmp->word[j] = w[j];
                    printf("%c", w[j]);
                }
                table[h]->next = tmp;
            }
            printf("\n");
            i = 0;
        }
        counter++;
    }
    if (counter > 0)
    {
        statement = true;
    }
    return statement;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    int siz = 0;
    for (int i = 0; i < N; i++)
    {
        for (node *tmp = table[i]; tmp->next != NULL; tmp = tmp->next)
        {
            siz++;
        }
    }
    return siz;
}
// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        destroy(table[i]);
    }
    return false;
}
void destroy(node *n)
{
    if (n == NULL)
    {
        return;
    }
    else
    {
        destroy(n->next);
    }
    free(n);
}
int len(const char* s)
{
    int l = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        l++;
    }
    return l;
}
char* lower(char* str)
{
    char* r = malloc(len(str)+1);
    for (int i = 0; str[i] != 0; i++)
    {
        r[i] = str[i];
        int a = (int) str[i];
        if (a < 97)
        {
            r[i] = (char) a + 32;
        }
    }
    return r;
    free(r);
}
