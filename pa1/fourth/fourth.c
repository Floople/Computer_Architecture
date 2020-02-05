#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
  FILE *file;
  int temp;
  int r1;
  int c1;
  int r2;
  int c2;
  int sum;
  file = fopen(argv[1], "r");
  if(file == NULL) {
    printf("error\n");
    return 0;
  }
  fscanf(file, "%d %d", &r1, &c1);
  int* matrix1[r1];
  for(int i = 0; i < r1; i++) {
    matrix1[i] = (int *) malloc(c1 * sizeof(int));
  }
  for(int i = 0; i < r1; i++) {
    for(int j = 0; j < c1; j++) {
      fscanf(file, "%d", &temp);
      matrix1[i][j] = temp;
    }
  }
  fscanf(file, "%d %d", &r2, &c2);
  int* matrix2[r2];
  for(int i = 0; i < r2; i++) {
    matrix2[i] = (int *) malloc(c2 * sizeof(int));
  }
  for(int i = 0; i < r2; i ++) {
    for(int j = 0; j < c2; j++) {
      fscanf(file, "%d", &temp);
      matrix2[i][j] = temp;
    }
  }
  if(c1 != r2) {
    printf("bad-matrices\n");
    return 0;
  }
  int* matrixFinal[r1];
  for(int i =0; i < r1; i++) {
    matrixFinal[i] = (int *)malloc(c2 * sizeof(int));
  }
  for(int i = 0; i < r1; i++) {
    for(int j = 0; j < c2; j++) {
      matrixFinal[i][j] = 0;
      sum = 0;
      for(int k = 0; k < r2; k++) {
        sum = sum + matrix1[i][k] * matrix2[k][j];
      }
      matrixFinal[i][j] = sum;
    }
  }
  for(int i = 0; i < r1; i++) {
    for(int j = 0; j < c2; j++) {
      temp = matrixFinal[i][j];
      if(j + 1 == c2) {
        printf("%d",temp);
      }
      else{
        printf("%d\t",temp);
      }
    }
    printf("\n");
  }
  return 0;
}
