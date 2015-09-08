#include <stdio.h>

main()
{
int a,b,i;
a=1;
while(a != 0) {
	printf("Number [1-100]: ?\n");
	scanf("%d", &a);
	b=0;
	for(i=2; i<a; i++) {
		if(a%i == 0 && a!= i && a!= 0) {
			b=1;
			printf("Non-prime, divisible by %d\n", i);
			break;
		}
	}
	if(b==0 && a != 0){
		printf("Prime\n");
	}
}
printf("Done\n");
return;
}


