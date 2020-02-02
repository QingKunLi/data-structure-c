
#include <stdio.h>
#include "stack.h"

int main() {
  Stack S = CreateStack();
  Push(S, 5);
  Push(S, 4);
  Push(S, 3);
  printf("%d\n", Pop(S));
  Push(S, 6);
  printf("%d\n", Pop(S));
  printf("%d\n", Pop(S));
  printf("%d\n", Pop(S));
  Pop(S);
  return 0;
}