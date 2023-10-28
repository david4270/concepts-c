#include "algo.h"
#include <stdlib.h>

int maxOf(const int a[], int n){
    int max = a[0];
    for(int i = 0; i < n; i++){
        if(a[i] > max){
            max = a[i];
        }
    }
    return max;
}

int arrayWork(){
    int * a;
    int n;

    printf("size of array: ");
    scanf("%d", &n);

    a = calloc(n, sizeof(int));

    if (a == NULL){
        printf("Failed to allocate memory");
        return -1;
    }
    else{
        for(int i = 0; i < n; i++){
            printf("%dth element of array:", i+1);
            scanf("%d", &a[i]);
        }

        for(int i = 0; i < n; i++){
            printf("%d ", a[i]);
        }
        printf("\n");
        printf("The maximum of array is %d\n", maxOf(a,n));
        free(a);
    }
    return 0;
}


#define swap(type,x,y) do{type t = x; x = y; y = t;} while(0)

int swapArray(){
    int * a;
    int n;

    printf("Size of array: ");
    scanf("%d", &n);

    a = calloc(n, sizeof(int));

    if(a == NULL){
        printf("Failed to allocate memory");
        return -1;
    }

    for(int i = 0; i < n; i++){
        printf("%dth element fo arrary: ", i+1);
        scanf("%d",&a[i]);
    }
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }

    printf("\n");

    //swap order of array

    for(int i = 0; i < n/2; i++){
        swap(int,a[i],a[n-i-1]);
    }

    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }

    free(a);


    return 0;
}