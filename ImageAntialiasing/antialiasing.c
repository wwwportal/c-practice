#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOP (1 << 0)
#define LEFT (1 << 1)
#define BOTTOM (1 << 2)
#define RIGHT (1 << 3)

typedef struct {
	int red;
	int green;
	int blue;
} pixel;

int REDVAL = 0;
int GREENVAL = 0;
int BLUEVAL = 0;
int X = 0;
int Y = 0;

int readLine(FILE* source);

void antialias(pixel*** original, pixel*** antialiased, int y, int x);

/**
* Antialiases pixels from an array
* and stores the antialiased pixel values in a new array
*/
void antialias(pixel*** original, pixel*** antialiased, int y, int x) {
	int dy, dx;
	int redSum = 0;
	int greenSum = 0;
	int blueSum = 0;
	int neighbors = 0;

	/* for top and bottom */
	for (dy = -1; dy <= 1; dy++) {
		/* and for left and right */
		for (dx = -1; dx <= 1; dx++) {
			int ny = y + dy;
			int nx = x + dx;
			
			/* if pixels are within a valid range */
			if (ny >= 0 && ny < Y && nx >= 0 && nx < X) {
				redSum += original[ny][nx]->red;
				greenSum += original[ny][nx]->green;
				blueSum += original[ny][nx]->blue;
				neighbors++;
			}
		}
	}
	
	/* assign antialiased pixel values to corresponding pixels in target array */
	antialiased[y][x]->red = redSum / neighbors;
	antialiased[y][x]->green = greenSum / neighbors;
	antialiased[y][x]->blue = blueSum / neighbors;
}

/* Reads one line from file, casts output to an int and returns it.*/
int readLine(FILE* source)
{
    char line[5];
    int val=0;
    if (fgets(line,15,source))
    {
        val=strtol(line,NULL,10);
    }
    else
    {
        /* Better error management will please your lab prof and earn you a bit of grace in marking.*/
        printf("Unexpected end of file!"); 
        return -1;
    }
    return val;
}

/* Program relies on an intact sample_image_input.txt file and probably bad things will happen if you tamper with it.
   Suggest you don't tamper with it.
   But you are adults and you get to eat dessert before dinner if you want.
*/
int main(void)
{
    FILE* stream = fopen("sample_image_input.txt", "r");
	if (!stream) {
		printf("Error reading file...");
	}
    int x=0; /* Max x and y*/
    int y=0;
    int xi, yi; /* x-iterator and y-iterator respectively*/

    x=readLine(stream); /* Reads size of graphic. If you prefer, x is cols, y is rows.*/
    y=readLine(stream);
	printf("SizeofX: %d, SizeofY: %d\n", x, y);
	X = x;
	Y = y;

    /* Create 2D array of pixel-type structs here.
        Size is x by y.
        Create a second array of same, and ensure it is empty.
    */
	pixel*** original;
	pixel*** antialiased;
	original = malloc(y * sizeof(pixel**));
	antialiased = malloc(y * sizeof(pixel**));
	
    /* Loading your array.*/
    for (yi=0;yi<y;yi++)
    {
		original[yi] = malloc (x * sizeof(pixel*));
		antialiased[yi] = malloc (x * sizeof(pixel*));
        for (xi=0;xi<x;xi++)
        {
			original[yi][xi] = malloc(sizeof(pixel));
			antialiased[yi][xi] = malloc(sizeof(pixel));
            /* Load individual struct elements here.*/
            REDVAL = readLine(stream);
            GREENVAL = readLine(stream);
            BLUEVAL = readLine(stream);
			
			original[yi][xi]->red = REDVAL;
			original[yi][xi]->green = GREENVAL;
			original[yi][xi]->blue = BLUEVAL;
			
			printf("%02x", REDVAL);
			printf("%02x", GREENVAL);
			printf("%02x ", BLUEVAL);
        }
		printf("\n");
    }
    /* Data is now loaded. */

	/* Antialias each pixel as per document instructions.
		Create a function that antialiases one pixel with the values of its neighbours.
		Watch out for edge cases!
	*/
	/* Finally, print your array as a series of hexadecimal characters
	exactly match the provided output for format.*/
	printf("\n");printf("\n");printf("\n");
	for (yi=0;yi<y;yi++) {
		for (xi=0;xi<x;xi++) {
			/* antialias pixel at (yi, xi)*/
			antialias(original, antialiased, yi, xi);
			printf("%02x", antialiased[yi][xi]->red);
			printf("%02x", antialiased[yi][xi]->green);
			printf("%02x ", antialiased[yi][xi]->blue);
		}
		printf("\n");
	}
	
	/* free arrays */
	for (yi=0;yi<y;yi++) {
		for (xi=0;xi<x;xi++) {
			free(original[yi][xi]);
			free(antialiased[yi][xi]);
		}
		free(original[yi]);
		free(antialiased[yi]);
	}
	free(original);
	free(antialiased);
	fclose(stream);
	return 0;
}
