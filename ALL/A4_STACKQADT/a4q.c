#include<stdio.h>
#include "QueueADT.h"

void spool(struct queue* Q, int jobID); //adds a job to q.
void print(struct queue* Q); //removes the job to be printed from q.
void list(struct queue* Q); //lists the jobs in q in the spooled order

int main()
{
  struct queue *Q = (struct queue*) malloc(sizeof(struct queue));
  Init(Q);
  int i;
  list(Q);
  printf("Spooling...\n");
  for(i=0;i<5;i++){
    printf("Adding %d to Q...\n",i);
    spool(Q,i);
  }
  list(Q);
  printf("Printing...\n");
  for(i=0;i<5;i++)
    print(Q);
  printf("Printing...\n");
  print(Q);
  
  printf("Spooling more...\n");
  for(i=0;i<5;i++){
    printf("Adding %d to Q...\n",i);
    spool(Q,i);
  }
  list(Q);
  return 0;
}  

void spool(struct queue* Q, int jobID){
  EnQ(Q, jobID);
} 

void print(struct queue* Q){
  int print = DeQ(Q);
  if(print==INT_MIN) {
    printf("No jobs to be printed\n");
    return;
  }
  printf("%d is printed\n",print);
}

void list(struct queue* Q){
  if(IsEmpty(Q)) {
    printf("No jobs to be printed\n");
    return;
  }
  printf("The jobs are:\n");
  Display(Q);
}