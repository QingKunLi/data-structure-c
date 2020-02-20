
#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"

Position Find(BinTree BT, TreeElement item)
{
  if (!BT)
  {
    fprintf(stderr, "Bintree is empty.\n");
    return NULL;
  }
  if (BT->value > item)
  {
    return Find(BT->left, item);
  }
  else if (BT->value < item)
  {
    return Find(BT->right, item);
  }
  else
  {
    return BT;
  }
}
Position FindMin(BinTree BT)
{
  if (!BT)
  {
    fprintf(stderr, "Bintree is empty.\n");
    return NULL;
  }
  // 迭代实现
  Position T = BT;
  while (T->left)
  {
    T = T->left;
  }
  return T;
}
Position FindMax(BinTree BT)
{
  if (!BT)
  {
    fprintf(stderr, "Bintree is empty.\n");
    return NULL;
  }
  // 递归实现
  if (!BT->right)
  {
    return BT;
  }
  else
  {
    return FindMax(BT->right);
  }
}
BinTree Insert(BinTree BT, TreeElement item)
{
  if (!BT)
  {
    // 树为空
    BinTree T = (BinTree)malloc(sizeof(struct TNode));
    T->value = item;
    T->left = T->right = NULL;
    return T;
  }
  if (BT->value > item)
  {
    BT->left = Insert(BT->left, item);
  }
  else if (BT->value < item)
  {
    BT->right = Insert(BT->right, item);
  }
  return BT;
}
BinTree Delete(BinTree BT, TreeElement item)
{
  if (!BT)
  {
    fprintf(stderr, "Item isn't in the tree.\n");
    return NULL;
  }
  if (BT->value > item)
  {
    BT->left = Delete(BT->left, item);
  }
  else if (BT->value < item)
  {
    BT->right = Delete(BT->right, item);
  }
  else
  {
    if (BT->right && BT->left)
    {
      // 若节点度为2
      Position T = FindMin(BT->right); // 找到右子树的最小值
      BT->value = T->value;
      BT->right = Delete(BT->right, T->value);
    }
    else if (BT->right)
    {
      // 若存在右节点
      BinTree T = BT;
      BT = BT->right;
      free(T);
    }
    else
    {
      // 若存在左节点或为叶节点
      BinTree T = BT;
      BT = BT->left;
      free(T);
    }
  }
  return BT;
}

// 二叉树的遍历

// 先序遍历
void PreorderTraversal(BinTree BT)
{
  BinTree T = BT;
  BinTree stack[10];
  int top = 0;
  while (T || top != 0)
  {
    while (T)
    {
      stack[top++] = T;
      T = T->left;
    }
    if (top != 0)
    {
      T = stack[--top];
      printf("%d ", T->value);
      T = T->right;
    }
  }
  printf("\n");
}

// 中序遍历
void InorderTraversal(BinTree BT) {
  BinTree T = BT;
  BinTree stack[10];
  int top = 0;
  while (T || top != 0) {
    while (T) {
      printf("%d ", T->value);
      stack[top++] = T;
      T = T->left;
    }
    if (top != 0) {
      T = stack[--top];
      T = T->right;
    }
  }
  printf("\n");
}

// 后序遍历
void PostorderTraversal(BinTree BT) {
  BinTree T = BT;
  BinTree stack[10];
  BinTree last = NULL;
  int top = 0;
  while (T || top != 0) {
    while (T) {
      stack[top++] = T;
      T = T->left;
    }
    if (top != 0) {
      T = stack[top - 1];
      if (!T->right || last == T->right) {
        T = stack[--top];
        last = T;
        printf("%d ", T->value);
        T = NULL;
      } else {
        last = T;
        T = T->right;
      }
    }
  }
  printf("\n");
}

// 层序遍历
void LevelorderTraversal(BinTree BT) {
  BinTree T;
  BinTree queue[10];
  int front = -1, rear = -1;
  queue[++rear] = BT;
  while (front != rear) {
    T = queue[++front];
    printf("%d ", T->value);
    if (T->left) {
      queue[++rear] = T->left;
    }
    if (T->right) {
      queue[++rear] = T->right;
    }
  }
  printf("\n");
}