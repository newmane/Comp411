#include <stdio.h>

int factorial(int n) {
  if(n == 0) {
    return 1;
  } else {
    return factorial(n-1)*n;
  }
}

main()
{
int a = 1;
while(a != 0) {
  printf("Enter a number: ");
  scanf("%d", &a);
  printf("%d! = %d\n", a, factorial(a));
}
return;
}
