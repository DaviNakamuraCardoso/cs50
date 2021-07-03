#include <cs50.h>
#include <stdio.h>

int main(void)
{
  float price = get_float("Qual é o preço em dólares?\n");
  printf("O preço em reais é R$%.2f.\n", price*5.50);
}
