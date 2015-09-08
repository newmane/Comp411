#include <stdio.h>
#include <stdlib.h>
struct point {
  int x;
  int y;
  struct point* next;
};

struct point *palloc(void) {
  return (struct point *) malloc(sizeof(struct point));
}

struct point *addpoint(struct point *pt,int temp1, int temp2) { 
  if(pt == NULL) {
    pt = palloc();
    pt->x = temp1;
    pt->y = temp2;
    pt->next = NULL;
    } else {
      pt->next = addpoint(pt->next, temp1, temp2);
    }
  return pt;
}

main() {
  struct point *pt;
  int temp1, temp2;
  int test = 0;
  while(test == 0) {
    scanf("%d%d", &temp1, &temp2);
    if(temp1 == 0 && temp2 == 0) {
      break;
    }
    pt = addpoint(pt, temp1, temp2);
  }
  int answer;
  while(pt != NULL) {
    answer = ((pt->x) * (pt->x) + (pt->y) * (pt->y));
    printf("%d\n", answer);
    pt = pt->next;
  }
}
