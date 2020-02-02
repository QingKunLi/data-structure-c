
#ifndef __LIST_H__
#define __LIST_H__

/* 线性表的链式存储 */
typedef int ElementType;
typedef struct LNode* List;
typedef struct LNode* PtrLNode;

struct LNode {
  ElementType value;
  PtrLNode next;
};

List MakeEmpty();
PtrLNode FindKth(int K, List L);
int Find(ElementType X, List L);
void Insert(ElementType X, int i, List L);
void Delete(int i, List L);
int Length(List L);

#endif