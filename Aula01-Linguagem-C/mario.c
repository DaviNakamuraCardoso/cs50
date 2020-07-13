#include <cs50.h>
#include <stdio.h>

void hash(int n);
void space(int x);
void hashtag(int h);

int main(void)
{
  int n;
  do {
  n = get_int("Width: ");
} while(n < 1 || n > 8);
  hash(n);
}

void hash(int n) {
  int i;
  for(i = 1; i <= n; i++) {
      space(n-i);
      hashtag(i);
      printf("  ");
      hashtag(i);
      space(n-i);
      printf("\n");
    }
}

void space(int x) {
  int d;
  for(d = 1; d <= x; d++) {
    printf(" ");
  }
}
void hashtag(int h) {
  int a;
  for(a = 1; a <= h; a++) {
    printf("#");
  }
}
