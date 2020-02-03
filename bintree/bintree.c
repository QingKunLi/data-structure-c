
#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"

Position Find(BinTree BT, ElementType item) {
  if (!BT) {
    fprintf(stderr, "Bintree is empty.\n");
    return NULL;
  }
  if (BT->value > item) {
    return Find(BT->left, item);
  } else if (BT->value < item) {
    return Find(BT->right, item);
  } else {
    return BT;
  }
}
Position FindMin(BinTree BT) {
  if (!BT) {
    fprintf(stderr, "Bintree is empty.\n");
    return NULL;
  }
  // 迭代实现
  Position T = BT;
  while (T->left) {
    T = T->left;
  }
  return T;
}
Position FindMax(BinTree BT) {
  if (!BT) {
    fprintf(stderr, "Bintree is empty.\n");
    return NULL;
  }
  // 递归实现
  if (!BT->right) {
    return BT;
  } else {
    return FindMax(BT->right);
  }
}
BinTree Insert(BinTree BT, ElementType item) {
  if (!BT) {
    // 树为空
    BinTree T = (BinTree)malloc(sizeof(struct TNode));
    T->value = item;
    T->left = T->right = NULL;
    return T;
  }
  if (BT->value > item) {
    BT->left = Insert(BT->left, item);
  } else if (BT->value < item) {
    BT->right = Insert(BT->right, item);
  }
  return BT;
}
BinTree Delete(BinTree BT, ElementType item) {
  if (!BT) {
    fprintf(stderr, "Item isn't in the tree.\n");
    return NULL;
  }
  if (BT->value > item) {
    BT->left = Delete(BT->left, item);
  } else if (BT->value < item) {
    BT->right = Delete(BT->right, item);
  } else {
    if (BT->right && BT->left) {
      // 若节点度为2
      Position T = FindMin(BT->right); // 找到右子树的最小值
      BT->value = T->value;
      BT->right = Delete(BT->right, T->value); 
    } else if (BT->right) {
      // 若存在右节点
      BinTree T = BT;
      BT = BT->right;
      free(T);
    } else {
      // 若存在左节点或为叶节点
      BinTree T = BT;
      BT = BT->left;
      free(T);
    }
    return BT;
  }
}
// void PreorderTraversal(BinTree BT) {
//   while (BT) {

//   }
// }