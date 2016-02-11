#include "Graph.h"
#include "Stack.h"
#include "Queue.h"

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
void DFSUtil(Graph *g,int src,int *arr){
    Stack st={{0},-1};
    int i=0;

    if(src>g->v){
        printf("src vertex is greater than max vertices");
        return;
    }
    push(src,&st);
    arr[src]=1;
    printf("DFS: %d", src);
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
            DFSUtil(g,i,visited);
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
    printf("BFS: ");
    while(!isEmptyQ(&q)){
        int temp=deQueue(&q);
        printf(" %d",temp);
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
            BFSUtil(g,i,visited);
            counter++;
        }
    }
    printf("\nTotal Connected Components using BFS:%d\n",counter);

}
