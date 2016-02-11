#include <stdio.h>
#include <stdlib.h>
#include "Quicksort.h"
#include "BubbleSort.h"
#include "Utility.h"
#include "LinkedList.h"
#include "Stack.h"
#include "Graph.h"
#include "Queue.h"

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
	  Graph *g=NULL;
    g=(Graph*)calloc(1,sizeof(Graph));
    g->v=6;
    addEdge(0, 1,g);
    addEdge(0, 2,g);
    addEdge(1, 2,g);
    addEdge(2, 0,g);
    addEdge(2, 3,g);
    addEdge(4, 5,g);
    addEdge(5,5,g);
    printAdjMatrix(g);
    printf("\n");
    DFS(g);
    BFS(g);

	
    return 0;
}
