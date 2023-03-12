#include <stdio.h>
#include <string.h>
#include "bst.h"
#include "command.h"

int IsIdentical(bst t1, bst t2);
int NoLeafNodes(bst t);
int NoNonLeafNodes(bst t);
int TotalNodes(bst t);
void Info(bst t);
bst CommandLine(bst root);

int main()
{
  bst t1=NULL, t2=NULL;
  printf("The following application uses BST to accept two different binary search trees using a command line interface and checks whether they are identical or not.\n");
  CommandLineMan();
  printf("\nt1\n");
  t1=CommandLine(t1);
  printf("\nt2\n");
  t2=CommandLine(t2);
  if(IsIdentical(t1,t2))
    printf("\nt1 and t2 are identical\n");
  else
    printf("\nt1 and t2 are not identical\n");
  return 0;
}

//UTILITY FUNCTIONS
bst CommandLine(bst root){
  int i=-1;
  do{
    i++;
    printf(">> ");
    scanf("%s",cmdlist[i].cmd);
    if(!strcmp(cmdlist[i].cmd,"i")||!strcmp(cmdlist[i].cmd,"d")||!strcmp(cmdlist[i].cmd,"s")){
       scanf("%d",&cmdlist[i].val);
    }
  }while(strcmp(cmdlist[i].cmd,"exit"));
  
  for(i=0;strcmp(cmdlist[i].cmd,"exit");i++){
    if(!strcmp(cmdlist[i].cmd,"i")){
      root = Insert(root,cmdlist[i].val);
    }
    else if(!strcmp(cmdlist[i].cmd,"d")){
      root = Delete(root,cmdlist[i].val);
    }
    else if(!strcmp(cmdlist[i].cmd,"s")){
      if(Search(root,cmdlist[i].val)){
        printf("%d is Available\n",cmdlist[i].val);
      }
      else
        printf("%d is Unavailable",cmdlist[i].val);
    }
    else if(!strcmp(cmdlist[i].cmd,"disp")){
      Print2D(root);
    }
    else if(!strcmp(cmdlist[i].cmd,"min")){
      printf("Min: %d\n",MinValueNode(root)->data);
    }
    else if(!strcmp(cmdlist[i].cmd,"max")){
      printf("Max: %d\n",MaxValueNode(root)->data);
    }
    else if(!strcmp(cmdlist[i].cmd,"in")){
      printf("Inorder:"); InOrder(root); printf("\n");
    }
    else if(!strcmp(cmdlist[i].cmd,"pre")){
      printf("Preorder:"); PreOrder(root); printf("\n");
    }
    else if(!strcmp(cmdlist[i].cmd,"post")){
      printf("Postorder:"); PostOrder(root); printf("\n");
    }
    else if(!strcmp(cmdlist[i].cmd,"level")){
      printf("Levelorder:"); LevelOrder(root); printf("\n");
    }
    else{
      printf("%s is an invalid command\n", cmdlist[i].cmd);
    }
  }
  Info(root);
  return root;
}

void Info(bst t) {
    printf("\n");
    printf("No of leaf nodes: %d\n",NoLeafNodes(t));
    printf("No of Non-leaf nodes: %d\n",NoNonLeafNodes(t)); 
    printf("Total no of nodes: %d\n",TotalNodes(t)); 
}
//APPLICATION FUNCTIONS
int IsIdentical(bst t1, bst t2){
    // Check if both the trees are empty
    if (t1 == NULL && t2 == NULL)
        {return 1;}
    // If any one of the tree is non-empty
    // and other is empty, return false
    else if (t1 != NULL && t2 == NULL)
        {return 0;}
    else if (t1 == NULL && t2 != NULL)
        {return 0;}
    else { // Check if current data of both trees equal
        // and recursively check for left and right subtrees
        if (t1->data == t2->data && IsIdentical(t1->left, t2->left) && IsIdentical(t1->right, t2->right))
            {return 1;}
        else
            {return 0;}
    }
}


int NoLeafNodes(bst t){
    if(t == NULL)    
        return 0;
    if(t->left == NULL && t->right == NULL)
        return 1;        
    else
        return NoLeafNodes(t->left) + NoLeafNodes(t->right);
}

int NoNonLeafNodes(bst t){
    if (t == NULL || (t->left == NULL && t->right == NULL))
        return 0;
    return 1 + NoNonLeafNodes(t->left) + NoNonLeafNodes(t->right);
}

int TotalNodes(bst t){
  return NoLeafNodes(t) + NoNonLeafNodes(t);
}
