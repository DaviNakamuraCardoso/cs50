#include "helpers.h"

void average_color(int height, int width, RGBTRIPLE image_copy[height][width], RGBTRIPLE img[height][width], int a, int b, int sr, int er, int sc, int ec);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int average = (image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen) / 3;
            image[i][j].rgbtRed = average;
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width/2; j++)
        {
            RGBTRIPLE tmp = image[i][j];
            image[i][j] = image[i][width-j-1];
            image[i][width-j-1] = tmp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE image_cop[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image_cop[i][j] = image[i][j];
        }
    }
    for (int d = 0; d < height; d++)
    {
        for (int e = 0; e < width; e++)
        {
            if (d == 0)
            {
                if (e == 0)
                {
                    average_color(height, width, image_cop, image, d, e, 0, 1, 0, 1);
                }
                else if (e == width-1)
                {
                    average_color(height, width, image_cop, image, d, e, 0, 1, -1, 0);
                }
                else
                {
                    average_color(height, width, image_cop, image, d, e, 0, 1, -1, 1);
                }
            }
            else if (d == height-1)
            {
                if (e == 0)
                {
                    average_color(height, width, image_cop, image, d, e, -1, 0, 0, 1);
                }
                else if (e == width-1)
                {
                    average_color(height, width, image_cop, image, d, e, -1, 0, -1, 0);
                }
                else
                {
                    average_color(height, width, image_cop, image, d, e, -1, 0, -1, 1);
                }
            }
            else
            {
                if (e == 0)
                {
                    average_color(height, width, image_cop, image, d, e, -1, 1, 0, 1);
                }
                else if (e == width-1)
                {
                    average_color(height, width, image_cop, image, d, e, -1, 1, -1, 0);
                }
                else
                {
                    average_color(height, width, image_cop, image, d, e, -1, 1, -1, 1);
                }
            }
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
void average_color(int height, int width, RGBTRIPLE image_copy[height][width], RGBTRIPLE img[height][width], int a, int b, int sr, int er, int sc, int ec)
{
    int counter = 0;
    int blue = 0;
    int green = 0;
    int red = 0;
    for (int i = sr; i <= er; i++)
    {
        for (int j = sc; j <= ec; j++)
        {
            blue += image_copy[a+i][b+j].rgbtBlue;
            green += image_copy[a+i][b+j].rgbtGreen;
            red += image_copy[a+i][b+j].rgbtRed;
            counter++;
        }
    }
    img[a][b].rgbtGreen = green / counter;
    img[a][b].rgbtBlue = blue / counter;
    img[a][b].rgbtRed = red / counter;

}
