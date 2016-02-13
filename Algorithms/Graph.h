#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"
#define MAX_VERTICES 20
#define INVALID_INDEX -1


typedef struct Graph{
    int v;
    int adj[MAX_VERTICES][MAX_VERTICES];
}Graph;

void addEdge(int v,int w,Graph *g);
void DFSUtil(Graph *g,int src,int *arr);
void printAdjMatrix(Graph *g);
void DFS(Graph *g);
void BFSUtil(Graph *g,int src,int *arr);
void BFS(Graph *g);
