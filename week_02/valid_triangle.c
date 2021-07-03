#include <stdio.h>
#include <cs50.h>

bool valid_tri(float a, float b, float c);
int main(void)
{
    float x = get_float("Primeiro número: ");
    float y = get_float("Segundo número: ");
    float z = get_float("Terceiro número: ");
    bool d = valid_tri(x, y, z);
    if (d) {
        printf("Valid.\n");
    }
    else {
        printf("Invalid.\n");
    }
}
bool valid_tri(float a, float b, float c) {
    if (a > 0 && b > 0 && c > 0) {
        if (a+b > c && a+c > c && b+c > a) {
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}
