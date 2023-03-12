#include <stdio.h>
#include "CLLADT.h"

void Display(PNode CLL);
void Rotate(PNode *CLL,int direction, int count);

void main(){
  PNode CLL = NULL;
  printf("CLL= "); Display(CLL);
  printf("insertfirst(CLL,3) "); InsertFirst(&CLL,3);
  Display(CLL);
  printf("insertfirst(CLL,5) "); InsertFirst(&CLL,5);
  Display(CLL);
  printf("insertlast(CLL,6) "); InsertLast(&CLL, 6);
  Display(CLL);
  printf("rotate(CLL,1,1) "); Rotate(&CLL,1,1);
  Display(CLL);
  printf("rotate(CLL,-1,1) "); Rotate(&CLL,-1,1);
  Display(CLL);
  printf("rotate(CLL,1,3) "); Rotate(&CLL,1,3);
  Display(CLL);
  printf("rotate(CLL,1,4) "); Rotate(&CLL,1,4);
  Display(CLL);
  printf("deletefirst(CLL) "); DeleteFirst(&CLL);
  Display(CLL);
  printf("deletelast(CLL) "); DeleteLast(&CLL);
  Display(CLL);
  printf("deletelast(CLL) "); DeleteLast(&CLL);
  Display(CLL);
}

void Rotate(PNode *CLL,int direction, int count){
  if(!(*CLL)){
    return;
  }
  int c=0;
  int temp;
  if (direction==-1)
    while(c<count){
      temp=(DeleteFirst(CLL))->data;
      InsertLast(CLL,temp);
      c++;
    }
  else if(direction==1)
    while(c<count){
      temp=(DeleteLast(CLL))->data;
      InsertFirst(CLL,temp);
      c++;
    }
}

void Display(PNode CLL){
  PNode temp;
  if(!CLL){
    printf("Null\n");
    return;
  }
  temp=CLL->next;
  do{
    printf("%d ",temp->data);
    temp=temp->next;
  }while(temp!=CLL->next);
  printf("\n");
}