#include <stdio.h>

/*
void alias(int **local) {

}

int main() {
	int x = 7;
	int *p = &x;
}
*/


void observe(int **arr) {
	printf("&arr in callee:		%p\n", (void*)&arr);
	printf(" arr value :		%p\n", (void*)arr);
}

int main() {
	int x = 42;
	int *p = &x;
	int **pp = &p;
	int **aox = p;

	printf("&x in caller		%p\n", (void*)&x);
	printf("aox in the caller	%p\n", (void*)aox);
	printf("x in caller			%p\n", (void*)x);
	printf("&pp in caller		%p\n", (void*)&pp);
	printf("pp in caller		%p\n", (void*)pp);
	observe(pp);
	return 0;
}

