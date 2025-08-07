#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int determinant1(){
    int a,b,c,d;
    int det;
    printf("2x2 MATRIX DETERMINANT CALCULATOR\n");
    scanf("%d %d %d %d", &a, &b, &c, &d);
    det = (a*b)-(c*d);
    printf("\n%d\n",det);
    return det;
}

void sum2(){
    int a;
    int b;
    int sum;
    printf("Enter the first number: ");
    scanf("%d", &a);
    printf("Enter the second number: ");
    scanf("%d", &b);
    sum = a + b;
    printf("The sum of %d and %d is %d\n", a, b, sum);
}

void isWhat3(){
    int var;
    printf("Enter an integer: ");
    scanf("%d", &var);
    if (var == 0) {
        printf("The number is zero\n");
    } else if (var > 0) {
        printf("The number is positive\n");
    } else if (var < 0) {
        printf("The number is negative\n");
    }
}

void ARRR4(){
    int arr[5];
    int i;
    srand(time(NULL));
    for(i=0;i<5;i++){
        *(arr+i) = rand();
        printf("[%d]\n", arr[i]);
    }
}

int prada5(){
    int a;
    int b;
    int prod;
    printf("Enter a number: ");
    scanf("%d", &a);
    printf("Enter a number: ");
    scanf("%d", &b);
    prod = a * b;
    printf("The product of %d and %d is %d.\n", a,b,prod);
    return prod;
}

void loopy6(){
    int i;
    for(i=1; i<=10; i++){
        if (i==5){
            printf("uh oh... we've reached 5. time to break\n");
            break;
        } else {
            printf("%d ", i);
        }
    }
}

int powr(int base, int exponent){
    int pow = base;
    int i;
    for(i = 1; i<=exponent; i++){
        pow *= base;
        printf("%d\n", base);
    }
    return base;
}

void poly7(){
    int x;
    int coeff[4];
    printf("Let's calculate where:\n");
    printf("P(x)=a+bx+cx^2+dx^3");
    printf("Enter the four coefficients: ");
    scanf("%d %d %d %d", &coeff[0], &coeff[1], &coeff[2], &coeff[3]);
    printf("Enter the value of x: ");
    scanf("%d", &x);
}

void prime(){
    int number;
    
}

int main(){
    powr(2, 5);
    return 0;
}