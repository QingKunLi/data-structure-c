
#ifndef __QUEUE_H__
#define __QUEUE_H__

/* 循环队列 */

typedef int ElementType;
typedef struct QNode* Queue;

#define ERROR -1

struct QNode {
  ElementType *data;
  int front;
  int rear;
  int size;
};

Queue CreateQueue(int MaxSize);
int IsFull(Queue Q);
int IsEmpty(Queue Q);
void Add(Queue Q, ElementType item);
ElementType Delete(Queue Q);

#endif