#include "LinkedList.h"


void reverseList(Node**head){

    Node* next=NULL;
    Node *prev=NULL;
    Node *curr=*head;

    while(curr){

    next=curr->pNext;
    curr->pNext=prev;
    prev=curr;
    curr=next;
    }
*head=prev;
}

void AddNode(Node** node,int key){
Node* temp=NULL;
Node* head=*node;

#ifdef _DEBUG_
printf("keyvalue:%d\n",key);
#endif
temp=(Node*)calloc(1,sizeof(Node));
temp->key=key;
if(*node==NULL){
    *node=temp;
#ifdef _DEBUG_
    printf("1st Node:%p\n",node);
#endif
}else{
    Node* pTemp=head;
    while(pTemp->pNext){
        pTemp=pTemp->pNext;
#ifdef _DEBUG_
        printf("Node:%p\n",node);
#endif
    }
    pTemp->pNext=temp;
#ifdef _DEBUG_
    printf("last node added:%p\n",temp);
#endif
}
        return ;
}


void printList(Node *node){
    Node* pTemp=node;
    while(pTemp){
        printf("%d\t",pTemp->key);
        pTemp=pTemp->pNext;
    }
    printf("\n");
}
