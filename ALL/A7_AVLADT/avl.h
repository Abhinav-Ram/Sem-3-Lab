#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define SIZE 20
#define COUNT 10

typedef struct node* avl;
struct node {
  char name[SIZE];
  long int pn;
  int height;
	avl right, left; 
};

void InOrder(avl t){
  if(t){
    InOrder(t->left);
    printf("%s %ld\n", t->name,t->pn);
    InOrder(t->right);
  }
}

int Search(avl t, char* key){
	if(t == NULL)
		return 0;
  if(strcmp(t->name,key)==0)
    return 1;
	if(strcmp(t->name,key)<0)
		return Search(t->right, key);
	return Search(t->left, key);
}

int Height( avl n ) {
  if( n == NULL ) 
    return -1;
  else 
    return n->height; 
}

int Max( int l, int r) {
  return l > r ? l: r; 
}

avl SingleRotateWithRight( avl k1 ){ 
  avl k2;
  k2 = k1->right;
  k1->right = k2->left;
  k2->left = k1;
  k1->height = Max( Height( k1->left ), Height( k1->right ) ) + 1;
  k2->height = Max( Height( k2->right ), k1->height ) + 1;
  return k2; /* New root */
}


avl SingleRotateWithLeft( avl k2 ){ 
  avl k1 = NULL;
  k1 = k2->left;
  k2->left = k1->right;
  k1->right = k2;
  k2->height = Max( Height( k2->left ), Height( k2->right ) ) + 1;
  k1->height = Max( Height( k1->left ), k2->height ) + 1;
  return k1; 
}

avl DoubleRotateWithLeft( avl k3 ){ 
  k3->left = SingleRotateWithRight( k3->left );
return SingleRotateWithLeft( k3 );
}

avl DoubltRotateWithRight( avl k1 ){ 
  k1->right = SingleRotateWithLeft( k1->right );
  return SingleRotateWithRight( k1 );
} 

avl Insert(avl t, char* c, long p){
  if( t == NULL ){
    t = (avl) malloc(sizeof(struct node));
    if( t != NULL ){
      strcpy(t->name,c);
      t->pn = p;
      t->height = 0;
      t->left = t->right = NULL;
    }
  }
  else if( strcmp(c,t->name)<0){ 
    t->left = Insert(t->left,c,p);
    if( Height( t->left ) - Height( t->right ) == 2 )
      if( strcmp(c,t->left->name) <0 )
        t = SingleRotateWithLeft(t);
      else 
        t = DoubleRotateWithLeft(t);;
  }
  else if(strcmp(c,t->name)>0){ 
    t->right = Insert(t->right,c,p);
    if( Height( t->right ) - Height(t->left ) == 2 )
      if( strcmp(c,t->right->name) >0)
        t=SingleRotateWithRight(t);
      else
        t=DoubltRotateWithRight(t);
  } 
  t->height = Max(Height(t->left),Height(t->right))+1;
  return t; 
}

/**************UTILIY************/
void Print2DUtil(avl t, int space)
{
    // Base case
    if (t == NULL){
        return;
    } 
    // Increase distance between levels
    space += COUNT;
 
    // Process right child first
    Print2DUtil(t->right, space);
 
    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
       printf(" ");
    printf("%s\n",t->name);
 
    // Process left child
    Print2DUtil(t->left, space);
}
 
// Wrapper over Print2DUtil()
void Print2D(avl t)
{
    // Pass initial space count as 0
    printf("-------------------------------------------\n");
    Print2DUtil(t, 0);
    printf("-------------------------------------------\n");
}

/********************************/
