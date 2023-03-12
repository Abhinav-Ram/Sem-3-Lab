#define INT_MIN -2147483648
#define MAX_SIZE 50
#include <stdlib.h>

struct Stack { 
  int top;
  unsigned capacity;
  char* array;
};

struct Stack* createStack(unsigned capacity) {
  int i;
  struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
  stack->capacity = capacity;
  stack->top = -1;
  stack->array = (char*) malloc(stack->capacity * sizeof(char));
  return stack;
}

int IsFull(struct Stack* stack){
  return stack->top == stack->capacity - 1; 
}

int IsEmpty(struct Stack* stack){
  return stack->top == -1; 
}

void Push(struct Stack* stack, char item){
  if (IsFull(stack))
    return;
  stack->array[++stack->top] = item; 
}

char Pop(struct Stack* stack){
  if (IsEmpty(stack))
    return '\0';
  return stack->array[stack->top--]; 
}

char GetTop(struct Stack* stack){
  if (IsEmpty(stack))
    return '\0';
  return stack->array[stack->top]; 
}
