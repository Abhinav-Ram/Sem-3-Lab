#include<stdio.h>
#include "array.h"

int InsertAfterData(int a[], int data1, int data2){
	int pos = 0, size = Size(a);	
	do{
		pos = Search(a, pos, data1);
		size = InsertAt(a, size, pos+1, data2);
		pos=pos+2;
	}while(pos<size && Search(a, pos, data1) != -1);
	return 0;
}


void PrintArray(int a[], int size){
	int i;
	for(i=0;i<size; i++){
		printf("%d\t",i);		
	}
	printf("\n");
	for(i=0;i<size; i++){
		printf("%d\t",a[i]);		
	}
	printf("\n");

}

int main(){
    int NumArr[Max_Size];
	int i=-1, SizeArr, Data1, Data2, pos, spos;
	printf("Enter numbers(-100 terminates the input process):\n");
	do{
		i++;
		scanf("%d", &NumArr[i]);
		
	}while(NumArr[i]!=-100);

	printf("Enter data to search:");
	scanf("%d",&Data1);
	printf("Enter position to search from:");
	scanf("%d",&pos);
	spos = Search(NumArr,pos,Data1);
	if(spos==-2)
    {
    	printf("position is negative!\n");
        printf("Please enter from 0-%d\n",Size(NumArr)-1);
        return -1;
    }
	if(spos==-3)
    {
    	printf("position out of bounds!\n");
        printf("Please enter from 0-%d\n",Size(NumArr)-1);
        return -1;
    }
	if(spos==-1){
	    printf("Element not found!\n");	
	    return -1;
	}
    
    printf("Element found at index: %d\n",spos);
	
	printf("Enter data to be inserted:");
	scanf("%d",&Data2);

	printf("Before inserting:\n");
	SizeArr = Size(NumArr);
	PrintArray(NumArr,SizeArr);

	InsertAfterData(NumArr, Data1, Data2);

	printf("After inserting:\n");
	SizeArr = Size(NumArr);
	PrintArray(NumArr, SizeArr);
	return 0;
}
