
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

List MakeEmpty() {
  List L = (List)malloc(sizeof(struct LNode));
  L->next = NULL;
  return L;
}
PtrLNode FindKth(int K, List L) {
  PtrLNode p = L->next;
  int i = 0;
  while(p && i < K) {
    p = p->next;
    i++;
  }
  return p;
}
int Find(ElementType X, List L) {
  PtrLNode p = L->next;
  int index = 0;
  while(p) {
    if (p->value == X) return index;
    p = p->next;
    index++;
  }
  return -1;
}
void Insert(ElementType X, int i, List L) {
  // 在头部插入
  if (i == 0) {
    PtrLNode node = (PtrLNode)malloc(sizeof(struct LNode));
    node->value = X;
    node->next = L->next;
    L->next = node;
    return;
  } else {
    PtrLNode before = FindKth(i-1, L); // 找到前一个节点
    if (!before) {
      fprintf(stderr, "Invalid position to insert.\n");
      return;
    } else {
      PtrLNode node = (PtrLNode)malloc(sizeof(struct LNode));
      node->value = X;
      node->next = before->next;
      before->next = node;
      return;
    }
  }
}
void Delete(int i, List L) {
  if (Length(L) == 0) {
    fprintf(stderr, "List is empty.\n");
    return;
  }
  // 删除头节点
  if (i == 0) {
    PtrLNode node = L->next;
    L->next = node->next;
    free(node);
    return;
  } else {
    PtrLNode before = FindKth(i-1, L); // 找到要删除的节点前面的节点
    if (!before || !before->next) {
      fprintf(stderr, "Invalid position to delete.\n");
      return;
    } else {
      PtrLNode node = before->next;
      before->next = node->next;
      free(node);
      return;
    }
  }
}
int Length(List L) {
  PtrLNode p = L;
  int len = 0;
  while (p->next) {
    p = p->next;
    len++;
  }
  return len;
}