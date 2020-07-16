#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    string names[4] = {"Davi", "Caue", "Samuel", "João"};
    for (int i = 0; i < 4; i++) {
        if (strcmp(names[i], "Davi")) {
            printf("Achei\n");
            return 0;
        }
    }
    printf("Não achei\n");
    return 1;
}
