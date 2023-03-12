//Array 0 to n-1
#include <stdio.h>
#define SIZE 50

int Swap(float* a, float* b){
  float temp = *a;
  *a = *b;
  *b = temp;
}

int Parent(int i){
  return (i-1)/2 ;
}

int Left(int i){
  return 2*i+1;
}

int Right(int i){
  return 2*i+2;
}

void HeapifyUp(float A[], int i){
  int p = Parent(i);
  while (i > 0 && A[p] > A[i]){
    Swap(&A[p],&A[i]);
    i = p;
    if(i != 0)
      p = Parent(i);
  }
}

void HeapifyDown(float A[], int n, int i){
  int l,r,m;
  while(1){ 
    l = Left(i);
    r = Right(i);
    m = i; 
    if (l < n && A[m] > A[l]) 
  		m = l;
		
  	if (r < n && A[m] > A[r])
  		m = r;
    
    if (m != i){
  		Swap(&A[i], &A[m]);
      i=m;
    }
    else
      return;
  }
}

int Insert(float A[], int n, float x){
  n = n + 1;
  A[n-1] = x;
  HeapifyUp(A,n-1);
  return n;
}

int DeleteMin(float A[], int n){
  if(n==0)
    return n;
  A[0] = A[n-1];
  n = n-1;
  HeapifyDown(A, n, 0);
  return n;
}

float GetMin(float A[], int size){
  if (size == 0)
    return -100;
  return A[0];
}

void BuildHeap(float A[], int size){
  int temp = 1;
  while(temp<size){
    temp = Insert(A,temp,A[temp]);
  }
}