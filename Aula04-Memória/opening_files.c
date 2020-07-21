#include <stdio.h>
#include <cs50.h>

int main(void)
{
    char *name = get_string("Nome: ");
    char *number = get_string("Número: ");
    // Abrindo o arquivo
    FILE *file = fopen("lista_telefonica.csv", "a");
    // Print (escrevendo) no arquivo
    fprintf(file, "%s, %s\n", name, number);
    // Fechando o arquivo
    fclose(file);
}
