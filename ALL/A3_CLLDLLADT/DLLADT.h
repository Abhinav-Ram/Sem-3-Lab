#include <stdlib.h>

typedef struct Node* PNode;

struct Node{
  int data;
  PNode next;
  PNode prev;
};

int Size(PNode *CLL){
    int count=0;
    PNode temp = (*CLL);
    while(*CLL){
        temp->next = temp;
        count++;
    }
    return count;
}

void InsertFirst(PNode* DLL, int item){
  PNode temp = (PNode) malloc(sizeof(struct Node));
  temp->data = item;
  temp->prev = NULL;
  if(!(*DLL)){
    temp->next = NULL;
    (*DLL) = temp;
    return;
  }
  temp->next = (*DLL);
  (*DLL)->prev = temp;
  (*DLL) = temp;
}

void InsertLast(PNode* DLL, int item){
  PNode temp = (PNode) malloc(sizeof(struct Node));
  temp->data = item;
  temp->next = NULL;
  if(!(*DLL)){
    temp->prev = NULL;
    (*DLL) = temp;
    return;
  }
  PNode temp1 = (*DLL);
  while(temp1->next){
    temp1=temp1->next;
  }
  temp1->next = temp;
  temp->prev = temp1;
}

PNode DeleteFirst(PNode* DLL){
  PNode temp=(*DLL);
  if(!temp)
    return NULL;
  if(!(temp->next)){
    (*DLL) = NULL;
    return temp;
  }
  (*DLL) = (*DLL)->next;
  (*DLL)->prev = NULL;
  return temp;
}

PNode DeleteLast(PNode* DLL){
  PNode temp=(*DLL);
  if(!temp)
    return NULL;
  if(!(temp->next)){
    (*DLL) = NULL;
    return temp;
  }
  while(temp->next) temp = temp->next;
  PNode temp1 = temp->prev;
  temp1->next = NULL;
  return temp;
}