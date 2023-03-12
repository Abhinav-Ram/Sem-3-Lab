#include <stdio.h>
#define SIZE 100

int GetFirstOccur(int a[ ], int size, int target);
int GetLastOccur(int a[ ], int size, int target);

int main(){
  int i,a[SIZE], target;
  printf("\nAPPLICATION 1: First and Last occurence of target\n");
  printf("\nEnter integers, terminate with -100\n");
  printf("\nA[] = ");
  i=0;
  a[0] = -1;
  do{
    a[0]++;
    scanf("%d",&a[++i]);
  }while(a[i]!=-100);
  
  printf("target = ");
  scanf("%d", &target);
  printf("First Occurence = %d\n",GetFirstOccur(a,a[0],target));
  printf("Last Occurence = %d\n",GetLastOccur(a,a[0],target));

  printf("(A \"-1\" occurence means not found)\n");  
  return 0;
}

int GetFirstOccur(int a[ ], int size, int target){
  int low = 1;
  int high = size;
  int result = -1;
  while (low <= high){
    int mid = (low + high)/2;
    
    if (target == a[mid]){
      result = mid;
      high = mid - 1;
    }
    
    else if (target < a[mid]) {
      high = mid - 1;
    }
        
    else {
      low = mid + 1;
      }
  }

  return result;
}

int GetLastOccur(int a[ ], int size, int target){
  int low = 1;
  int high = size;
  int result = -1;
  while (low <= high){
    int mid = (low + high)/2;
    
    if (target == a[mid]){
      result = mid;
      low = mid + 1;
    }
    
    else if (target < a[mid]) {
      high = mid - 1;
    }
        
    else {
      low = mid + 1;
      }
  }
  
  return result;
}

