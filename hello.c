#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string s = get_string("What's your name? "); 
    printf("Hello, %s!\n", s);
    return 0; 
}