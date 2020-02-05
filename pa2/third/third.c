#include <stdio.h>
#include <stdlib.h>

unsigned short get(unsigned short num, unsigned short place) {
  unsigned short temp = num & (1 << place);
  return temp >> place;
}

int main(int argc, char** argv) {
  unsigned short num = (unsigned short)atoi(argv[1]);
  int palindrome = 1; // 0 = false, 1 = true
  int front = 0;
  int back = 15;
  while(front < back) {
    if(get(num, front) != get(num, back)) {
      palindrome = 0;
      break;
    }
    front++;
    back--;
  }
  if(palindrome == 0) {
    printf("Not-Palindrome\n");
  }
  else {
    printf("Is-Palindrome\n");
  }
}
