#include <stdio.h>

main()
{
  int A[3][3];
  int B[3][3];
  int C[3][3];
  int i, j, k;

  printf("Please enter the values for A[0..2][0..2], one row per line:\n");
  for(i = 0; i < 3; i++) {
    for(j = 0; j < 3; j++) {
      scanf("%d", &A[i][j]);
    }
  } 

  printf("Please enter the values for B[0..2][0..2], one row per line:\n");
  for(i = 0; i < 3; i++) {
    for(j = 0; j < 3; j++) {
      scanf("%d", &B[i][j]);
    }
  }

  printf("A=\n");
  for(i = 0; i < 3; i++) {
    for(j = 0; j < 3; j++) {
      printf("   %3i", A[i][j]);
    }
    printf("\n");
  }

  printf("B=\n");
  for(i = 0; i < 3; i++) {
    for(j = 0; j < 3; j++) {
      printf("   %3i", B[i][j]);
    }
    printf("\n");
   }

  /* multiply C = A.B: */

  for (i = 0; i < 3; i++)
    for (j = 0; j < 3; j++)
    {
      C[i][j] = 0;
      for (k =0; k < 3; k++)
        C[i][j] += A[i][k] * B[k][j];
    }

  printf("C=A.B=\n");
  for(i = 0; i < 3; i++) {
    for(j = 0; j < 3; j++) {
      printf("   %3i", C[i][j]);
    }
    printf("\n");
  }

  /* multiply C = B.A: */
  
  for (i = 0; i < 3; i++)
    for (j = 0; j < 3; j++)
    {
      C[i][j] = 0;
      for (k =0; k < 3; k++)
        C[i][j] += B[i][k] * A[k][j];
    }

  printf("C=B.A=\n");
  for(i = 0; i < 3; i++) {
    for(j = 0; j < 3; j++) {
      printf("   %3i", C[i][j]);
    }
    printf("\n");
  }
}
