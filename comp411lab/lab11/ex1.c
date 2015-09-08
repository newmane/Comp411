#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_fn1(char* s1, char* s2) {
  float v1, v2;
  v1 = atof(s1);
  v2 = atof(s2);
  if(v1 < v2) {
    return -1;
  }
  else if(v1 > v2) {
    return 1;
  } else {
    return 0;
  }
}

int compare_fn2(char* s1, char* s2) {
  float v1, v2;
  v1 = atof(s1);
  v2 = atof(s2);
  if(v1 > v2) {
    return -1;
  }
  else if(v1 < v2) {
    return 1;
  } else {
    return 0;
  }
}

void swap(void *v[], int i, int j) {
  void *temp;
  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

void bubble_sort_generic(void *v[], int n, int (*compare_fn)(void *, void*)) {
  int i, j;
  for(i = 0; i < n; i++) {
    for(j = n - 1; j > i; j--) {
       if((*compare_fn)(v[j-1], v[j]) > 0) {
         swap(v, j-1, j);
      }
    }
  }
}

main() {
  int i, length;
  char* array[1000];
  char temp[1000];
  int tester = 0;
  int count = 0;
  
  while(tester == 0) {
    fgets(temp, 1000, stdin);
    if(atof(temp) == 0) {
      break;
    }
    length = strlen(temp);
    array[count] = malloc(length -1);
    strcpy(array[count], temp);
    count++;
  }

  printf("The original values are:\n");
  for(i = 0; i < count; i++) {
    printf("%1.4G", atof(array[i]));
    if(i < count - 1) {
      printf(" ");
    }
  }

  bubble_sort_generic((void **) array, count, (int (*)(void*, void*)) compare_fn1);
 
  printf("\nThe sorted values are:\n");
  for(i = 0; i < count; i++) {
    printf("%1.4G", atof(array[i]));
    if(i < count - 1) {
      printf(" ");
    }
  }

  bubble_sort_generic((void**) array, count, (int (*)(void*, void*)) compare_fn2);
 
  printf("\nThe sorted values are:\n");
  for(i = 0; i < count; i++) {
    printf("%1.4G", atof(array[i]));
    if(i < count - 1) {
      printf(" ");
    }
  }
  printf("\n");
}
