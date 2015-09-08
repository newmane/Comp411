#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void bedtimestory(char words[20][15], int current, int number) {
  if(current == 0) {
    printf("A %s couldn't sleep, so her mother told a story about a little %s,\n", words[current], words[current + 1]);
    current++;
  }
  if(current < number - 2) {
    int i;
    for(i = 0; i < current; i++) {
      printf("  ");
    }
    printf("who couldn't sleep, so the %s's mother told a story about a little %s,\n", words[current], words[current + 1]);
    current++;
  }
  if(current == number - 2) {
    while(current >= 0) {
      int i;
      for(i = 0; i < current; i++) {
        printf("  ");
      }
      if(current == number - 2) {
        printf("... who fell asleep.\n");
      }
      else if(current == 0) {
        printf("... and then the %s fell asleep.\n", words[0]);
      }
      else {
        printf("... and then the little %s fell asleep;\n", words[current]);
      }
      current--;
    }
  current++;
  }
  if(current < number - 1 && current > 0) {
    bedtimestory(words, current, number);
  }
}

main() {
  char names[20][15];
  int number, j, i;
  char temp[15];
  strcpy(temp, "END\n");
  int difference = -1;
 
  number = 0;
  j = 0;

  while(difference != 0) {
    fgets(names[j], 15, stdin);
    difference = strcmp(temp, names[j]);
    j++;
    number++;
  }

  for(i = 0; i < number; i++) {
    int length = strlen(names[i]);
    if(names[i][length - 1] == '\n') {
      names[i][length - 1] = '\0';
    }
  }
  bedtimestory(names, 0, number);
}
