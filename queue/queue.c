
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Queue CreateQueue(int MaxSize) {
  Queue Q = (Queue)malloc(sizeof(struct QNode));
  Q->data = (ElementType *)malloc(sizeof(ElementType)*(MaxSize+1));
  Q->size = MaxSize+1;
  Q->front = Q->rear = 0;
  return Q;
}
int IsFull(Queue Q) {
  return (Q->rear + 1) % Q->size == Q->front;
}
int IsEmpty(Queue Q) {
  return Q->rear == Q->front;
}
void Add(Queue Q, ElementType item) {
  if (IsFull(Q)) {
    fprintf(stderr, "Queue is full.\n");
    return;
  }
  Q->data[(++Q->rear) % Q->size] = item;
}
ElementType Delete(Queue Q) {
  if (IsEmpty(Q)) {
    fprintf(stderr, "Queue is empty.\n");
    return ERROR;
  }
  return Q->data[(++Q->front) % Q->size];
}