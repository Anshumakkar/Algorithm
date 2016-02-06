#include <stdio.h>

void swap(int *a,int *b){
int t=*a;
*a=*b;
*b=t;
}


void printArr(int *a,int len){
int i=0;

    for( i=0;i<=len;i++){
        printf(" %d ",a[i]);
    }
    printf("\n");
}
