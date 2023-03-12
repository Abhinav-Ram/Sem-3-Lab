#include <stdio.h>
#define SIZE 100

void PrintArray(int a[], int size);
int Swap(int* a, int* b);
int GetMin(int a[ ], int init, int size);
void SelectionSort(int a[], int size);

int main(){
  int i, a[SIZE];
  i=0;
  a[0] = -1;
  printf("\nAPPLICATION 3: Selection Sort\n");
  printf("\nEnter integers, terminate with -100\n");
  printf("\nA[] = ");  
  do{
    a[0]++;
    scanf("%d",&a[++i]);
  }while(a[i]!=-100);
  SelectionSort(a,a[0]);  
  return 0;
}

int Swap(int* a, int* b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

int GetMin(int a[ ], int init, int size){
  int i = init+1;
  int m = init;
  while(i<=size){
    if(a[i]<a[m])
      m = i;
    i++;
  }
  return m;
}

void SelectionSort(int a[], int size){
  int i, m;
  for(i=1; i<=size; i++){
    m = GetMin(a,i,size);
    Swap(&a[m],&a[i]);
    PrintArray(a,size);
  }
}

/********UTILITIES************/
void PrintArray(int a[], int size){
  int i=1;
  while(i<=size){
    printf("%d ",a[i]);
    i++;
  }
  printf("\n");
}
/*****************************/