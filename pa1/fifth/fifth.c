#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
  char *temp = malloc(sizeof(char) *2);
  char vowel;
  int counter = 0;
  int length = 0;
  for (int i = 0; i < argc; i++) {
    temp = argv[i];
    length += strlen(temp);
  }
  char result[length];
  for(int i = 0; i < length; i++) {
    result[i] = '\0';
  }
  for(int i = 1; i < argc; i++) {
    temp = argv[i];
    for(int j = 0; j < strlen(temp); j++) {
      vowel = temp[j];
      if(vowel == 'a' || vowel == 'e' || vowel == 'i' || vowel == 'o' || vowel == 'u'|| vowel == 'A' || vowel == 'E'|| vowel == 'I' || vowel == 'O' || vowel == 'U') {
        result[counter] = vowel;
        counter++;
      }
    }
  }
  printf("%s\n", result);
  return 0;
}
