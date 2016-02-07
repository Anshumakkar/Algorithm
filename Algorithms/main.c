#include <stdio.h>
#include <stdlib.h>
#include "Quicksort.h"
#include "BubbleSort.h"
#include "Utility.h"
#include "LinkedList.h"

int main()
{
    int arr[]={9,6,5,4};
    printArr(arr,3);
    quicksort(arr,0,3);
    //bubbleSort(arr,3);
    printArr(arr,3);
    Node* p=NULL;
    AddNode(&p,10);
    AddNode(&p,20);
    AddNode(&p,30);
    AddNode(&p,40);
    AddNode(&p,90);
    printList(p);
    reverseList(&p);
    printList(p);
    return 0;
}
