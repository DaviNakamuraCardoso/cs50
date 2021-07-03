#include <cs50.h>
#include <stdio.h>

int main(void)
{
  printf("Você nasceu há pelo menos %i dias.\n", get_int("Qual é a sua idade?\n")*365);
}
