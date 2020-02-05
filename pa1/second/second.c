#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
  int occurrence;
};
int size;
void insert(struct node **linkedList, int x) {
  int* incrementer;
  struct node * prev = NULL;
  struct node * ptr = *linkedList;
  struct node * temp = NULL;
  temp = (struct node*)malloc(sizeof(struct node));
  temp -> data = x;
  temp -> next = NULL;
  temp -> occurrence = 1;
  if(*linkedList == NULL) {
    *linkedList = temp;
    size++;
    return;
  }
   while(ptr != NULL) {
     if (x == ptr -> data) {
       size++;
       incrementer = &ptr->occurrence;
       *incrementer = *incrementer + 1;
       return;
     }
     if (x < ptr -> data) {
       if(prev == NULL) {
         temp -> next = *linkedList;
         *linkedList = temp;
         size++;
         return;
       }
       else {
         prev -> next = temp;
         temp -> next = ptr;
         size++;
         return;
       }
     }
     prev = ptr;
     ptr = ptr -> next;
   }
   if(prev != NULL) {
     prev -> next = temp;
     size++;
   }
   return;
};
void delete(struct node** linkedList, int x) {
  int* incrementer;
  struct node *ptr = *linkedList;
  struct node *prev = NULL;
  while(ptr != NULL) {
    if(ptr -> occurrence == 1 && ptr -> data == x) {
      if(prev == NULL) {
        *linkedList = ptr -> next;
        free(ptr);
        ptr = *linkedList;
        size--;
      }
      else{
        prev -> next = ptr -> next;
        free(ptr);
        ptr = prev -> next;
        size--;
      }
    }
    else {
      if(ptr -> occurrence > 1 && ptr -> data == x) {
        incrementer = &ptr->occurrence;
        *incrementer =* incrementer - 1;
        size--;
      }
      prev = ptr;
      ptr = ptr -> next;
    }
  }
};
int main(int argc, char** argv) {
  FILE *file;
  int val;
  char type;
  struct node* linkedList = NULL;
  struct node* ptr = NULL;
  file = fopen(argv[1], "r");
  if(file == NULL) {
    printf("error\n");
    return 0;
  }
  while(fscanf(file, "%c %d \n", &type, &val) == 2) {
    if(type == 'i') {
      insert(&linkedList, val);
    }
    if(type == 'd') {
      delete(&linkedList, val);
    }
  }
  ptr = linkedList;
  printf("%d\n", size);
  while(ptr != NULL) {
    printf("%d\t", ptr -> data);
    ptr = ptr -> next;
  }
  printf("\n");
  return 0;
}
