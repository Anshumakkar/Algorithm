#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
int key;
struct Node *pNext;
}Node;


void reverseList(Node**head);
void AddNode(Node** node,int key);
void printList(Node *node);

