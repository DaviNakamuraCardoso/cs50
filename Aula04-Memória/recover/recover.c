#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
// Defining a byte
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		printf("Error: Missing 1 command line argument...\nUsage: ./recover.c [filename]\n");
		return 1;
	}
	else if (argc != 2)
	{
		printf("Error: To many command line arguments...\n");
		return 1;
	}

	// Opening the memory card
	FILE *card = fopen(argv[1], "r");
	BYTE bytes[16000][512];
	fread(bytes, 512, 16000, card);

	// Seting the jpeg counter to zero;
	int jpegs = 0;
	FILE *img;

	// Looping over all blocks of memory
	for (int i = 0; i < 16000; i++)
	{
		if (bytes[i][0] == 0xff && bytes[i][1] == 0xd8 && bytes[i][2] == 0xff && (bytes[i][3] & 0xf0) == 0xe0)
		{
			if (jpegs == 0)
			{
				char* first = malloc(7);
				sprintf(first, "%03i.jpg", jpegs);
				img = fopen(first , "w");
				free(first);
				fwrite(bytes[i], 512, 1, img);
				jpegs++;
			}
			else
			{
				char* filename = malloc(7);
				fclose(img);
				sprintf(filename, "%03i.jpg", jpegs);
				img = fopen(filename, "w");
				free(filename);
				fwrite(bytes[i], 512, 1, img);
				jpegs++;
			}
		}
		else if (jpegs >= 1)
		{
			fwrite(bytes[i], 512, 1, img);
		}
		else
		{
			continue;
		}
	}
	return 0;
}
