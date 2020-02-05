#include <stdio.h>
#include <stdlib.h>
int main(int argc, char** argv) {
  FILE *file;
	int size;
  int array[20];
  int tempArray[20];
  int temp;
  int place = 0;
  int evenPlace;
  file = fopen(argv[1], "r");
  if(file == NULL) {
    printf("file not found\n ");
    return 0;
  }
  fscanf(file, "%d", &size);
  if(array == NULL) {
    printf("array not found\n");
    return 0;
  }
  for(int i = 0; i < size; i++) {
    fscanf(file, "%d", &temp);
    array[i] = temp;
  }
  /*for(int i = 0; i < size; i++) {
    printf("%d\t", array[i]);
  }
  return 0; */
  for(int i = 0; i < size; i++) {
    if(array[i] % 2 == 0) {
      tempArray[place] = array[i];
      place++;
    }
  }
  evenPlace = place;
  for(int i = 0; i < size; i++) {
    if(array[i] % 2 != 0) {
      tempArray[place] = array[i];
      place++;
    }
  }
  for(int i = 0; i < evenPlace; i ++) {
    for(int j = i + 1; j < evenPlace; j++) {
        if(tempArray[i] > tempArray[j]) {
          temp = tempArray[i];
          tempArray[i] = tempArray[j];
          tempArray[j] = temp;
        }
    }
  }
  for(int i = evenPlace; i < size; i ++) {
    for(int j = i + 1; j < size; j++) {
        if(tempArray[i] < tempArray[j]) {
          temp = tempArray[i];
          tempArray[i] = tempArray[j];
          tempArray[j] = temp;
        }
    }
  }
  for(int i = 0; i < size; i++) {
    printf("%d\t", tempArray[i]);
  }
  return 0;
}
