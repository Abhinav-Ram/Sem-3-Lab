#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node* PNode;

struct Node{
  char data[4];
  PNode next;
};

char* GetData(PNode list){
  return list->data;
}

char* Search(PNode list, char* item){
  PNode temp;
  temp = list;
  while(temp){
    if(!strcmp(temp->data,item)){
      return "Found";
    }
    temp=temp->next;
  }
  return "Not Found";
}

int Length(PNode list){
  int len;
  PNode temp;
  len=0;
  temp=list;
  while(temp){
    len++;
    temp=temp->next;
  }
  return len;
}

PNode InsertLast(PNode list, char item[]){
  PNode temp1 = (PNode) malloc(sizeof(struct Node));
  strcpy(temp1->data,item);
  temp1->next=NULL;
  PNode temp = list;
  if(list==NULL){
    list=temp1;
    return list;
  }
  while(temp->next!=NULL){
    temp=temp->next;
  }
  temp->next=temp1;
  return list;
}

PNode InsertFirst(PNode list, char item[]){
  PNode temp = (PNode) malloc(sizeof(struct Node));
  strcpy(temp->data,item);
  temp->next=list;
  list=temp;
  return list;
}
  
char* DeleteFirst(PNode* list){
  char * c = (char *) malloc(sizeof(char) * 5);
  PNode temp = *list;
  if(!temp)
    return "\0";
  strcpy(c, GetData(temp));
  *list=(*list)->next;
  free(temp);
  return c;
}
char* DeleteLast(PNode *list) {
	PNode temp = (*list)->next, prev = *list;
	if(!temp) return "\0";
	char * c = (char *) malloc(sizeof(char) * 5);
	while(temp->next){ 
		temp = temp->next;
		prev = prev->next;
	}
	strcpy(c, GetData(temp));
	prev->next=NULL;
	free(temp);
	return c;
}
void InsertMiddle(PNode list, char* item1, char* item2){
  PNode temp1, temp;
  temp = list;
  while(temp!=NULL){
    if(!strcmp(temp->data,item1))
      temp1=temp;
    temp=temp->next;
  }
  temp=temp1;
  temp1=NULL;
  temp1=(PNode) malloc(sizeof(struct Node)); 
  strcpy(temp1->data,item2);
  temp1->next=temp->next;
  temp->next=temp1;
}

void DeleteMiddle(PNode list, char * item) {
    PNode temp = list -> next, prev = list;
    while(temp) {
        if (!strcmp(item, temp -> data)) {
            prev -> next = temp -> next;
            free(temp);
            return;
        }
        temp = temp -> next;
        prev = prev -> next;
    }
    
}