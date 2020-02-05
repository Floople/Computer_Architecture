#include <stdio.h>
#include <stdlib.h>
#include <string.h>
unsigned short set(unsigned short num, unsigned short place, unsigned short type) {
  unsigned short temp;
  if(type == 1) {
    temp = num | (1 << place);
  }
  else if(type == 0) {
    temp = num & ~(1 << place);
  }
  printf("%hu\n", temp);
  return temp;
}
void get(unsigned short num, unsigned short place) {
  unsigned short temp = num & (1 << place);
  printf("%hu\n", temp >> place);
}
unsigned short comp(unsigned short num, unsigned short place) {
  unsigned short temp = num ^ (1 << place);
  printf("%hu\n", temp);
  return temp;
}
int main(int argc, char** argv) {
   FILE *file;
   file = fopen(argv[1], "r");
   char *operation = (char *) malloc(5 * sizeof(char));
   unsigned short num;
   unsigned short temp;
   unsigned short place;
   fscanf(file, "%hu\n", &num);
   while(fscanf(file,"%s %hu %hu\n", operation, &place, &temp) == 3) {
     //printf("%s %hu %hu\n",operation, place, temp);
     if(strcmp(operation,"get") == 0) {
       get(num, place);
     }
     else if(strcmp(operation, "set") == 0) {
       num = set(num, place, temp);
     }
     else if(strcmp(operation, "comp") == 0) {
       num = comp(num, place);
     }
   }
   return 0;
 }
 /*
 5 = 101
 00000101
 00000100 &
 00000100
 7 = 111
 00000111
 00000010 &
 */
