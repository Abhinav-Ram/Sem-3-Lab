#include "avl.h"

void Print_Dir(avl);
avl Add_Phone(avl,char*,int);

int main(){
  avl t = NULL;
  int rpt;
  char name[SIZE], c;
  long int phoneno;
  printf("TELEPHONE DIRECTORY APPLICATION\nEnter names and phonenos separated by space and each record separated by NEWLINE.\nEnter \'0 0\' to terminate the input.\nDo not enter duplicate names\n\n");
  rpt = 0;
  do{
    scanf("%s %ld",name,&phoneno);
    if(strcmp(name,"0")){
      if(Search(t,name))
        rpt = 1;
      else{
        t=Add_Phone(t,name,phoneno);
	printf("Insert: %s\n", name);
	Print2D(t);      
      }
    }
  }while(strcmp(name,"0"));
  if(rpt == 1)
    printf("\nDuplicated names ignored\n");
  printf("\nDIRECTORY LIST:\n");
  Print_Dir(t);
  printf("\n"); 
  return 0;
}

void Print_Dir(avl t){
  InOrder(t);
} //to print the directory in sorted order of names.

avl Add_Phone(avl t, char* n, int p){
  return Insert(t,n,p);
} //to include a person and phone number


/*
Madhesh 9811111111
Rangesh 9822222222
Sarvesh 9833333333
Donesh 9844444444
Sikshesh 9855555555
Dinesh 9866666666
Amresh 9877777777
Parvesh 9888888888
Dhyanesh 9899999999
0 0

*/