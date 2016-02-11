
#include "Stack.h"

void push(int a,Stack *s){
    if(s->counter==MAX_ENTRIES-1){
        printf("Stack is full\n");
        return ;
    }
    s->counter++;
    s->arr[s->counter]=a;

}

bool isEmpty(Stack *s){

    return (s->counter>INVALID_INDEX)?false:true;
}

int pop(Stack *s){
    int ret=-1;
    if(isEmpty(s)){
        printf("Stack is empty");
        return -1;
    }
    ret=s->arr[s->counter];
    s->counter--;
    return ret;
}


int top(Stack *s){
    if(isEmpty(s)){
        printf("Stack is empty");
        return -1;
    }else{
        return s->arr[s->counter];
    }
}
