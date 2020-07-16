#include <stdio.h>
#include <cs50.h>
#include <string.h>

typedef struct
{
    string name;
    string number;
}
person;

int main(void)
{
    person people[4];
    people[0].name = "Davi";
    people[0].number = "23032-9432";

    people[1].name = "Caue";
    people[1].number = "93903-9300";

    people[2].name = "Samuel";
    people[2].number = "3902-2216";

    people[3].name = "João";
    people[3].number = "3920-2213";

    for (int i = 0; i < 4; i++) {
        if (strcmp(people[i].name, "Samuel") == 0)
        {
            printf("Achei! O número do %s é %s\n", people[i].name, people[i].number);
            return 0;
        }
    }
    printf("Não achei o número dele.\n");
    return 1;
}
