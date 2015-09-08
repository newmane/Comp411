#include <stdio.h>

unsigned int fibonacci(unsigned int n)
{
  if (n == 0) {
   return 0;
  }
  if (n == 1) {
   return 1;
  }
  else {
   return fibonacci(n-1) + fibonacci(n-2);
  }
}

main ()
{
  int num;
  int t = 0;
  unsigned int numunsigned, result;
  while(t == 0) {
   scanf("%d", &num);
   numunsigned = num;
   result = fibonacci(numunsigned);
   printf("%u\n", result);
   if (result == 0) {
    break;
   }
  }
  return;
}
