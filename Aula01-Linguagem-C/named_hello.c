#include <cs50.h>
#include <stdio.h>

int main(void)
{
  string answer = get_string("Qual é o seu nome?\n");
  printf("Olá, %s\n", answer);
}
