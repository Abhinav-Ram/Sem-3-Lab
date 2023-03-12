#include <stdio.h>
#include "StackTree.h"
#include "StackADT.h"

int Prec(char);
int InfixToPostfix(char*);
int IsBalParan(char *exp);
int IsOperator(char ch);
int Operate(int val1, int val2, char op);
int IsOperand(char ch);
int Solve(et t);
et ConstructTree(char* exp);

void main() {
  int i, j;
  char var[SIZE];
  int val[SIZE];
  char exp[] = "A*(B+C)/D";
  printf("Infix expression: %s\n",exp);
  InfixToPostfix(exp);
  printf("Postfix expression: %s\n",exp);
  et t = ConstructTree(exp);

  printf("\nInorder traversal of binary tree is \n");
  InOrder(t);
  printf("\nPreorder traversal of binary tree is \n");
  PreOrder(t);
  printf("\nPostorder traversal of binary tree is \n");
  PostOrder(t);
  printf("\nLevelorder traversal of binary tree is \n");
  LevelOrder(t);
  printf("\n");
  print2D(t);

  printf("\nEvaluation of the above expression.\n");
  printf("Result is %d\n",Solve(t));
}


//UTILITY FUNCTIONS:-
int SolveUTIL(et t){
  int num;
  if(t){
    if(IsOperand(t->data)){
      printf("Enter %c:",t->data);
      scanf("%d",&num);
      return num;
    }
    return Operate(SolveUTIL(t->left), SolveUTIL(t->right), t->data);
  }
}


int IsBalParan(char* exp){
  struct Stack* stack = createStack(strlen(exp));
	int i=0;
	while(exp[i]){
		if(exp[i]=='('){
			Push(stack, exp[i]);
		}
		else if(exp[i]==')'){
			if(IsEmpty(stack)){
				return 0;
			}
			else{
				Pop(stack);
			}	
		}		
		i++;
	}	
	if(!IsEmpty(stack))
		return 0;
	return 1;
}
int Prec(char ch){
  switch (ch){
    case '+':
    case '-':
        return 1; 
    case '*':
    case '/':
      return 2;
  }
  return -1;
}
int IsOperator(char ch){
  return (ch == '+') || (ch == '-') || (ch == '*') || (ch == '/');
}
int Operate(int val1, int val2, char op){
  switch (op){
    case '+': return val1+val2;
    case '-': return val1-val2;
    case '*': return val1*val2;
    case '/': return val1/val2;
  }
  return INT_MIN;
}
int IsOperand(char ch){
    return (ch >= 'a' && ch <= 'z') ||
           (ch >= 'A' && ch <= 'Z');
}

//infix to postfix using stack
int InfixToPostfix(char* exp){
  int i, k;
  struct Stack* stack = createStack(strlen(exp));
  if(!stack){
    //printf("Out of memory\n");
    return 0;
  }
  if(!IsBalParan(exp)){
    //printf("Unbalanced braces\n");
    return 0;
  }

  for (i = 0, k = -1; exp[i]; ++i){
    if (IsOperand(exp[i])){
      if(i!=0 && IsOperand(exp[i-1])){
        //printf("Consecutive Operands not allowed\n");
          return 0;
      }
      exp[++k] = exp[i];
    }

    else if (exp[i] == '(')
      Push(stack, exp[i]); //Push ( to stack)
    
    else if (exp[i] == ')'){
      while (!IsEmpty(stack) && GetTop(stack)!= '(')
        exp[++k] = Pop(stack); //Pop until u counter corresponding (
      if (!IsEmpty(stack) && GetTop(stack) !='('){
        //printf("Invalid Exprn\n");
        return 0;   
      }
      else
        Pop(stack);
    }

    else if (IsOperator(exp[i])) {
      if(i==0){
        //printf("Starting character can't be an operator\n");
        return 0;
      }   
      if(IsOperator(exp[i-1])){
        //printf("Consecutive Operators not allowed\n");
        return 0;
      }
      while (!IsEmpty(stack) && Prec(exp[i]) <= Prec(GetTop(stack)))
        exp[++k] = Pop(stack);
      Push(stack, exp[i]);
    }
    
    else{
      //printf("Invalid Character present\n");
      return 0;
    }
  }

  while (!IsEmpty(stack)){
    if(GetTop(stack)!='(')
      exp[++k] = Pop(stack);
    else
    Pop(stack);
  }  
  exp[++k] = '\0';
  return 1;
}

//construct expression tree
et ConstructTree(char* exp){
  struct TStack* st = Create(strlen(exp));
  et t, t1, t2;
  for (int i=0; i<strlen(exp); i++){
    if (!IsOperator(exp[i])){
      t = Construct(exp[i]);
      push(st,t);
    }
    else {
      t = Construct(exp[i]);
      t1 = pop(st);     
      t2 = pop(st);
      t->right = t1;
      t->left = t2;
      push(st,t);
    }
  }
  t = pop(st);
  return t;
}

//evaluate expression
int Solve(et t){
  return SolveUTIL(t);
}
