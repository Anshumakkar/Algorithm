#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"
#define MAX_ENTRIES 20
#define INVALID_INDEX -1
typedef struct Stack{
    int arr[MAX_ENTRIES];
    int counter;
}Stack;

void push(int a,Stack *s);
int pop(Stack *s);
int top(Stack *s);
bool isEmpty(Stack *s);



