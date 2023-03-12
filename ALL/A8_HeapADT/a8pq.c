#include "heap.h"
#include <stdio.h>

float* BelPL(float[], int, float);

int main(){
  float PQ[SIZE], BPL=0.7;
  int i, size=9;
  float* ModPQ;

  //INPUT

  printf("No of families: ");
  scanf("%d", &size);
  printf("Income in K: ");
  for(i = 0; i < size; i++)
    scanf("%f", &PQ[i]);
  printf("BPL limit: ");
  scanf("%f", &BPL);
  
  //OPERATION
  
  //Here ModPQ is a special array whose 1st element (ModPQ[0]) is the size and elements are from A[1] to A[size] where size = ModPQ[0]
  
  //BelPL carries over the BPL benefeciaries over to ModPQ by repeatedly calling DeleteMin

  ModPQ = BelPL(PQ,size,BPL);
  //OUTPUT
  
  printf("\nRemoved incomes: ");
  for(i = 1; i <= *ModPQ; i++)
    printf("%f ", *(ModPQ+i));
  printf("\n");
}


float * BelPL(float* PQ, int size, float BPL) {
  static float  ModPQ[10];
  int i=1;
  ModPQ[0]=0;
  BuildHeap(PQ, size);
  while(GetMin(PQ,size) < BPL) {
    ModPQ[i] = GetMin(PQ,size);
    i++;
    size = DeleteMin(PQ,size);
    ModPQ[0]++;
  }
  return ModPQ;
}

//1.7 4.3 7.8 1.5 5.6 2.5 8 1 0.7 1.5