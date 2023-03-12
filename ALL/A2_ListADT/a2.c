#include <stdio.h>
#include "ListADT.h"

void Display(PNode list){
  PNode temp;
  temp = list;
  if(list==NULL){
    printf("No names\n");
    return;
  }
  while(temp){
    printf("%s ",GetData(temp));
    temp=temp->next;
  }
  printf("\n");
}


void CreateSorted(PNode *head,char item[])
{
    if(*head==NULL)
    {
        *head = InsertFirst(*head,item);
        return;
    }

    PNode curr= *head;
    PNode prev=NULL;

    while(curr!=NULL)
    {
        if(strcmp(GetData(curr),item)>0)
        {
            if(prev==NULL)
            {
                *head = InsertFirst(*head,item);
                return;
            }
            else
            {
                InsertMiddle(*head,prev->data,item);
                return;
            }
        }
        prev=curr;
        curr=curr->next;
    }
    
    if(curr==NULL)
    {
        *head = InsertLast(*head,item);
        return;
    }
}
PNode Reverse(PNode  *list){
  PNode prev, next, curr;
  prev = next = NULL;
  curr= *list;
  while(curr){
    next=curr->next;
    curr->next=prev;
    prev=curr;
    curr=next;
  }
  *list=prev;
  return *list;
}

PNode RotateLeft(PNode  *list){
  char* c = (char *) malloc(sizeof(char) * 5);
  strcpy(c,DeleteFirst(list));
  InsertLast(*list,c);
}

void main() {
  PNode l1 = NULL;
  PNode l2 = NULL;
  Display(l1); //No names
  printf("Length(l1) "); printf("%d\n",Length(l1)); // 0
  printf("InsertLast(l1,\"cat\") "); l1=InsertLast(l1,"cat"); 
  Display(l1); // cat
  printf("InsertLast(l1,\"mat\") "); l1=InsertLast(l1,"mat"); 
  Display(l1); // cat mat
  printf("InsertFirst(l1,\"rat\") "); l1=InsertFirst(l1,"rat"); 
  Display(l1); // rat cat mat
  printf("InsertLast(l1,\"cat\") "); l1=InsertLast(l1,"cat"); 
  Display(l1); // rat cat mat cat
  printf("InsertMiddle(l1,\"cat\",\"bat\") "); InsertMiddle(l1,"cat","bat"); 
  Display(l1); // rat cat mat cat bat
  printf("Search(l1,\"mat\") "); 
  printf("%s\n",Search(l1,"mat")); //Found
  printf("Search(l1,\"sat\") "); 
  printf("%s\n",Search(l1,"sat")); //Not Found
  printf("GetData(l1) "); printf("%s\n",GetData(l1)); // rat
  printf("Length(l1) "); printf("%d\n",Length(l1)); // 5
  printf("Reverse(l1) "); l2=Reverse(&l1); 
  Display(l2); //bat cat mat cat rat
  printf("DeleteMiddle(l1) "); DeleteMiddle(l1,"cat");
  Display(l1); // bat mat cat rat
  printf("DeleteFirst(l1) "); DeleteFirst(&l1); 
  Display(l1); // mat cat rat
  printf("DeleteLast(l1) "); DeleteLast(&l1);
  Display(l1); // mat cat
  printf("CreateSorted(l1,\"pat\") "); CreateSorted(&l1,"pat"); 
  Display(l1); // mat cat pat
  printf("CreateSorted(l1,\"eat\") "); CreateSorted(&l1,"eat"); 
  Display(l1); // eat mat cat pat
  printf("CreateSorted(l1,\"ant\") "); CreateSorted(&l1,"ant"); 
  Display(l1); // ant eat mat cat pat
  printf("RotateLeft(l1) "); RotateLeft(&l1); 
  Display(l1);
}