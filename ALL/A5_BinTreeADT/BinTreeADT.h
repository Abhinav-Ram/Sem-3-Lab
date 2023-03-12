#include <string.h>
#include <stdlib.h>

#define SIZE 50
#define INT_MIN -2147483648
#define COUNT 10

//tree ADT and functions
typedef struct tree* et;

struct tree{
  char data;
  et left, right;
};

int Height(et t){
  if (t == NULL)
    return 0;
  else {
    /* compute the height of each subtree */
    int lheight = Height(t->left);
    int rheight = Height(t->right);
    /* use the larger one */
    return (lheight > rheight)?(lheight + 1):(rheight + 1);
  }
}

void print2DUtil(et t, int space)
{
    if (t == NULL)
      return;
    space += COUNT;
    print2DUtil(t->right, space);
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%c\n", t->data);
    print2DUtil(t->left, space);
}
void print2D(et t)
{
   print2DUtil(t, 0);
}

et Construct(char v){
  et temp = (et) malloc(sizeof(struct tree));
  temp->left = temp->right = NULL;
  temp->data = v;
  return temp;
};

void PrintCurrentLevel(et t, int level){
  if (t == NULL)
    return;
  if (level == 1){
    printf("%c ", t->data);
  }
  else if (level > 1){
    PrintCurrentLevel(t->left,level-1);    
    PrintCurrentLevel(t->right,level-1);    
  }
}

//tree iterations
void InOrder(et t){
  if(t){
    InOrder(t->left);
    printf("%c", t->data);
    InOrder(t->right);
  }
}
void PreOrder(et t){
  if(t){
    printf("%c", t->data);
    PreOrder(t->left);
    PreOrder(t->right);
  }
}
void PostOrder(et t){
  if(t){
    PostOrder(t->left);
    PostOrder(t->right);
    printf("%c", t->data);
  }
}
void LevelOrder(et t){
  int h = Height(t);
  int i,j;
  for(i=1;i<=h;i++){
      PrintCurrentLevel(t,i);
      printf("\n");
  }
}

