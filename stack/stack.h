
#ifndef __STACK_H__
#define __STACK_H__

/* 堆栈的链式存储 */
typedef int ElementType;
typedef struct SNode* Stack;
typedef struct SNode* PtrSNode;

#define ERROR -1

struct SNode {
  ElementType value;
  PtrSNode next;
};

Stack CreateStack();
int IsEmpty(Stack S);
void Push(Stack S, ElementType item);
ElementType Pop(Stack S);

#endif