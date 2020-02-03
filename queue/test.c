
#include <stdio.h>
#include "queue.h"

int main() {
  Queue Q = CreateQueue(5);
  Add(Q, 1);
  Add(Q, 3);
  Add(Q, 13);
  Add(Q, 27);
  Add(Q, 131);
  Add(Q, 1096);
  ElementType value;
  while ((value = Delete(Q)) != ERROR) {
    printf("%d ", value);
  }
  printf("\n");
  return 0;
}