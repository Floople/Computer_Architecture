#include <stdio.h>
#include <stdlib.h>
// 1 = true
// 2 = false
struct node {
  int data;
  struct node *next;
};
struct node *hashTable[10000];

int insert(int value) {
  int hashKey;
  if (value < 0) {
    hashKey = -value % 10000;
  }
  else {
    hashKey = value % 10000;
  }
  struct node *hashVal = (struct node*) malloc(sizeof(struct node));
  hashVal -> data = value;
  hashVal -> next = NULL;
  if(hashTable[hashKey] == NULL) {
    hashTable[hashKey] = hashVal;
    return 2;
  }
  struct node *temp = hashTable[hashKey];
  while(temp != NULL) {
    if(temp -> data == value) {
      return 1;
    }
    temp = temp -> next;
  }
  hashVal -> next = hashTable[hashKey];
  hashTable[hashKey] = hashVal;
  return 1;
};
int search(int value) {
  int hashKey;
  if(value < 0) {
    hashKey = -value % 10000;
  }
  else {
    hashKey = value % 10000;
  }
  struct node *hashVal = hashTable[hashKey];
  while(hashVal != NULL) {
    if(hashVal -> data == value) {
      return 1;
    }
    hashVal = hashVal -> next;
  }
  return 2;
};
int main(int argc, char** argv) {
  int collisions = 0;
  int searches = 0;
  char type;
  int val;
  FILE *file;
  file = fopen(argv[1], "r");
  if(file == NULL) {
    printf("error\n");
    return 0;
  }
  while(fscanf(file, "%c %d\n", &type, &val) == 2) {
    if(type == 'i') {
      if(insert(val) == 1) {
        collisions++;
        insert(val);
      }
    }
    if(type == 's') {
      if(search(val) == 1) {
        searches++;
      }
    }
  }
  printf("%d\n", collisions);
  printf("%d\n", searches);
};
