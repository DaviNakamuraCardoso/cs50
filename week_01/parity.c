#include "cs50.h"
#include "stdio.h"

int main(void)
{
  int n = get_int("Digite um número: ");
  if (n % 2 == 0) {
    printf("Par\n");
  }
  else {
    printf("Ímpar.\n"); 
  }
}
