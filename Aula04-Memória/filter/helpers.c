#include "helpers.h"
#include <math.h>
#include <stdlib.h>

void average_color(int height, int width, RGBTRIPLE image_copy[height][width], RGBTRIPLE img[height][width], int a, int b, int sr, int er, int sc, int ec);
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float three = 3;
            float average = (image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen) / three;
            int rounded = round(average);
            image[i][j].rgbtRed = rounded;
            image[i][j].rgbtBlue = rounded;
            image[i][j].rgbtGreen = rounded;
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
    RGBTRIPLE img[height+2][width+2];
    for (int d = 0; d < height+2; d++)
    {
        for (int e = 0; e < width+2; e++)
        {
            if (d == 0 || e == 0 || d == height+1 || e == width+1)
            {
                img[d][e].rgbtRed = 0;
                img[d][e].rgbtBlue = 0;
                img[d][e].rgbtGreen = 0;
            }
            else
            {
                img[d][e] = image[d-1][e-1];
            }
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float redx = 0;
            float redy = 0;
            float greenx = 0;
            float greeny = 0;
            float bluex = 0;
            float bluey = 0;
            for (int a = -1; a <= 1; a++)
            {
                for (int b = -1; b <= 1; b++)
                {
                    redx += (img[i+1+b][j+1+a].rgbtRed * (a) * (2 - abs(b)));
                    redy += (img[i+1+b][j+1+a].rgbtRed * (b) * (2 - abs(a)));
                    greenx += (img[i+1+b][j+1+a].rgbtGreen * (a) * (2 - abs(b)));
                    greeny += (img[i+1+b][j+1+a].rgbtGreen * (b) * (2 - abs(a)));
                    bluex += (img[i+1+b][j+1+a].rgbtBlue * (a) * (2 - abs(b)));
                    bluey += (img[i+1+b][j+1+a].rgbtBlue * (b) * (2 - abs(a)));
                }
            }
            int red = round(sqrt(((redx*redx)+(redy*redy))));
            int green = round(sqrt(((greenx*greenx)+(greeny*greeny))));
            int blue = round(sqrt(((bluex*bluex)+(bluey*bluey))));
            if (red > 255)
            {
                red = 255;
            }
            if (blue > 255)
            {
                blue = 255;
            }
            if (green > 255)
            {
                green = 255;
            }
            image[i][j].rgbtRed = red;
            image[i][j].rgbtGreen = green;
            image[i][j].rgbtBlue = blue;
        }
    }
    return;
}
void average_color(int height, int width, RGBTRIPLE image_copy[height][width], RGBTRIPLE img[height][width], int a, int b, int sr, int er, int sc, int ec)
{
    float counter = 0;
    float blue = 0;
    float green = 0;
    float red = 0;
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
    img[a][b].rgbtGreen = round(green / counter);
    img[a][b].rgbtBlue = round(blue / counter);
    img[a][b].rgbtRed = round(red / counter);

}
