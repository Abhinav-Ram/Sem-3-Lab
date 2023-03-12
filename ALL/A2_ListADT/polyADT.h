#include<stdlib.h>

typedef struct poly* Poly;

struct poly
{
  int coeff;
  int exp;
  Poly next;
};

int Coeff(Poly expr, int exp){
  Poly temp=expr;
  int coeff=0;
  while(temp){
    if(temp->exp==exp){
      coeff += temp->coeff;
    }
    temp=temp->next;
  }
  return coeff;
}

void InsertOrder(Poly* expr, int coeff, int exp){
  Poly temp = (Poly) malloc(sizeof(struct poly));
  Poly curr, prev;
  temp->coeff = coeff;
  temp->exp = exp;
  temp->next=NULL;
  if(*expr==NULL){
    *expr=temp;
    return;
  }
  else {
    if(temp->exp>(*expr)->exp){
      temp->next=*expr;
      *expr=temp;
      return;
    }
    else{
      prev=*expr;
      curr=(*expr)->next;
      while(curr){
        if(temp->exp>curr->exp){
          temp->next=curr;
          prev->next=temp;
          return;
        }
        curr=curr->next;
        prev=prev->next;
      }
    }
    if(curr==NULL){
      prev->next=temp;
    }
  }
}

Poly poly1 = NULL;
Poly poly2 = NULL;