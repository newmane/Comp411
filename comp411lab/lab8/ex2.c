#include <stdio.h>
#include <string.h>

unsigned int factorial(unsigned int n) {
  if(n == 0) {
    return 1;
  } else {
    return n*factorial(n-1);
  }
}

main() {
  char temp[20];
  int result;
  fgets(temp, 20, stdin);
  while(a_to_i(temp) != 0) {
    result = a_to_i(temp);
    printf("%d\n",factorial(result));
    fgets(temp, 20, stdin);
  }
  printf("1\n");
}

int a_to_i(char* str) {
  int i;
  int answer = 0;
  int length= strlen(str);
  int place = 1;

  for(i = length - 2; i >= 0; i--){
    answer += (str[i]-48)*place;
    place *= 10;
  }
  return answer;
}
