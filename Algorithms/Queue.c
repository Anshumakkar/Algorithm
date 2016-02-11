#include "Queue.h"


bool isEmptyQ(Queue *q){
    return (q->front==q->rear)?true:false;
}
void enQueue(int en,Queue *q){
    q->rear++;
    q->arr[q->rear]=en;
}
int deQueue(Queue *q){
    int ret=-1;
    if(!isEmptyQ(q)){
        q->front++;
        ret=q->arr[q->front];
    }
    return ret;
}
