#include "BinTreeADT.h"

//tree stack and functions
struct TStack { 
  int top;
  unsigned capacity;
  et* array;
};


struct TStack* Create(unsigned capacity) {
  int i;
  struct TStack* stack = (struct TStack*) malloc(sizeof(struct TStack));
  stack->capacity = capacity;
  stack->top = -1;
  stack->array = (et*) malloc(stack->capacity * sizeof(struct tree));
  return stack;
}
int isfull(struct TStack* stack){
  return stack->top == stack->capacity - 1; 
}
int isempty(struct TStack* stack){
  return stack->top == -1; 
}
void push(struct TStack* stack, et item){
  if (isfull(stack))
    return;
  stack->array[++stack->top] = item; 
}
et pop(struct TStack* stack){
  if (isempty(stack))
    return NULL;
  return stack->array[stack->top--]; 
}
