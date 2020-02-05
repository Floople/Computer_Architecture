#include <stdio.h>
#include <stdlib.h>
#include <string.h>
unsigned short get(unsigned short num, unsigned short place) {
  unsigned short temp = num & (1 << place);
  return temp >> place;
}
int main(int argc, char** argv) {
  int counter = 0;
  int counter2 = 0;
  int isPair = 0; // 0 = false, 1 = true
  unsigned short num = (unsigned short)atoi(argv[1]);
  for(int i = 0; i < 16; i++) {
    if(get(num, i) == 1) {
      counter++;
    }
    if(get(num,i) == 0) {
      isPair = 0;
    }
    if(get(num,i) == 1) {
      if(isPair == 1) {
        counter2++;
        isPair = 0;
      }
      else {
        isPair = 1;
      }
    }
  }
  if(counter % 2 == 1) {
    printf("Odd-Parity\t");
  }
  if(counter % 2 == 0) {
    printf("Even-Parity\t");
  }
  printf("%d\n", counter2);
}
