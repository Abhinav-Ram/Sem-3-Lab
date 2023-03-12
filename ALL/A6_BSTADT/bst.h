#include <stdlib.h>
#include <stdio.h>
#define SIZE 50
#define COUNT 10

/*insert, delete, inorder, preorder, postorder, levelorder (optional), search, maximum,
minimum*/

typedef struct Node* bst;
struct Node {
	int  data;
	bst right, left; 
};

bst CreateNode(int key){
	bst t = (bst) malloc(sizeof(struct Node));
	t->data = key;
	t->left = t->right = NULL;
	return t;
}

int Height(bst t){
  if (t == NULL)
    return -1;
  else {
    /* compute the height of each subtree */
    int lheight = Height(t->left);
    int rheight = Height(t->right);
    /* use the larger one */
    return (lheight > rheight)?(lheight + 1):(rheight + 1);
  }
}

bst MinValueNode(bst node){
	bst current = node;
	while(current->left != NULL)
		current = current->left;
		return current;
}

bst MaxValueNode(bst node){
	bst current = node;
	while(current && current->right != NULL)
		current = current->right;
		return current;
}

bst Insert(bst t, int key){
	if(t==NULL)
		return CreateNode(key);

    if(key > t->data)
			t->right = Insert(t->right,key);
		else if(key < t->data)
			t->left = Insert(t->left,key);
	return t;			
}

bst Search(bst t, int key){
	if(t == NULL || t->data == key)
		return t;
	if(t->data < key)
		return Search(t->right, key);
	return Search(t->left, key);
}

bst Delete(bst t, int key){
	if(t==NULL)
		return t;
	if(key < t->data)
		t->left = Delete(t->left, key);
	else if(key > t->data)
		t->right = Delete(t->right, key);
	else{
    		if(t->left == NULL){
			bst temp = t->right;
			free(t);
			return temp;
		}
		else if(t->right == NULL){
			bst temp = t->left;
			free(t);
			return temp;
		}		

		bst temp = MinValueNode(t->right);
		t->data = temp->data;
		t->right = Delete(t->right, temp->data);
	}
	return t;
}

void PrintCurrentLevel(bst t, int level){
  if (t == NULL)
    return;
  if (level == 1){
    printf("%d ", t->data);
  }
  else if (level > 1){
    PrintCurrentLevel(t->left,level-1);  
    PrintCurrentLevel(t->right,level-1);    
  }
}

//tree iterations
void InOrder(bst t){
  if(t){
    InOrder(t->left);
    printf("%d ", t->data);
    InOrder(t->right);
  }
}
void PreOrder(bst t){
  if(t){
    printf("%d ", t->data);
    PreOrder(t->left);
    PreOrder(t->right);
  }
}
void PostOrder(bst t){
  if(t){
    PostOrder(t->left);
    PostOrder(t->right);
    printf("%d ", t->data);
  }
}
void LevelOrder(bst t){
  int h = Height(t);
  int i,j;
  for(i=1;i<=h;i++){
      PrintCurrentLevel(t,i);
      printf(" ");
  }
}

//TO BE CHANGED
void Print2DUtil(bst t, int space)
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
    printf("%d\n",t->data);
 
    // Process left child
    Print2DUtil(t->left, space);
}
 
// Wrapper over Print2DUtil()
void Print2D(bst t)
{
    // Pass initial space count as 0
    printf("-------------------------------------------\n");
    Print2DUtil(t, 0);
    printf("-------------------------------------------\n");
}
