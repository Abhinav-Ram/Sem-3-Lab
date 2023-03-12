#include <stdio.h>
#include "polyADT.h"


void Display(Poly expr){
  Poly temp;
  temp = expr;
  if(expr->coeff==0&&expr->exp==0){
    printf("Null\n");
    return;
  }
  while(temp->next){
    if(temp->coeff!=0)
      printf("%dx%d+",temp->coeff, temp->exp);
    temp=temp->next;
  }
  printf("%d",temp->coeff);
  printf("\n");
}

Poly SumPoly(Poly poly1,Poly poly2){
  Poly sum = NULL;
  int degree = (poly1->exp>=poly2->exp)?poly1->exp:poly2->exp;
  while(degree>=0){
    InsertOrder(&sum,(Coeff(poly1,degree)+Coeff(poly2,degree)),degree);
    degree--;
  }
  return sum;
}

void main(){
  int coeff, exp;
  printf("Enter the polynomial coeff and exp separated by SPACE and each term's coeff and exp separated by NEWLINE.\nTerminate your imput with a constant term with exp=0.\nEnter the first polynomial:\n");
  do{
    scanf("%d %d", &coeff,&exp);
    InsertOrder(&poly1,coeff,exp);
  }while(exp!=0);
  Display(poly1);

  printf("Enter the second polynomial:\n");
  do{
    scanf("%d %d", &coeff,&exp);
    InsertOrder(&poly2,coeff,exp);
  }while(exp!=0);
  Display(poly2);
  printf("Sum is:\n");
  Display(SumPoly(poly1,poly2));
}