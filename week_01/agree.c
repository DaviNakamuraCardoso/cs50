// Inclusões necessárias

#include <stdio.h>
#include <cs50.h>

int main(void)

// Obtendo input
{
  char c = get_char("Você concorda?\n");
  // Analisando e devolvendo uma resposta
  if (c == 's' || c == 'S')
  {
    printf("Você concorda.\n");
  }
  else if (c == 'n' || c == 'N')
  {
    printf("Você não concorda.\n");
  }
}
