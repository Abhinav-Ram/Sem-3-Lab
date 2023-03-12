#include <stdio.h>
#include "DLLADT.h"

void Display(PNode DLL);
void Rotate(PNode *DLL,int direction, int count);

void main(){
  PNode DLL = NULL;
  printf("DLL= "); Display(DLL);
  printf("insertfirst(DLL,3) "); InsertFirst(&DLL,3);
  Display(DLL);
  printf("insertfirst(DLL,5) "); InsertFirst(&DLL,5);
  Display(DLL);
  printf("insertlast(DLL,6) "); InsertLast(&DLL, 6);
  Display(DLL);
  printf("rotate(DLL,1,1) "); Rotate(&DLL,1,1);
  Display(DLL);
  printf("rotate(DLL,-1,1) "); Rotate(&DLL,-1,1);
  Display(DLL);
  printf("rotate(DLL,1,3) "); Rotate(&DLL,1,3);
  Display(DLL);
  printf("rotate(DLL,1,4) "); Rotate(&DLL,1,4);
  Display(DLL);
  printf("deletefirst(DLL) "); DeleteFirst(&DLL);
  Display(DLL);
  printf("deletelast(DLL) "); DeleteLast(&DLL);
  Display(DLL);
  printf("deletelast(DLL) "); DeleteLast(&DLL);
  Display(DLL);
}

void Rotate(PNode *DLL,int direction, int count){
  if(!(*DLL)){
    return;
  }
  int c=0;
  int temp;
  if (direction==-1)
    while(c<count){
      temp=(DeleteFirst(DLL))->data;
      InsertLast(DLL,temp);
      c++;
    }
  else if(direction==1)
    while(c<count){
      temp=(DeleteLast(DLL))->data;
      InsertFirst(DLL,temp);
      c++;
    }
}


void Display(PNode DLL){
  PNode temp;
  temp = DLL;
  if(!DLL){
    printf("Null\n");
    return;
  }
  do{
    printf("%d ",temp->data);
    temp=temp->next;
  }while(temp);
  printf("\n");
}