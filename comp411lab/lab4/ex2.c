#include <stdio.h>
#include <string.h>

#define MAX 1000 /* The maximum number of characters in a line of input */

main()
{
  char text[MAX], c, reversetext[MAX];
  int i,j,k;
  int lowercase, uppercase, digits, other;
  int length;
  
  puts("Type some text (then ENTER):\n");
  
  /* Save typed characters in text[]: */

  fgets(text, MAX, stdin);

  length = strlen(text)-1;

  /* Input in reverse */
  k = length;
  j = k;
  for(; k >= 0; k--)
  {
   reversetext[j-k] = text[k];
  }
  printf("Your input in reverse is:");
  printf("%s", reversetext);


  /* Analyse contents of text[]: */

    
  for (i = lowercase = uppercase = digits = other = 0; i < MAX; i++)
  {
    c = text[i];
    if (c >= 'a' && c <= 'z')
      lowercase++;
    else if (c >= 'A' && c <= 'Z')
      uppercase++;
    else if (c >= '0' && c <= '9')
      digits++;
    else
    {
      if (c == '\n')
        break;
      other++;
   }
 }

  puts("\nYou typed:");
  printf("A string with %d characters\n", length);
  printf("\t%d lower case letters\n", lowercase);
  printf("\t%d upper case letters\n", uppercase);
  printf("\t%d digits\n", digits);
  printf("\t%d others\n", other);
}
