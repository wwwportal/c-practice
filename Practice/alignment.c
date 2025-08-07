/* alignment.c
 *
 * Yassine Amraoui
 * CST8234
 * 2025-07-01
 * 
 * Code to elucidate padding and alignment rules in structs
 * and to spark insights about better memory management
 * when it comes to using structs
 */

#include <stdio.h>

typedef struct {
    char c;
    int i;
    double d;
} o1;

typedef struct {
    int i;
    char c;
    double d;
} o2;

typedef struct {
    double d;
    char c;
    int i;
} o3;

typedef struct {
    double d;
    int i;
    char c;
} o4;

typedef struct {
    int i;
    double d;
    char c;
} o5;

typedef struct {
    char c;
    double d;
    int i;
} o6;

int main() {

    printf("SIZE OF TYPES\n");
    printf("Integer %ld\n", sizeof(int));
    printf("Double %ld\n", sizeof(double));
    printf("Character %ld\n", sizeof(char));

    printf("Size of our structs\n");

    printf("o1 %ld\n", sizeof(o1));
    printf("o2 %ld\n", sizeof(o2));
    printf("o3 %ld\n", sizeof(o3));
    printf("o4 %ld\n", sizeof(o4));
    printf("o5 %ld\n", sizeof(o5));
    printf("o6 %ld\n", sizeof(o6));

    return 0;
}
