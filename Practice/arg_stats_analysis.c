#include <stdlib.h>
#include <stdio.h>

float average(int count, int sum){
        float average = sum/count;
        return average;
}

int main(int argc, char* argsv[]) {
	int lth;
	int ltt;
	int i;
	int sum;
	float average;
	for(i=1;i<argc-1;i++) {
		int num = atoi(argsv[i]);
		if(num<100) {
			lth++;
			if(num<30) {
				ltt++;
			}
		}
	}

	for(i=1;i<argc-1;i++) {
		int num = atoi(argsv[i]);
		sum += num;
	}

	average = average((argc-1), sum); 

	printf("%s %d \n", "Number of arguments less than 100:", lth);
	printf("%s %d \n", "Number of arguments less than 30:", ltt);
	printf("%s %f.4 \n", "The average is: ", average);
	return 0;
}
