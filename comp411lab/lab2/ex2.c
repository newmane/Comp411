/*  Example: C program to find area of a circle */

#include <stdio.h>
#define PI 3.14159

main()
{
  float r, a;
	r = 1;
  while(r != 0) {
  printf("Enter the circle's radius (in centimeters): ");
  scanf("%f", &r);

  a = PI * r * r /( 2.54 * 2.54);

  printf("Its area is %3.2f square inches.\n", a);
}
  return;
}
