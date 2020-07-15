#include <stdio.h>
#include <cs50.h>
#include <math.h>

float readability(int letters, int words, int sentences);
int len(string text, char command);
int main(void)
{
  string txt = get_string("Text: ");
  int l = len(txt, 'c');
  int s = len(txt, 's');
  int w = len(txt, 'w') + 1;
  int read = round(readability(l, w, s));
  if (read < 1) {
    printf("Before Grade 1\n");
  }
  else if (read >= 1 && read < 16) {
    printf("Grade %i\n", read);
  }
  else {
    printf("Grade 16+\n");
  }
}
int len(string text, char command) {
  int n = 0;
  for(int i = 0; text[i] != 0; i++) {
    int ascii = text[i];
     if (command == 'c' && ascii >= 65 && ascii <= 122) {
       n++;
  }
     else if (command == 's' && (ascii == 33 || ascii == 46 || ascii == 63)){
       n++;
     }
     else if (command == 'w' && ascii == 32){
       n++;
     }}

    return n;
}
float readability(int letters, int words, int sentences) {
  float l = (float) letters * 100 / words;
  float s = (float) sentences * 100 / words;
  float r = (0.0588 * l) - (0.296 * s) - 15.8;
  return r;
}
