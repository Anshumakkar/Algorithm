#include <stdio.h>
#include <stdlib.h>
#include<limits.h>

/*Dijsktra's Algorithm*/
typedef struct AdjListNode{
int dest;
int weight;
struct  AdjListNode *next;
}AdjListNode;

typedef struct AdjList{
    AdjListNode *head;
}AdjList;

typedef struct Graph{
    int V;
    AdjList* array;
}Graph;


Graph* createGraph(int V){

    Graph* g=(Graph*)calloc(1,sizeof(Graph));
    g->V=V;
    g->array=(AdjList*)calloc(V,sizeof(AdjList));
    return g;

}

AdjListNode* createNewNode(int dest,int weight){

    AdjListNode* newNode=(AdjListNode*)calloc(1,sizeof(AdjListNode));
    newNode->dest=dest;
    newNode->weight=weight;
    newNode->next=NULL;
    return newNode;
}


void AddEdge(Graph* g, int src,int dest,int weight){

    AdjListNode* newNode=createNewNode(dest,weight);
    newNode->next=g->array[src].head;
    g->array[src].head=newNode;

    newNode=createNewNode(src,weight);
    newNode->next=g->array[dest].head;
    g->array[dest].head=newNode;
}

void printGraph(struct Graph* graph)
{
    int v;
    for (v = 0; v < graph->V; ++v)
    {
        struct AdjListNode* pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl)
        {
            printf("-> %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

int MinDistance(int dist[],int sptset[],int V){
    int min_index=-1,min_value=INT_MAX;
    int i=0;
    for(i=0;i<V;i++){
        if(sptset[i]==0&&dist[i]<=min_value){
            min_value=dist[i];
            min_index=i;
        }
    }
    return min_index;

}


void printSolution(int dist[], int n)
{   int i=0;
   printf("Vertex   Distance from Source\n");
   for ( i = 0; i < n; i++)
      printf("%d \t\t %d\n", i, dist[i]);
}


void CalculateShortestPath(Graph* g,int src){
    int i=0;
    int vertices=g->V;
    int *dist=(int*)malloc(g->V*sizeof(int));
    int *sptSet=(int*)calloc(g->V,sizeof(int));
    int u=-1;
    int vertex=0;
    int weight=0;
    AdjListNode *temp=NULL;
    for(i=0;i<vertices;i++){
      dist[i]=INT_MAX;
    }
    dist[src]=0;


    for(i=0;i<vertices;i++){
        u=MinDistance(dist,sptSet,vertices);
        sptSet[u]=1;
        printf("\n vertex=[%d]",u);
        temp=g->array[u].head;
        while(temp){
            vertex=temp->dest;
            weight=temp->weight;
            if(sptSet[vertex]==0 && dist[u]!=INT_MAX && dist[u]+weight<dist[vertex]){
                printf("\nUpdating the distance for vertex[%d] weight=[%d]",vertex,weight);
                dist[vertex]=weight+dist[u];
            }
            temp=temp->next;
        }


    }

    printSolution(dist,vertices);
}
/*
int main()
{
    printf("Hello world!\n");
    Graph*g=createGraph(9);
    AddEdge(g,0,1,4);
    AddEdge(g,0,7,8);
    AddEdge(g,1,2,8);
    AddEdge(g,1,7,11);
    AddEdge(g,2,8,2);
    AddEdge(g,2,3,7);
    AddEdge(g,2,5,4);
    AddEdge(g,3,5,14);
    AddEdge(g,3,4,9);
    AddEdge(g,4,5,10);
    AddEdge(g,5,6,2);
    AddEdge(g,6,8,6);
    AddEdge(g,6,7,1);
    AddEdge(g,7,8,7);
    printGraph(g);
    CalculateShortestPath(g,3);
    return 0;
}
*/
