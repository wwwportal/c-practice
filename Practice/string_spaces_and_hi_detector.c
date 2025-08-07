#include <stdio.h>


int spacesCounter(char * str) { 
    int count = 0;
    /* this method returns the number of spaces in a string */
    while(str != NULL && *str != '\0'){
        if (*str == ' ') {
            ++count;
        }
        str++;
    }
    return count;
}

int hasHI(char *str) {
    int HI = -1;
    int no = 1; /* no "HI" has not been detected in the string yet. */
    /*This method takes a string and returns 1 if 'HI' is in the string*/
    while(str != NULL && *str != '\0' && no == 1){
        if(*str == 'H'){
            char *H = str;
            char *I = H+1;
            if (I != NULL && *(I) != '\0' && *I == 'I') {
                no = 0;
                HI = 1;
            } else {
                HI = -1;
            }
        }
        str++; /*increment the string pointer*/
    }
    return HI;
}

void hasHIFeedback(int hi) {
    if (hi == -1) {
        printf("'HI' was not found in the string!\n");
    } else if (hi == 1) {
        printf("'HI' was found in the string!\n");
    }
}


int main () {
    char * str = "HI! This string should have 6 spaces.";
    int count = spacesCounter(str);
    int hi = hasHI(str);
    printf("%s\n", str);
    printf("The string has %d spaces", count);
    hasHIFeedback(hi);
    return 0;
}