#include "Graph.h"
#include "Stack.h"
#include "Queue.h"


void addDirectedEdge(int v,int w,Graph *g){
    if(v>g->v||w>g->v){
        printf("Array index of bounds\n");
        return ;
    }
     g->adj[v][w]=1;
}
void addEdge(int v,int w,Graph *g)
{
    if(v>g->v||w>g->v){
        printf("Array index of bounds\n");
        return ;
    }
    g->adj[v][w]=1;
    g->adj[w][v]=1;
}



void printAdjMatrix(Graph *g){
    int i=0,j=0;
    for( i=0;i<g->v;i++){
        for( j=0;j<g->v;j++){
            printf(" %d ",g->adj[i][j]);
        }
        printf("\n");
    }

}



void DFSUtilRecurive(Graph*g,int src,int *arr){

    int i=0;
    arr[src]=1;
    printf(" %d ",src);
   // printf("Entering with %d\n",src);
    for(i=0;i<g->v;i++){
        if(g->adj[src][i]!=0 && arr[i]==0){
                //printf("goinginside with %d\n",i);
            DFSUtilRecurive(g,i,arr);
        }
    }
//printf("exiting with %d\n",src);

}
void DFSUtil(Graph *g,int src,int *arr){
    Stack st={{0},-1};
    int i=0;

    if(src>g->v){
        printf("src vertex is greater than max vertices");
        return;
    }
    push(src,&st);
    arr[src]=1;
    printf(" %d", src);
    while(!isEmpty(&st)){
        int temp=top(&st);
        int f=0;
        for(i=0;i<g->v;i++){
            if(g->adj[temp][i]!=0 && arr[i]==0){
                printf(" %d ",i);
                push(i,&st);
                arr[i]=1;
                f=1;
                break;
            }
        }
        if(f==0)
            pop(&st);

    }
    printf("\n");
}


void DFS(Graph *g){
    int visited[MAX_VERTICES];
    int i=0;
    int counter=0;
    for(i=0;i<MAX_VERTICES;i++){
        visited[i]=0;
    }
    for(i=0;i<g->v;i++){
        if(visited[i]==0){
            printf("\nConnected Component using DFS:--> ",(counter+1));
            DFSUtilRecurive(g,i,visited);
            printf("\n");
            counter++;
        }
    }
    printf("\nTotal Connected Components using DFS:%d\n",counter);

}


void BFSUtil(Graph *g,int src,int *arr){
    Queue q={{0},-1,-1};
    int i=0;

    if(src>g->v){
        printf("src vertex is greater than max vertices");
        return;
    }
    enQueue(src,&q);
    arr[src]=1;
    while(!isEmptyQ(&q)){
        int temp=deQueue(&q);
        printf(" %d ",temp);
        for(i=0;i<g->v;i++){
            if(g->adj[temp][i]!=0 && arr[i]==0){
               // printf(" %d ",i);
                enQueue(i,&q);
                arr[i]=1;
            }
        }
    }
    printf("\n");
}



void BFS(Graph *g){
 int visited[MAX_VERTICES];
    int i=0;
    int counter=0;
    for(i=0;i<MAX_VERTICES;i++){
        visited[i]=0;
    }
    for(i=0;i<g->v;i++){
        if(visited[i]==0){
            printf("\nConnected Component using BFS:--> ",(counter+1));
            BFSUtil(g,i,visited);
            printf("\n");
            counter++;
        }
    }
    printf("\nTotal Connected Components using BFS:%d\n",counter);

}
bool isUndirectedGraphCyclicUtil(Graph *g,int src,int* arr,int parent){
    int i=0;
    arr[src]=1;
    printf(" %d ",src);
   // printf("Entering with %d\n",src);
    for(i=0;i<g->v;i++){
        if(g->adj[src][i]!=0){
                //printf("goinginside with %d\n",i);
            if(arr[i]==0)
               if( isUndirectedGraphCyclicUtil(g,i,arr,src))
                    return true;
            else if(i!=parent)
                return true;

        }
    }
    return false;

}

bool isUndirectedGraphCyclic(Graph *g){
  int visited[MAX_VERTICES];
  bool retValue=true;
    int i=0;
    int counter=0;
    for(i=0;i<MAX_VERTICES;i++){
        visited[i]=0;
    }
    for(i=0;i<g->v;i++){
        if(visited[i]==0){
            if(isUndirectedGraphCyclicUtil(g,i,visited,-1)){
                printf("Cycle exists\n");
                return true;
            }
        }
    }
    printf("Cycle does not exists\n");
    return false;
}

bool isDirectedGraphCyclicUtil(Graph *g,int src,int* arr,int* recStack){
    int i=0;
    arr[src]=1;
    recStack[src]=1;
    for(i=0;i<g->v;i++){
        if(g->adj[src][i]!=0){
            if(arr[i]==0 && isDirectedGraphCyclicUtil(g,i,arr,recStack))
                return true;
            else if(recStack[i]==1)
                return true;


        }
    }
    recStack[src]=0;
    return false;

}

bool isDirectedGraphCyclic(Graph *g){
  int visited[MAX_VERTICES];
  int recStack[MAX_VERTICES];
  int i=0;
    for(i=0;i<MAX_VERTICES;i++){
        visited[i]=0;
        recStack[i]=0;
    }

     for(i=0;i<g->v;i++){
        if(visited[i]==0){
            if((isDirectedGraphCyclicUtil(g,i,visited,recStack))){
                printf("Cycle exists\n");
                return true;
            }
        }
    }
    printf("Cycle does not exists\n");
    return false;
}


void topologicalSortUtil(Graph* g,int src,int* visited,Stack *S){

     int i=0;
    visited[src]=1;
      for(i=0;i<g->v;i++){
        if(g->adj[src][i]!=0 && visited[i]==0){
            topologicalSortUtil(g,i,visited,S);
        }
    }
     //printf("push %d ", src);
    push(src,S);
    //printf(" %d\n",S->counter);
}



void topologicalSort(Graph *g){

Stack *S=NULL;
S=(Stack *)calloc(1,sizeof(Stack));
S->counter=INVALID_INDEX;
int *visited=NULL;
int i=0;
visited=(int*)calloc(g->v,sizeof(int));

for(i=0;i<g->v;i++){
    if(visited[i]==0){
        topologicalSortUtil(g,i,visited,S);
    }
}
printf("\n********************\nTopological Sort : ");
while(!isEmpty(S)){
    int ret= pop(S);
    printf(" %d", ret);

}


printf("\n********************\n");


}



