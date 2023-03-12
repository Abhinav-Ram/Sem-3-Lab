#define INT_MIN -2147483648
#define SIZE 10
#include <stdlib.h>

struct queue
{
  int f,r,max;
  int data[SIZE];
};


int GetFront(struct queue *Q){
  return Q->f;
}

int GetRear(struct queue *Q){
  return Q->r;
}

void Init(struct queue *Q)
{
  Q->f=-1;
  Q->r=-1;
  Q->max=SIZE;
}
int IsFull(struct queue *Q)
{
  if((Q->r+1)%Q->max==Q->f)
  {
    return 1;
  }
  return 0;
}
int IsEmpty(struct queue *Q)
{
  if(Q->f==-1 && Q->r==-1)
  {
    return 1;
  }
  return 0;
}
void EnQ(struct queue *Q,int val)
{
  if(IsEmpty(Q))
  {
    Q->f=0;
    Q->r=0;
    Q->data[Q->r]=val;
  }
  else if(IsFull(Q))
    return;
  else
  {
   Q->r=(Q->r+1)%Q->max;
    Q->data[Q->r]=val;
  }
}

int DeQ(struct queue *Q)
{
  int item=Q->data[Q->f];
  if(IsEmpty(Q)){
    return INT_MIN;
  }
  else if(Q->f==Q->r)
  {
    
    Q->f=-1;
    Q->r=-1;
  }
  else
    Q->f=(Q->f+1)%Q->max;
  return item;
}
void Display(struct queue *Q)
{
  if(IsEmpty(Q))
    return;
  int i;
  for(i=Q->f;i!=Q->r; i=(i+1)%Q->max)
  {
    printf("%d ",Q->data[i]);
  }
  printf("%d\n",Q->data[i]);
}