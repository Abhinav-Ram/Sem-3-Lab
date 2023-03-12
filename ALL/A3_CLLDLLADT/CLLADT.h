#include <stdlib.h>

typedef struct Node* PNode;

struct Node{
  int data;
  PNode next;
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

void InsertFirst (PNode* CLL, int item){
  PNode temp = (PNode) malloc(sizeof(struct Node));
  temp->data = item;
  if (!(*CLL)) {
    (*CLL)=temp;
    temp->next = temp;
    return; 
  }
  temp->next = (*CLL)->next; 
  (*CLL)->next = temp; 
}

void InsertLast (PNode* CLL, int item){
  PNode temp = (PNode) malloc(sizeof(struct Node));
  temp->data = item;
  PNode temp1;
  if (!(*CLL)) {
    (*CLL)=temp;
    temp->next = temp;
    return; 
  }
  temp1=(*CLL)->next;
  (*CLL)->next=temp;
  (*CLL)=temp;
  (temp->next)=temp1;

}

PNode DeleteFirst(PNode* CLL){
  PNode temp;
  if(!(*CLL))
    return NULL;
  if((*CLL)->next==(*CLL)){
    temp = (*CLL);
    (*CLL)=NULL;
    return temp;
  }
  temp=(*CLL)->next;
  (*CLL)->next = (*CLL)->next->next;
  return temp;
}

PNode DeleteLast(PNode* CLL){
  PNode temp;
  PNode temp1;
  if(!(*CLL))
    return NULL;
  if((*CLL)->next==(*CLL)){
    temp=(*CLL);
    (*CLL)=NULL;
    return temp;
  }
  temp=(*CLL)->next;
  temp1=(*CLL);
  while(temp->next!=(*CLL))
    temp=temp->next;
  temp->next = (*CLL)->next;
  (*CLL)=temp;
  return temp1;
}
