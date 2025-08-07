/* structures.c
 *
 * Yassine Amraoui
 * CST8234
 * 2025-07-01
 *
 * Code to help identify patterns in programming problems and match them
 * structures for implementation
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 3
#define HEIGHT 3
#define DEPTH 2

typedef char bool;

typedef struct {
    int x;
    int y;
    int z;
    bool live;
} Coordinates;

void displayGrid( char grid[(WIDTH * HEIGHT) * DEPTH] ) {
    
    /* does this line assign 0 to all the variabled or only i? */
    int j, k, l, i = 0;

    /* code added to box each level so that we can see if the
        bounds are working correctly (WIDTH for horizontal and
        HEIGHT for vertical)
    */

    for (k = 0; k < DEPTH; k++) {
        printf("Level %d\n", k+1);
        for (l = 0; l < (WIDTH + 2); l++) printf ("#");
        printf("\n");
        for (; i < (HEIGHT + (HEIGHT * k)); i++) {
            printf("#");
            for (j = 0; j < WIDTH; j++) printf("%c", grid[(i * WIDTH) + j] );
            printf("#\n");
        }
            for (l = 0; l < (WIDTH + 2); l++) printf ("#");
            printf("\n");
    }
    return;

}

void resetgrid( char * grid ) {

    /* blank out the grid */

    int i;

    for (i = 0; i < (WIDTH * HEIGHT * DEPTH); i++) *(grid + i) = ' ';

    return;
}

int main(){

    /* make two instances of the Coordinates structure wander
       around a 3X3X3 grid until they collide. Show they progress
       and cause them to die when they collide. Report the collision with
       a simple message: 'boom!'
    */

    char grid[(WIDTH * HEIGHT) * DEPTH];

    srand(time(NULL)); /* seeds the pseudo random number generator from the clock */

    resetgrid(grid);

    displayGrid(grid);

    return 0;
}
