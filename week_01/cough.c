// Inclusões iniciais

#include <cs50.h>
#include <stdio.h>
// Coloque a primeira sentença da função para indicar sua
// presença ao interpretador

void cough(int n);

int main(void)

{
  cough(3);
}


// Definição do loop for
void cough(int n) {
  for(int i = 0; i < n; i++) {
  printf("Coff\n");
}
}
