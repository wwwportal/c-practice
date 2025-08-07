#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argsv[]) {
    int smallest = atoi(argsv[1]);
    int same = 0;
    if (argc != 4) {
        printf("Invalid number of arguments.");
    } 
    int i = 1;
    for(int i = 1; i < argc; i++) {
        int num = atoi(*argsv[i]);
        if (num<smallest) {
            smallest = argsv[i];
        } else if (num == smallest) {
            same++;
        }

        if (argc-1 == same) {
            printf("there is no smallest number.");
        }

    }
}
