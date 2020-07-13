#include <cs50.h>
#include <stdio.h>

int sum(long a);
int len(long a);
float startswith(long a, int b);
int main(void)



{
  long z = get_long("dajfkajlfjafj: ");
  int c = sum(z);
  int l = len(z);
  int s = startswith(z, 1);

  printf("%i\n", c);
  printf("%i\n", l);
  printf("%i\n", s);
  if (s == 4) {
    printf("You rock!");
  }


}
int sum(long a) {
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
int len(long a) {
    int i;
    for(i = 0; a > 0.1; i++) {
        a = a / 10;

    }
    return i;
}
float startswith(long a, int b) {
  int i;
  int l = len(a);
  for(i = 1; i<= l-b; i++) {
    a = a / 10;
  }
  return a;
}
