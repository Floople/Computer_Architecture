#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  int height;
  struct node * left;
  struct node * right;
};

void insert(struct node** head, int val, int h) {
  struct node * temp = *head;
  if(temp == NULL) {
    temp = (struct node*) malloc(sizeof(struct node));
    temp -> data = val;
    temp -> height = h + 1;
    temp -> left = NULL;
    temp -> right = NULL;
    *head = temp;
  }
  else if (temp -> data > val) {
    insert(&temp -> left, val, h + 1);
  }
  else if(temp -> data < val) {
    insert(&temp -> right, val, h + 1);
  }
};

void printBST(struct node* head) {
  if(head != NULL) {
    printBST(head -> left);
    printf("%d\t", head -> data);
    printBST(head -> right);
  }
};

int main(int argc, char** argv) {
  FILE *file;
  file = fopen(argv[1],"r");
  char type;
  int num;
  struct node* bst = NULL;

  if(file == NULL) {
    printf("error\n");
    return 0;
  }
  while(fscanf(file, "%c %d\n", &type, &num) == 2) {
    if(type == 'i') {
      insert(&bst, num, 0);
    }
  }
  if(bst != NULL) {
    printBST(bst);
  }
}
