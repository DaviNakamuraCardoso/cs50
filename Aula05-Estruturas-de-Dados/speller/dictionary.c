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
int D = 0;

// Number of buckets in hash table
const unsigned int N = 272727;
void destroy(node* n);
int clen(const char* s);
int ascii(const char c);
// Hash table
node *table[N];
// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int h = hash(word);
    bool status = false;
    node *tmp = (node*)malloc(sizeof(node));
    node *f = tmp;
    if (table[h] != NULL)
    {
        for (tmp = table[h]; tmp != NULL; tmp = tmp->next)
        {
           if (tmp != NULL)
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
        }
    }
    free(f);
    return status;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned int h;
    int c = 10000;
    int num = 0;
    for (int i = 0; i < 3; i++)
    {
        if (clen(word) == 1)
        {
            num += ascii(word[0]) * c;
        }
        else if (clen(word) == 2)
        {
            if (i < 2)
            {
                num += ascii(word[i]) * c;
            }
            else
            {
                num += 97;
            }
        }
        else
        {
            num += ascii(word[i]) * c;
        }
        c = c / 100;

    }
    h = num - 979797;
    return h;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *d = fopen(dictionary, "r");
    bool statement = false;
    int c;
    char *w = malloc((46)*sizeof(char));
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
            w[i] = '\0';
            int h = hash(w);
            if (table[h] == NULL)
            {
                table[h] = malloc(sizeof(node));
                for (int j = 0; w[j] != '\0'; j++)
                {
                    table[h]->word[j] = w[j];
                }
            }
            else
            {
                node* tmp = malloc(sizeof(node));
                tmp->next = table[h]->next;
                for (int j = 0; w[j] != '\0'; j++)
                {
                    tmp->word[j] = w[j];
                }
                table[h]->next = tmp;
            }
            for (int e = 0; e < 46; e++)
            {
                w[e] = '\0';
            }
            i = 0;
            D++;
        }
        counter++;
    }
    if (counter > 0)
    {
        statement = true;
    }
    fclose(d);
    free(w);
    return statement;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return D;
}
// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    int n = (int) N;
    for (int i = 0; i < n; i++)
    {
        destroy(table[i]);
    }
    return true;
}
void destroy(node* n)
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

int ascii(const char c)
{
    int a = (int) c;
    if (a < 97)
    {
        a += 32;
    }
    return a;
}
int clen(const char* s)
{
    int l = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        l++;
    }
    return l;
}
