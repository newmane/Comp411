#include <stdio.h>

main()
{
float a,b,c,s,p;

printf("Enter three floating-point numbers:\n");
scanf("%f", &a);
scanf("%f", &b);
scanf("%f", &c);
s = a + b + c;
p = a * b * c;
printf("Sum is %3.4f\n", s);
printf("Product is %3.4f\n", p);

return;
}

