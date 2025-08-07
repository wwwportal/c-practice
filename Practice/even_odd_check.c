#include <stdlib.h>
#include <stdio.h>

int main(int argsc, char* argv[]) {
	int num = atoi(argv[1]);
	if (num%2==0) { 
		printf("is even");
	} else {
		printf("is odd");
	}
	return 0;
}
