#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"
#define MAX_ENTRIES 20
#define INVALID_INDEX -1


typedef struct Queue{
    int arr[MAX_ENTRIES];
    int front;
    int rear;
}Queue;


bool isEmptyQ(Queue *q);
void enQueue(int en,Queue *q);
int deQueue(Queue *q);

