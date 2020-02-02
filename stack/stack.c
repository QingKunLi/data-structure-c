
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Stack CreateStack() {
  Stack S = (Stack)malloc(sizeof(struct SNode));
  S->next = NULL;
  return S;
}
int IsEmpty(Stack S) {
  return S->next == NULL;
}
void Push(Stack S, ElementType item) {
  PtrSNode node = (PtrSNode)malloc(sizeof(struct SNode));
  node->value = item;
  node->next = S->next;
  S->next = node;
}
ElementType Pop(Stack S) {
  if (IsEmpty(S)) {
    fprintf(stderr, "Stack is empty.\n");
    return ERROR;
  }
  PtrSNode node = S->next;
  ElementType value = node->value;
  S->next = node->next;
  free(node);
  return value;
}
