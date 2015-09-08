#include <stdio.h>

main()
{
int r,i;

printf("Please enter a number from 1 to 5: ");
scanf("%i", &r);
if(r < 1 || r > 5)
  	printf("Number is not in the range from 1 to 5\n");
else
	for(i=0; i<r; i++)
		printf("Hello World\n");
return;
}
