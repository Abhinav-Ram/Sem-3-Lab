#include <stdio.h>
#define SIZE 100

int CountOnes(int a[], int size);

int main(){
  int i, a[SIZE];
  printf("\nAPPLICATION 2: Number of 1’s in a sorted binary array.\n");
  printf("\nEnter integers, terminate with -100\n");

  i=0;
  a[0] = -1;
  printf("\nA[] = ");
  do{
    a[0]++;
    scanf("%d",&a[++i]);
  }while(a[i]!=-100);
  printf("No of ones = %d\n",CountOnes(a,a[0]));
  return 0;
}

int CountOnes(int a[], int size){
  int i=size, count=0;
  while(i>=1 && a[i]==1){
    count++;
    i--;
  }
  return count;
}