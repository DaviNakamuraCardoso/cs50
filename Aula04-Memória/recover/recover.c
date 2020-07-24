#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Defining a byte
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
	// Basic input validation
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

	// Opening the memory card to get it's size;
	FILE *card = fopen(argv[1], "r");
	int c;
	int counter = 0;

	// Using fgetc to get the file's size in bytes;
	while ((c = getc(card)) != EOF)
	{
		counter++;
	}

	// Creating a buffer based on the byte counter;
	int blocks = counter / 512;
	BYTE bytes[blocks][512];

	// Reopening the card;
	card = fopen(argv[1], "r");
	fread(bytes, 512, blocks, card);

	// Seting the jpeg counter to zero adn declaring the image pointer;
	int jpegs = 0;
	FILE *img;

	// Looping over all blocks and searching for jpegs;
	for (int i = 0; i < blocks; i++)
	{
		if (bytes[i][0] == 0xff && bytes[i][1] == 0xd8 && bytes[i][2] == 0xff && (bytes[i][3] & 0xf0) == 0xe0)
		{
			// If it isn't the first image, close the previous one;
			if (jpegs >= 1)
			{
				fclose(img);
			}
			// Creating the filename string (aka char*);
			char* filename = malloc(7);
			sprintf(filename, "%03i.jpg", jpegs);

			// Overwriting the img pointer;
			img = fopen(filename, "w");
			fwrite(bytes[i], 512, 1, img);

			// Resetting
			free(filename);
			jpegs++;
		}
		// If a JPEG was already found, keep writing it;
		else if (jpegs >= 1)
		{
			fwrite(bytes[i], 512, 1, img);
		}
		// Else, continue;
		else
		{
			continue;
		}
	}
	// Closing the last image;
	fclose(img);
	return 0;
}
