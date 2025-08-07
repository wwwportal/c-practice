/**
 * Name: Yassine Amraoui
 * Student number: 041044570
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

float calculations(char *argsv[], int startIndex, int numNum);

void displayHelp() {
    printf("moneychange [OPTION]… AMOUNT EXCHANGE [EXCHANGE]\n");
    printf("A program to convert currency with provided rate(s)\n");
    printf("-s, --symbol CURRENCY   sets the printed currency symbol\n");
    printf("-l, --long              shows detailed conversion amounts\n");
}

int checkLong(char *argsv[]) {
    int i;
    for (i = 1; i <= 2; i++) { 
    /** logical error: symbol option may not be the first option
     * so the range should've been between 1 and 4.
     * The reasoning is that the Long option takes only one CLI argument,
     * but the symbol option takes 2 CLI arguments.
     * Therefore, the long symbol could be the 4th argument if the user
     * enters the symbol option first.
     **/
        if (argsv[i] != NULL &&
            (strcmp(argsv[i], "-l") == 0 || strcmp(argsv[i], "--long") == 0)) {
            return i + 1;
        }
    }
    return 0;
}

int checkSymbol(char *argsv[], char symbol[]) {
    int i, j, symdex;
    for (i = 1; i <= 3; i++) {
        if (argsv[i] != NULL &&
            (strcmp(argsv[i], "-s") == 0 || strcmp(argsv[i], "--symbol") == 0)) {
			/*if the argument is not null and is either -s or --symbol*/
            symdex = i + 1; /*the next argument should contain an actual symbol*/
            if (argsv[symdex] == NULL) { /*if the symbol is null*/
                return -1;
            }
            if (strlen(argsv[symdex]) != 3) { /*if the symbol is not three letters*/
                return -1;
            }
            for (j = 0; j < 3; j++) { /* if the symbol does only contain letters*/
                if (!isalpha(argsv[symdex][j])) {
                    return -1;
                }
            }
            strncpy(symbol, argsv[symdex], 4); /*copy the 3-letter symbol to variable called symbol*/
            return symdex;
        }
    }
    return 0;
}

int checkNums(int argc, char *argsv[], int start) {
    int nums = 0;
    int i;
    char *end;

    for (i = start; i < argc; i++) {
        /* Use strtod to detect invalid numeric strings */
        strtod(argsv[i], &end);
        if (*end != '\0') { /*if strtod found an invalid number*/
            printf("Invalid number: %s\n", argsv[i]);
            return 0;
        }
        nums++;
    }
    return nums;
}

float calculations(char *argsv[], int startIndex, int numNum) {
    float amount, rate1, rate2;

    if (numNum == 2) {
        amount = (float) atof(argsv[startIndex]);
        rate1 = (float) atof(argsv[startIndex + 1]);
        return amount * rate1;
    } else if (numNum == 3) {
        amount = (float) atof(argsv[startIndex]);
        rate1 = (float) atof(argsv[startIndex + 1]);
        rate2 = (float) atof(argsv[startIndex + 2]);
        return amount * (rate1 / rate2);
    } else {
        return -1;
    }
}

int main(int argc, char *argsv[]) {
    char symbol[4];
    int symdex;
	int londex;
	int startIndex;
	int numNum;
	int mode;
    float result, amount;

    /* initialize symbol buffer */
    symbol[0] = '\0';

    symdex = checkSymbol(argsv, symbol);
    if (symdex == -1) {
        printf("Invalid symbol.\n");
        return 1;
    }

    londex = checkLong(argsv);

    startIndex = 1;
    if (symdex != 0 || londex != 0) {
        if (symdex > londex) {
            startIndex = symdex + 1;
        } else {
            startIndex = londex;
        }
    }

    numNum = checkNums(argc, argsv, startIndex);
    if (numNum == 0) {
        return 1;
    }

	amount = (float) atof(argsv[startIndex]);
    result = calculations(argsv, startIndex, numNum);

    /* determine output mode (symbol=2, long=1) */
    mode = 0;
    if (symdex != 0) {
        mode += 2;
    }
    if (londex != 0) {
        mode += 1;
    }

    switch (mode) {
        case 0:
            /* no -s or -l */
            printf("%.2f\n", result);
            break;
        case 1:
            /* only -l */
            printf("%.2f becomes %.2f\n", amount, result);
            break;
        case 2:
            /* only -s */
            printf("%.2f %s\n", result, symbol);
            break;
        case 3:
            /* both -s and -l */
            printf("%.2f becomes %.2f %s\n", amount, result, symbol);
            break;
    }
    return 0;
}