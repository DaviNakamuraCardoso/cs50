#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *card = fopen("./recover/card.raw", "r");
    int c;
    int count = 0;
    int jpegs = 0;
    while ((c = fgetc(card)) != -1)
    {
        count++;
    }
    int blocks = count / 512;
    int bytes[blocks][512];
    FILE *img;
    fread(bytes, 512, blocks, card);
    for (int i = 0; i < blocks; i++)
    {
        if (bytes[i][0] == 0xff && bytes[i][1] == 0xd8 && bytes[i][2] == 0xff && (bytes[i][3] & 0xf0) == 0xe0)
        {
            if (jpegs >= 1)
            {
                fclose(img);
            }
            char* filename = malloc(7);
            sprintf(filename, "%03i.jpg", jpegs);
            img = fopen(filename, "w");
            fwrite(bytes[i], 4, 128, img);
            free(filename);
            jpegs++;
        }
        else if (jpegs >= 1)
        {
            fwrite(bytes[i], 4, 128, img);
        }
        else
        {
            continue;
        }
        fclose(img);
    }

}
