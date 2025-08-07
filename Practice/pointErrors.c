/*  pointer_practice.c
 *
 *  A playground full of classic pointer-management bugs:
 *  – freeing stack memory
 *  – realloc misuse (local vs caller’s pointer, lost pointer on failure)
 *  – wrong sizeof in malloc/realloc
 *  – passing the wrong level of indirection
 *  – lifetime errors (using pointers after scope end)
 *  – undefined-behaviour expressions with crazy precedence
 *  – double-free / leaks
 *
 *  Your mission: make this compile cleanly (-Wall -Wextra), run without
 *  crashing, and behave logically.
 */

#include <stdio.h>
#include <stdlib.h>

void  grow      (int **buf, size_t *cap);            /* BUGGY */
void  push      (int **stack, size_t *top, int value);/* BUGGY */
void  swapHeads (int **a, int **b);                  /* OK if called right */

int main(void)
{
    /* ---------- 1.  Broken stack implementation ---------- */
    int stackCap  = 4;
    int stackTop  = 0;
    int *stack    = NULL;          /* will be resized in push() */

    push(&stack, &stackTop, 10);
    push(&stack, &stackTop, 20);

    /* ---------- 2.  Wrong-level-indirection swap ---------- */
    int head1 = 1, head2 = 2;
    int *p1   = &head1;
    int *p2   = &head2;
    swapHeads(p1, p2);             /* should swap, but doesn’t… why? */

    /* ---------- 3.  Undefined-behaviour expression ---------- */
    int arr[5] = {1,2,3,4,5};
    int *q     = arr;
    printf("Weird value: %d\n", *((q + 2)[1]));  /* UB precedence puzzle */

    /* ---------- 4.  Freeing stack memory ---------- */
    free(&head1);                  /* instant UB! */

    /* ---------- 5.  grow() mismanages realloc ---------- */
    grow(&stack, &stackCap);       /* may leak or seg-fault */

    /* ---------- 6.  Use-after-free / leak demo ---------- */
    int *temp = malloc(2 * sizeof *temp);
    temp[0] = 111;
    free(temp);
    printf("Use-after-free: %d\n", temp[0]);   /* UB again */

    /* purposely never free(stack); to test leak detection tools */
    return 0;
}

/* ===========================================================
   BUG FARM BELOW
   =========================================================== */

void grow(int **buf, size_t *cap)
{
    *cap *= 2;
    /* WRONG: realloc’s first arg must be *buf, and result must be checked */
    *buf = realloc(buf, (*cap) * sizeof(int));
}

void push(int **stack, size_t *top, int value)
{
    if (*top == 0)
        *stack = malloc(sizeof **stack);                       /* OK */
    else
        /* WRONG sizeof: sizeof *stack == sizeof(int*), not sizeof(int) */
        *stack = realloc(*stack, (*top + 1) * sizeof *stack);  /* leaks on NULL */

    (*stack)[(*top)++] = value;   /* also unsafe if realloc returned NULL */
}

void swapHeads(int **a, int **b)
{
    int *tmp = *a;
    *a = *b;
    *b = tmp;
}
