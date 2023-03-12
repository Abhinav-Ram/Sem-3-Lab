#include <stdio.h>
#include <string.h>
#include "StackADT.h"

int IsPair(char,char);
void IsBalanced(char*);

void main(){
  char exp[MAX_SIZE];
  strcpy(exp,"[()]");
  printf("\nVALID EXPRESSION: %s\n",exp);
  IsBalanced(exp);

  strcpy(exp,"([)]");
  printf("\nDISORDERLY ARRANGED: %s\n",exp);
  IsBalanced(exp);

  strcpy(exp,"([]))");
  printf("\nUNBALANCED NO OF PARANTHESES/BRACKETS: %s\n",exp);
  IsBalanced(exp);

  strcpy(exp,"([)]");
  printf("\nDISORDERLY ARRANGED: %s\n",exp);
  IsBalanced(exp);
}

void IsBalanced(char* exp){
  struct Stack* stack = createStack(strlen(exp));
  int i;
  for(i = 0; exp[i]; i++){
    if(exp[i] == '(' || exp[i] == '['){
      Push(stack,exp[i]);
    }
    else if(exp[i] == ')' || exp[i] == ']'){
      if(IsEmpty(stack) || !IsPair(Pop(stack),exp[i])){
        printf("Unbalanced expression\n");
        return;
      }
    }
    else{
      printf("Unbalanced expression\n");
      return;
    }
  }
  if(IsEmpty(stack)){
    printf("Balanced expression\n");
    return;
  }
  else{
    printf("Unbalanced expression\n");
    return;
  }
}

int IsPair(char c1,char c2){
  return c1 == '(' && c2 == ')' || c1 == '[' && c2 == ']';
}