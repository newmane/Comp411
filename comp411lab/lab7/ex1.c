#include <stdio.h>

main() 
{
  int columns, rows, PPM_MAX, red, blue, green, Gray_Value, i;
  char magicnum[5];
  scanf("%s", magicnum);
  printf("P2");
  printf("\n");
  scanf("%d%d%d", &columns, &rows, &PPM_MAX);
  printf("%d\n%d\n%d\n", columns, rows, 255);

  for(i = 0; i < rows * columns; i++) {
      scanf("%d%d%d", &red, &green, &blue);
      Gray_Value = ((red + green + blue) * 255) / (3 * PPM_MAX);
      printf("%d\n", Gray_Value);
  }

}
