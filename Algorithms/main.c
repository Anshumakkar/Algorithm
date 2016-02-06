#include <stdio.h>
#include <stdlib.h>
#include "Quicksort.h"
#include "BubbleSort.h"
#include "Utility.h"

int main()
{
    int arr[]={9,6,5,4};
    printArr(arr,3);
    quicksort(arr,0,3);
    //bubbleSort(arr,3);
    printArr(arr,3);
    return 0;
}
