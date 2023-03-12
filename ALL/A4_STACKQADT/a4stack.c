#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "StackADT.h"

int power(int,int);
int IsOperand(char);
int IsOperator(char);
int Prec(char);
int NoOfDigits(int);
int Operate(int,int,char);

int InfixToPostfix(char*);
int EvalPostfix(char* exp);
int IsBalParan(char *exp);

void main(){
  char exp[MAX_SIZE];

  printf("\nInfixToPostfix:-\n");
  strcpy(exp,"(a+(b)");
  printf("UNBALANCED BRACE: %s\n",exp);
  InfixToPostfix(exp);

  strcpy(exp,"+a+b");
  printf("STARTING WITH OPERATOR: %s\n",exp);
  InfixToPostfix(exp);

  strcpy(exp,"a++b");
  printf("CONSECUTIVE OPERATOR: %s\n",exp);
  InfixToPostfix(exp);

  strcpy(exp,"ab+c");
  printf("CONSECUTIVE OPERAND: %s\n",exp);
  InfixToPostfix(exp);

  printf("\nEvalPostfix:-\n");
  printf("Format:\n1) Positive Number - space(\' \') followed by number\n");
  printf("2) Negative Number - underscore(\'_\') followed by number (underscore to represent negative sign)\n");
  printf("3) Operator - just the operator\n");
  
  strcpy(exp," 6_5$ 3/ 4+");
  printf("\nINVALID EXPRESSION: (prints INT_MIN)\n%s ($ symbol)\n",exp);
  printf("Result: %d\n",EvalPostfix(exp));

  strcpy(exp," 6 5 3/4+");
  printf("\nINVALID EXPRESSION: (prints wrong result)\n%s (no space before 4)\n",exp);
  printf("Result: %d\n",EvalPostfix(exp));

  strcpy(exp," 6_5* 3/ 4+");
  printf("\nVALID EXPRESSION:\n%s\n",exp);
  printf("Result: %d\n",EvalPostfix(exp));

}

int InfixToPostfix(char* exp){
  int i, k;
  struct Stack* stack = createStack(strlen(exp));
  if(!stack){
    printf("Out of memory\n");
    return 0;
  }
  if(!IsBalParan(exp)){
    printf("Unbalanced braces\n");
    return 0;
  }

  for (i = 0, k = -1; exp[i]; ++i){
    if (IsOperand(exp[i])){
      if(i!=0 && IsOperand(exp[i-1])){
        printf("Consecutive Operands not allowed\n");
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
        printf("Invalid Exprn\n");
        return 0;   
      }
      else
        Pop(stack);
    }

    else if (IsOperator(exp[i])) {
      if(i==0){
        printf("Starting character can't be an operator\n");
        return 0;
      }   
      if(IsOperator(exp[i-1])){
        printf("Consecutive Operators not allowed\n");
        return 0;
      }
      while (!IsEmpty(stack) && Prec(exp[i]) <= Prec(GetTop(stack)))
        exp[++k] = Pop(stack);
      Push(stack, exp[i]);
    }
    
    else{
      printf("Invalid Character present\n");
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
  printf("%s\n",exp);
  return 1;
}

int EvalPostfix(char* exp){
  struct Stack* stack = createStack(strlen(exp));
  int i, k, digit;
  int val1, val2;
  if (!stack) return INT_MIN+1; //Memory error

  for (i = 0; exp[i]; ++i){
    if (isdigit(exp[i]) || exp[i] == '_' || exp[i] == ' '){
      Push(stack,exp[i]);
      //printf("Pushed %c\n",exp[i]);
    }
       
    else if (IsOperator(exp[i])){
      //printf("%c\n",exp[i]);
      val1=0;
      val2=0;
      
      for(k=1; GetTop(stack)!=' ' && GetTop(stack)!='_'; k*=10){
        val2 = val2 + ((int) Pop(stack) - 48)*k;
        //printf("%d %d\n",k,val2);
      }
      if(Pop(stack) == '_') val2 *= (-1);
      //printf("Popped %d\n",val2);

      for(k=1; GetTop(stack)!=' ' && GetTop(stack)!='_'; k*=10){
        val1 = val1 + ((int) Pop(stack) - 48)*k;
        //printf("%d %d\n",k,val1);
      }
      if(Pop(stack) == '_') val1 *= (-1);
      //printf("Popped %d\n",val1);

      val1 = Operate(val1, val2, exp[i]);
      //printf("%d\n",val1);
      val2 = 0;

      if(val1 < 0) {
        Push(stack,'_');
        val1 *= (-1);
      }
      else
        Push(stack,' ');

      digit = NoOfDigits(val1)-1;
      while(digit >= 0){
        Push(stack,((char) (val1/power(10,digit) + 48)));
        val1 = val1 % power(10,digit);
        digit--;
      }
    }

    else
      return INT_MIN;
  }

  for(k=1; GetTop(stack)!=' ' && GetTop(stack)!='_'; k*=10){
    val1 = val1 + ((int) Pop(stack) - 48)*k;
    //printf("%d %d\n",k,val1);
  }
  if(Pop(stack) == '_') val1 *= (-1);
    //printf("Popped %d\n",val1);
    
  return val1;
}

//UTILITY FUNCTIONS:-

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

int IsOperand(char ch){
    return (ch >= 'a' && ch <= 'z') ||
           (ch >= 'A' && ch <= 'Z');
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

int NoOfDigits(int n){
    if (n/10 == 0)
        return 1;
    return 1 + NoOfDigits(n / 10);
}

int power(int x, int y){
    int temp;
    if( y == 0)
        return 1;
    temp = power(x, y/2);
    if (y%2 == 0)
        return temp*temp;
    else
        return x*temp*temp;
}