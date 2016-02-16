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
    Graph *gC=NULL;
    gC=(Graph*)calloc(1,sizeof(Graph));
    gC->v=5;
    addEdge(0, 1,gC);
    addEdge(0, 2,gC);
    addEdge(1, 2,gC);
    addEdge(0, 3,gC);
    addEdge(3, 4,gC);
 	printAdjMatrix(gC);
    printf("\n");
    isUndirectedGraphCyclic(gC);


	 Graph *gDC=NULL;
    gDC=(Graph*)calloc(1,sizeof(Graph));
    gDC->v=4;
    addDirectedEdge(0, 1,gDC);
    addDirectedEdge(0, 2,gDC);
    addDirectedEdge(1, 2,gDC);
    addDirectedEdge(2, 0,gDC);
    addDirectedEdge(2, 3,gDC);
    addDirectedEdge(3, 3,gDC);
	printAdjMatrix(gDC);
	isDirectedGraphCyclic(gDC);

/** Topological Sort*/

    Graph *gTSort=NULL;
    gTSort=(Graph*)calloc(1,sizeof(Graph));
    gTSort->v=6;
     addDirectedEdge(5, 2,gTSort);
    addDirectedEdge(5, 0,gTSort);
    addDirectedEdge(4, 0,gTSort);
    addDirectedEdge(2, 3,gTSort);
    addDirectedEdge(3, 1,gTSort);
    addDirectedEdge(4, 1,gTSort);
    topologicalSort(gTSort);
    return 0;
}
