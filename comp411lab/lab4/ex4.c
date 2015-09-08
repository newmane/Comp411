#include <stdio.h>

#define VALS 10 /* The number of values to be sorted */

main()
{
  int i, sorted, swaps = 0, numiterations = 0;
  float x[VALS], temp;
  
  /* Input values: */
  
  printf("Enter %i floating point values:\n", VALS);
  for (i = 0; i < VALS; i++)
  { printf("#%i: ", i + 1);
    scanf("%f", &x[i]);
  }
  
  /* Bubble sort: */
  
  do {
       for (i = 1, sorted = 1; i < VALS; i++)
       {
         if (x[i-1] > x[i])
         {
           sorted = 0;
           temp = x[i-1];
           x[i-1] = x[i];
           x[i] = temp;
           swaps++;
         }
       }
     numiterations++;
     } while (!sorted);
  
  /* Output sorted values: */
  
  puts("\nIn ascending order, the values are:");     
  for (i = 0; i < VALS; i++)
    printf("%G\n", x[i]);
  printf("\n%i swaps and %i iterations were performed.\n", swaps, numiterations);     
}
