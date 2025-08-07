#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int maintainArray(int ** array, int elements, int capacity, int loadfactor);
int checkNum (int num);
int ** addMultiple(int ** multiples, int num);
int ** addOther(int ** others, int num);
void printFreeArray(int ** array);

int main (int argc, char ** argv) {
	int initCap = 10;
	FILE * fptr = fopen("myFile.csv", "r");
	int ** multiples;
	int ** others;
	int num;
	int multiple;
	int mcount = 0;
	int mcapacity;
	char ch;
	int ocount = 0;
	int ocapacity;
	char buffer[10];
	int reallocate;
	double loadFactor = 75;
	multiples = (int *)malloc(initCap * sizeof(int *));
	others = malloc(sizeof(int *));
	
	if (fptr) {
		while ((fscanf(fptr, "%d", &num)) == 1) { /* this is probably wrong */
			int good = 0;
			while((ch = fgetc(fptr)) != '\n') {
				if (isdigit(ch)) {
					good++;
				}
				if (good == strlen(buffer)) {
					multiple = checkNum(num);
					if (multiple == 0) {
						addMultiple(multiples, num);
						mcount++;
					} else {
						addOther(others, num);
						ocount++;
					}
					
					reallocate = maintainArray(&multiples, mcount, mcapacity, loadFactor);
					if (reallocate == 0) mcapacity *= 2;
					reallocate = maintainArray(&others, ocount, ocapacity, loadfactor);
					if (reallocate == 0) ocapacity *= 2;
					
				} else {
					printf("Error: inputMismatch.");
					return 1;
				}
			}
		}
	}
	fclose(fptr);
	return 0;
}

int maintainArray(int *** array, int elements, int capacity, int loadfactor) {
	int resizeThreshold = (capacity * loadFactor)/100;
	int newSize = capacity * 2;
	if (elements == resizeThreshold) {
		int *temp = realloc(*array, newSize * sizeof * array);
		/* if reallocation failed */
		if (!temp) perror("realloc"); exit(1);
		array = temp;
		return 1;
	} else {
		return 0;
	}
}

int checkNum (int num) {
	
	if ((num % 3) == 0) {
		return 0;
	} else {
		return 1;
	}
}

int ** addMultiple(int ** multiples, int num) {
	int * thisMultiple = *multiples;
	int count;
	while (thisMultiple != NULL) {
		count++;
		thisMultiple = *(multiples + count);
	} /* until we reach the end of the array */
	/* then allocate memory for the new element */
	thisMultiple = malloc(sizeof(int));
	*(thisMultiple) = num;
	return multiples;
}

int ** addOther(int ** others, int num) {
	int * thisOther = *others;
	int count = 0;
	while (thisOther != NULL) {
		count++;
		thisOther = *(others + count);
	} /* until we reach the end of the array */
	/* then allocate memory for the new element */
	thisOther = malloc(sizeof(int));
	*(thisOther) = num;
	return others;
}

void printFreeArray(int ** array) {
	int * thisElement = *array;
	int count = 0;
	while (thisElement != NULL) {
		printf("%d\n", *(thisElement));
		count++;
		int * nextElement = *(array + count);
		free(thisElement);
		thisElement = nextElement;
	}
}