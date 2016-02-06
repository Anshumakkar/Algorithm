#include <stdio.h>
#include <stdlib.h>
#include "utility.h"

void bubbleSort(int *arr,int len){
int swapped=0;
int i=0;
int n=len;

    do{
        swapped=0;
        for(i=1;i<=n;i++){
            if(arr[i-1]>arr[i]){
                swapped=1;
                swap(&arr[i],&arr[i-1]);
            }
        }
        n=n-1;
    }while(swapped);
}
