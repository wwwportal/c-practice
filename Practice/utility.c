/* utility.c
 *
 * Yassine Amraoui
 * CST8234
 * 2025-07-01
 */

#include <stdio.h>

void clearinputbuffer(){

    /* throw away extra characters on the input buffer */

    char c;
    while ((c = getchar()) != '\n' && c != EOF);
    return;

}
