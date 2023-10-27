#include "algo.h"

/*** Pascal's Triangle ***/
int factorial(int n){
    int toReturn;
    toReturn = 1;

    for(int i = 1; i <= n; i++){
        toReturn *= i;
    }
    return toReturn;
}

void pascalTriangle(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-i-1; j++){
            printf("  ");
        }
        for(int j = 0; j < i+1; j++){
            printf("%3d ", factorial(i)/(factorial(j) * factorial(i-j))); //i_C_j
        }
        printf("\n");
    }
}


/*** Table of multiplication ***/
void mulTable(int n){

    printf(" x |");
    for(int i = 1; i <= n; i++){
        printf("%3d ",i);
    }
    printf("\n");

    printf("---+");
    for(int i = 1; i <= n; i++){
        printf("----");
    }
    printf("\n");

    for(int i = 1; i <=n; i++){
        printf("%2d |", i);
        for (int j = 1; j <= n; j++){
            printf("%3d ", i*j);
        }
        printf("\n");
    }
    return;
}


/*** Get sum from a to b ***/

int sumNum(int a, int b){
    int toReturn;
    int it;

    toReturn = 0;
    it = a;

    while(it <= b){
        toReturn += it;
        it++;
    }

    return toReturn;

}

int sumNumHelper(){
    int a, b;
    int toReturn;
    printf("Lower boundary of sum: ");
    scanf("%d",&a);
    printf("Upper boundary of sum: ");
    scanf("%d",&b);
    toReturn = sumNum(a,b);
    printf("Sum from %d to %d is %d\n", a, b, toReturn);
    return toReturn;
}


/*** Get max, min, median of three numbers ***/

int compareAndContrast(){
    int a, b, c;
    int op;
    int toReturn;

    op = 0;
    toReturn = 0;
    
    printf("Enter three numbers\n");
    printf("First Number: ");
    scanf("%d", &a);
    printf("Second Number: ");
    scanf("%d", &b);
    printf("Third Number: ");
    scanf("%d", &c);

    printf("Press 1 for max, 2 for min, 3 for median: ");
    while(op < 1 || op > 3){
        scanf("%d", &op);
        if(op < 1 || op > 3){
            printf("Wrong operation! Try again: ");
        }
    }
    switch (op){
    case 1:
        printf("Get max of three numbers\n");
        toReturn = getMax(a,b,c);
        break;
    case 2:
        printf("Get min of three numbers\n");
        toReturn = getMin(a,b,c);
        break;
    case 3:
        printf("Get median of three numbers\n");
        toReturn = getMedian(a,b,c);
        break;
    default:
        break;
    }

    printf("%d\n", toReturn);
    return toReturn;
}

int getMax(int a, int b, int c){
    int toReturn;
    if(a >= b){
        toReturn = a;
    }
    else{
        toReturn = b;
    }

    if(toReturn < c){
        toReturn = c;
    }
    return toReturn;
}

int getMin(int a, int b, int c){
    int toReturn;

    if(a < b){
        toReturn = a;
    }
    else{
        toReturn = b;
    }

    if(toReturn > c){
        toReturn = c;
    }

    return toReturn;
}

int getMedian(int a, int b, int c){
    int toReturn;

    if(a >= b){
        if(b >= c){
            toReturn = b;
        }
        else if(c >= a){
            toReturn = a;
        }
        else{
            toReturn = c;
        }
    }
    else if(a > c){
        toReturn = a;
    }
    else if(c > b){
        toReturn = b; 
    }
    else{
        toReturn = c;
    }
    
    return toReturn;

}