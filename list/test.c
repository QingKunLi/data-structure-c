
#include <stdio.h>
#include "list.h"

void Traversal(List L);

int main() {
  List L = MakeEmpty();
  for (int i = 0; i < 5; i++) {
    Insert(i*3, i, L);
  }
  PtrLNode p = FindKth(2, L);
  printf("%d\n", p->value);
  Traversal(L);
  Insert(7, 1, L);
  Traversal(L);
  Delete(6, L);
  Traversal(L);
  return 0;
}

void Traversal(List L) {
  PtrLNode p = L->next;
  while(p) {
    printf("%d ", p->value);
    p = p->next;
  }
  printf("\n");
}