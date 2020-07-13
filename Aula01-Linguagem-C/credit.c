// Inclusões iniciais
#include <cs50.h>
#include <stdio.h>

int len(long a); // Indicando a presença de funções
int sum(int a);
float sw(long a, int b);
int split(long a, char b);

int main(void)

{
    long n = get_long("Number: ");
    int sum = split(n, 'm') + split(n, 'n');
    int l = len(n);
    int s = sw(n, 2);
    if (sum % 10 == 0) {
      if ((l == 16 || l == 13) && sw(n, 1) == 4) {
        printf("VISA\n");
      }
      else if (l == 15 && (s == 34 || s == 37)) {
        printf("AMEX\n");
      }
      else if (l == 16 && (s == 51 || s == 52 || s == 53 || s == 54 || s == 55)) {
        printf("MASTERCARD\n");
      }
      else {
        printf("INVALID\n");
      }

 }
  else {
    printf("INVALID\n");
  }

}


int len(long a) {
    int i;
    for(i = 0; a > 0.1; i++) {
        a = a / 10;

    }
    return i;
}
int sum(int a) {
    int p = 0;
    int i;
    int b = len(a);
    for(i = 1; i <= b; i++) {
      int x = a % 10;
        a = a / 10;
        p += x;
    }
    return p;
}
float sw(long a, int b) {
  int i;
  int l = len(a);
  for(i = 1; i<= l-b; i++) {
    a = a / 10;
  }
  return a;
}
int split(long a, char b) { // Essa função obtém três argumentos, b e c,
// que representam, respectivamente, o comprimento do número, o número em si e um comando, que
// indica se o é desejado obter os números a serem multiplicados por dois (m) ou os números
// que não serão multiplicados por dois (n)
    int i;
    int p = 0;
    int l = len(a);
    for (i = 1; i <= l; i++) {
        int x = a % 10;
        a = a / 10;
        if (b =='m') {
          if (i % 2 == 0) {
                   p += sum(2 * x);
               }
        }
        else {
          if (i % 2 != 0) {
            p += x;
          }

      }
  }
return p;
}
