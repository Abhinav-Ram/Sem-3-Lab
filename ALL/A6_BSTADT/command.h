#define SIZE 50
#define LENGTH 6

struct Command {
  char cmd[LENGTH];
  int val;
}cmdlist[SIZE];

void CommandLineMan(){
  printf("MANUAL\n");
  printf("Commands format - <command-name> <value(optional)>\n");
  printf("1.i - Insert a value into tree\n2.d - Delete a value from tree\n3.s - Search a value in tree\n4.max-Maximum value\n5.min-Minimum value\n6.disp - Display the tree\n7.in - Inorder traversal\n8.pre - Preorder traversal\n7.post - Postorder traversal\n7.level - Levelorder traversal\n11.exit-Exit command line\n\n");
}